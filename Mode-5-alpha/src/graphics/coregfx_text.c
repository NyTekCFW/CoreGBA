/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_text.c                                                           */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 17/12/2024 23:11:36 by NyTekCFW                                 */
/*   Updated: 17/12/2024 23:11:38 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

u8	r_glyph_width(char c)
{
	if (c >= 0x20 && c <= 0x7E)
		return (font_basic_width[c - 0x20]);
	if (c >= 0x0B && c <= 0x17)
		return (font_button_width[c - 0x0B]);
	return (8);
}

u8	r_glyph_height(void)
{
	return (9);
}

u32	r_textwidth(const char *str)
{
	u32	width = 0;

	if (!str)
		return (0);
	while (*str)
	{
		width += r_glyph_width(*str);
		++str;
	}
	return (width);
}

static void	draw_symbol(char c, s16 x, s16 y, u8 space)
{
	u16	*symbol = NULL;

	switch (c)
	{
		case 0x0B: symbol = img_button_a; break;
		case 0x0C: symbol = img_button_b; break;
		case 0x0D: symbol = img_dpad_up; break;
		case 0x0E: symbol = img_dpad_down; break;
		case 0x0F: symbol = img_dpad_left; break;
		case 0x10: symbol = img_dpad_right; break;
		case 0x11: symbol = img_dpad_left_right; break;
		case 0x12: symbol = img_dpad_up_down; break;
		case 0x13: symbol = img_dpad_none; break;
		case 0x14: symbol = img_button_L; break;
		case 0x15: symbol = img_button_R; break;
		case 0x16: symbol = img_button_start; break;
		case 0x17: symbol = img_button_select; break;
	}
	draw_image(x, y, space, 8, symbol);
}

IN_IWRAM void	draw_text(char *str, s16 x, s16 y, u16 clr)
{
	t_virtual	*vmem = get_virtual();
	u16			*vbuf = gcm_get_draw_buffer();
	int			x_new = x;
	char		*c = 0;
	s16			i = 0;
	s8			x2 = 0;
	s8			y2 = 0;
	u8			space = 0;

	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			y += 9;
			x = x_new;
			++i;
			continue ;
		}
		space = r_glyph_width(str[i]);
		if (str[i] >= 0x0B && str[i] <= 0x17)
			draw_symbol(str[i], x, y, space);
		else if (str[i] >= 0x20 && str[i] <= 0x7E)
		{
			if (x >= 0 && x + space <= vmem->scaled_width
				&& y >= 0 && y + 9 <= vmem->scaled_height)
			{
				c = font_basic[(u8)str[i] - 0x20];
				y2 = -1;
				while (++y2 < 8)
				{
					if (c[y2])
					{
						x2 = 8;
						while (--x2 >= 0)
						{
							if (c[y2] & (1 << x2))
								vbuf[(y + y2) * vmem->width + (x + x2)] = clr;
						}
					}
				}
			}
		}
		x += space;
		++i;
	}
}


/*

IN_IWRAM void	draw_text(char *str, s16 x, s16 y, u16 clr)
{
	t_virtual	*vmem = get_virtual();
	u16			*vbuf = gcm_get_draw_buffer();
	int			x_new = x - 7;
	char		*c = 0;
	s16			i = -1;
	s8			x2 = 0;
	s8			y2 = 0;

	if (!str)
		return ;
	while (str[++i])
	{
		if (x >= 0 && str[i] == 't')
			--x;
		if (str[i] == '\n')
		{
			y += 9;
			x = x_new;
			++i;
			continue ;
		}
		if ((x >= 0 || (x == -1 && str[i] == 't')) && x + 7 <= vmem->scaled_width
			&& y >= 0 && y + 7 <= vmem->scaled_height
			&& str[i] >= 0x21 && str[i] <= 0x7E)
		{
			c = font_basic[(u8)str[i] - 0x21];
			y2 = -1;
			while (++y2 < 8)
			{
				if (c[y2])
				{
					x2 = 8;
					while (--x2 >= 0)
					{
						if (c[y2] & (1 << x2))
							vbuf[(y + y2) * vmem->width + (x + x2)] = clr;
					}
				}
			}
		}
		if (str[i] == 'i' || str[i] == 'I' || str[i] == 'l' || str[i] == 'H'  || str[i] == '('  || str[i] == ')' || str[i] == '+' || str[i] == '-')
			x += 6;
		else if (str[i] == ' ' || str[i] == '\t')
			x += 2;
		else if (str[i] == '\'')
			x += 3;
		else if (str[i] == ',' || str[i] == '.' || str[i] == ':' || str[i] == ';')
			x += 5;
		else if (str[i] == '#' || str[i] == '%'  || str[i] == '/' || str[i] == '&' || str[i] == '0' || str[i] == '1' || str[i] == '4')
			x += 8;
		else if (str[i] == '*')
			x += 9;
		else
			x += 7;
	}
}

*/