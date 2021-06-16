/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:45:37 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 20:20:19 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t			ft_splits_len(char ***splits)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	while (splits[i])
	{
		j = 0;
		while (splits[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}
