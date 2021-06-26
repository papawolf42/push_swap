/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:42:44 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 13:53:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"
#include "simulator.h"
#include "command.h"

t_bool	ft_cmd_r(t_stack *stack)
{
	if (stack->len == 0)
	{
		ft_putstr_fd("not enough node\n", 1);
		return (fail);
	}
	stack->tail = stack->tail->next;
	stack->head = stack->head->next;
	return (success);
}

t_bool	ft_ra(t_ctrl *ctrl)
{
	if (ft_cmd_r(&ctrl->a) == fail)
		return (fail);
	ft_cmd_addback(ctrl, ra);
	return (success);
}

t_bool	ft_rb(t_ctrl *ctrl)
{
	if (ft_cmd_r(&ctrl->b) == fail)
		return (fail);
	ft_cmd_addback(ctrl, rb);
	return (success);
}

t_bool	ft_rr(t_ctrl *ctrl)
{
	if (ft_ra(ctrl) == fail
		|| ft_rb(ctrl) == fail)
		return (fail);
	return (success);
}
