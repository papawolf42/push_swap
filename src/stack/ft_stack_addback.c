/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:49:55 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 14:01:57 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void    ft_stack_addback(t_stack *stack, t_node *node)
{
    if (stack->head == NULL)
    {
        stack->head = node;
        stack->tail = node;
    }
    node->before = stack->tail;
    node->next = stack->head;
    stack->head->before = node;
    stack->tail->next = node;
    stack->tail = node;
}
