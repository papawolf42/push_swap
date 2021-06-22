/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:21:17 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/21 17:56:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "structure.h"

t_bool	ft_check_end(t_ctrl *ctrl)
{
	size_t	i;
	t_node	*node;

	if (ctrl->a.len != ctrl->len)
		return (false);
	i = 0;
	node = ctrl->a.head;
	while (i < ctrl->len)
	{
		if (node->index != i + 1)
			return (false);
		node = node->next;
		i++;
	}
	return (true);
}
