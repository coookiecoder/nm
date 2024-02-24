/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_symbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:46:36 by abareux           #+#    #+#             */
/*   Updated: 2024/02/24 13:21:18 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <elf.h>

#include <utils.h>

void	show_symbol_32(void *file_data)
{
	Elf32_Ehdr *file_eheader = file_data;
	Elf32_Phdr *file_pheader = file_data + file_eheader->e_phoff;
	Elf32_Shdr *file_sheader = file_data + file_eheader->e_shoff;
	(void) file_pheader;
	(void) file_sheader;
}

void	show_symbol_64(void *file_data)
{
	Elf64_Ehdr	*file_eheader = file_data;
	Elf64_Shdr	*file_sheader;
	Elf64_Sym	*file_symtab = NULL;

	for (int cursor = 1; cursor < file_eheader->e_shnum; cursor++)
	{
		file_sheader = file_data + file_eheader->e_shoff + file_eheader->e_shentsize * cursor;
		if (file_sheader->sh_type == SHT_SYMTAB)
			file_symtab = (void *) file_sheader;
	}
}

void	show_symbol(char *file_data)
{

	if (file_data[4] == 1)
		show_symbol_32(file_data);
	else if (file_data[4] == 2)
		show_symbol_64(file_data);
	else
		return ; // THE FUCK I'M SUPOSSED TO DO
}
