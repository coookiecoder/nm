/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:41:16 by abareux           #+#    #+#             */
/*   Updated: 2024/02/24 15:56:50 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	char	*start;

	start = str;
	while (*str)
		str++;
	return (str - start);
}

int	not_found(char *file)
{
	write(2, "nm: '", 5);
	write(2, file, ft_strlen(file));
	write(2, "': No such file\n", 16);
	return (1);
}

int	not_recognized(char *file)
{
	write(2, "nm: '", 5);
	write(2, file, ft_strlen(file));
	write(2, "': No such file\n", 16);
	return (1);
}

int	no_symbol(char *file)
{
	write(2, "nm: '", 5);
	write(2, file, ft_strlen(file));
	write(2, "': no symbols\n", 14);
	return (1);
}

static
char	get_digit(void *ptr, int digit)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
	while (digit)
	{
		number = number / 16;
		digit--;
	}
	number = number % 16;
	if (number <= 9)
		return (number + '0');
	else
		return (number - 10 + 'a');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putptr(void *ptr)
{
	int	digit = 15;
	int	result = 2;
	int	start_print = 0;

	if (!ptr)
		return (write(1, "                ", 16));
	while (digit >= 0)
	{
		ft_putchar(get_digit(ptr, digit));
		start_print = 1;
		result++;
		digit--;
	}
	return (result);
}
