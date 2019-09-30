/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:58:02 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/30 21:16:38 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "bmp.h"

// static void	parse_bmp(t_file *file)
// {
//
// }

int			 bmp_to_array(char *bmp, t_bmp *image)
{
	int		fd;
	t_file	file;

	(void)image;

	presets(&file);
	if ((fd = open(bmp, O_RDONLY)) < 0)
		return (wipe(&file, BMP_E_OPEN));
	if (!(file.stream = (uint8_t*)malloc(BUFFER)))
		return (wipe(&file, BMP_E_MALLOC));
	if ((file.info.weight = (read(fd, file.stream, BUFFER))) <= 0)
		return (wipe(&file, BMP_E_READ));
	else if (file.info.weight == BUFFER)
		return (wipe(&file, BMP_E_SIZE));
	if (close(fd))
		return (wipe(&file, BMP_E_CLOSE));
	// else
	// 	parse_bmp(file);
	return (wipe(&file, BMP_OK));

}

int		main(int ac, char **av)
{
	t_bmp	image;

	if (ac >= 2)
		bmp_to_array(av[1], &image);
	return (0);
}
