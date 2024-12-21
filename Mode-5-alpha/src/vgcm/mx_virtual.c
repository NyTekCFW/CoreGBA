/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mx_virtual.c                                                             */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 09/12/2024 11:24:27 by NyTekCFW                                 */
/*   Updated: 09/12/2024 12:00:38 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mx_global.h"

t_virtual	*get_virtual(void)
{
	return (&gmx()->vmem);
}

static void	set_virtual_scale(void)
{
	u16	v = 256;//256=normal 128=scale 

	if (get_virtual()->use_scaling)
			v = 128;
	*(volatile u16 *)0x4000020 = v;//REG_BG2PA 
	*(volatile u16 *)0x4000026 = v;//REG_BG2PD
}

void	set_virtual_mode(int mode, int use_mode_5_scale)
{
	t_virtual	*vmem = get_virtual();

	if (mode >= MODE_3_BG2 && mode <= MODE_5_BG2)
	{
		*(u16 *)0x4000000 = mode;
		vmem->mode = mode;
		vmem->use_scaling = 0;
		switch (mode)
		{
			case MODE_3_BG2:
			{
				vmem->scaled_width = vmem->width = 240;
				vmem->scaled_height = vmem->height = 160;
				break ;
			}
			case MODE_4_BG2:
			{
				vmem->scaled_width = vmem->width = 240;
				vmem->scaled_height = vmem->height = 160;
				break ;
			}
			case MODE_5_BG2:
			{
				vmem->scaled_width = vmem->width = 160;
				vmem->scaled_height = vmem->height = 128;
				if (use_mode_5_scale)
				{
					vmem->scaled_width = 120;
					vmem->scaled_height = 80;
					vmem->use_scaling = 1;
				}
				set_virtual_scale();
				break ;
			}
		}
	}
}

void	set_virtual_timer(int status)
{
	t_virtual	*vmem = get_virtual();

	if (!vmem->timer_on && status)
	{
		clock_init();
		vmem->timer_on = 1;
	}
}

int	boot_virtual_loader(int mode)
{
	if (mode == MODE_5_BG2)
	{
		set_virtual_mode(mode, 1);
		set_virtual_timer(1);
		return (1);
	}
	return (0);
}

