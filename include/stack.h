/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:14:07 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 14:07:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "structure.h"

t_node	*ft_node_new(int value, size_t index);
void    ft_stack_addback(t_stack *stack, t_node *node);

#endif
