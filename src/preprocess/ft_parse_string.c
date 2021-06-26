/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 00:32:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 10:12:43 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "bool.h"
#include "error.h"
#include "preprocess.h"

static void	ft_arrcpy(int *dst, int *src, size_t len)
{
	while (len--)
	{
		*dst = *src;
		dst++;
		src++;
	}
}

static t_bool	ft_alloc_arrays(int len, int **array, int **array_sorted)
{
	*array = (int *)malloc(sizeof(int) * len);
	if (*array == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	*array_sorted = (int *)malloc(sizeof(int) * len);
	if (*array_sorted == NULL)
		return (ft_destroy_array(*array)
			&& ft_error_msg(ERR_MALLOC_FAIL));
	return (success);
}

t_bool	ft_parse_string(t_ctrl *ctrl, char ***splits, int **array,
int **array_sorted)
{
	ctrl->len = ft_splits_len(splits);
	if (ft_alloc_arrays(ctrl->len, array, array_sorted))
		return (fail);
	if (ft_atoi_array(splits, *array))
		return (ft_destroy_array(*array) && ft_destroy_array(*array_sorted));
	ft_arrcpy(*array_sorted, *array, ctrl->len);
	if (ft_merge_sort_array(*array_sorted, ctrl->len) == fail)
		return (ft_destroy_array(*array) && ft_destroy_array(*array_sorted));
	return (success);
}
