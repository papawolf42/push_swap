/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 00:32:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 11:13:56 by gunkim           ###   ########.fr       */
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

static t_bool	ft_alloc_arrays(t_ctrl *ctrl, int **array, int **array_sorted)
{
	*array = (int *)malloc(sizeof(int) * ctrl->len);
	if (*array == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	*array_sorted = (int *)malloc(sizeof(int) * ctrl->len);
	if (*array_sorted == NULL)
		return (ft_destroy_array(*array)
			&& ft_error_msg(ERR_MALLOC_FAIL));
	return (success);
}

static void	ft_print_array(int *array, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

t_bool	ft_parse_string(t_ctrl *ctrl, char *str, int **array,
int **array_sorted)
{
	char		**strs;

	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (fail);
	ctrl->len = ft_strslen(strs);
	if (ft_alloc_arrays(ctrl, array, array_sorted))
		return (fail);
	ft_atoi_array(strs, array, ctrl->len);
	ft_arrcpy(*array_sorted, *array, ctrl->len);
	if (ft_merge_sort_array(*array_sorted, ctrl->len) == fail)
		return (fail);
	ft_print_array(*array, ctrl->len);
	ft_print_array(*array_sorted, ctrl->len);
	return (success);
}
