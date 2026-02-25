/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:50:33 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/16 14:35:19 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	print_char(t_buffer *buf, t_flags *flags, char c)
{
	if (!flags->minus)
		pad_width(buf, flags->width - 1, 0);
	buffer_add_char(buf, c);
	if (flags->minus)
		pad_width(buf, flags->width - 1, 0);
}

void	print_str(t_buffer *buf, t_flags *flags, char *str)
{
	int	len;
	int	i;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->dot && flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	if (!flags->minus)
		pad_width(buf, flags->width - len, 0);
	i = 0;
	while (i < len)
	{
		buffer_add_char(buf, str[i]);
		i++;
	}
	if (flags->minus)
		pad_width(buf, flags->width - len, 0);
}

void	print_percent(t_buffer *buf, t_flags *flags)
{
	if (!flags->minus)
		pad_width(buf, flags->width - 1, 0);
	buffer_add_char(buf, '%');
	if (flags->minus)
		pad_width(buf, flags->width - 1, 0);
}
