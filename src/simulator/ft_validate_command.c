/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:20:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/19 13:12:33 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bool.h"

static t_bool	ft_validate_command_each(char *s)
{
	if (s[0] == 's'
		&& (s[1] == 'a' || s[1] == 'b' || s[1] == 's')
		&& s[2] == '\0')
		return (true);
	else if (s[0] == 'p'
		&& (s[1] == 'a' || s[1] == 'b')
		&& s[2] == '\0')
		return (true);
	else if (s[0] == 'r'
		&& (s[1] == 'a' || s[1] == 'b' || s[1] == 'r')
		&& s[2] == '\0')
		return (true);
	else if (s[0] == 'r'
		&& (s[1] == 'r')
		&& (s[2] == 'a' || s[1] == 'b' || s[1] == 'r')
		&& s[3] == '\0')
		return (true);
	else
		return (false);
}

t_bool	ft_validate_command(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		if (ft_validate_command_each(split[i]) == false)
			return (false);
		i++;
	}
	return (true);
}