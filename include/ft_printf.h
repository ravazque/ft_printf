/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:15:22 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/09 16:42:18 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_buffer
{
	char	data[BUFFER_SIZE];
	int		index;
	int		total;
}	t_buffer;

int		ft_printf(const char *format, ...);

void	buffer_init(t_buffer *buf);
void	buffer_add_char(t_buffer *buf, char c);
void	buffer_add_str(t_buffer *buf, char *str, int len);
int		buffer_flush(t_buffer *buf);

void	ft_print_char(t_buffer *buf, int c);
void	ft_print_str(t_buffer *buf, char *str);
void	ft_print_nbr(t_buffer *buf, int n);
void	ft_print_unsigned(t_buffer *buf, unsigned int n);
void	ft_print_hex(t_buffer *buf, unsigned int num, int upper);
void	ft_print_ptr(t_buffer *buf, void *ptr);

#endif
