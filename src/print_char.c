/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:30:45 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/07 14:22:33 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_char(t_buffer *buf, int c)
{
	buffer_add_char(buf, (char)c);
}

void	ft_print_str(t_buffer *buf, char *str)
{
	int	len;

	if (!str)
	{
		buffer_add_str(buf, "(null)", 6);
		return ;
	}
	len = 0;
	while (str[len])
		len++;
	buffer_add_str(buf, str, len);
}
