/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:35:14 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/09 19:22:06 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	handle_conversion(t_buffer *buf, char c, va_list args)
{
	if (c == 'c')
		ft_print_char(buf, va_arg(args, int));
	else if (c == 's')
		ft_print_str(buf, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_print_nbr(buf, va_arg(args, int));
	else if (c == 'u')
		ft_print_unsigned(buf, va_arg(args, unsigned int));
	else if (c == 'x')
		ft_print_hex(buf, va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ft_print_hex(buf, va_arg(args, unsigned int), 1);
	else if (c == 'p')
		ft_print_ptr(buf, va_arg(args, void *));
	else if (c == '%')
		buffer_add_char(buf, '%');
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buf;
	int			i;

	if (!format)
		return (-1);
	buffer_init(&buf);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			handle_conversion(&buf, format[i], args);
		}
		else
			buffer_add_char(&buf, format[i]);
		i++;
	}
	va_end(args);
	buffer_flush(&buf);
	return (buf.total);
}
