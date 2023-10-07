/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:30:43 by ksho              #+#    #+#             */
/*   Updated: 2023/09/23 16:17:16 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count(int num)
{
	int		i;
	size_t	size;

	i = num;
	size = 1;
	if (i < 0)
	{
		i = -i;
		size++;
	}
	while (10 <= i)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static char	*ft_return_intmin(void)
{
	char	*res;

	res = (char *)ft_calloc(12, sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, "-2147483648", 11);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	size;

	if (n == -2147483648)
		return (ft_return_intmin());
	size = ft_count(n) - 1;
	result = (char *)ft_calloc(size + 2, sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (10 <= n)
	{
		result[size--] = 48 + (n % 10);
		n = n / 10;
	}
	result[size] = 48 + n;
	return (result);
}
