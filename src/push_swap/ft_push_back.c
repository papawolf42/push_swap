/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_from_up.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 23:02:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/25 10:55:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"

void	ft_push_back(t_ctrl *ctrl, t_type stack, size_t count)
{
	if (stack == a)
	{
		while (count--)
			ft_pa(ctrl);
	}
	else if (stack == b)
	{
		while (count--)
			ft_pb(ctrl);
	}
}
