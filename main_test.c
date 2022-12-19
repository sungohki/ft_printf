/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:47:12 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/19 18:09:33 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libftprintf.h"
#include "libft/libft.h"
#include "ft_printf.c"

static void	addr_write(unsigned long n, int fd)
{
	char	temp;

	temp = "0123456789abcdef"[n % 16];
	if (n / 16 > 0)
		addr_write(n / 16, fd);
	write(fd, &temp, 1);
}

int	main(void)
{
	// conversion에 널 포인터가 들어간 경우
	printf("test : [%s]\n", (void *)0);
	// conversion선언은 되었으나 args를 선언안한 경우
	// printf("test : [%s]\n");	// segmentation fault 발생
	// write 함수는 %를 그대로 출력하는가?
	write(1, "test : [%s %]\n", 15);
	// %s를 그냥 그대로 출력하고 싶으면 어떻게 해야하는가?
	printf("test : [cspdiuxX%%], len : [%%]\n");
	// detect_cvs 테스트
	for (int i = 0; i < 9; i++)
		printf("%c", STRFORMAT[i]);
	printf("\ntest : %  d\n", detect_cvs("%l"));
	// count_cvs 테스트
	if(1){
		char	*test10 = "%c %  s %    a %e % %%";
		printf("count : [%d]\n", count_cvs(test10));
	}

	// 출력 포맷 테스트
	if (1){
		int num = 1;
		int *pt = &num;
		// printf("%c %s %p %d %i %u %x %X %%\n",
		// 'a',
		// "hello,world!",
		// pt,
		// (unsigned int)-123,
		// INT32_MAX,
		// -1,
		// 123,
		// 112);
		printf("1 : %p\n", pt);
		write(1, "2 : 0x", 6);
		addr_write((unsigned long)pt, 1);
		write(1, "\n", 1);
	}
	// putaddr 테스트
	if(1){
		void		*test10;
		size_t		temp;

		temp = (size_t)&test10;
		for (int i = 0; i < 16; i++){
			write(1, &"0123456789abcdef"[temp % 16], 1);
			temp = temp / 16;
		}
	}
	return (0);
}