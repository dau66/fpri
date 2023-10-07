/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:31:05 by ksho              #+#    #+#             */
/*   Updated: 2023/07/12 18:55:04 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*change_base(unsigned long long us, int b, char *r, int c)
{
	while (us != 0)
	{
		if ((us % b) < 10)
			r[c - 1] = (us % b) + 48;
		else
			r[c - 1] = (us % b) + 55;
		us /= b;
		c--;
	}
	return (r);
}

char	*ft_point_base(unsigned long long point, int base)
{
	char				*rtn;
	int					count;
	unsigned long long	us;

	count = 0;
	us = point;
	if (point == 0)
		return (ft_strdup("0"));
	while (point != 0)
	{
		point = point / base;
		count++;
	}
	rtn = ft_calloc(count + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	rtn = change_base(us, base, rtn, count);
	return (rtn);
}
