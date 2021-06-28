/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:31:56 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 16:59:49 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCESS_H
# define PREPROCESS_H

# include <stddef.h>
# include "structure.h"

t_bool	ft_preprocess(t_ctrl *ctrl, int argc, char **argv);

char	***ft_splits(int argc, char **argv);

t_bool	ft_parse_string(t_ctrl *ctrl, char ***splits, int **array,
			int **array_sorted);
size_t	ft_splits_len(char ***splits);
t_bool	ft_atoi_array(char ***splits, int *array, t_prog prog);
long	ft_atoi_long(const char *nstr);

t_bool	ft_merge_sort_array(int *array, size_t len);

t_bool	ft_validate_number(char *str);
t_bool	ft_validate_range(long nbr);
t_bool	ft_validate_duplicate(t_ctrl *ctrl, int *array);

t_bool	ft_init_stack(t_ctrl *ctrl, int *array, int *array_sorted);

#endif
