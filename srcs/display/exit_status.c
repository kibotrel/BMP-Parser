/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:43:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/02 06:20:04 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "bmp.h"
#include "libft.h"

static char	*get_error(uint32_t status)
{
	if (status == BMP_E_OPEN)
		return (")\n\t- Unable to open the given file.\n");
	if (status == BMP_E_MALLOC)
		return (")\n\t- Unable to allocate memory.\n");
	if (status == BMP_E_READ)
		return (")\n\t- Unable to read the given file.\n");
	if (status == BMP_E_SIZE)
		return (")\n\t- The given file (expected at most 16MiB).\n");
	if (status == BMP_E_CLOSE)
		return (")\n\t- Unable to close the given file.\n");
	if (status == BMP_E_SIGNATURE)
		return (")\n\t- Wrong file signature (expected 0x424D).\n");
	if (status == BMP_E_LSEEK)
		return (")\n\t- Unable to reposition reading offset.\n");
	if (status == BMP_E_DIB)
		return (")\n\t- DIB not supported (expected BITMAPV4HEADER).\n");
	if (status == BMP_E_BPP)
		return (")\n\t- Bits per pixel not supported (expected 24bits).\n");
	if (status == BMP_E_COMPRESSION)
		return (")\n\t- Compression method not supported (expected 0).\n");
	return (")\n\t- Not yet done.\n");
}

int			dislay_output(uint32_t status)
{
	if (status)
	{
		ft_putstr("\033[31;1mError:\033[0m BMP Parser returned an error (");
		ft_putnbr(status);
		ft_putstr(get_error(status));
		return (1);
	}
	else
	{
		ft_putendl("\033[32;1mSuccess :\033[0m BMP file correctly parsed.");
		return (0);
	}
}
