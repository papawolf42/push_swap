/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:48:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/23 20:28:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"
#include "util.h"

void	ft_sort_3_a(t_ctrl *ctrl, t_node *head)
{
	size_t	min;
	size_t	first;
	size_t	second;
	size_t	thrid;

	min = ft_get_index_min(head, 3);
	first = head->index - min + 1;
	second = head->next->index - min + 1;
	thrid = head->next->next->index - min + 1;
	if (first == 1 && second == 3)
	{
		ft_sa(ctrl);
		ft_ra(ctrl);
	}
	else if (first == 2 && second == 1)
		ft_sa(ctrl);
	else if (first == 2 && second == 3)
		ft_rra(ctrl);
	else if (first == 3 && second == 1)
		ft_ra(ctrl);
	else if (first == 3 && second == 2)
	{
		ft_sa(ctrl);
		ft_rra(ctrl);
	}
}

void	ft_sort_3_b(t_ctrl *ctrl, t_node *head)
{
	size_t	min;
	size_t	first;
	size_t	second;
	size_t	thrid;

	min = ft_get_index_min(head, 3);
	first = head->index - min;
	second = head->next->index - min;
	thrid = head->next->next->index - min;
	if (first == 1 && second == 2)
	{
		ft_sb(ctrl);
		ft_rrb(ctrl);
	}
	else if (first == 1 && second == 3)
		ft_rb(ctrl);
	else if (first == 2 && second == 1)
		ft_rrb(ctrl);
	else if (first == 2 && second == 3)
		ft_sb(ctrl);
	else if (first == 3 && second == 2)
	{
		ft_sb(ctrl);
		ft_rb(ctrl);
	}
}

void	ft_sort_3(t_ctrl *ctrl, t_type stack, t_node *head)
{
	if (stack == a)
		ft_sort_3_a(ctrl, head);
	else if (stack == b)
		ft_sort_3_b(ctrl, head);
}
