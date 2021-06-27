/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:17:18 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "error.h"
#include "preprocess.h"

static t_bool	ft_free_static(size_t depth, char ***splits
	, int *array, int *array_sorted)
{
	if (depth == 1)
		return (ft_destroy_splits(splits));
	else if (depth == 2)
		return (ft_destroy_splits(splits)
			&& ft_destroy_array(array) && ft_destroy_array(array_sorted));
	return (fail);
}

t_bool	ft_preprocess(t_ctrl *ctrl, int argc, char **argv)
{
	char	***splits;
	int		*array;
	int		*array_sorted;

	splits = ft_splits(argc, argv);
	if (splits == NULL)
		return (fail);
	if (ft_parse_string(ctrl, splits, &array, &array_sorted) == fail)
		return (ft_free_static(1, splits, array, array_sorted));
	if (ft_validate_duplicate(ctrl, array_sorted) == fail)
		return (ft_free_static(1, splits, array, array_sorted));
	if (ft_init_stack(ctrl, array, array_sorted))
		return (ft_free_static(2, splits, array, array_sorted));
	ft_free_static(2, splits, array, array_sorted);
	return (success);
}
