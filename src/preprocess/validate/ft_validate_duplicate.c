/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_are_duplicate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:39:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 22:49:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bool.h"
#include "error.h"
#include "structure.h"

t_bool	ft_validate_duplicate(t_ctrl *ctrl, int *array)
{
	size_t		i;

	i = 0;
	if (ctrl->len <= 1)
		return (success);
	while (i < ctrl->len - 1)
	{
		if (array[i] == array[i + 1])
			return (ft_destroy_array(array)
				&& ft_error_msg(ERR_NUMBER_DUPLICATE));
		i++;
	}
	return (success);
}
