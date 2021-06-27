/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:46:03 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:50:11 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "push_swap.h"
#include "util.h"

void	ft_select_pivot(t_ctrl *ctrl, t_wstack stack, t_parts *parts,
			size_t size)
{
	size_t	div;
	size_t	mod;
	size_t	offset;

	offset = ft_get_index_min(ft_get_head_from_stack(ctrl, stack), size) - 1;
	div = size / 3;
	mod = size % 3;
	parts->size = size;
	parts->pivot_1 = offset + div;
	parts->pivot_2 = offset + 2 * div + (mod == 2) + 1;
	if (stack == a)
	{
		parts->hold_down.size = div + (mod == 1) + (mod == 2);
		parts->push_up.size = div + (mod == 2);
		parts->push_down.size = div;
	}
	else if (stack == b)
	{
		parts->hold_down.size = div;
		parts->push_up.size = div + (mod == 2);
		parts->push_down.size = div + (mod == 1) + (mod == 2);
	}
	parts->hold_down.stack = stack;
	parts->push_up.stack = !stack;
	parts->push_down.stack = !stack;
}
