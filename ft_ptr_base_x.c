/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_base_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:31:05 by ksho              #+#    #+#             */
/*   Updated: 2023/09/23 16:18:03 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*change_base(unsigned int us, int b, char *r, int c)
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

char	*ft_point_base_x(unsigned int point, int base)
{
	char			*rtn;
	int				count;
	unsigned int	us;

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
