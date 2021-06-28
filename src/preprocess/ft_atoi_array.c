/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:41:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 17:00:51 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bool.h"
#include "preprocess.h"
#include "error.h"

t_bool	ft_atoi_array(char ***splits, int *array, t_prog prog)
{
	size_t	i;
	size_t	j;
	size_t	k;
	long	temp;

	k = 0;
	i = 0;
	while (splits[i])
	{
		j = 0;
		while (splits[i][j])
		{
			if (ft_validate_number(splits[i][j]))
				return (ft_error_msg(ERR_BAD_NUMBER, prog));
			temp = ft_atoi_long(splits[i][j]);
			if (ft_validate_range(temp))
				return (ft_error_msg(ERR_BAD_RANGE, prog));
			array[k] = (int)temp;
			k++;
			j++;
		}
		i++;
	}
	return (success);
}
