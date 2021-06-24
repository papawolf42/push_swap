/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:03:25 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/23 20:12:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "util.h"

size_t	ft_get_index_min(t_node *node, size_t size)
{
	size_t	min;

	min = node->index;
	while (size--)
	{
		min = ft_min_sizet(min, node->index);
		node = node->next;
	}
	return (min);
}
