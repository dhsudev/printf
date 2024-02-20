/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:10:53 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/20 10:48:42 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
int print_char(int c)
{
	return (write(1,&c,1))
}
int print_string(char *s)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while(s[i])
	{
		count += print_char(s[i]);
		i++;
	}
	return (count);
}
int print_digit(long n, int base)
{
	int count;
	char	*symb;

	symb = "0123456789abcdef";
	if (n < 0)
	{
		print_char('-');
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return (print_char(symb[n]));
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}
int print_format(char spec, va_list ap)
{
	int count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_string(va_arg(ap, char *));
	else if (spec == 'd')
		count += print_digit((long)va_arg(ap, int), 10);
	else if (spec == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), ,16);
	else
		count += write(1,&spec,1);
	return(count);
}

int		ft_printf(const char *format, ...)
{
	va_list	*ap;
	int		count;
	int		i;
	
	va_start(ap, format);
	count = 0;
	while(format[i]){
		if(format[i] == '%')
			count += print_format(format[i+1], ap);
		else
			count += write(1, format[i], 1);
		i++;
	}
	return (count);
}