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

#include "../includes/mx_global.h"

void	update_clear_color(u8 row, u8 col, u16 color)
{
	gcm_set_clear_color(color);
}

void	init_keycode(void)
{
	add_keycode(BUTTON_A, KEY_A, NULL);
	add_keycode(BUTTON_B, KEY_B, NULL);
	add_keycode(BUTTON_L, KEY_L, NULL);
	add_keycode(BUTTON_R, KEY_R, NULL);
	add_keycode(BUTTON_START, KEY_START, NULL);
	add_keycode(BUTTON_SELECT, KEY_SELECT, NULL);
	add_keycode(BUTTON_MOVE_FORWARD, KEY_UP, NULL);
	add_keycode(BUTTON_MOVE_BACKWARD, KEY_DOWN, NULL);
	add_keycode(BUTTON_MOVE_LEFT, KEY_LEFT, NULL);
	add_keycode(BUTTON_MOVE_RIGHT, KEY_RIGHT, NULL);
	color_picker_set_control(BUTTON_MOVE_RIGHT, BUTTON_MOVE_LEFT, BUTTON_MOVE_FORWARD, BUTTON_MOVE_BACKWARD, update_clear_color);
}

void	color_loop(int *row, int *b)
{
	static s8 rrow = 0;
	static s8 column = 0;
	static s8 dir = 0;

	if (!dir)
		++column;
	else
		--column;
	if (column == 16 || column == -1)
		rrow = (rrow + 1) % 13;
	if (column == 16)
	{
		dir = !dir;
		column = 15;
	}
	else if (column == -1)
	{
		dir = !dir;
		column = 0;
	}
	*row = rrow;
	*b = column;
}

void	callback(void)
{
	static unsigned long int	frame = 0;
	s16							i = 0;

	u16	(*tab)[16] = (u16 (*)[16])0x05000000;
	int	row = 0;
	int	vb = 0;

	if (!(frame % 5))
	{
		color_loop(&row, &vb);
		replace_color(208, tab[row][vb]);
	}
	if (!(frame % 15))
	{
		i = -1;
		set_keycode_status(KEY_A, key_pressed(KEY_A));
		set_keycode_status(KEY_B, key_pressed(KEY_B));
		set_keycode_status(KEY_L, key_pressed(KEY_L));
		set_keycode_status(KEY_R, key_pressed(KEY_R));
		set_keycode_status(KEY_SELECT, key_pressed(KEY_SELECT));
		set_keycode_status(KEY_START, key_pressed(KEY_START));
		set_keycode_status(KEY_UP, key_pressed(KEY_UP));
		set_keycode_status(KEY_DOWN, key_pressed(KEY_DOWN));
		set_keycode_status(KEY_LEFT, key_pressed(KEY_LEFT));
		set_keycode_status(KEY_RIGHT, key_pressed(KEY_RIGHT));
		while (++i < BUTTON_MAX)
			keynum_execute(i);
	}
	frame = (frame + 1) % 0xFFFFFFFF;
}

void	execute_rendering(void)
{
	static u32	left = 0;
	u32			cpu = 0;
	int			maxfps = 60;
	float		timescale = 1;

	if (!clock_waittime(left))
		return ;
	left = clock() + (CLOCKS_PER_SEC / (30 * timescale));
	cpu = clock();
	gcm_clear_draw_buffer();
//	draw_text("Press " STR_BUTTON_A " To start", 0, 70, 0xFFFF);
	usleep((CLOCKS_PER_SEC / maxfps));
	char *t = xitoa(get_fps(cpu));
	draw_text(t, 0, 0, 0);
	xfree((void **)&t);
}


void	execute_task(void)
{
	t_mx	*mx = gmx();
	gcm_set_clear_color(0xFF);
	while (1)
	{
		execute_rendering();
		gcm_prepare_flip();
		CpuCopy(gcm_get_draw_buffer(), gcm_get_active_buffer(), gcm_get_buffer_size());
	}
}

int main(void)
{
	t_mx		*mx = NULL;

	if (boot_virtual_loader(MODE_5_BG2))
	{
		xsrand(0);
		init_keyboard();
		init_keycode();
		gcm_init_body();
		build_all_colors();
		mmap_get_total_mem();
		gcm_set_clear_color(0xFFFF);
		irqInit();
		irqEnable(IRQ_VBLANK);
		irqSet(IRQ_VBLANK, callback);
		mx = gmx();
		while (mx)
		{
			execute_task();
			
			
		//	
			//gcm_clear_window();
			//draw_rec(40, 40, 23, 10, 0xFF);
			//draw_circle(60, 40, 4,  0xff, 1);
		//	sleep(0.001f);
		//	char *t = xitoa(clock());
		//	draw_text(t,0,i * 10, 0);
		//	xfree((void **)&t);
		//	++i;
			//while(clock() < co + CLOCKS_PER_MS * 10)
			//	;
			/*co = clock();
			
			t = xitoa(clock() - co);
			draw_text(t,0,20, 0);
			xfree((void **)&t);
			while(clock() < co + CLOCKS_PER_SEC * 3)
				;*/
		}
	}
}


