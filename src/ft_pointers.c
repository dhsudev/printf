/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:50:08 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:07 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	print_pt(unsigned long long n)
{
	int		count;
	char	*symb;

	symb = "0123456789abcdef";
	if (n < 16)
		return (print_char(symb[n]));
	else
	{
		count = print_pt(n / 16);
		return (count + print_pt(n % 16));
	}
}
