/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:37:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 17:00:40 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "bool.h"
#include "error.h"

t_bool	ft_validate_range(long nbr)
{
	if (INT_MAX < nbr || nbr < INT_MIN)
		return (fail);
	return (success);
}
