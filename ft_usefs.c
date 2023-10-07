/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:18:38 by ksho              #+#    #+#             */
/*   Updated: 2023/09/28 12:19:51 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_p_str(char *str)
{
	int		i;
	char	*strnull;

	i = 0;
	strnull = "(null)";
	if (!str)
	{
		write(1, strnull, 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

// int ft_putstr_count(char *c)
// {
//     int n;

//     if (!c)
//         return (0);
//     n = ft_putstr_fd(c, 1);
//     return (n);
// }

int	ft_p_ptr(unsigned long long ptr)
{
	char	*pointa;
	int		n;

	n = 0;
	pointa = ft_point_base(ptr, 16);
	if (!pointa)
		return (0);
	n += ft_putstr_fd("0x", 1);
	pointa = ft_tolower_all(pointa);
	n += ft_putstr_fd(pointa, 1);
	free(pointa);
	return (n);
}

int	ft_p_num(int i)
{
	int		a;
	char	*str;

	str = ft_itoa(i);
	a = ft_putstr_fd(str, 1);
	free(str);
	return (a);
}
