/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:47:12 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 11:50:53 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include "libft/libft.h"

int	main(void)
{
	// conversion에 널 포인터가 들어간 경우
	printf("test : [%s]\n", (void *)0);
	// conversion선언은 되었으나 args를 선언안한 경우
	printf("test : [%s]\n");
	return (0);
}
