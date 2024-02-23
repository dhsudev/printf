/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:24:58 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/21 19:35:25 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_digit(long n, long base, int upper);
int		print_string(char *s);
int		print_char(int c);
int		print_format(char spec, va_list ap, int *count);
int		print_pt(unsigned long long n);

#endif