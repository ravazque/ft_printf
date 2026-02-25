/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:05:33 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 17:35:44 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

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

void	flags_init(t_flags *flags);
int		parse_flags(const char *format, int *i, t_flags *flags, va_list args);

void	print_char(t_buffer *buf, t_flags *flags, char c);
void	print_str(t_buffer *buf, t_flags *flags, char *str);
void	print_nbr(t_buffer *buf, t_flags *flags, int n);
void	print_unsigned(t_buffer *buf, t_flags *flags, unsigned int n);
void	print_hex(t_buffer *buf, t_flags *flags, unsigned long num, int upper);
void	print_ptr(t_buffer *buf, t_flags *flags, void *ptr);
void	print_percent(t_buffer *buf, t_flags *flags);

int		ft_strlen(char *str);
int		ft_numlen(long n, int base);
int		ft_atoi(const char *str);
int		is_flag(char c);
int		is_conversion(char c);

void	pad_width(t_buffer *buf, int width, int zero);
void	put_sign(t_buffer *buf, int n, t_flags *flags);
void	put_prefix(t_buffer *buf, t_flags *flags, int upper);

#endif
