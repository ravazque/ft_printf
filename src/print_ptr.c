/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:10:27 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/09 15:48:12 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_putptr(t_buffer *buf, unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_putptr(buf, n / 16);
	buffer_add_char(buf, base[n % 16]);
}

void	ft_print_ptr(t_buffer *buf, void *ptr)
{
	unsigned long	addr;

	if (!ptr)
	{
		buffer_add_str(buf, "(nil)", 5);
		return ;
	}
	addr = (unsigned long)ptr;
	buffer_add_str(buf, "0x", 2);
	ft_putptr(buf, addr);
}
