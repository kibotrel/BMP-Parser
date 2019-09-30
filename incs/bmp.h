/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:59:02 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/30 20:56:10 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <stdint.h>

typedef enum		e_errors
{
	BMP_OK,
	BMP_E_OPEN,
	BMP_E_MALLOC,
	BMP_E_READ,
	BMP_E_SIZE,
	BMP_E_CLOSE
}					t_errors;

typedef	struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct		s_info
{
	t_vec			size;
	uint8_t			error;
	uint32_t		weight;
}					t_info;

typedef struct		s_file
{
	t_info			info;
	uint8_t			*stream;
}					t_file;

typedef struct		s_bmp
{
	int				width;
	int				height;
}					t_bmp;

/*
**	core/bmp_to_array.c
*/

int					bmp_to_array(char *bmp, t_bmp *image);

/*
**	clean/clean.c
*/

int					wipe(t_file *file, uint32_t status);

/*
**	display/display.c
*/

int					dislay_output(uint32_t status);

/*
**	setup/setup.c
*/

void				presets(t_file *file);

#endif
