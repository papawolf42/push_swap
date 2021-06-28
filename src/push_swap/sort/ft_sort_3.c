/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:48:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 02:21:55 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "structure.h"
#include "command.h"
#include "util.h"

void	ft_sort_3(t_ctrl *ctrl, t_wstack stack)
{
	if (stack == a)
		ft_sort_3_a(ctrl, ctrl->a.head);
	else if (stack == b)
		ft_sort_3_b(ctrl, ctrl->b.head);
}
