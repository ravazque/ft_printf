/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:25:17 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/14 18:10:22 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	pad_width(t_buffer *buf, int width, int zero)
{
	char	pad_char;

	if (zero)
		pad_char = '0';
	else
		pad_char = ' ';
	while (width > 0)
	{
		buffer_add_char(buf, pad_char);
		width--;
	}
}

void	put_sign(t_buffer *buf, int n, t_flags *flags)
{
	if (n < 0)
		buffer_add_char(buf, '-');
	else if (flags->plus)
		buffer_add_char(buf, '+');
	else if (flags->space)
		buffer_add_char(buf, ' ');
}

void	put_prefix(t_buffer *buf, t_flags *flags, int upper)
{
	if (flags->hash)
	{
		buffer_add_char(buf, '0');
		if (upper)
			buffer_add_char(buf, 'X');
		else
			buffer_add_char(buf, 'x');
	}
}
