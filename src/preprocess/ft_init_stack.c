/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:24:35 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 16:53:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "structure.h"
#include "stack.h"
#include "bool.h"
#include "error.h"

static size_t	ft_get_index(size_t i, int *array, int *array_sorted)
{
	size_t	idx;

	idx = 0;
	while (array[i] != array_sorted[idx])
		idx++;
	return (idx + 1);
}

t_bool			ft_init_stack(t_ctrl *ctrl, int *array, int *array_sorted)
{
	size_t	i;
	size_t	idx;
	t_node	*node;

	ft_bzero(&ctrl->a, sizeof(t_stack));
	ft_bzero(&ctrl->b, sizeof(t_stack));
	ctrl->a.len = ctrl->len;
	i = 0;
	while (i < ctrl->len)
	{
		node = NULL;
		idx = ft_get_index(i, array, array_sorted);
		node = ft_node_new(array[i], idx);
		if (node == NULL)
			return (ft_error_msg(ERR_MALLOC_FAIL, ctrl->prog));
		ft_stack_addback(&ctrl->a, node);
		i++;
	}
	return (success);
}
