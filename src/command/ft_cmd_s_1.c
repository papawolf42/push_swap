/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_s_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:51:59 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/27 21:33:02 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "structure.h"
#include "command.h"
#include "simulator.h"

t_bool	ft_sa(t_ctrl *ctrl)
{
	if (ft_cmd_s(&ctrl->a, ctrl->prog) == fail)
		return (fail);
	ft_cmd_addback(ctrl, sa);
	return (success);
}

t_bool	ft_sb(t_ctrl *ctrl)
{
	if (ft_cmd_s(&ctrl->b, ctrl->prog) == fail)
		return (fail);
	ft_cmd_addback(ctrl, sb);
	return (success);
}

t_bool	ft_ss(t_ctrl *ctrl)
{
	if (ft_sa(ctrl) == fail
		|| ft_sb(ctrl) == fail)
		return (fail);
	ft_cmd_addback(ctrl, ss);
	return (success);
}
