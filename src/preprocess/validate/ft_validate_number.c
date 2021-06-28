/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:45:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 17:01:35 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "error.h"

t_bool			ft_validate_number(char *str)
{
	if (*str != '\0' && (*str == '-' || *str == '+'))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == false)
			return (fail);
		str++;
	}
	return (success);
}
