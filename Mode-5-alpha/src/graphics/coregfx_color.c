/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_color.c                                                          */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 12/12/2024 15:04:10 by NyTekCFW                                 */
/*   Updated: 18/12/2024 17:59:04 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mx_global.h"

inline u16	rgb_to_15bit(u8 r, u8 g, u8 b)
{
	return ((r >> 3) | ((g >> 3) << 5) | ((b >> 3) << 10));
}

inline void	rgb15_to_rgb(u16 rgb15, u8 *r, u8 *g, u8 *b)
{
	*r = ((rgb15 & 0x1F) << 3) | ((rgb15 & 0x1F) >> 2);
	*g = (((rgb15 >> 5) & 0x1F) << 3) | (((rgb15 >> 5) & 0x1F) >> 2);
	*b = (((rgb15 >> 10) & 0x1F) << 3) | (((rgb15 >> 10) & 0x1F) >> 2);
}

static inline u16	*_get_tab(void)
{
	return ((u16 *)0x05000000);
}

/// @brief return the static tab of color (index 0 - 207)
/// @return //tab[ROW_COLOR_TYPE (0->13)][Brightness intensity (0->15)]
inline u16	(*get_stab_color(void))[16]
{
    return ((u16 (*)[16])0x05000000);
}

static u16	*_get_ncolor(void)
{
	static u16	index = 0;

	return (&index);
}

static int	_color_is_reg(u16 color)
{
	u16	j = 0;
	u16	*n = _get_ncolor();
	u16	*ptr = _get_tab();

	for (j = 0; j < *n; ++j)
	{
		if (ptr[j] == color)
			return (1);
	}
	return (0);
}

u16	get_color_index(u16 color)
{
	u16	j = 0;
	u16	*n = _get_ncolor();
	u16	*ptr = _get_tab();

	for (j = 0; j < *n; ++j)
	{
		if (ptr[j] == color)
			return (j);
	}
	return (0xFFFF);
}

/// @brief replace a color at index > 208
/// @param index index 209 ->255
/// @param color color to store
void	replace_color(u16 index, u16 color)
{
	u16	*n = _get_ncolor();
	u16	*ptr = _get_tab();
	if (index < *n && index >= 208 && (index == 208 || !_color_is_reg(color)))
		ptr[index] = color;
}

void	register_color(u16 color, u16 *get_index)
{
	u16	*n = _get_ncolor();
	u16	*ptr = _get_tab();

	if (get_index)
		*get_index = 0;
	if (*n < 256 && !_color_is_reg(color))
	{
		if (get_index)
			*get_index = *n;
		ptr[*n] = color;
		++(*n);
	}
}

u16	get_color_at(u16 index)
{
	u16	*n = _get_ncolor();
	u16	*ptr = _get_tab();

	if (index < 256 && index < *n)
		return (ptr[index]);
	return (0);
}

void fast_find_color(void);

void	build_all_colors(void)
{
	float	whiteness_factor = 0;
	float	brightness = 0;
	int		i = 0;
	int		r_temp = 0;
	int		g_temp = 0;
	int		b_temp = 0;
	u16		(*tab)[16] = get_stab_color();
	u16		base_colors[13] =
	{
		rgb_to_15bit(0xff, 0, 0),      // Rouge
		rgb_to_15bit(0xff, 0x7f, 0),     // Orange
		rgb_to_15bit(0xff, 0xff, 0),     // Jaune
		rgb_to_15bit(0x7f, 0xff, 0),     // Vert clair
		rgb_to_15bit(0, 0xff, 0),      // Vert
		rgb_to_15bit(0, 0xff, 0x7f),     // Vert cyan
		rgb_to_15bit(0, 0xff, 0xff),      // Cyan
		rgb_to_15bit(0, 0x7f, 0xff),      // Bleu cyan
		rgb_to_15bit(0, 0, 0xff),      // Bleu
		rgb_to_15bit(0x7f, 0, 0xff),     // Bleu violet
		rgb_to_15bit(0xff, 0, 0xff),     // Violet
		rgb_to_15bit(0xff, 0, 0x7f),    // Violet rouge / Pink
		rgb_to_15bit(0x7f, 0x7f, 0x7f)     // Gris
	};
	u16		c = 0;
	u8		r = 0;
	u8		g = 0;
	u8		b = 0;
	u8		r_base = 0;
	u8		g_base = 0;
	u8		b_base = 0;
	u8		r_new = 0;
	u8		g_new = 0;
	u8		b_new = 0;

	for (i = 0; i < 13; ++i)
	{
		c = base_colors[i];
		r = (c >> 10) & 0x1F;
		g = (c >> 5) & 0x1F;
		b = c & 0x1F;
		r_base = r << 3;
		g_base = g << 3;
		b_base = b << 3;
		for (int j = 0; j < 16; ++j)
		{
			if (j < 8)
				brightness = max(0.0f, 0.18f + (0.1f * j));
			else if (j == 8)
				brightness = 1.0f;
			else if (j > 8)
			{
				whiteness_factor = (j - 8) / 8.0f;
				r_temp = (int)(r_base + ((255 - r_base) * whiteness_factor));
				g_temp = (int)(g_base + ((255 - g_base) * whiteness_factor));
				b_temp = (int)(b_base + ((255 - b_base) * whiteness_factor));
				r_new = (u8)min(255, r_temp) >> 3;
				g_new = (u8)min(255, g_temp) >> 3;
				b_new = (u8)min(255, b_temp) >> 3;
				tab[i][j] = (r_new << 10) | (g_new << 5) | b_new;
				continue ;
			}
			r_new = (u8)(r_base * brightness);
			g_new = (u8)(g_base * brightness);
			b_new = (u8)(b_base * brightness);
			r_new = (r_new > 255 ? 255 : r_new) >> 3;
			g_new = (g_new > 255 ? 255 : g_new) >> 3;
			b_new = (b_new > 255 ? 255 : b_new) >> 3;
			tab[i][j] = (r_new << 10) | (g_new << 5) | b_new;
		}
	}
	//fast_find_color();
	if (*_get_ncolor() < 209)
		*_get_ncolor() = 209;// 208 + 1 to make a color loop into the 208 slot
    *(volatile u32 *)0x40001C4 = *_get_ncolor();
}

void fast_find_color(void)
{
	int	i = 0;
	int	k = 0;
	u16	*ptr = _get_tab();
	u16	base = 0;

	for (k = 1; k < 208; ++k)
	{
		base = ptr[k];
		i = k - 1;
		while (i >= 0 && ptr[i] > base)
		{
			ptr[i + 1] = ptr[i];
			--i;
		}
		ptr[i + 1] = base;
	}
}
