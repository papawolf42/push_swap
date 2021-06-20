/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:16:10 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/20 18:22:26 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "bool.h"
# include "structure.h"

t_bool	ft_jump_command(t_ctrl *ctrl, char *str);
t_bool	ft_jump_command_undo(t_ctrl *ctrl, char *str);

t_bool	ft_sa(t_ctrl *ctrl);
t_bool	ft_sb(t_ctrl *ctrl);
t_bool	ft_ss(t_ctrl *ctrl);
t_bool	ft_cmd_s(t_stack *stack);
t_bool	ft_cmd_s_2(t_stack *stack);
t_bool	ft_cmd_s_normal(t_stack *stack);

t_bool	ft_pa(t_ctrl *ctrl);
t_bool	ft_pb(t_ctrl *ctrl);
t_bool	ft_cmd_p(t_stack *dst, t_stack *src);
void	ft_cmd_p_normal(t_stack *dst, t_stack *src);

t_bool	ft_ra(t_ctrl *ctrl);
t_bool	ft_rb(t_ctrl *ctrl);
t_bool	ft_rr(t_ctrl *ctrl);
t_bool	ft_cmd_r(t_stack *stack);

t_bool	ft_rra(t_ctrl *ctrl);
t_bool	ft_rrb(t_ctrl *ctrl);
t_bool	ft_rrr(t_ctrl *ctrl);
t_bool	ft_cmd_rr(t_stack *stack);

#endif
