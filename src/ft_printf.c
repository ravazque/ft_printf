/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 00:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	handle_conversion(t_buffer *buf, t_flags *flags, char c,
		va_list args)
{
	if (c == 'c')
		print_char(buf, flags, va_arg(args, int));
	else if (c == 's')
		print_str(buf, flags, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		print_nbr(buf, flags, va_arg(args, int));
	else if (c == 'u')
		print_unsigned(buf, flags, va_arg(args, unsigned int));
	else if (c == 'x')
		print_hex(buf, flags, va_arg(args, unsigned int), 0);
	else if (c == 'X')
		print_hex(buf, flags, va_arg(args, unsigned int), 1);
	else if (c == 'p')
		print_ptr(buf, flags, va_arg(args, void *));
	else if (c == '%')
		print_percent(buf, flags);
}

static void	process_format(t_buffer *buf, const char *format, va_list args)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			parse_flags(format, &i, &flags, args);
			if (is_conversion(format[i]))
			{
				handle_conversion(buf, &flags, format[i], args);
				i++;
			}
		}
		else
		{
			buffer_add_char(buf, format[i]);
			i++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_buffer	buf;

	if (!format)
		return (-1);
	buffer_init(&buf);
	va_start(args, format);
	process_format(&buf, format, args);
	va_end(args);
	buffer_flush(&buf);
	return (buf.total);
}
