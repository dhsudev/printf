/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:19:24 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/02/21 20:01:21 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/printf.h"
#include <limits.h>

int main (void){
		int cnt;
		cnt = printf("%s", (char *)NULL);
		printf("writed: %d\n", cnt);
		cnt = ft_printf("%s", (char *)NULL);
		printf("writed: %d", cnt);

}