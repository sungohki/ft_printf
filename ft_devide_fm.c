/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devide_fm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:34:02 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:34:17 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_devide_fm(va_list *args, char format)
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
		return (ft_str_fm(temp.arg_void, format));
	}
	else if (format == 'c' || format == 'd' || format == 'i')
	{
		temp.arg_int = va_arg(*args, int);
		return (ft_str_fm(&temp.arg_int, format));
	}
	else if (format == 'u' || format == 'x' || format == 'X')
	{
		temp.arg_unint = (unsigned int)va_arg(*args, unsigned int);
		return (ft_str_fm(&temp.arg_unint, format));
	}
	else
		return ("%");
}
