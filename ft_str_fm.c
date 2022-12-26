/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:33:06 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:33:27 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_str_fm(void *ch, char format)
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
