/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_splits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:55:19 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 13:00:31 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "error.h"

t_bool	ft_destroy_splits(char ***splits)
{
	size_t		i;

	i = 0;
	while (splits[i])
	{
		ft_destroy_split(splits[i]);
		i++;
	}
	free(splits);
	return (fail);
}
