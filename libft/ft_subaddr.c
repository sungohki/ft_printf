/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:25:10 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	addr_len(unsigned long addr)
{
	int		len;

	len = 0;
	while (addr > 0)
	{
		addr = addr / 16;
		len++;
	}
	return (len);
}

char	*ft_subaddr(void *ch)
{
	char			*result;
	int				len;
	unsigned long	temp;

	temp = (unsigned long)ch;
	len = 2 + addr_len(temp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	result[len--] = 0;
	result[0] = '0';
	result[1] = 'x';
	while (temp > 0)
	{
		result[len--] = "0123456789abcdef"[temp % 16];
		temp = temp / 16;
	}
	return (result);
}
