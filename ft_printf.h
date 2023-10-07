/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:43:14 by ksho              #+#    #+#             */
/*   Updated: 2023/09/23 16:16:52 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_p_char(char c);
int		ft_p_str(char *str);
int		ft_p_ptr(unsigned long long value);
int		ft_p_num(int value);
int		ft_p_unnum(unsigned int value);
int		ft_p_hexa(unsigned int value, int flag);
char	*ft_point_base(unsigned long long point, int base);
char	*ft_itoa(int n);
int		ft_p_unnum(unsigned int i);
int		ft_putchar_fd(char *s, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*ft_tolower_all(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *b, size_t n);
int		ft_ope_check(int c, va_list *args);
int		out_putter(const char *fmt, va_list *args);
int		ft_printf(const char *fmt, ...);
char	*ft_strdup(const char *str);
char	*ft_point_base_x(unsigned int point, int base);
#endif
