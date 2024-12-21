/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mx_img.c                                                                 */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 11/12/2024 17:48:39 by NyTekCFW                                 */
/*   Updated: 11/12/2024 17:48:43 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

u16	*get_px_adr(t_virtual* vmem, u16 *vbuf, u16 x, u16 y)
{
	if (y <= vmem->scaled_height && x <= vmem->scaled_width)
		return (&vbuf[y * vmem->width + x]);
	return (NULL);
}

void	mx_put_pixel(t_virtual* vmem, u16 *vbuf, u16 x, u16 y, u16 clr)
{
	if (y <= vmem->scaled_height && x <= vmem->scaled_width)
		vbuf[y * vmem->width + x] = clr;
}

IN_IWRAM void	draw_image(s16 x, s16 y, s16 w, s16 h, const u16 *map)
{
	u16			*vbuf = gcm_get_draw_buffer();
	t_virtual	*vmem = get_virtual();
	u16			y2 = 0;
	u16			x2 = 0;
	u16			color = 0;
	s16			w2 = w;
	s16			x3 = x;
	s16			y3 = y;
	s16			map_x_offset = 0;
	u32			i = 0;
	u32			j = 0;

	x2 = max(0, x);
	y2 = max(0, y);
	if (y > vmem->scaled_height || x > vmem->scaled_width || 
		(w = min(w + (x < 0 ? x : 0), vmem->scaled_width - x2)) <= 0 || 
		(h = min(h + (y < 0 ? y : 0), vmem->scaled_height - y2)) <= 0)
		return;
	x = x2;
	y = y2;
	if (x3 < 0)
		map_x_offset = -x3;
	i = (y * vmem->width) + x;
	j = ((y3 < 0 ? -y3 : 0) * w2) + map_x_offset;
	for (y2 = 0; y2 < h; ++y2)
	{
		for (x2 = 0; x2 < w; ++x2)
		{
			color = map[j + x2];
			if (color)
				vbuf[i + x2] = color;
		}
		i += vmem->width;
		j += w2;
	}
}

IN_IWRAM void	print_img(s16 x, s16 y, s16 w, s16 h, const u16 *map)
{
	u16			*vbuf = gcm_get_draw_buffer();
	t_virtual	*vmem = get_virtual();
	u16			*start = NULL;
	u16			*bstart = NULL;
	s16			y2 = 0;
	s16			x2 = 0;
	s16			w2 = w;
	u16			size = 0;
	s16			map_y_offset = 0;
	s16			map_x_offset = 0;

	x2 = max(0, x);
	y2 = max(0, y);
	if (y < 0)
		map_y_offset = -y;
	if (x < 0)
		map_x_offset = -x;
	if (y > vmem->scaled_height || x > vmem->scaled_width || 
		(w = min(w + (x < 0 ? x : 0), vmem->scaled_width - x2)) <= 0 || 
		(h = min(h + (y < 0 ? y : 0), vmem->scaled_height - y2)) <= 0)
		return;
	x = x2;
	y = y2;
	size = w * sizeof(u16);
	start = &vbuf[(y * vmem->width) + x];
	x2 = (map_y_offset * w2) + map_x_offset;
	bstart = (u16 *)&map[x2];
	for (y2 = 0; y2 < h; ++y2)
	{
		CpuCopy(bstart, start, size);
		start += vmem->width;
		bstart += w2;
	}
}
