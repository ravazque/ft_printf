/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:06:58 by ravazque          #+#    #+#             */
/*   Updated: 2024/10/22 11:33:41 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_enter_str(va_list args, const char enter_str)
{
	int	len;

	len = 0;
	if (enter_str == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (enter_str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (enter_str == 'd' || enter_str == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (enter_str == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (enter_str == 'x' || enter_str == 'X')
		len += ft_puthex(va_arg(args, unsigned int), enter_str);
	else if (enter_str == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (enter_str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *enter_str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, enter_str);
	while (enter_str[i])
	{
		if (enter_str[i] == '%' && enter_str[i + 1])
		{
			len += ft_enter_str(args, enter_str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(enter_str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
