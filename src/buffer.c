/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 00:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	buffer_init(t_buffer *buf)
{
	buf->index = 0;
	buf->total = 0;
}

int	buffer_flush(t_buffer *buf)
{
	int	written;

	written = 0;
	if (buf->index > 0)
	{
		written = write(1, buf->data, buf->index);
		buf->index = 0;
	}
	return (written);
}

void	buffer_add_char(t_buffer *buf, char c)
{
	if (buf->index >= BUFFER_SIZE)
		buffer_flush(buf);
	buf->data[buf->index] = c;
	buf->index++;
	buf->total++;
}

void	buffer_add_str(t_buffer *buf, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		buffer_add_char(buf, str[i]);
		i++;
	}
}
