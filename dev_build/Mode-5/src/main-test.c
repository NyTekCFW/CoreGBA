/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 09/12/2024 07:08:08 by NyTekCFW                                 */
/*   Updated: 09/12/2024 09:10:57 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coregba.h"

void	up_timescale(void)
{
	t_engine	*engine = get_engine();

	engine->timescale += 0.1f;
	if (engine->timescale > 3.0f)
		engine->timescale = 3.0f;
}

void	down_timescale(void)
{
	t_engine	*engine = get_engine();

	engine->timescale -= 0.1f;
	if (engine->timescale < 0.3f)
		engine->timescale = 0.3f;
}

void	task_key_init(void)
{
	add_keycode(BUTTON_A, KEY_A, up_timescale);
	add_keycode(BUTTON_B, KEY_B, down_timescale);
	add_keycode(BUTTON_L, KEY_L, NULL);
	add_keycode(BUTTON_R, KEY_R, NULL);
	add_keycode(BUTTON_START, KEY_START, NULL);
	add_keycode(BUTTON_SELECT, KEY_SELECT, NULL);
	add_keycode(BUTTON_MOVE_FORWARD, KEY_UP, NULL);
	add_keycode(BUTTON_MOVE_BACKWARD, KEY_DOWN, NULL);
	add_keycode(BUTTON_MOVE_LEFT, KEY_LEFT, NULL);
	add_keycode(BUTTON_MOVE_RIGHT, KEY_RIGHT, NULL);
}

void	task_scripts(void)
{

}

int i = 4;
int u = 1;
void	task_rendering(void)
{
	t_engine	*engine = get_engine();

	gcm_clear_draw_buffer();
	char *t = xitoa(engine->fps_out);
	draw_text(t, 0, 0, 0xffff);
	xfree((void **)&t);
}

void	task_irq(void)
{

}

int main(void)
{
	t_callback	*callback = get_callback();

	callback->scripts = task_scripts;
	callback->rendering = task_rendering;
	callback->keys = task_key_init;
	callback->irq = task_irq;
	run_tasks(1, 0xff, 60, 1.0f, 0);
}


