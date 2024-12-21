/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   corekey_code.c                                                           */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 11/12/2024 16:26:37 by NyTekCFW                                 */
/*   Updated: 20/12/2024 23:50:19 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mx_global.h"

void	set_keycode_status(u16 code, u8 active)
{
	s8		i = get_key_num(code);
	t_key	*key = get_key(i);

	if (key)
	{
		if (!key->ignore || (key->ignore && !active))
			key->is_pressed = active;
		if (!active)
			key->ignore = 0;
	}
}

u8	keycode_pressed(u16 code)
{
	s8		i = get_key_num(code);
	t_key	*key = get_key(i);

	if (key)
		return (key->is_pressed);
	return (0);
}

void	add_keycode(u8 id, u16 code, void (*(func))(void))
{
	s8		i = get_key_num(code);
	t_key	*key = get_key(id);

	if (key && i == -1)
	{
		key->code = code;
		key->callback = func;
		key->id = id;
	}
}

void	init_keyboard(void)
{
	s8		i = -1;
	while (++i < BUTTON_MAX)
		gmx()->key[i] = (t_key){0};
}
