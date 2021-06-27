/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_command_undo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:23:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 21:33:45 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"
#include "command.h"

static int	ft_strncmp_custom(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 != l2)
		return (fail);
	while ((*s1 == *s2) && l1--)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_bool	ft_jump_command_undo(t_ctrl *ctrl, char *str)
{
	size_t					i;
	static t_pft_command	pft_cmd[] = {
		{"sa", ft_sb},
		{"sb", ft_sa},
		{"ss", ft_ss},
		{"pa", ft_pb},
		{"pb", ft_pa},
		{"ra", ft_rra},
		{"rb", ft_rrb},
		{"rr", ft_rrr},
		{"rra", ft_ra},
		{"rrb", ft_rb},
		{"rrr", ft_rr},
	};

	i = 0;
	while (ft_strncmp_custom(str, pft_cmd[i].key) != 0)
		i++;
	return (pft_cmd[i].ft_command(ctrl));
}
