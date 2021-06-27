/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:42:44 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 21:32:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"
#include "simulator.h"
#include "command.h"

t_bool	ft_cmd_rr(t_stack *stack, t_prog prog)
{
	if (stack->len == 0 && prog == simulator)
	{
		ft_putstr_fd("not enough node\n", 1);
		return (fail);
	}
	else if (stack->len == 0)
		return (success);
	stack->tail = stack->tail->before;
	stack->head = stack->head->before;
	return (success);
}

t_bool	ft_rra(t_ctrl *ctrl)
{
	if (ft_cmd_rr(&ctrl->a, ctrl->prog) == fail)
		return (fail);
	ft_cmd_addback(ctrl, rra);
	return (success);
}

t_bool	ft_rrb(t_ctrl *ctrl)
{
	if (ft_cmd_rr(&ctrl->b, ctrl->prog) == fail)
		return (fail);
	ft_cmd_addback(ctrl, rrb);
	return (success);
}

t_bool	ft_rrr(t_ctrl *ctrl)
{
	if (ft_rra(ctrl) == fail
		|| ft_rrb(ctrl) == fail)
		return (fail);
	return (success);
}
