/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 06:12:33 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/05 07:34:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"

t_bool			ft_error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	if (msg)
	{
		ft_putstr_fd(msg, 1);
		ft_putchar_fd('\n', 1);
	}
	return (fail);
}
