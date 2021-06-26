/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:40:06 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 17:59:56 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "structure.h"

void	ft_recursive_push_swap(t_ctrl *ctrl, t_wstack stack, size_t size);

void	ft_sort_3(t_ctrl *ctrl, t_wstack stack);
void	ft_sort_less_3(t_ctrl *ctrl, t_wstack stack, size_t size);

void	ft_select_pivot(t_ctrl *ctrl, t_wstack stack, t_parts *parts,
			size_t size);

void	ft_push_two_third(t_ctrl *ctrl, t_wstack stack, t_parts *parts);
void	ft_push_two_third_without_reverse(t_ctrl *ctrl, t_wstack stack,
			t_parts *parts);

void	ft_push_back(t_ctrl *ctrl, t_wstack stack, size_t count);

t_node	*ft_get_head_from_stack(t_ctrl *ctrl, t_wstack stack);

void	ft_combine_commands(t_ctrl *ctrl);

void	ft_print_commands(t_ctrl *ctrl, size_t len);

#endif
