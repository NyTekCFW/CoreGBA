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

#include "../includes/coregba.h"

/// @brief Global library
/// @return ptr of the static
t_coregba	*get_coregba(void)
{
	static t_coregba	lib_coregba = {0};

	return (&lib_coregba);
}

t_callback	*get_callback(void)
{
	return (&get_coregba()->callback);
}

t_basic	*get_basic(void)
{
	return (&get_coregba()->basic);
}
