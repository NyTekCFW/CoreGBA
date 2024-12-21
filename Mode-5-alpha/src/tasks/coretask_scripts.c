/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coretask_rendering.c                                                     */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 21/12/2024 19:29:02 by NyTekCFW                                 */
/*   Updated: 21/12/2024 19:29:17 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

void	execute_rendering(t_basic *basic, t_callback *callback)
{
	static u32	left = 0;
	u32			cpu = 0;

	while (clock() < left)
		;
	left = clock() + (CLOCKS_PER_SEC / (30 * basic->timescale));
	cpu = clock();
	gcm_clear_draw_buffer();
	if (callback->rendering)
		callback->rendering();
	while (clock() < cpu + (CLOCKS_PER_SEC / basic->max_fps))
		;
	basic->fps_out = get_fps(cpu);
}

void	run_task_script(void)
{
	t_basic		*basic = get_basic();
	t_callback	*callback = get_callback();

	while (basic->running)
	{
		if (callback->scripts)
			callback->scripts();
		execute_rendering(basic, callback);
		gcm_prepare_flip();
		CpuCopy(gcm_get_draw_buffer(), gcm_get_active_buffer(), gcm_get_buffer_size());
	}
	basic->initialised = 0;
}
