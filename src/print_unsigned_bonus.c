/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:30:44 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 11:25:36 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static int	ft_unsigned_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	put_unsigned_recursive(t_buffer *buf, unsigned long n)
{
	if (n >= 10)
		put_unsigned_recursive(buf, n / 10);
	buffer_add_char(buf, (n % 10) + '0');
}

static void	print_unsigned_precision(t_buffer *buf, unsigned int n,
		t_flags *flags)
{
	int	numlen;
	int	precision_pad;

	numlen = ft_unsigned_len(n);
	precision_pad = 0;
	if (flags->precision > numlen)
		precision_pad = flags->precision - numlen;
	while (precision_pad > 0)
	{
		buffer_add_char(buf, '0');
		precision_pad--;
	}
	if (!(flags->dot && flags->precision == 0 && n == 0))
		put_unsigned_recursive(buf, (unsigned long)n);
}

void	print_unsigned(t_buffer *buf, t_flags *flags, unsigned int n)
{
	int	num_width;
	int	total_pad;
	int	numlen;

	numlen = ft_unsigned_len(n);
	if (flags->dot && flags->precision == 0 && n == 0)
		num_width = 0;
	else if (flags->dot && flags->precision > numlen)
		num_width = flags->precision;
	else
		num_width = numlen;
	total_pad = flags->width - num_width;
	if (!flags->minus && !flags->zero)
		pad_width(buf, total_pad, 0);
	if (flags->zero && !flags->dot)
	{
		pad_width(buf, total_pad, 1);
		if (!(flags->dot && flags->precision == 0 && n == 0))
			put_unsigned_recursive(buf, (unsigned long)n);
	}
	else
		print_unsigned_precision(buf, n, flags);
	if (flags->minus)
		pad_width(buf, total_pad, 0);
}
