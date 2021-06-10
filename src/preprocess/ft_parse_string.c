/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 00:32:18 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/06 15:47:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "bool.h"
#include "error.h"
#include "preprocess.h"

static void		ft_print_array(int *array, size_t strslen)
{
	size_t		i;

	i = 0;
	while (i < strslen)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

t_bool			ft_parse_string(char *str, int **array)
{
	char		**strs;
	size_t		strslen;
	
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (fail);
	strslen = ft_strslen(strs);
	*array = (int *)malloc(sizeof(int) * strslen);
	if (*array == NULL)
		return (ft_error_msg(ERR_MALLOC_FAIL));
	ft_atoi_array(strs, array, strslen);
	if (ft_merge_sort_array(*array, strslen) == fail)
		return (fail);
	ft_print_array(*array, strslen);
	return (success);
}
