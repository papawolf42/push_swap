/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_command_undo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:23:09 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 17:41:29 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bool.h"
#include "structure.h"
#include "command.h"

t_bool	ft_jump_command_undo(t_ctrl *ctrl, char *str)
{
	size_t					i;
	static t_pft_command	pft_cmd[] = {
		{"sa", 2, ft_sb},
		{"sb", 2, ft_sa},
		{"ss", 2, ft_ss},
		{"pa", 2, ft_pb},
		{"pb", 2, ft_pa},
		// {"ra", 2, ft_cmd_rra},
		// {"rb", 2, ft_cmd_rrb},
		// {"rr", 2, ft_cmd_rrr},
		// {"rra", 3, ft_cmd_ra},
		// {"rrb", 3, ft_cmd_rb},
		// {"rrr", 3, ft_cmd_rr},
	};

	i = 0;
	while (ft_strncmp(str, pft_cmd[i].key, pft_cmd[i].len) != 0)
		i++;
	return (pft_cmd[i].ft_command(ctrl));
}
