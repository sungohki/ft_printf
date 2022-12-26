/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:59:42 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:01:54 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h" 
#include "libft/libft.h"

char	detect_fm(const char *ch)
{
	int	index;

	if (*ch == '%')
	{
		index = 0;
		while (STRFORMAT[index])
			if (*(ch + 1) == STRFORMAT[index++])
				return (*(ch + 1));
	}
	return (0);
}

char	*str_fm(void *ch, char format)
{
	if (format == 'c')
		return (ft_substr((char *)ch, 0, 1));
	else if (format == 'p')
		return (ft_subaddr(ch));
	else if (format == 'd' || format == 'i')
		return (ft_itoa(*(int *)ch));
	else if (format == 'u')
		return (ft_itoa_us(*(unsigned int *)ch));
	else if (format == 'x')
		return (ft_itoa_hex(*(unsigned int *)ch, 0));
	else if (format == 'X')
		return (ft_itoa_hex(*(unsigned int *)ch, 1));
	else
		return (0);
}

char	*devide_fm(va_list *args, char format)
{
	t_arg	temp;

	if (format == 's')
	{
		temp.arg_str = (char *)va_arg(*args, char *);
		return (temp.arg_str);
	}
	else if (format == 'p')
	{
		temp.arg_void = (void *)va_arg(*args, void *);
		return (str_fm(temp.arg_void, format));
	}
	else if (format == 'c' || format == 'd' || format == 'i')
	{
		temp.arg_int = va_arg(*args, int);
		return (str_fm(&temp.arg_int, format));
	}
	else if (format == 'u' || format == 'x' || format == 'X')
	{
		temp.arg_unint = (unsigned int)va_arg(*args, unsigned int);
		return (str_fm(&temp.arg_unint, format));
	}
	else
		return ("%");
}

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
		fm = detect_fm(fstr);
		if (fm)
		{
			temp = devide_fm(&args, fm);
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
