/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 18:20:41 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	flags_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = -1;
}

static void	parse_flag_chars(const char *format, int *i, t_flags *flags)
{
	while (is_flag(format[*i]))
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == '.')
		{
			flags->dot = 1;
			break ;
		}
		(*i)++;
	}
}

static void	parse_width(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		(*i)++;
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->width = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
}

static void	parse_precision(const char *format, int *i, t_flags *flags,
		va_list args)
{
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		if (format[*i] == '*')
		{
			flags->precision = va_arg(args, int);
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			flags->precision = ft_atoi(&format[*i]);
			while (format[*i] >= '0' && format[*i] <= '9')
				(*i)++;
		}
		else
			flags->precision = 0;
	}
}

int	parse_flags(const char *format, int *i, t_flags *flags, va_list args)
{
	flags_init(flags);
	parse_flag_chars(format, i, flags);
	parse_width(format, i, flags, args);
	parse_precision(format, i, flags, args);
	if (flags->minus)
		flags->zero = 0;
	return (*i);
}
