/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:47:03 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 18:04:25 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex_fd(unsigned int n, int fd)
{
	char	temp;

	temp = "0123456789abcdef"[n % 16];
	if (n / 16 > 0)
		ft_putnbr_hex_fd(n / 16, fd);
	write(fd, &temp, 1);
}
