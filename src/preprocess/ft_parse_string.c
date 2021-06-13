/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 00:32:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/13 18:43:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "bool.h"
#include "error.h"
#include "preprocess.h"

static void		ft_print_array(int *array, size_t len)
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

t_bool			ft_parse_string(t_ctrl *ctrl, char *str, int **array)
{
	char		**strs;
	
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (fail);
	ctrl->len = ft_strslen(strs);
	*array = (int *)malloc(sizeof(int) * ctrl->len);
	if (*array == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	ft_atoi_array(strs, array, ctrl->len);
	if (ft_merge_sort_array(*array, ctrl->len) == fail)
		return (fail);
	ft_print_array(*array, ctrl->len);
	return (success);
}

