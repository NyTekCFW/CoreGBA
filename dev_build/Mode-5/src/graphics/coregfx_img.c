/* ************************************************************************** */
/*   ~Header by : NyTekCFW~                                   SVSC Dev Team   */
/*                                                                            */
/*   coregfx_img.c                                                            */
/*                                                                            */
/*   By: NyTekCFW - Youtube.com/NyTekCFW                                      */
/*                                                                            */
/*   Created: 20/12/2024 17:17:48 by NyTekCFW                                 */
/*   Updated: 20/12/2024 17:19:32 by NyTekCFW                                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics/coregfx_img.h"

//logo 8x8
unsigned short	img_button_a[64] =
{
	0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x318c,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_button_b[64] =
{
	0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x318c,0x318c,0x675a,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x318c,0x675a,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x318c,0x675a,0x7fff,0x7fff,0x318c,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_up[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x043c,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_down[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x043c,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_right[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x043c,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_left[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x043c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_left_right[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x043c,0x7fff,0x7fff,0x7fff,0x043c,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_up_down[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x043c,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x043c,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_dpad_none[64] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,
	0x318c,0x318c,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

//logo 16x8
unsigned short	img_button_L[128] =
{
	0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x0000,
	0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_button_R[128] =
{
	0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x318c,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,0x0000,
	0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,0x0000,
};

unsigned short	img_button_start[192] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x318c,0x7fff,0x318c,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x318c,0x7fff,0x318c,0x318c,0x318c,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x318c,0x7fff,
	0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x318c,0x7fff,
	0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,0x318c,0x7fff,
	0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,
};

unsigned short	img_button_select[192] =
{
	0x0000,0x0000,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x0000,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x7fff,0x318c,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,
	0x318c,0x7fff,0x318c,0x318c,0x318c,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x318c,0x7fff,
	0x7fff,0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x7fff,0x318c,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x318c,0x7fff,
	0x7fff,0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x318c,
	0x7fff,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x7fff,0x7fff,0x318c,0x318c,0x7fff,0x318c,0x318c,
	0x7fff,0x318c,0x318c,0x7fff,0x318c,0x318c,0x7fff,0x318c,
	0x318c,0x7fff,0x7fff,0x318c,0x7fff,0x7fff,0x7fff,0x318c,
	0x0000,0x318c,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,
	0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x7fff,0x318c,0x318c,
	0x0000,0x0000,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,
	0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x318c,0x0000,
};

unsigned short	img_color_picker_bkg[676] =
{
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD,
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD,
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD,
	0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
	0xFFFF, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD,
	0x77BD, 0x4631, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x4631, 0xFFFF,
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0xFFFF, 0x4631, 0x0001, 0x0001,
	0x0001, 0x0001, 0x0001, 0x0001, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x0001, 0x3DEF,
	0x3DEF, 0x3DEF, 0x3DEF, 0x0001, 0x4631, 0xFFFF, 0x0001, 0x001F, 0x001F, 0x001F,
	0x001F, 0x0001, 0xFFFF, 0x4631, 0x0001, 0x01FF, 0x01FF, 0x01FF, 0x01FF, 0x0001,
	0x4631, 0x77BD, 0x77BD, 0x4631, 0x0001, 0x3DEF, 0x3DEF, 0x3DEF, 0x3DEF, 0x0001,
	0x4631, 0xFFFF, 0x0001, 0x001F, 0x001F, 0x001F, 0x001F, 0x0001, 0xFFFF, 0x4631,
	0x0001, 0x01FF, 0x01FF, 0x01FF, 0x01FF, 0x0001, 0x4631, 0x77BD, 0x77BD, 0x4631,
	0x0001, 0x3DEF, 0x3DEF, 0x3DEF, 0x3DEF, 0x0001, 0x4631, 0xFFFF, 0x0001, 0x001F,
	0x001F, 0x001F, 0x001F, 0x0001, 0xFFFF, 0x4631, 0x0001, 0x01FF, 0x01FF, 0x01FF,
	0x01FF, 0x0001, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x0001, 0x3DEF, 0x3DEF, 0x3DEF,
	0x3DEF, 0x0001, 0x4631, 0xFFFF, 0x0001, 0x001F, 0x001F, 0x001F, 0x001F, 0x0001,
	0xFFFF, 0x4631, 0x0001, 0x01FF, 0x01FF, 0x01FF, 0x01FF, 0x0001, 0x4631, 0x77BD,
	0x77BD, 0x4631, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x4631, 0xFFFF,
	0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0xFFFF, 0x4631, 0x0001, 0x0001,
	0x0001, 0x0001, 0x0001, 0x0001, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
	0xFFFF, 0xFFFF, 0xFFFF, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD,
	0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x77BD, 0x77BD, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631,
	0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x4631, 0x77BD,
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD,
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD,
	0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD, 0x77BD
};
