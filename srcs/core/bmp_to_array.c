/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:58:02 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/03 02:31:58 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "bmp.h"

static int	prechecks(t_file *file, char *bmp, uint8_t *buffer)
{
	int			fd;
	int			size;

	if ((fd = open(bmp, O_RDONLY)) < 0)
		return (BMP_E_OPEN);
	if ((size = read(fd, buffer, BUFFER_SIZE)) < 0)
		return (BMP_E_READ);
	if (size < BUFFER_SIZE)
		return (BMP_E_HEADER);
	if (check_signature(buffer))
		return (BMP_E_SIGNATURE);
	if (check_size(&file->info.bmp.weight, buffer + 2))
		return (BMP_E_SIZE);
	if (!(file->stream = (uint8_t*)malloc(file->info.bmp.weight)))
		return (BMP_E_MALLOC);
	if (lseek(fd, 0, SEEK_SET) < 0)
		return (BMP_E_LSEEK);
	if ((read(fd, file->stream, file->info.bmp.weight)) < 0)
		return (BMP_E_READ);
	if (close(fd))
		return (BMP_E_CLOSE);
	return (BMP_OK);
}

static int	parse_bmp(t_file *file, t_bmp *image)
{
	(void)image;
	if ((file->info.error = check_header(file)))
		return (file->info.error);
	setup_infos(&file->info);
	if (!(file->pixels = (uint32_t*)malloc(file->info.memory)))
		return (BMP_E_MALLOC);
	// if ((build_image(file)))
	// 	return (BMP_E_IMAGE);
	printf("--- INFORMATIONS ---\n\n\tHeader :\n\n\t- BMP size    : %u\n\t- Data offset : %u\n", file->info.bmp.weight, file->info.bmp.offset);
	printf("\n\tDIB :\n\n\t- DIB size         : %u\n\t- Image dimensions : %u x %u\n\t- Planes           : %u\n\t- Bits per pixel   : %u\n\t- Compression      : %u\n\t- Raw size         : %u\n\t- DPI              : %u - %u\n\t- Colors           : %u\n\t- Important        : %u\n\n", file->info.dib.size, file->info.dib.res.x, file->info.dib.res.y, file->info.dib.planes, file->info.dib.bpp, file->info.dib.compression, file->info.dib.raw, file->info.dib.dpi.x, file->info.dib.dpi.y, file->info.dib.colors, file->info.dib.important);
	printf("\tInfos :\n\n\t- Memory          : %u\n\t- Scanline        : %u\n\t- Padding         : %u\n\t- Row             : %u\n\t- Bytes per pixel : %u\n\n", file->info.memory, file->info.scanline, file->info.padding, file->info.row, file->info.bytes);
	return (BMP_WIP);
}

int			bmp_to_array(char *bmp, t_bmp *img)
{
	t_file		file;
	uint8_t		buffer[BUFFER_SIZE];

	presets(&file);
	if ((file.info.error = prechecks(&file, bmp, buffer)))
		return (wipe(&file, file.info.error));
	else
		return (wipe(&file, parse_bmp(&file, img)));
}

int			main(int ac, char **av)
{
	t_bmp	image;

	if (ac >= 2)
		bmp_to_array(av[1], &image);
	return (0);
}
