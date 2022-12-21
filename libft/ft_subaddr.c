/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/21 22:28:55 by sungohki         ###   ########.fr       */
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

static void	addr_write(unsigned long n, char *addr)
{
	*(addr++) = '0';
	*(addr++) = 'x';
	while (*addr)
		addr++;
	while (n > 0)
	{
		*(--addr) = "0123456789abcdef"[n % 16];
		n = n / 16;
	}
}

char	*ft_subaddr(void *ch)
{
	char	*result;
	int		len;

	len = 2 + addr_len((unsigned long)ch);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	addr_write((unsigned long)ch, result);
	return (result);
}
