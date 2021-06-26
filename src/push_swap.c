/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:01:46 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 13:12:44 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structure.h"
#include "preprocess.h"
#include "simulator.h"
#include "push_swap.h"
// #include "stack.h"

void	ft_recursive_push_swap(t_ctrl *ctrl, t_wstack stack, size_t size)
{
	t_parts	parts;

	if (size <= 3)
	{
		ft_sort_less_3(ctrl, stack, size);
		return ;
	}
	ft_bzero(&parts, sizeof(parts));
	ft_select_pivot(ctrl, stack, &parts, size);
	ft_push_two_third(ctrl, stack, &parts);
	ft_recursive_push_swap(ctrl, parts.hold_down.stack, parts.hold_down.size);
	ft_recursive_push_swap(ctrl, parts.push_up.stack, parts.push_up.size);
	ft_push_back(ctrl, parts.hold_down.stack, parts.push_up.size);
	ft_recursive_push_swap(ctrl, parts.push_down.stack, parts.push_down.size);
	ft_push_back(ctrl, parts.hold_down.stack, parts.push_down.size);
}

int	main(int argc, char *argv[])
{
	t_ctrl	ctrl;

	if (ft_preprocess(&ctrl, argc, argv))
		exit (0);
	ft_recursive_push_swap(&ctrl, a, ctrl.len);
	// ft_print_stack(&ctrl);
	ft_print_commands(&ctrl, ctrl.cmds.len);
	return (true);
}
