/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:41:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/16 10:46:28 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bool.h"
#include "preprocess.h"
#include "error.h"

t_bool	ft_atoi_array(char ***splits, int *array)
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
				return (fail);
			temp = ft_atoi_long(splits[i][j]);
			if (ft_validate_range(temp))
				return (fail);
			array[k] = (int)temp;
			k++;
			j++;
		}
		i++;
	}
	return (success);
}
