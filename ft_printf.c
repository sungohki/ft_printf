/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:59:42 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:34:52 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h" 
#include "libft/libft.h"

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	size_t	len;
	char	fm;
	char	*temp;

	len = 0;
	va_start(args, fstr);
	while (*fstr)
	{
		fm = ft_detect_fm(fstr);
		if (fm)
		{
			temp = ft_devide_fm(&args, fm);
			ft_putstr_fd(temp, 1);
			len += ft_strlen(temp);
			fstr = fstr + 2;
		}
		else
		{
			write(1, fstr++, 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
