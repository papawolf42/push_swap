/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:15:48 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/17 17:45:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"

void	ft_cmd_s_2(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	stack->head = stack->tail;
	stack->tail = temp;
}

void	ft_cmd_s_normal(t_stack *stack)
{
	t_node	*neck;

	neck = stack->head->next;
	stack->tail->next = neck;
	stack->head->next = neck->next;
	stack->head->before = neck;
	neck->before = stack->tail;
	neck->next = stack->head;
	stack->head = neck;
}

t_bool	ft_cmd_s(t_stack *stack)
{
	if (stack->len >= 3)
		ft_cmd_s_normal(stack);
	else if (stack->len == 2)
		ft_cmd_s_2(stack);
	else if (stack->len == 1)
		ft_putstr_fd("not enough node\n", 1);
	return (success);
}

t_bool	ft_cmd_sa(t_ctrl *ctrl)
{
	if (ft_cmd_s(&ctrl->a) == fail)
		return (fail);
	return (success);
}
