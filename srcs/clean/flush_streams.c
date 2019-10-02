/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:38:46 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/01 22:57:23 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "bmp.h"

int	wipe(t_file *file, uint32_t status)
{
	if (file->stream)
		free(file->stream);
	return (dislay_output(status));
}
