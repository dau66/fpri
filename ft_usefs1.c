/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:31:41 by ksho              #+#    #+#             */
/*   Updated: 2023/09/23 16:18:50 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_put_unbr(unsigned int nmb)
{
	int				count;
	unsigned int	tmp;
	char			*c;

	count = 0;
	tmp = nmb;
	if (nmb == 0)
		count++;
	while (nmb)
	{
		nmb = nmb / 10;
		count++;
	}
	c = ft_calloc(count + 1, sizeof(char));
	while (count)
	{
		nmb = tmp % 10;
		c[count - 1] = nmb + '0';
		tmp /= 10;
		count--;
	}
	count = ft_putstr_fd(c, 1);
	free(c);
	return (count);
}

int	ft_p_unnum(unsigned int i)
{
	int	n;

	n = ft_put_unbr(i);
	return (n);
}

int	ft_p_hexa(unsigned int i, int flag)
{
	int		c;
	char	*str;

	c = 0;
	str = ft_point_base_x(i, 16);
	if (flag == 1)
		str = ft_tolower_all(str);
	c = ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (c);
}
