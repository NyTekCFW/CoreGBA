/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   mx_gcm.h                                                                 */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 10/12/2024 14:31:40 by NyTekCFW                                 */
/*   Updated: 10/12/2024 14:31:42 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef MX_GCM_H
# define MX_GCM_H

enum e_mx_gcm
{
	GCM_FRONT	= 0,
	GCM_BACK,
	GCM_CURRENT,
	GCM_MAX
};

typedef struct mx_gcm_s
{
	u8		current_buffer;
	vu16	*flip_status;
	u32		vbuf[GCM_MAX];
	u16		clear_color;
	u16		total_size;
}	t_gcm;


u8			gcm_get_active_id(void);
u16			*gcm_get_active_buffer(void);
u16			*gcm_get_draw_buffer(void);
u16			*gcm_get_front_buffer(void);
u16			*gcm_get_back_buffer(void);
u16			gcm_get_buffer_size(void);
void		gcm_init_body(void);
void		gcm_prepare_flip(void);
void		gcm_set_clear_color(u16 clr);
void		gcm_clear_active_buffer(void);
void		gcm_clear_draw_buffer(void);
t_gcm		*get_gcm(void);
#endif