/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_two_thrid_without_reverse.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:23:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 20:04:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"
#include "util.h"

void	ft_push_two_third_a_without_reverse(t_ctrl *ctrl, t_parts *parts,
			t_node *node)
{
	int		count;
	t_node	*temp;

	count = parts->push_up.size + parts->push_down.size;
	while (count)
	{
		temp = node->next;
		if (node->index >= parts->pivot_2)
			ft_ra(ctrl);
		else if (node->index < parts->pivot_2)
		{
			count--;
			ft_pb(ctrl);
			if (node->index <= parts->pivot_1)
				ft_rb(ctrl);
		}
		node = temp;
	}
}

void	ft_push_two_third_b_without_reverse(t_ctrl *ctrl, t_parts *parts,
			t_node *node)
{
	int		count;
	t_node	*temp;

	count = parts->push_up.size + parts->push_down.size;
	while (count)
	{
		temp = node->next;
		if (node->index <= parts->pivot_1)
			ft_rb(ctrl);
		else if (node->index > parts->pivot_1)
		{
			count--;
			ft_pa(ctrl);
			if (node->index >= parts->pivot_2)
				ft_ra(ctrl);
		}
		node = temp;
	}
}

void	ft_push_two_third_without_reverse(t_ctrl *ctrl, t_wstack stack,
			t_parts *parts)
{
	if (stack == a)
		ft_push_two_third_a_without_reverse(ctrl, parts, ctrl->a.head);
	else if (stack == b)
		ft_push_two_third_b_without_reverse(ctrl, parts, ctrl->b.head);
}
