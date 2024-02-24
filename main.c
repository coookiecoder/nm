/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:41:27 by abareux           #+#    #+#             */
/*   Updated: 2024/02/24 15:55:06 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <utils.h>
#include <show_symbol.h>

#define FD_ERROR -1

#define ERROR 0

void	*load_file(char *path, unsigned long long *file_size)
{
	int fd = open(path, O_RDONLY);

	if (fd == FD_ERROR)
		return (ERROR);

	struct stat file_stat;

	if (fstat(fd, &file_stat) < 0)
		return (ERROR);

	void *file_data = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	*file_size = file_stat.st_size;

	close(fd);

	return (file_data);
}

int	identify(char *file_data)
{
	if (file_data[0] != 0x7f)
		return (0);
	if (file_data[1] != 0x45)
		return (0);
	if (file_data[2] != 0x4c)
		return (0);
	if (file_data[3] != 0x46)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	char				*file_data;
	unsigned long long	file_size;
	int					cursor = 0;
	unsigned char		return_value = 0;

	if (argc == 1)
	{
		file_data = load_file("a.out", &file_size);

		if (file_data == ERROR)
			return (not_found("a.out"));
		
		if (!identify(file_data))
			return (not_recognized("a.out"));

		show_symbol(file_data);

		munmap(file_data, file_size);

		return (0);
	}
	
	while (cursor < argc - 1)
	{
		file_data = load_file(argv[cursor + 1], &file_size);
	
		if (file_data == ERROR)
			return_value = not_found(argv[cursor + 1]);

		else if (file_data && !identify(file_data))
			return_value = not_recognized(argv[cursor + 1]);

		else if (file_data)
		{
			if (argc > 2)
			{
				write(1, "\n", 1);
				write(1, argv[cursor + 1], ft_strlen(argv[cursor + 1]));
				write(1, ":\n", 2);
			}

			if (show_symbol(file_data) == 1)
				no_symbol(argv[cursor + 1]);

			munmap(file_data, file_size);
		}

		cursor++;
	}

	return (return_value);
}
