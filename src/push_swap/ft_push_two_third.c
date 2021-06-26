/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_two_third.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:14:05 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 10:47:46 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"
#include "util.h"

/*
피봇 1보다 작으면 ra로 hold하고,
피봇 1보다 크면 pb로 넘김.
이때 넘긴 수 중에
피봇 2보다 작으면 rb로 down하고,
피봇 2보다 크면 up에 남겨둠.
*/
void	ft_push_two_third_a(t_ctrl *ctrl, t_parts *parts, t_node *node)
{
	int		count;
	t_node	*temp;

	count = parts->push_up.size + parts->push_down.size;
	while (count)
	{
		temp = node->next;
		if (node->index >= parts->pivot_2)
		{
			parts->hold_down.count++;
			ft_ra(ctrl);
		}
		else if (node->index < parts->pivot_2)
		{
			count--;
			ft_pb(ctrl);
			if (node->index > parts->pivot_1)
			{
				parts->push_up.count++;
				ft_rb(ctrl);
			}
		}
		node = temp;
	}
	count = ft_min_sizet(parts->hold_down.count, parts->push_up.count);
	while (count--)
		ft_rrr(ctrl);
	count = parts->hold_down.count - parts->push_up.count;
	while (count)
	{
		if (count > 0)
		{
			ft_rra(ctrl);
			count--;
		}
		else if (count < 0)
		{
			ft_rrb(ctrl);
			count++;
		}
	}
}

void	ft_push_two_third_b(t_ctrl *ctrl, t_parts *parts, t_node *node)
{
	int		count;
	t_node	*temp;

	count = parts->push_up.size + parts->push_down.size;
	while (count)
	{
		temp = node->next;
		if (node->index <= parts->pivot_1)
		{
			parts->hold_down.count++;
			ft_rb(ctrl);
		}
		else if (node->index > parts->pivot_1)
		{
			count--;
			ft_pa(ctrl);
			if (node->index < parts->pivot_2)
			{
				parts->push_up.count++;
				ft_ra(ctrl);
			}
		}
		node = temp;
	}
	count = ft_min_sizet(parts->hold_down.count, parts->push_up.count);
	while (count--)
		ft_rrr(ctrl);
	count = parts->hold_down.count - parts->push_up.count;
	while (count)
	{
		if (count > 0)
		{
			ft_rrb(ctrl);
			count--;
		}
		else if (count < 0)
		{
			ft_rra(ctrl);
			count++;
		}
	}
}

void	ft_push_two_third(t_ctrl *ctrl, t_wstack stack, t_parts *parts)
{
	if (stack == a)
		ft_push_two_third_a(ctrl, parts, ctrl->a.head);
	else if (stack == b)
		ft_push_two_third_b(ctrl, parts, ctrl->b.head);
}
