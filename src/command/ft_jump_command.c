/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:23:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 18:35:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"
#include "command.h"

t_bool	ft_jump_command(t_ctrl *ctrl, char *str)
{
	size_t					i;
	static t_pft_command	pft_cmd[] = {
		{"sa", 2, ft_sa},
		{"sb", 2, ft_sb},
		{"ss", 2, ft_ss},
		{"pa", 2, ft_pa},
		{"pb", 2, ft_pb},
		{"ra", 2, ft_ra},
		{"rb", 2, ft_rb},
		{"rr", 3, ft_rr},
		{"rra", 3, ft_rra},
		{"rrb", 3, ft_rrb},
		{"rrr", 3, ft_rrr},
	};

	i = 0;
	while (ft_strncmp(str, pft_cmd[i].key, pft_cmd[i].len) != 0)
		i++;
	return (pft_cmd[i].ft_command(ctrl));
}
