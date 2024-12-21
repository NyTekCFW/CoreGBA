/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mxgba.c                                                                  */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 10/12/2024 14:54:20 by NyTekCFW                                 */
/*   Updated: 10/12/2024 14:54:23 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mx_global.h"

/// @brief Global library stored in iwram for fast data access
/// @return ptr of the static
t_mx	*gmx(void)
{
	static t_mx	mx = {0};

	return (&mx);
}
