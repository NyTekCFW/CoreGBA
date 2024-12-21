/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coretask_run.c                                                           */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 21/12/2024 18:35:01 by NyTekCFW                                 */
/*   Updated: 21/12/2024 19:14:05 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

void	run_tasks(u8 scaled, u16 clear_color, u32 rand_seed)
{
	t_basic		*basic = get_basic();
	t_callback	*callback = get_callback();

	boot_virtual(scaled);
	gcm_init_body();
	gcm_set_clear_color(clear_color);
	init_keyboard();
	if (callback->keys)
		callback->keys();
	run_task_irq();
	build_all_colors();
	xsrand(rand_seed);
	basic->initialised = 1;
	basic->running = 1;
	if (basic->max_fps < 5)
		basic->max_fps = 60;
	if (basic->timescale < 0.3f)
		basic->timescale = 1.0f;
	if (basic->timescale > 2.0f)
		basic->timescale = 1.0f;
	run_task_script();
}
