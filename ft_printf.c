/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:59:42 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 18:10:07 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h" 
#include "libft/libft.h"

int	detect_cvs(const char *ch)
{
	int	index;

	if (*ch == '%')
	{
		index = 0;
		while (index < 9)
		{
			if (*(ch + 1) == STRFORMAT[index++])
				return (1);
		}
	}
	return (0);
}

int	count_cvs(const char *fstr)
{
	int			count;
	const char	*temp;

	count = 0;
	temp = fstr;
	while (*temp)
		if (detect_cvs(temp++))
			count++;
	return (count);
}

void	write_format(void *ch, char format)
{
	if (format == 'c')
		ft_putchar_fd(*(char *)ch, 1);
	else if (format == 's')
		ft_putstr_fd((char *)ch, 1);
	// else if (format == 'p')
		// ft_putaddr_fd(ch, 1);
	else if (format == 'd')
		ft_putnbr_fd(*(int *)ch, 1);
	else if (format == 'i')
		ft_putnbr_fd(*(int *)ch, 1);
	// else if (format == 'u')
		// ft_putnbr_fd(ch, 1);
	else if (format == 'x')
		ft_putnbr_hex_fd(*(unsigned int *)ch, 1);
	// else if (format == 'X')
		// ft_putnbr_hex_fd(*(unsigned int *)ch, 1);
}

int	ft_printf(const char *fstr, ...)
{
	// va_list	temp;
	int		result;
	int		format_count;

	result = ft_strlen(fstr);
	format_count = count_cvs(fstr);
	// va_start(temp, format_count);
	// while (*fstr)
	// {
		
	// }
	return (result);
}
