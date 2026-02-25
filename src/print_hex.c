/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:20:38 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/08 18:30:55 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_puthex(t_buffer *buf, unsigned int n, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(buf, n / 16, upper);
	buffer_add_char(buf, base[n % 16]);
}

void	ft_print_hex(t_buffer *buf, unsigned int num, int upper)
{
	ft_puthex(buf, num, upper);
}
