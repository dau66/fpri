/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:44:17 by ksho              #+#    #+#             */
/*   Updated: 2023/09/23 16:15:21 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_ope_check(int c, va_list *args)
{
	if (c == 'c')
		return (ft_p_char((unsigned char)va_arg(*args, int)));
	else if (c == 's')
		return (ft_p_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_p_ptr((uintptr_t)va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_p_num(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_p_unnum(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_p_hexa(va_arg(*args, unsigned int), 1));
	else if (c == 'X')
		return (ft_p_hexa(va_arg(*args, unsigned int), 0));
	else
		return (ft_p_str("%"));
}

int	out_putter(const char *fmt, va_list *args)
{
	int	i;

	i = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_p_char(*fmt);
			fmt++;
			i++;
			continue ;
		}
		else
		{
			fmt++;
			i += ft_ope_check((int)*fmt, args);
		}
		fmt++;
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	i = out_putter(fmt, &args);
	va_end(args);
	return (i);
}
