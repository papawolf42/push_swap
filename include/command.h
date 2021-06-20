/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:16:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/19 13:11:52 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "bool.h"
# include "structure.h"

t_bool	ft_jump_command(t_ctrl *ctrl, char *str);

t_bool	ft_cmd_s(t_stack *stack);
t_bool	ft_cmd_sa(t_ctrl *ctrl);

#endif
