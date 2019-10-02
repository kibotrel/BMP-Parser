/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:02:58 by kibotrel          #+#    #+#             */
/*   Updated: 2019/10/02 06:20:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bmp.h"

void	setup_infos(t_info *info)
{
	info->padding = padding(info->dib);
	info->scanline = scanline(info->dib, info->padding);
	info->row = info->scanline - info->padding;
	info->memory = memory(info->dib, &info->bytes);
}

void	presets(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	ft_bzero(&file->info, sizeof(t_info));
	ft_bzero(&file->info.bmp, sizeof(t_hdr));
	ft_bzero(&file->info.dib, sizeof(t_dib));
	ft_bzero(&file->info.dib.dpi, sizeof(t_vec));
	ft_bzero(&file->info.dib.res, sizeof(t_vec));
}
