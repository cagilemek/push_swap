/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:01:08 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 14:37:30 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_hexa(unsigned long nb, char *base);
int	ft_unputnbr(unsigned int nb);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_address(void *p);

#endif