/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coretask_tasks.h                                                         */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 21/12/2024 19:35:05 by NyTekCFW                                 */
/*   Updated: 21/12/2024 19:35:06 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORETASK_TASKS_H
# define CORETASK_TASKS_H

void	run_task_irq(void);
void	run_task_script(void);
void	run_tasks(u8 scaled, u16 clear_color, u32 rand_seed);

#endif