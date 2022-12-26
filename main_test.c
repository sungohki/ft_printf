/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:47:12 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 17:10:49 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libftprintf.h"
#include "libft/libft.h"
#include "ft_printf.c"

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

// static void	addr_write(unsigned long n, char *addr)
// {
// 	*(addr++) = '0';
// 	*(addr++) = 'x';
// 	while (*addr)
// 		addr++;
// 	while (n > 0)
// 	{
// 		*(--addr) = "0123456789abcdef"[n % 16];
// 		n = n / 16;
// 	}
// }

// char	*ft_subaddr(void *ch)
// {
// 	char	*result;
// 	int		len;

// 	len = 2 + addr_len((unsigned long)ch);
// 	result = (char *)malloc(sizeof(char) * (len + 1));
// 	if (result == 0)
// 		return (0);
// 	result[len] = 0;
// 	addr_write((unsigned long)ch, result);
// 	return (result);
// }

int	main(void)
{
	// // conversion에 널 포인터가 들어간 경우
	// printf("test : [%s]\n", (void *)0);
	// // conversion선언은 되었으나 args를 선언안한 경우
	// // printf("test : [%s]\n");	// segmentation fault 발생
	// // write 함수는 %를 그대로 출력하는가?
	// write(1, "test : [%s %]\n", 15);
	// // %s를 그냥 그대로 출력하고 싶으면 어떻게 해야하는가?
	// printf("test : [cspdiuxX%%], len : [%%]\n");
	// // detect_fm 테스트
	// for (int i = 0; i < 9; i++)
	// 	printf("%c", STRFORMAT[i]);
	// printf("\ntest : %  d\n", detect_fm("%l"));
	// // // count_fm 테스트
	// // if(1){
	// // 	char	*test10 = "%c %  s %    a %e % %%";
	// // 	printf("count : [%d]\n", count_fm(test10));
	// // }

	// // 출력 포맷 테스트
	// if (1){
	// 	int num = 1;
	// 	int *pt = &num;
	// 	// printf("%c %s %p %d %i %u %x %X %%\n",
	// 	// 'a',
	// 	// "hello,world!",
	// 	// pt,
	// 	// (unsigned int)-123,
	// 	// INT32_MAX,
	// 	// -1,
	// 	// 123,
	// 	// 112);
	// 	printf("1 : %p\n", pt);
	// 	write(1, "2 : 0x", 6);
	// 	addr_write((unsigned long)pt, 1);
	// 	write(1, "\n", 1);
	// }
	// // putaddr 테스트
	// if(1){
	// 	void		*test10;
	// 	size_t		temp;

	// 	temp = (size_t)&test10;
	// 	for (int i = 0; i < 16; i++){
	// 		write(1, &"0123456789abcdef"[temp % 16], 1);
	// 		temp = temp / 16;
	// 	}
	// }
	// // strlen 테스트 + 이미 문자열에 있는 %는 출력하는가?
	// if (1){
	// 	char	*test10 = "%s%d\n\t";
	// 	printf("\nstrlen : [%lu, %lu]\n", strlen(test10), ft_strlen(test10));
	// 	printf("%s\n", test10);
	// }
	// // sizeof() 함수 테스트
	// if (1){
	// 	printf("size :[%lu] [%lu]\n", sizeof(va_list), sizeof(char *));
	// }
	// ft_printf() 함수 테스트
	if (1){
		// ft_printf("hello, %s", "world");
		int	test[10];	// for ft_printf
		int	test2[10];	// for printf
		char	*ex = "hello";
		test[0] = ft_printf("ft_%%c : [%c]\n", 'a'); 
		test2[0] = printf("ex_%%c : [%c]\n", 'a');
		test[1] = ft_printf("ft_%%s : [%s]\n", "hello, world!"); 
		test2[1] = printf("ex_%%s : [%s]\n", "hello, world!"); 
		// addr_write((unsigned long)ex, 1);
		// write(1, "\n", 1);
		// ft_putaddr_fd(ex, 1);
		// write(1, "\n", 1);
		test[2] = ft_printf("ft_%%p : [%p] [%s]\n", ex, ex);
		printf("len : %d\n", addr_len((unsigned long)ex));
		test2[2] = printf("ex_%%p : [%p] [%s]\n", ex, ex); 
		test[3] = ft_printf("ft_%%d : [%d] [%d]\n", 123, -123); 
		test2[3] = printf("ex_%%d : [%d] [%d]\n", 123, -123); 
		test[4] = ft_printf("ft_%%i : [%i] [%i]\n", 321, -321); 
		test2[4] = printf("ex_%%i : [%i] [%i]\n", 321, -321); 
		test[5] = ft_printf("ft_%%u : [%u] [%u]\n", INT32_MAX, -1); 
		test2[5] = printf("ex_%%u : [%u] [%u]\n", INT32_MAX, -1); 
		test[6] = ft_printf("ft_%%x : [%x]\n", 1234); 
		test2[6] = printf("ex_%%x : [%x]\n", 1234); 
		test[7] = ft_printf("ft_%%X : [%X]\n", 1234); 
		test2[7] = printf("ex_%%X : [%X]\n", 1234); 
		test[8] = ft_printf("ft_%%%% : [%%]\n"); 
		test2[8] = printf("ex_%%%% : [%%]\n"); 
		printf("ft_printf :\t");
		for(int i = 0; i < 9; i++){
			printf("%d ", test[i]);
		}
		printf("\n");
		printf("printf :\t");
		for(int i = 0; i < 9; i++){
			printf("%d ", test2[i]);
		}
		printf("\n");
	}
	return (0);
}