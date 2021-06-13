/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/10 21:51:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "error.h"
#include "preprocess.h"

t_bool			ft_preprocess(t_ctrl *ctrl, char *str)
{
	int		*array;

	if (ft_validate_are_number(str) == fail)
		return (ft_error_msg(ERR_BAD_NUMBER));
	if (ft_parse_string(ctrl, str, &array) == fail)
		return (fail);
	if (ft_validate_are_duplicate(ctrl, array) == fail)
		return (fail);
	// if (ft_init_stack())
	// 정렬을 하고
	// 스택 a와 b를 동적할당해야되나? ㅇㅇ
	// 그 정렬순서를 index에 넣고
	return (success);
}

