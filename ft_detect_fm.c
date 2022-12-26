/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_fm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:31:28 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 21:05:08 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_detect_fm(const char *ch)
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
