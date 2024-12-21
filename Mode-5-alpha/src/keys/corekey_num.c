/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   corekey_num.c                                                            */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 11/12/2024 17:27:59 by NyTekCFW                                 */
/*   Updated: 20/12/2024 23:50:10 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/coregba.h"

s8	get_key_num(u16 code)
{
	s8	i = -1;

	while (++i < BUTTON_MAX)
	{
		if (get_coregba()->key[i].code == code)
			return (i);
	}
	return (-1);
}

void	keynum_replace(u8 id, void (*(func))(void))
{
	t_key	*key = get_key(id);

	if (key)
		key->callback = func;
}

u8	keynum_execute(u8 id)
{
	t_key	*key = get_key(id);

	if (key	&& !key->ignore && key->is_pressed && key->callback)
		return (key->callback(), 1);
	return (0);
}

u16	key_pressed(u16 key)
{
	return (!((*(vu16 *)0x4000130) & key));
}

t_key	*get_key(u8 id)
{
	if (id < BUTTON_MAX)
		return (&get_coregba()->key[id]);
	return (NULL);
}
