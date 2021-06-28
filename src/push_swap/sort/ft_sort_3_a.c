/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 02:08:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 02:12:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "command.h"
#include "util.h"

static void	ft_sort_3_a_13(t_ctrl *ctrl)
{
	ft_ra(ctrl);
	ft_sa(ctrl);
	ft_rra(ctrl);
}

static void	ft_sort_3_a_23(t_ctrl *ctrl)
{
	ft_ra(ctrl);
	ft_sa(ctrl);
	ft_rra(ctrl);
	ft_sa(ctrl);
}

static void	ft_sort_3_a_31(t_ctrl *ctrl)
{
	ft_sa(ctrl);
	ft_ra(ctrl);
	ft_sa(ctrl);
	ft_rra(ctrl);
}

static void	ft_sort_3_a_32(t_ctrl *ctrl)
{
	ft_sa(ctrl);
	ft_ra(ctrl);
	ft_sa(ctrl);
	ft_rra(ctrl);
	ft_sa(ctrl);
}

void		ft_sort_3_a(t_ctrl *ctrl, t_node *head)
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
		ft_sort_3_a_13(ctrl);
	else if (first == 2 && second == 1)
		ft_sa(ctrl);
	else if (first == 2 && second == 3)
		ft_sort_3_a_23(ctrl);
	else if (first == 3 && second == 1)
		ft_sort_3_a_31(ctrl);
	else if (first == 3 && second == 2)
		ft_sort_3_a_32(ctrl);
}
