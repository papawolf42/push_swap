/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_two_third.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:14:05 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 20:16:13 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void	ft_reverse_stacks(t_ctrl *ctrl, t_wstack which_stack,
			size_t hold_down, size_t push_up)
{
	int		count;

	count = ft_min_sizet(hold_down, push_up);
	while (count--)
		ft_rrr(ctrl);
	count = hold_down - push_up;
	while (count)
	{
		if ((which_stack == a && count > 0 && count--)
			|| (which_stack == b && count < 0 && count++))
			ft_rra(ctrl);
		else if ((which_stack == a && count < 0 && count++)
			|| (which_stack == b && count > 0 && count--))
			ft_rrb(ctrl);
	}
}

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
	ft_reverse_stacks(ctrl, a, parts->hold_down.count, parts->push_up.count);
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
	ft_reverse_stacks(ctrl, b, parts->hold_down.count, parts->push_up.count);
}

void	ft_push_two_third(t_ctrl *ctrl, t_wstack stack, t_parts *parts)
{
	if (stack == a)
		ft_push_two_third_a(ctrl, parts, ctrl->a.head);
	else if (stack == b)
		ft_push_two_third_b(ctrl, parts, ctrl->b.head);
}
