/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:45:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 12:02:23 by gunkim           ###   ########.fr       */
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
			return (ft_error_msg(ERR_BAD_NUMBER));
		str++;
	}
	return (success);
}
