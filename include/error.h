/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <papawolf@kakao.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:54:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/28 16:51:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "structure.h"

# define ERR_BAD_NUMBER "non-number found"
# define ERR_BAD_RANGE "number overlay int range"
# define ERR_MALLOC_FAIL "allocating memory fails"
# define ERR_NUMBER_DUPLICATE "numbers are duplicated"
# define ERR_BAD_COMMAND "bad command found"

# define ESC_ERASE_LEFT "\033[1K"

t_bool			ft_error_msg(char *msg, t_prog prog);

t_bool			ft_destroy_splits(char ***splits);
t_bool			ft_destroy_split(char **strs);
t_bool			ft_destroy_array(int *array);

#endif
