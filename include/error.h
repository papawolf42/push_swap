/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:54:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/26 12:56:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "bool.h"

# define ERR_BAD_NUMBER "non-number found"
# define ERR_BAD_RANGE "number overlay int range"
# define ERR_MALLOC_FAIL "allocating memory fails"
# define ERR_NUMBER_DUPLICATE "numbers are duplicated"
# define ERR_BAD_COMMAND "bad command found"

# define ESC_ERASE_LEFT "\033[1K"

t_bool			ft_error_msg(char *msg);

t_bool			ft_destroy_splits(char ***splits);
t_bool			ft_destroy_split(char **strs);
t_bool			ft_destroy_array(int *array);

#endif
