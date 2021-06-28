/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:13:43 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 01:53:16 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structure.h"

static void	ft_destroy_stack(t_ctrl *ctrl)
{
	t_node	*node;
	t_node	*temp;

	if (ctrl->a.head == NULL)
		return ;
	node = ctrl->a.head;
	while (ctrl->a.len--)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	node = ctrl->b.head;
	ctrl->a.head = NULL;
	ctrl->a.tail = NULL;
	while (ctrl->b.len--)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	ctrl->b.head = NULL;
	ctrl->b.tail = NULL;
}

static void	ft_destroy_list_of_commands(t_cmds *cmds)
{
	t_cmd	*cmd;
	t_cmd	*temp;

	if (cmds->head == NULL)
		return ;
	cmd = cmds->head;
	while (cmds->len--)
	{
		temp = cmd->next;
		free(cmd);
		cmd = temp;
	}
	cmds->head = NULL;
	cmds->tail = NULL;
}

void		ft_process_end(t_ctrl *ctrl)
{
	ft_destroy_stack(ctrl);
	ft_destroy_list_of_commands(&ctrl->cmds);
}
