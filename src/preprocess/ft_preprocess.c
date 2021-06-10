/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/06 11:50:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "error.h"
#include "preprocess.h"

t_bool			ft_preprocess(char *str)
{
	int		*array;

	if (ft_validate_are_number(str) == fail)
		return (ft_error_msg(ERR_BAD_NUMBER));
	if (ft_parse_string(str, &array) == fail)
		return (fail);
	// if (ft_validate_are_duplicate(array) == fail)
		// return (fail);
	// if (ft_init_stack())
	// 정렬을 하고
	// 스택 a와 b를 동적할당해야되나? ㅇㅇ
	// 그 정렬순서를 index에 넣고
	return (success);
}
