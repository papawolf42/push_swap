/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_are_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 07:17:11 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/05 07:35:39 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "error.h"

t_bool			ft_validate_are_number(char *str)
{
	while (*str)
	{
		if (!(*str == ' ' ||
			ft_isdigit(*str) == true ||
			*str == '-' ||
			*str == '+'))
			return (ft_error_msg(ERR_BAD_NUMBER));
		str++;
	}
	return (success);
}
