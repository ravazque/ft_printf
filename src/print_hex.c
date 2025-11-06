/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 00:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	put_hex_recursive(t_buffer *buf, unsigned long n, int upper)
{
	char	*base_lower;
	char	*base_upper;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (n >= 16)
		put_hex_recursive(buf, n / 16, upper);
	if (upper)
		buffer_add_char(buf, base_upper[n % 16]);
	else
		buffer_add_char(buf, base_lower[n % 16]);
}

static int	get_hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	print_hex_with_precision(t_buffer *buf, unsigned long n,
		t_flags *flags, int upper)
{
	int	numlen;
	int	precision_pad;

	numlen = get_hex_len(n);
	precision_pad = 0;
	if (flags->precision > numlen)
		precision_pad = flags->precision - numlen;
	if (flags->hash && n != 0)
		put_prefix(buf, flags, upper);
	while (precision_pad > 0)
	{
		buffer_add_char(buf, '0');
		precision_pad--;
	}
	if (!(flags->dot && flags->precision == 0 && n == 0))
		put_hex_recursive(buf, n, upper);
}

void	print_hex(t_buffer *buf, t_flags *flags, unsigned long num, int upper)
{
	int	numlen;
	int	total_width;
	int	prefix_len;

	numlen = get_hex_len(num);
	if (flags->dot && flags->precision > numlen)
		numlen = flags->precision;
	prefix_len = 0;
	if (flags->hash && num != 0)
		prefix_len = 2;
	total_width = flags->width - numlen - prefix_len;
	if (!flags->minus && !flags->zero)
		pad_width(buf, total_width, 0);
	if (flags->zero && !flags->dot)
	{
		if (flags->hash && num != 0)
			put_prefix(buf, flags, upper);
		pad_width(buf, total_width, 1);
		if (!(flags->dot && flags->precision == 0 && num == 0))
			put_hex_recursive(buf, num, upper);
	}
	else
		print_hex_with_precision(buf, num, flags, upper);
	if (flags->minus)
		pad_width(buf, total_width, 0);
}
