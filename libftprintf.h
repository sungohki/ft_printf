/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:11 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/21 17:19:10 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_arg
{
	char			arg_c;
	char			*arg_str;
	int				arg_int;
	unsigned int	arg_unint;
	void			*arg_void;
}					t_arg;

# define STRFORMAT "cspdiuxX%"

#endif
