/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_s_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:51:59 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 17:41:12 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "structure.h"
#include "command.h"

t_bool	ft_sa(t_ctrl *ctrl)
{
	if (ft_cmd_s(&ctrl->a) == fail)
		return (fail);
	return (success);
}

t_bool	ft_sb(t_ctrl *ctrl)
{
	if (ft_cmd_s(&ctrl->b) == fail)
		return (fail);
	return (success);
}

t_bool	ft_ss(t_ctrl *ctrl)
{
	if (ft_sa(ctrl) == fail
		|| ft_sb(ctrl) == fail)
		return (fail);
	return (success);
}
