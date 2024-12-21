/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_colorpicker.h                                                    */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 20/12/2024 15:18:44 by NyTekCFW                                 */
/*   Updated: 20/12/2024 15:19:16 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREGFX_COLORPICKER_H
# define COREGFX_COLORPICKER_H

void	color_picker_logic(s16 p_x, s16 p_y);
void	color_picker_unset_control(void);
void	color_picker_set_control(u16 next_color, u16 prev_color, u16 inc_brightness, u16 dec_brightness, void (*callback)(u8, u8, u16));
u8		get_color_picker_status(void);

#endif