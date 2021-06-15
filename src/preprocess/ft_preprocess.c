/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 11:13:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "error.h"
#include "preprocess.h"

t_bool	ft_preprocess(t_ctrl *ctrl, char *str)
{
	int		*array;
	int		*array_sorted;

	if (ft_validate_are_number(str) == fail)
		return (ft_error_msg(ERR_BAD_NUMBER));
	if (ft_parse_string(ctrl, str, &array, &array_sorted) == fail)
		return (fail);
	if (ft_validate_are_duplicate(ctrl, array_sorted) == fail)
		return (fail);
	if (ft_init_stack(ctrl, array, array_sorted))
		return (fail);
	return (success);
}
