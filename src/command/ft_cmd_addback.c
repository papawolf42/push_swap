/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:33:34 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 12:22:04 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bool.h"
#include "structure.h"

t_cmd	*ft_cmd_new(t_wcmd cmd)
{
	t_cmd	*cmd_new;

	cmd_new = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd_new == NULL)
		return (NULL);
	cmd_new->cmd = cmd;
	cmd_new->next = NULL;
	cmd_new->before = NULL;
	return (cmd_new);
}

t_bool	ft_cmd_addback(t_ctrl *ctrl, t_wcmd cmd)
{
	t_cmd	*cmd_new;
	t_cmd	*temp;

	cmd_new = ft_cmd_new(cmd);
	if (cmd_new == NULL)
		return (fail);
	if (ctrl->cmds.head == NULL)
	{
		ctrl->cmds.head = cmd_new;
		ctrl->cmds.tail = cmd_new;
	}
	else if (ctrl->cmds.head != NULL)
	{
		temp = ctrl->cmds.tail;
		temp->next = cmd_new;
		ctrl->cmds.tail = cmd_new;
		ctrl->cmds.tail->before = temp;
	}
	ctrl->cmds.len++;
	return (success);
}
