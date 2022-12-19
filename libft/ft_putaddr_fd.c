/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:23:40 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 18:04:28 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	addr_len(size_t addr)
{
	int		len;

	len = 0;
	while (addr > 0)
	{
		len++;
		addr = addr / 16;
	}
	return (len);
}

static void	addr_write(unsigned long n, int fd)
{
	char	temp;

	temp = "0123456789abcdef"[n % 16];
	if (n / 16 > 0)
		addr_write(n / 16, fd);
	write(fd, &temp, 1);
}

void	ft_putaddr_fd(void *ch, int fd)
{
	unsigned long	temp;
	char			*result;
	int				len;

	temp = (unsigned long)&ch;
	len = addr_len(temp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return ;
	write(fd, "0x", 2);
	addr_write(temp, fd);
}
