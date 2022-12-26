/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:59:42 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/27 05:41:50 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	print_arg(va_list *args, char format)
{
	char	*temp;
	int		arg_len;

	temp = ft_devide_fm(args, format);
	if (temp == 0)
		return (-1);
	arg_len = ft_write_fm(temp, format);
	if (format != '%' && temp != 0)
		free(temp);
	return (arg_len);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		len;
	int		arg_len;
	char	fm;

	len = 0;
	va_start(args, fstr);
	while (*fstr)
	{
		fm = ft_detect_fm(fstr);
		if (fm)
		{
			arg_len = print_arg(&args, fm);
			fstr = fstr + 2;
		}
		else if (*(fstr++) != '%')
			arg_len = write(1, fstr - 1, 1);
		if (arg_len == -1)
			return (-1);
		len += arg_len;
	}
	va_end(args);
	return (len);
}
