/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:18:41 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/01 12:46:14 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_checkpourcent_error(const char *str, va_list list, int *i, int *len)
{
	if (str[(*i) + 1] == 'd' || str[(*i) + 1] == 'i')
		ft_putnbr_printf_error(va_arg(list, int), len);
	else if (str[(*i) + 1] == 'u')
		ft_putnbr_printf_error(va_arg(list, unsigned int), len);
	else if (str[(*i) + 1] == 'x')
		ft_putnbrhex_printf_error(va_arg(list, unsigned int), len);
	else if (str[(*i) + 1] == 'X')
		ft_putnbrhexupper_error(va_arg(list, unsigned int), len);
	else if (str[(*i) + 1] == 'c')
		ft_putchar_printf_error(va_arg(list, int), len);
	else if (str[(*i) + 1] == 's')
		ft_putstr_printf_error(va_arg(list, char *), len);
	else if (str[(*i) + 1] == 'p')
		ft_pointerisnullornot_error(va_arg(list, unsigned long int), len);
	else if (str[(*i) + 1] == '%')
	{
		write(2, "%", 1);
		*len = *len + 1;
	}	
	else
		(*i)--;
	(*i)++;
}

int	ft_printf_error(const char *str, ...)
{
	int		i;
	int		len;
	va_list	list;

	i = 0;
	len = 0;
	if (str)
	{
		va_start(list, str);
		while (str[i] != 0)
		{
			if (str[i] != '%')
			{
				write(2, &str[i], 1);
				len++;
			}	
			if (str[i] == '%')
			{
				ft_checkpourcent(str, list, &i, &len);
			}	
			i++;
		}
		va_end(list);
	}
	return (len);
}
