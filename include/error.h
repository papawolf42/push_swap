/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 01:54:32 by gunkim            #+#    #+#             */
/*   Updated: 2021/06/06 11:50:37 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "bool.h"

# define ERR_BAD_NUMBER "found not a number"
# define ERR_MALLOC_FAIL "allocating memory fails"

t_bool			ft_error_msg(char *msg);

#endif
