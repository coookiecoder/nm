/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_symbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:46:36 by abareux           #+#    #+#             */
/*   Updated: 2024/02/22 14:24:09 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <elf.h>

void	load_32(char *file_data, Elf32_Ehdr *file_header)
{
	// magic number
	file_header->e_ident[EI_MAG0] = file_data[0];
	file_header->e_ident[EI_MAG1] = file_data[1];
	file_header->e_ident[EI_MAG2] = file_data[2];
	file_header->e_ident[EI_MAG3] = file_data[3];
	// file class
	file_header->e_ident[EI_CLASS] = file_data[4];
	// data encoding
	file_header->e_ident[EI_DATA] = file_data[5];
	// file version
	file_header->e_ident[EI_VERSION] = file_data[6];
	// Operating System
	file_header->e_ident[EI_OSABI] = file_data[7];
	// ABI version
	file_header->e_ident[EI_ABIVERSION] = file_data[8];
	// Padding byte start, those byte have to be ignored && set to 0
	file_header->e_ident[EI_PAD] = 0;
	file_header->e_ident[10] = 0;
	file_header->e_ident[11] = 0;
	file_header->e_ident[12] = 0;
	file_header->e_ident[13] = 0;
	file_header->e_ident[14] = 0;
	file_header->e_ident[15] = 0;
}

void	load_64(char *file_data, Elf64_Ehdr *file_header)
{
	// magic number
	file_header->e_ident[EI_MAG0] = file_data[0];
	file_header->e_ident[EI_MAG1] = file_data[1];
	file_header->e_ident[EI_MAG2] = file_data[2];
	file_header->e_ident[EI_MAG3] = file_data[3];
	// file class
	file_header->e_ident[EI_CLASS] = file_data[4];
	// data encoding
	file_header->e_ident[EI_DATA] = file_data[5];
	// file version
	file_header->e_ident[EI_VERSION] = file_data[6];
	// Operating System
	file_header->e_ident[EI_OSABI] = file_data[7];
	// ABI version
	file_header->e_ident[EI_ABIVERSION] = file_data[8];
	// Padding byte start, those byte have to be ignored && set to 0
	file_header->e_ident[EI_PAD] = 0;
	file_header->e_ident[10] = 0;
	file_header->e_ident[11] = 0;
	file_header->e_ident[12] = 0;
	file_header->e_ident[13] = 0;
	file_header->e_ident[14] = 0;
	file_header->e_ident[15] = 0;
}

void	show_symbol(char *file_data)
{
	int	x86 = 0;
	int	x64 = 0;

	if (file_data[5] == 1)
	{
		Elf32_Ehdr file_header;
		load_32(file_data, &file_header);
		x86 = 1;
	}
	else if (file_data[5] == 2)
	{
		Elf64_Ehdr file_header;
		load_64(file_data, &file_header);
		x64 = 1;
	}
	else
	{
		write(2, "ayo wtf\n", 8);
		return ;
	}

}
