/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 12:15:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "error.h"
#include "preprocess.h"

t_bool	ft_preprocess(t_ctrl *ctrl, int argc, char **argv)
{
	char	***splits;
	int		*array;
	int		*array_sorted;

	splits = ft_splits(argc, argv);
	if (splits == NULL)
		return (fail);
	if (ft_parse_string(ctrl, splits, &array, &array_sorted) == fail)
		return (fail);
	if (ft_validate_duplicate(ctrl, array_sorted) == fail)
		return (fail);
	if (ft_init_stack(ctrl, array, array_sorted))
		return (fail);
	return (success);
}
