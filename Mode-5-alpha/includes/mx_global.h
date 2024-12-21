/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mx_global.h                                                              */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 09/12/2024 07:52:34 by NyTekCFW                                 */
/*   Updated: 09/12/2024 10:16:31 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MX_GLOBAL_H
# define MX_GLOBAL_H

#ifdef CONSOLE_MODE
# include </opt/devkitpro/libgba/include/gba_console.h>
//consoleDemoInit();
#endif

typedef unsigned int size_t;
#define ALIGNED(n) __attribute__((aligned(n)))
//# include <stdio.h>
//# include <stdlib.h>
# include </opt/devkitpro/libgba/include/gba_types.h>
# include </opt/devkitpro/libgba/include/gba_video.h>
# include </opt/devkitpro/libgba/include/gba_interrupt.h>
# include </opt/devkitpro/libgba/include/gba_systemcalls.h>
# include </opt/devkitpro/libgba/include/gba_input.h>

# include "./system/coresys_system.h"
# include "./utils/coreutil_utils.h"
# include "./keys/corekey_keys.h"
# include "mx_gcm.h"
# include "mx_virtual.h"
//bonus data
# include "./graphics/coregfx_graphics.h"

enum e_action
{
	ACT_INIT	= 0,
	ACT_GET,
	ACT_FREE
};

typedef struct callbacks_s
{
	void	(*pre_rendering)();
	void	(*post_rendering)();
}	t_callback;

typedef struct mx_s
{
	t_virtual	vmem;
	t_gcm		gcm;
	t_callback	callback;
	t_key		key[BUTTON_MAX];
}	t_mx;

t_mx	*gmx(void);

#endif
