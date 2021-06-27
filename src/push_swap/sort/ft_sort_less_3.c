/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_less_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:24:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 00:52:22 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "push_swap.h"
#include "command.h"

void	ft_sort_less_3_at_first(t_ctrl *ctrl, t_wstack stack, size_t size)
{
	if (size == 3)
		ft_sort_3_at_first(ctrl, stack);
	if (size == 2)
	{
		if (stack == a && ctrl->a.head->index > ctrl->a.head->next->index)
			ft_sa(ctrl);
		else if (stack == b && ctrl->b.head->index < ctrl->b.head->next->index)
			ft_sb(ctrl);
	}
}

void	ft_sort_less_3(t_ctrl *ctrl, t_wstack stack, size_t size)
{
	if (size == 3)
		ft_sort_3(ctrl, stack);
	if (size == 2)
	{
		if (stack == a && ctrl->a.head->index > ctrl->a.head->next->index)
			ft_sa(ctrl);
		else if (stack == b && ctrl->b.head->index < ctrl->b.head->next->index)
			ft_sb(ctrl);
	}
}
