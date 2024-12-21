/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   corectx_virtual.c                                                        */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 21/12/2024 17:06:44 by NyTekCFW                                 */
/*   Updated: 21/12/2024 17:59:23 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

t_virtual	*get_virtual(void)
{
	return (&get_coregba()->vmem);
}

static void	set_virtual_scale(void)
{
	u16	v = 256;//256=normal 128=scale 

	if (get_virtual()->use_scaling)
			v = 128;
	*(volatile u16 *)0x4000020 = v;//REG_BG2PA 
	*(volatile u16 *)0x4000026 = v;//REG_BG2PD
}

static void	set_virtual_mode(int mode, int use_mode_5_scale)
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

static void	set_virtual_timer(void)
{
	t_virtual	*vmem = get_virtual();

	if (!vmem->timer_on)
	{
		clock_init();
		vmem->timer_on = 1;
	}
}

void	boot_virtual(u8 scaled)
{
	set_virtual_mode(MODE_5_BG2, scaled);
	set_virtual_timer();
}

