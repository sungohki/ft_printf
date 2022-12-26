/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_fm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:16:24 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/27 01:43:08 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_fm(char *ch, char format)
{
	int	result;

	if (ch == 0)
		result = write(1, "(null)", 6);
	else if (format == 'c')
		result = write(1, ch, 1);
	else
		result = write(1, ch, ft_strlen(ch));
	return (result);
}
