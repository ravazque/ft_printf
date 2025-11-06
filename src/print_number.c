/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 18:20:31 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	put_number_recursive(t_buffer *buf, long n)
{
	if (n >= 10)
		put_number_recursive(buf, n / 10);
	buffer_add_char(buf, (n % 10) + '0');
}

static int	get_num_width(int n, t_flags *flags)
{
	int	width;

	if (flags->dot && flags->precision == 0 && n == 0)
		width = 0;
	else
		width = ft_numlen(n, 10);
	if (flags->dot && flags->precision > width)
		width = flags->precision;
	if (n < 0)
		width++;
	else if (flags->plus || flags->space)
		width++;
	return (width);
}

static void	print_number_with_precision(t_buffer *buf, long n, t_flags *flags)
{
	int	numlen;
	int	precision_pad;

	numlen = ft_numlen(n, 10);
	if (n < 0)
		numlen--;
	precision_pad = 0;
	if (flags->precision > numlen)
		precision_pad = flags->precision - numlen;
	put_sign(buf, n, flags);
	if (n < 0)
		n = -n;
	while (precision_pad > 0)
	{
		buffer_add_char(buf, '0');
		precision_pad--;
	}
	if (!(flags->dot && flags->precision == 0 && n == 0))
		put_number_recursive(buf, n);
}

void	print_nbr(t_buffer *buf, t_flags *flags, int n)
{
	int		total_width;
	int		num_width;
	long	ln;

	ln = n;
	num_width = get_num_width(n, flags);
	total_width = flags->width - num_width;
	if (!flags->minus && !flags->zero)
		pad_width(buf, total_width, 0);
	if (flags->zero && !flags->dot)
	{
		put_sign(buf, n, flags);
		if (ln < 0)
			ln = -ln;
		pad_width(buf, total_width, 1);
		if (!(flags->dot && flags->precision == 0 && n == 0))
			put_number_recursive(buf, ln);
	}
	else
		print_number_with_precision(buf, ln, flags);
	if (flags->minus)
		pad_width(buf, total_width, 0);
}

void	print_unsigned(t_buffer *buf, t_flags *flags, unsigned int n)
{
	t_flags	temp_flags;
	int		i;

	i = 0;
	while (i < (int)sizeof(t_flags))
	{
		((char *)&temp_flags)[i] = ((char *)flags)[i];
		i++;
	}
	temp_flags.plus = 0;
	temp_flags.space = 0;
	print_nbr(buf, &temp_flags, (int)n);
}
