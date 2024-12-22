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

static void	run_engine(void)
{
	t_engine	*engine = get_engine();
	t_callback	*callback = get_callback();

	while (engine->running)
	{
		if (callback->scripts)
			callback->scripts();
		run_task_rendering(engine, callback);
		gcm_prepare_flip();
		CpuCopy(gcm_get_draw_buffer(), gcm_get_active_buffer(), gcm_get_buffer_size());
	}
	engine->initialised = 0;
}

void	run_tasks(u8 scaled, u16 clear_color, u8 max_fps, float timescale, u32 rand_seed)
{
	t_engine	*engine = get_engine();
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
	engine->initialised = 1;
	engine->running = 1;
	engine->max_fps = (max_fps < 3) ? 60 : max_fps;
	engine->timescale = (timescale < 0.3) ? 1.0f : \
		((timescale > 2.0f) ? 1.0f : timescale);
	run_engine();
}
