/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:26:11 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:36:18 by sungohki         ###   ########.fr       */
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

int		ft_printf(const char *fstr, ...);
char	ft_detect_fm(const char *ch);
char	*ft_devide_fm(va_list *args, char format);
char	*ft_str_fm(void *ch, char format);

#endif
