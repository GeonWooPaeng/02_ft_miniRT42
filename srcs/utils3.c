/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:09:15 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/07 17:01:28 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "utils.h"
#include <stdio.h>

int	ft_atoi(char *str, int *n)
{
	int sign;
	long num;

	num = 0;
	num = 0;
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * (int)num);
}

double ft_atod(char *str)
{
	int num;
	double result;
	double point; //자리수

	num = ft_atoi(str);
	printf(">>>> %d\n", num);
	if (*str == '.')
		str++;
	printf("s >>> %s\n",str);
	point = num < 0 ? -0.1 : 0.1;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		result += point * (*str - '0');
		point *= 0.1;
	}
	return (result);
}

int main()
{
	char *a = "-9.42";
	char *b = "-0.3";
	char *c = "0.2";
	char *d = "1.0";
	// char *a = "-93";
	// char *b = "-0";
	// char *c = "0";
	// char *d = "1";

	// printf("%d\n",ft_atoi(a));
	// printf("%d\n",ft_atoi(b));
	// printf("%d\n",ft_atoi(c));
	// printf("%d\n",ft_atoi(d));
	printf("%lf\n",ft_atod(a));
	printf("%lf\n",ft_atod(b));
	printf("%lf\n",ft_atod(c));
	printf("%lf\n",ft_atod(d));

}