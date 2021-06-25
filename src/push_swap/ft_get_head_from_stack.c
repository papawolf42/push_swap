/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_head_from_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:08:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/25 11:12:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

t_node	*ft_get_head_from_stack(t_ctrl *ctrl, t_type stack)
{
	if (stack == a)
		return (ctrl->a.head);
	return (ctrl->b.head);
}
