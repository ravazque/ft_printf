/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 00:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	put_hex_ptr(t_buffer *buf, unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		put_hex_ptr(buf, n / 16);
	buffer_add_char(buf, base[n % 16]);
}

static int	get_ptr_len(unsigned long n)
{
	int	len;

	len = 2;
	if (n == 0)
		return (3);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	print_ptr(t_buffer *buf, t_flags *flags, void *ptr)
{
	int				len;
	int				pad;
	unsigned long	addr;

	if (!ptr)
	{
		len = ft_strlen("(nil)");
		if (!flags->minus)
			pad_width(buf, flags->width - len, 0);
		buffer_add_str(buf, "(nil)", len);
		if (flags->minus)
			pad_width(buf, flags->width - len, 0);
		return ;
	}
	addr = (unsigned long)ptr;
	len = get_ptr_len(addr);
	pad = flags->width - len;
	if (!flags->minus)
		pad_width(buf, pad, 0);
	buffer_add_str(buf, "0x", 2);
	put_hex_ptr(buf, addr);
	if (flags->minus)
		pad_width(buf, pad, 0);
}
