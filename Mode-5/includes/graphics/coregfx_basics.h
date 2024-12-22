/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_basics.h                                                         */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 20/12/2024 15:16:26 by NyTekCFW                                 */
/*   Updated: 20/12/2024 15:16:48 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREGFX_BASICS_H
# define COREGFX_BASICS_H

void	mx_put_pixel(t_virtual* vmem, u16 *vbuf, u16 x, u16 y, u16 clr);
void	draw_image(s16 x, s16 y, s16 w, s16 h, const u16 *map);
void	print_img(s16 x, s16 y, s16 w, s16 h, const u16 *map);
u16		*get_px_adr(t_virtual* vmem, u16 *vbuf, u16 x, u16 y);
#endif