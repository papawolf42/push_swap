/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 06:12:33 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 16:52:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "libft.h"
#include "bool.h"

t_bool	ft_error_msg(char *msg, t_prog prog)
{
	ft_putstr_fd("Error\n", 2);
	if (msg && prog == simulator)
	{
		ft_putstr_fd(msg, 2);
		ft_putchar_fd('\n', 2);
	}
	return (fail);
}
