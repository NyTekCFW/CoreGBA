/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mx_virtual.h                                                             */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 10/12/2024 14:42:27 by NyTekCFW                                 */
/*   Updated: 10/12/2024 14:42:29 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MX_VIRTUAL_H
# define MX_VIRTUAL_H

enum e_mode
{
	MODE_3_BG2	= 0x403, //1027
	MODE_4_BG2, //1028
	MODE_5_BG2 //1029
};

typedef struct mx_virtual_s
{
	u16	width;
	u16	height;
	u16	scaled_width;
	u16	scaled_height;
	u16	mode;
	u8	use_scaling;
	u8	timer_on;
}	t_virtual;

void		set_virtual_mode(int mode, int use_mode_5_scale);
void		set_virtual_timer(int status);
int			boot_virtual_loader(int mode);
t_virtual	*get_virtual(void);
#endif