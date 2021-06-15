/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:31:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/15 14:07:20 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCESS_H
# define PREPROCESS_H

# include <stddef.h>
# include "structure.h"

t_bool			ft_preprocess(t_ctrl *ctrl, char *str);

t_bool			ft_parse_string(t_ctrl *ctrl, char *str, int **array,
					int **array_sorted);
size_t			ft_strslen(char **strs);
void			ft_atoi_array(char **str, int **array, size_t len);
t_bool			ft_merge_sort_array(int *array, size_t len);

t_bool			ft_validate_are_number(char *str);
t_bool			ft_validate_are_duplicate(t_ctrl *ctrl, int *array);

t_bool			ft_init_stack(t_ctrl *ctrl, int *array, int *array_sorted);

#endif
