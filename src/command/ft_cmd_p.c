/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:06:43 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 17:41:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"

void	ft_cmd_p_normal(t_stack *dst, t_stack *src)
{
	t_node	*neck;

	neck = src->head->next;
	if (dst->len == 0)
	{
		dst->head = src->head;
		dst->tail = src->head;
	}
	src->tail->next = neck;
	neck->before = src->tail;
	if (dst->len != 0)
	{
		dst->tail->next = src->head;
		dst->head->before = src->head;
	}
	src->head->before = dst->tail;
	src->head->next = dst->head;
	dst->head = src->head;
	src->head = neck;
	if (src->len == 1)
	{
		src->head = NULL;
		src->tail = NULL;
	}
}

t_bool	ft_cmd_p(t_stack *dst, t_stack *src)
{
	if (src->len >= 1)
	{
		ft_cmd_p_normal(dst, src);
		dst->len++;
		src->len--;
	}
	else if (src->len < 1)
	{
		ft_putstr_fd("not enough node\n", 1);
		return (fail);
	}
	return (success);
}

t_bool	ft_pb(t_ctrl *ctrl)
{
	if (ft_cmd_p(&ctrl->b, &ctrl->a) == fail)
		return (fail);
	return (success);
}

t_bool	ft_pa(t_ctrl *ctrl)
{
	if (ft_cmd_p(&ctrl->a, &ctrl->b) == fail)
		return (fail);
	return (success);
}
