/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:41:58 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/06 11:32:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"

void			ft_atoi_array(char **str, int **array, size_t len)
{
	size_t		i;

	i = 0;
	while (len--)
	{
		(*array)[i] = ft_atoi(str[i]);
		i++;
	}
}
