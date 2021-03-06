/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:01:46 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 02:37:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structure.h"
#include "preprocess.h"
#include "push_swap.h"
#include "error.h"

static void	ft_recursive_push_swap(t_ctrl *ctrl, t_wstack stack,
			size_t size)
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

static void	ft_ignite_recursive_push_swap(t_ctrl *ctrl, t_wstack stack,
				size_t size)
{
	t_parts	parts;

	if (size <= 3)
	{
		ft_sort_less_3_at_first(ctrl, stack, size);
		return ;
	}
	ft_bzero(&parts, sizeof(parts));
	ft_select_pivot(ctrl, stack, &parts, size);
	ft_push_two_third_without_reverse(ctrl, stack, &parts);
	ft_recursive_push_swap(ctrl, parts.hold_down.stack, parts.hold_down.size);
	ft_recursive_push_swap(ctrl, parts.push_up.stack, parts.push_up.size);
	ft_push_back(ctrl, parts.hold_down.stack, parts.push_up.size);
	ft_recursive_push_swap(ctrl, parts.push_down.stack, parts.push_down.size);
	ft_push_back(ctrl, parts.hold_down.stack, parts.push_down.size);
}

int			main(int argc, char *argv[])
{
	t_ctrl	ctrl;

	ft_bzero(&ctrl, sizeof(ctrl));
	ctrl.prog = push_swap;
	if (ft_preprocess(&ctrl, argc, argv))
		exit(1);
	ft_ignite_recursive_push_swap(&ctrl, a, ctrl.len);
	ft_combine_commands(&ctrl, ctrl.cmds.head);
	ft_print_commands(&ctrl, ctrl.cmds.len);
	ft_process_end(&ctrl);
	return (true);
}
