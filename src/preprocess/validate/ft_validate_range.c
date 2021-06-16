/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:37:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 10:42:08 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "bool.h"
#include "error.h"

t_bool	ft_validate_range(long nbr)
{
	if (INT_MAX < nbr || nbr < INT_MIN)
		return (ft_error_msg(ERR_BAD_RANGE));
	return (success);
}
