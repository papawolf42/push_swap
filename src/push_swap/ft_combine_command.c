/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:14:27 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:52:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structure.h"

static void	ft_combine_one(t_ctrl *ctrl, t_cmd **cmd, t_wcmd wcmd)
{
	t_cmd	*dobby;

	dobby = (*cmd)->next;
	(*cmd)->cmd = wcmd;
	dobby->next->before = *cmd;
	(*cmd)->next = dobby->next;
	free(dobby);
	ctrl->cmds.len--;
}

static void	ft_combine_none(t_ctrl *ctrl, t_cmd **cmd)
{
	t_cmd	*temp;

	temp = (*cmd)->before;
	if ((*cmd)->next->next)
	{
		(*cmd)->next->next->before = (*cmd)->before;
		(*cmd)->before->next = (*cmd)->next->next;
	}
	else if ((*cmd)->next->next == NULL)
		(*cmd)->before->next = NULL;
	free((*cmd)->next);
	free(*cmd);
	*cmd = temp;
	ctrl->cmds.len -= 2;
}

void		ft_combine_commands(t_ctrl *ctrl, t_cmd *cmd)
{
	if (ctrl->cmds.len < 2)
		return ;
	while (cmd->next)
	{
		if ((cmd->cmd == sa && cmd->next->cmd == sb)
			|| (cmd->cmd == sb && cmd->next->cmd == sa))
			ft_combine_one(ctrl, &cmd, ss);
		else if ((cmd->cmd == sa && cmd->next->cmd == sa)
			|| (cmd->cmd == sb && cmd->next->cmd == sb)
			|| (cmd->cmd == pa && cmd->next->cmd == pb)
			|| (cmd->cmd == pb && cmd->next->cmd == pa)
			|| (cmd->cmd == ra && cmd->next->cmd == rra)
			|| (cmd->cmd == rb && cmd->next->cmd == rrb))
			ft_combine_none(ctrl, &cmd);
		else if ((cmd->cmd == ra && cmd->next->cmd == rb)
			|| (cmd->cmd == rb && cmd->next->cmd == ra))
			ft_combine_one(ctrl, &cmd, rr);
		else if ((cmd->cmd == rra && cmd->next->cmd == rrb)
			|| (cmd->cmd == rrb && cmd->next->cmd == rra))
			ft_combine_one(ctrl, &cmd, rrr);
		else
			cmd = cmd->next;
	}
}
