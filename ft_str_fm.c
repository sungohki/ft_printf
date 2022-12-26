/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:33:06 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/27 02:11:00 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_fm(void *ch, char format)
{
	char	*ex;

	if (format == 'c')
	{
		ex = (char *)malloc(sizeof(char));
		if (ex == 0)
			return (0);
		ex[0] = *(char *)ch;
		return (ex);
	}
	else if (format == 's')
		return (ft_substr((char *)ch, 0, ft_strlen((char *)ch)));
	else if (format == 'p')
		return (ft_subaddr(ch));
	else if (format == 'd' || format == 'i')
		return (ft_itoa(*(int *)ch));
	else if (format == 'u')
		return (ft_itoa_us(*(unsigned int *)ch));
	else if (format == 'x' || format == 'X')
		return (ft_itoa_hex(*(unsigned int *)ch, format - 'x'));
	else
		return (0);
}
