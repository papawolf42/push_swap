/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:03:17 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:49:13 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "structure.h"

static void	ft_print_commands_r_and_rr(t_wcmd cmd)
{
	if (cmd == ra)
		write(1, "ra\n", 3);
	else if (cmd == rb)
		write(1, "rb\n", 3);
	else if (cmd == rr)
		write(1, "rr\n", 3);
	else if (cmd == rra)
		write(1, "rra\n", 4);
	else if (cmd == rrb)
		write(1, "rrb\n", 4);
	else if (cmd == rrr)
		write(1, "rrr\n", 4);
}

static void	ft_print_commands_s_and_p(t_wcmd cmd)
{
	if (cmd == sa)
		write(1, "sa\n", 3);
	else if (cmd == sb)
		write(1, "sb\n", 3);
	else if (cmd == ss)
		write(1, "ss\n", 3);
	else if (cmd == pa)
		write(1, "pa\n", 3);
	else if (cmd == pb)
		write(1, "pb\n", 3);
}

void		ft_print_commands(t_ctrl *ctrl, size_t len)
{
	t_cmd	*cmd;

	cmd = ctrl->cmds.head;
	while (len--)
	{
		if (cmd->cmd <= pb)
			ft_print_commands_s_and_p(cmd->cmd);
		else if (ra <= cmd->cmd)
			ft_print_commands_r_and_rr(cmd->cmd);
		cmd = cmd->next;
	}
}
