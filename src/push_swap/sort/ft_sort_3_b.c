/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 02:12:54 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 02:15:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"
#include "util.h"

static void	ft_sort_3_b_12(t_ctrl *ctrl)
{
	ft_sb(ctrl);
	ft_rb(ctrl);
	ft_sb(ctrl);
	ft_rrb(ctrl);
	ft_sb(ctrl);
}

static void	ft_sort_3_b_13(t_ctrl *ctrl)
{
	ft_sb(ctrl);
	ft_rb(ctrl);
	ft_sb(ctrl);
	ft_rrb(ctrl);
}

static void	ft_sort_3_b_21(t_ctrl *ctrl)
{
	ft_rb(ctrl);
	ft_sb(ctrl);
	ft_rrb(ctrl);
	ft_sb(ctrl);
}

static void	ft_sort_3_b_31(t_ctrl *ctrl)
{
	ft_rb(ctrl);
	ft_sb(ctrl);
	ft_rrb(ctrl);
}

void		ft_sort_3_b(t_ctrl *ctrl, t_node *head)
{
	size_t	min;
	size_t	first;
	size_t	second;
	size_t	thrid;

	min = ft_get_index_min(head, 3);
	first = head->index - min + 1;
	second = head->next->index - min + 1;
	thrid = head->next->next->index - min + 1;
	if (first == 1 && second == 2)
		ft_sort_3_b_12(ctrl);
	else if (first == 1 && second == 3)
		ft_sort_3_b_13(ctrl);
	else if (first == 2 && second == 1)
		ft_sort_3_b_21(ctrl);
	else if (first == 2 && second == 3)
		ft_sb(ctrl);
	else if (first == 3 && second == 1)
		ft_sort_3_b_31(ctrl);
}
