/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:59:42 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/21 21:47:03 by sungohki         ###   ########.fr       */
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

void	write_fm(void *ch, char format)
{
	if (format == 'c')
		ft_putchar_fd(*(char *)ch, 1);
	else if (format == 's')
		ft_putstr_fd((char *)ch, 1);
	else if (format == 'p')
		ft_putaddr_fd(ch, 1);
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(*(int *)ch, 1);
	else if (format == 'u')
		ft_putnbr_us_fd(*(unsigned int *)ch, 1);
	else if (format == 'x')
		ft_putnbr_hex_fd(*(unsigned int *)ch, 1, 0);
	else if (format == 'X')
		ft_putnbr_hex_fd(*(unsigned int *)ch, 1, 1);
}

void	devide_fm(va_list *args, char format)
{
	t_arg	temp;

	if (format == 's')
	{
		temp.arg_str = (char *)va_arg(*args, char *);
		write_fm(temp.arg_str, format);
	}
	else if (format == 'p')
	{
		temp.arg_void = (void *)va_arg(*args, void *);
		write_fm(temp.arg_void, format);
	}
	else if (format == 'c' || format == 'd' || format == 'i')
	{
		temp.arg_int = va_arg(*args, int);
		write_fm(&temp.arg_int, format);
	}
	else if (format == 'u' || format == 'x' || format == 'X')
	{
		temp.arg_unint = (unsigned int)va_arg(*args, unsigned int);
		write_fm(&temp.arg_unint, format);
	}
	if (format == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		len;
	char	fm;

	len = ft_strlen(fstr);
	va_start(args, fstr);
	while (*fstr)
	{
		fm = detect_fm(fstr);
		if (fm)
		{
			devide_fm(&args, fm);
			fstr = fstr + 2;
		}
		else
			write(1, fstr++, 1);
	}
	va_end(args);
	return (len);
}
