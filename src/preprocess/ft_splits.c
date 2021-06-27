/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:09:26 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:48:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"

char	***ft_splits(int argc, char **argv)
{
	char	***splits;
	size_t	i;

	splits = (char ***)malloc(sizeof(char **) * (argc));
	if (splits == NULL)
		return (NULL);
	splits[argc - 1] = NULL;
	i = 0;
	while (i < (size_t)(argc - 1))
	{
		splits[i] = ft_split(argv[i + 1], ' ');
		if (splits[i] == NULL)
			return (NULL);
		i++;
	}
	return (splits);
}
