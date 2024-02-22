/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:41:16 by abareux           #+#    #+#             */
/*   Updated: 2024/02/22 13:43:51 by abareux          ###   ########.fr       */
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

