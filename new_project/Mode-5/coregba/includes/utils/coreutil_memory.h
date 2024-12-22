/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coreutil_memory.h                                                        */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 09/12/2024 07:49:40 by NyTekCFW                                 */
/*   Updated: 20/12/2024 20:35:28 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREUTIL_MEMORY_H
# define COREUTIL_MEMORY_H

void	*xmemcpy(void *dest, const void *src, size_t n);
void	*xmemset(void *s, u16 c, size_t n);
void	xfree(void **data);
int		xalloc(void **var, size_t nmemb, size_t ts);

#endif