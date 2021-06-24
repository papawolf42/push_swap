/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:10:16 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/23 20:15:27 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

int		ft_max_int(int a, int b);
size_t	ft_max_sizet(size_t a, size_t b);
int		ft_min_int(int a, int b);
size_t	ft_min_sizet(size_t a, size_t b);

size_t	ft_get_index_min(t_node *node, size_t size);

#endif
