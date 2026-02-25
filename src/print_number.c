/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:45:10 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/08 17:15:41 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_put_digits(t_buffer *buf, unsigned long n)
{
	if (n >= 10)
		ft_put_digits(buf, n / 10);
	buffer_add_char(buf, (n % 10) + '0');
}

void	ft_print_nbr(t_buffer *buf, int n)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		buffer_add_char(buf, '-');
		ln = -ln;
	}
	ft_put_digits(buf, (unsigned long)ln);
}

static void	ft_put_unsigned(t_buffer *buf, unsigned long n)
{
	if (n >= 10)
		ft_put_unsigned(buf, n / 10);
	buffer_add_char(buf, (n % 10) + '0');
}

void	ft_print_unsigned(t_buffer *buf, unsigned int n)
{
	ft_put_unsigned(buf, (unsigned long)n);
}
