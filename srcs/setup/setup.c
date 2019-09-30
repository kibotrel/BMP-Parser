/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:02:58 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/30 21:17:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bmp.h"

static void	info_setup(t_info *info)
{
	ft_bzero(info, sizeof(t_info));
}

void		presets(t_file *file)
{
	ft_bzero(file, sizeof(t_file));
	info_setup(&file->info);
}
