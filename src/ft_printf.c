/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:10:53 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/22 00:52:19 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) != -1)
		count++;
	else
		count = -1;
	return (count);
}

int	print_string(char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (print_string("(null)"));
	while (s[i])
	{
		count += print_char(s[i]);
		i++;
	}
	return (count);
}

int	print_digit(long n, long base, int upper)
{
	int		count;
	char	*symb;

	if (upper)
		symb = "0123456789ABCDEF";
	else
		symb = "0123456789abcdef";
	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base, upper) + 1);
	}
	else if (n < base)
		return (print_char(symb[n]));
	else
	{
		count = print_digit(n / base, base, upper);
		return (count + print_digit(n % base, base, upper));
	}
}

int	print_format(char spec, va_list ap, int *count)
{
	int temp;

	temp = *count;
	if (spec == 'c')
		*count += print_char(va_arg(ap, int));
	else if (spec == 's')
		*count += print_string(va_arg(ap, char *));
	else if (spec == 'i' || spec == 'd')
		*count += print_digit(va_arg(ap, int), 10, 0);
	else if (spec == 'u')
		*count += print_digit(va_arg(ap, unsigned int), 10, 0);
	else if (spec == 'x')
		*count += print_digit(va_arg(ap, unsigned int), 16, 0);
	else if (spec == 'X')
		*count += print_digit(va_arg(ap, unsigned int), 16, 1);
	else if (spec == '%')
		*count += print_char('%');
	else if (spec == 'p')
	{
		*count += print_string("0x");
		*count += print_pt(va_arg(ap, unsigned long long));
	}
	else
		return (-1);
	return (temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	count = 0;
	i = -1;
	while (format[++i] && count != -1)
	{
		if (format[i] == '%')
		{
			if (print_format(format[++i], ap, &count) > count)
				return (-1);
		}
		else
		{
			if (count + print_char(format[i]) <= count)
				return (-1);
			count++;
		}
		if (count == -1)
			return (-1);
	}
	return (count);
}
