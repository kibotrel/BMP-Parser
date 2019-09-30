/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:43:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/09/30 20:10:52 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

int	dislay_output(uint32_t status)
{
	if (status)
	{
		ft_putstr("\033[31;1mError:\033[0m BMP Parser returned an error (");
		ft_putnbr(status);
		ft_putendl(").");
		return (1);
	}
	else
	{
		ft_putendl("\033[32;1mSuccess :\033[0m BMP file correctly parsed.");
		return (0);
	}
}
