/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_colorpicker.c                                                    */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 18/12/2024 18:13:42 by NyTekCFW                                 */
/*   Updated: 18/12/2024 18:13:56 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mx_global.h"

typedef struct colorpicker_s
{
	s8		x;
	s8		y;
	u8		enabled;
	u16		color;
	u16		buttons[4];
	void	(*callback)(u8, u8, u16);
}	t_cp;

static t_cp	*get_cp(void)
{
	static t_cp	color_picker;

	return (&color_picker);
}

static void	color_pprev(void)
{
	t_cp	*cp = get_cp();
	s8		x = cp->x;

	cp->x = (x - 1 < 0) ? 12 : x - 1;
	cp->y = 8;
}

static void	color_pnext(void)
{
	t_cp	*cp = get_cp();

	cp->x = (cp->x + 1) % 13;
	cp->y = 8;
}

static void	color_pinc_brightness(void)
{
	t_cp	*cp = get_cp();

	cp->y = min(cp->y + 1, 15);
}

static void	color_pdec_brightness(void)
{
	t_cp	*cp = get_cp();

	cp->y = max(cp->y - 1, 0);
}

u8	get_color_picker_status(void)
{
	return (get_cp()->enabled);
}

/// @brief define control for color picker
/// @param next_color button attributed for next color (right) use keynum(BUTTON_A/BUTTON_B)
/// @param prev_color button attributed for previous color (left)
/// @param inc_brightness button attributed for increment brightness (up)
/// @param dec_brightness button attributed for decrement brightness (down)
/// @param callback a function called after all rendering done to update your color, e.g mycallback(u8 row, u8 col, u16 color)
void	color_picker_set_control(u16 next_color, u16 prev_color, u16 inc_brightness, u16 dec_brightness, void (*callback)(u8, u8, u16))
{
	t_cp	*cp = get_cp();

	cp->x = 0;
	cp->y = 8;
	cp->buttons[0] = next_color;
	cp->buttons[1] = prev_color;
	cp->buttons[2] = inc_brightness;
	cp->buttons[3] = dec_brightness;
	keynum_replace(next_color, color_pnext);
	keynum_replace(prev_color, color_pprev);
	keynum_replace(inc_brightness, color_pinc_brightness);
	keynum_replace(dec_brightness, color_pdec_brightness);
	cp->callback = callback;
	cp->enabled = 1;
}

void	color_picker_unset_control(void)
{
	t_cp	*cp = get_cp();

	cp->x = 0;
	cp->y = 8;
	cp->buttons[0] = 0;
	cp->buttons[1] = 0;
	cp->buttons[2] = 0;
	cp->buttons[3] = 0;
	keynum_replace(cp->buttons[0], NULL);
	keynum_replace(cp->buttons[1], NULL);
	keynum_replace(cp->buttons[2], NULL);
	keynum_replace(cp->buttons[3], NULL);
	cp->callback = NULL;
	cp->enabled = 0;
}

void	dump_screen_section(int x, int y, int w, int h)
{
	u16	*vbuf = gcm_get_draw_buffer();
	u16	*dump = mx_malloc((w * h) * sizeof(short));

	for (int y2 = 0; y2 < h; ++y2)
	{
		const u16 *src = &vbuf[((y + y2) * get_virtual()->width) + x];
		u16 *dst = &dump[y2 * h];
		CpuCopy16((void *)src, (void *)dst, w * sizeof(u16));
	}

	u32 size = w * h;
	for (u32 i = 0; i < size; ++i)
	{
		dump[i] = (dump[i] >> 8) | (dump[i] << 8);
	}
}

IN_IWRAM void	color_picker_logic(s16 p_x, s16 p_y)
{
	t_cp	*cp = get_cp();
	u16		(*tab)[16] = get_stab_color();
	s8		x = cp->x;
	s8		y = cp->y;
	s8		i = 0;
	s8		row = x - 1;
	u16 	n_x = p_x;

	print_img(p_x - 3, p_y - 10, 26, 26, img_color_picker_bkg);
	while (i < 3)
	{
		switch (i)
		{
			case 0: row = (x - 1 < 0) ? 12 : x - 1; break;
			case 1: row = x; break;
			case 2: row = (x + 1) % 13; break;
		}
		draw_rectangle(n_x, p_y + 1, 4, 4, tab[row][(row == x) ? y : 8], 1);
		if (row == x)
		{
			if (y + 1 < 16)
			{
				draw_rectangle(n_x - 1, p_y - 8, 6, 6, 0, 0);
				draw_rectangle(n_x, p_y - 7, 4, 4, tab[row][y + 1], 1);
			}
			if (y - 1 > -1)
			{
				draw_rectangle(n_x - 1, p_y + 8, 6, 6, 0, 1);
				draw_rectangle(n_x, p_y + 9, 4, 4, tab[row][y - 1], 1);
			}
		}
		++i;
		n_x += 8;
	}
	if (cp->callback)
		cp->callback(cp->x, cp->y, tab[x][y]);
}