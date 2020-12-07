/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 18:36:48 by gcredibl          #+#    #+#             */
/*   Updated: 2020/12/01 19:42:19 by gcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct		s_printf
{
	va_list			list;
	char			*str;
	char			*set_spec;
	char			spec;
	int				error;
	int				flag_zero;
	int				flag_min;
	int				flag_dot;
	int				width;
	int				prec;
	int				len;
}					t_printf;
extern t_printf		*g_printf;

int					ft_printf(const char *format, ...);
int					check(char *str);
void				restore_flags(void);
int					parser(char *str);
void				print_res(void);
int					set_flag(char *str);
int					set_width(char *str);
int					set_prec(char *str);
int					set_spec(char *str);
void				print_char(void);
void				print_string(void);
void				print_pointer(void);
void				print_digit(void);
void				print_unsigned_digit(void);
void				print_hex(void);
int					check_global(void);
void				print_end_char(char *str);
char				*append_start(char *str, char c, size_t n);
char				*append(char *str, char c, size_t n);
char				*print_string_precision(char *str);
char				*check_width(char *str);
char				*get_dec_precision(char *str);
void				ft_putstr(char *str);
int					ft_putstr_count(char *str);
char				*get_hex(unsigned long nb);
void				ft_putnbr_base(unsigned long nb, char *dst, int i);
char				get_char(char *base, int n);
int					count_len(unsigned long nb);
char				*ft_itoa_unsigned(unsigned n);
int					getlen_unsigned(unsigned n);
void				ft_putchar_str(char *dst, int n, char c);
#endif
