/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungohki <sungohki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:47:12 by sungohki          #+#    #+#             */
/*   Updated: 2022/12/26 1 by sungohki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

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
	// paco -s : no format
	if(1){
		int	test10[100];

		// printf("ex : ");
		// test10[0] = printf("\001\002\007\v\010\f\r\n");
		// printf("ft : ");
		// test10[1] = ft_printf("\001\002\007\v\010\f\r\n");
		// printf ("ex : [%d]\n", test10[0]);
		// printf ("ft : [%d]\n", test10[1]);
		test10[0] = printf("%%c\n", 'x');
		test10[1] = ft_printf("%%c\n", 'x');
		// printf("0 : [%d] 1 : [%d]\n", test10[0], test10[1]);
		
		// char	test20[21474];
		// for(int i = 0; i < 21474; i++)
		// 	test20[i] = '*';
		// test10[2] = printf("%s", test20);
		// printf("\n-> [%d]", test10[2]);
	}

	// // conversion??? ??? ???????????? ????????? ??????
	// printf("test : [%s]\n", (void *)0);
	// // conversion????????? ???????????? args??? ???????????? ??????
	// // printf("test : [%s]\n");	// segmentation fault ??????
	// // write ????????? %??? ????????? ????????????????
	// write(1, "test : [%s %]\n", 15);
	// // %s??? ?????? ????????? ???????????? ????????? ????????? ????????????????
	// printf("test : [cspdiuxX%%], len : [%%]\n");
	// // detect_fm ?????????
	// for (int i = 0; i < 9; i++)
	// 	printf("%c", STRFORMAT[i]);
	// printf("\ntest : %  d\n", detect_fm("%l"));
	// // // count_fm ?????????
	// // if(1){
	// // 	char	*test10 = "%c %  s %    a %e % %%";
	// // 	printf("count : [%d]\n", count_fm(test10));
	// // }

	// // ?????? ?????? ?????????
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
	// // putaddr ?????????
	// if(1){
	// 	void		*test10;
	// 	size_t		temp;

	// 	temp = (size_t)&test10;
	// 	for (int i = 0; i < 16; i++){
	// 		write(1, &"0123456789abcdef"[temp % 16], 1);
	// 		temp = temp / 16;
	// 	}
	// }
	// // strlen ????????? + ?????? ???????????? ?????? %??? ????????????????
	// if (1){
	// 	char	*test10 = "%s%d\n\t";
	// 	printf("\nstrlen : [%lu, %lu]\n", strlen(test10), ft_strlen(test10));
	// 	printf("%s\n", test10);
	// }
	// // sizeof() ?????? ?????????
	// if (1){
	// 	printf("size :[%lu] [%lu]\n", sizeof(va_list), sizeof(char *));
	// }

	// ft_printf() ?????? ?????????
	// if (1){
	// 	// ft_printf("hello, %s", "world");
	// 	int	test[10];	// for ft_printf
	// 	int	test2[10];	// for printf
	// 	char	*ex = "hello";
	// 	test[0] = ft_printf("ft_%%c : [%c]\n", 'a'); 
	// 	test2[0] = printf("ex_%%c : [%c]\n", 'a');
	// 	test[1] = ft_printf("ft_%%s : [%s]\n", "hello, world!"); 
	// 	test2[1] = printf("ex_%%s : [%s]\n", "hello, world!"); 
	// 	// addr_write((unsigned long)ex, 1);
	// 	// write(1, "\n", 1);
	// 	// ft_putaddr_fd(ex, 1);
	// 	// write(1, "\n", 1);
	// 	test[2] = ft_printf("ft_%%p : [%p] [%s]\n", ex, ex);
	// 	printf("len : %d\n", addr_len((unsigned long)ex));
	// 	test2[2] = printf("ex_%%p : [%p] [%s]\n", ex, ex); 
	// 	test[3] = ft_printf("ft_%%d : [%d] [%d]\n", 123, -123); 
	// 	test2[3] = printf("ex_%%d : [%d] [%d]\n", 123, -123); 
	// 	test[4] = ft_printf("ft_%%i : [%i] [%i]\n", 321, -321); 
	// 	test2[4] = printf("ex_%%i : [%i] [%i]\n", 321, -321); 
	// 	test[5] = ft_printf("ft_%%u : [%u] [%u]\n", INT32_MAX, -1); 
	// 	test2[5] = printf("ex_%%u : [%u] [%u]\n", INT32_MAX, -1); 
	// 	test[6] = ft_printf("ft_%%x : [%x]\n", 1234); 
	// 	test2[6] = printf("ex_%%x : [%x]\n", 1234); 
	// 	test[7] = ft_printf("ft_%%X : [%X]\n", 1234); 
	// 	test2[7] = printf("ex_%%X : [%X]\n", 1234); 
	// 	test[8] = ft_printf("ft_%%%% : [%%]\n"); 
	// 	test2[8] = printf("ex_%%%% : [%%]\n"); 
	// 	printf("ft_printf :\t");
	// 	for(int i = 0; i < 9; i++){
	// 		printf("%d ", test[i]);
	// 	}
	// 	printf("\n");
	// 	printf("printf :\t");
	// 	for(int i = 0; i < 9; i++){
	// 		printf("%d ", test2[i]);
	// 	}
	// 	printf("\n");
	// 	}
	// if(1){
		// printf("ft = %d\n", ft_printf("[%c][%c][%c]", '0', 0, '1'));
		// printf("ft = %d\n", ft_printf("[%c][%c][%c]", 0, '1', '2'));
		// printf("ft = %d\n", ft_printf("[%c][%c][%c]", '2', '1', 0));
		// printf("ex = %d\n", printf("[%c][%c][%c]", '0', 0, '1'));
		// printf("ex = %d\n", printf("[%c][%c][%c]", 0, '1', '2'));
		// printf("ex = %d\n", printf("[%c][%c][%c]", '2', '1', 0));
		// printf("ft = %d\n", ft_printf(" %c", '0' - 256));
		// printf("ex = %d\n", printf(" %c", '0' - 256));
		// ft_printf("[%c]\n", 0);
		// printf("write returns : [%zd]", write(1, "\0\n", 2));
		// printf("[%c]\n", 0);

		// printf("ft : %d\n", ft_printf(" [%s] [%s] [%s] [%s] [%s]", " - ", "", "4", "", "2 "));
		// printf("ex : %d\n", printf(" [%s] [%s] [%s] [%s] [%s]", " - ", "", "4", "", "2 "));
	// }

	// if (1){
		// printf("ex : %p %p \n", 0, 0);
		// ft_printf("ft : %p %p \n", 0, 0);

		// printf("ex : [%d]\n", printf("%s", NULL));
		// printf("//\nex1 : NULL is [%s] NULL \n", NULL);
		// printf("ex2 : NULL is [%s] NULL \n", 0);
		// ft_putstr_fd((char *)0, 1);
		// ft_printf("ft : NULL [%s] NULL ", NULL);
		// printf("//\n");

		// ft_printf("%iLaq-sHY%XfI5B(^u \n%x{Tfi\"%c^jz#o_`>", 2122883773, 1189719076, -1194259054, -1071431376);
		// ft_printf("E/Wd%p0@NCw+K%cNQ`\r%c\rQc(H#%%5r5Hvt[.uK%d*#ly\rH.%x %%Z3Y_", (void *)-2902810474066801905, -598970712, -1832214407, 435305193, -723518034);
	// }
	return (0);
}