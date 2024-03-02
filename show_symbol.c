/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_symbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:46:36 by abareux           #+#    #+#             */
/*   Updated: 2024/03/02 12:58:12 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <elf.h>

#include "utils.h"
#include "puttype.h"

#include <stdio.h>

int	show_symbol_32(void *file_data)
{
	Elf32_Ehdr	*file_eheader = file_data;
	Elf32_Shdr	*file_sheader;
	Elf32_Shdr	*file_symtab_header = NULL;
	Elf32_Shdr	*file_str_symtab_header = NULL;

	for (int cursor = 1; cursor < file_eheader->e_shnum; cursor++)
	{
		file_sheader = file_data + file_eheader->e_shoff + file_eheader->e_shentsize * cursor;
		if (file_sheader->sh_type == SHT_SYMTAB)
			file_symtab_header = file_sheader;
	}

	if (!file_symtab_header)
		return (1);

	file_str_symtab_header = file_data + file_eheader->e_shoff + file_eheader->e_shentsize * file_symtab_header->sh_link;

	Elf32_Sym	*symtab = file_data + file_symtab_header->sh_offset;

	symtab++;

	for (int cursor = 1; cursor < (int) file_symtab_header->sh_size / 24; cursor++)
	{
		char *name = file_data + file_str_symtab_header->sh_offset + symtab->st_name;
		if (!((name[ft_strlen(name) - 1] == 'o' || name[ft_strlen(name) - 1] == 'c') && name[ft_strlen(name) - 2] == '.') && name[0])
		{
			ft_putptr((void *) (unsigned long) symtab->st_value);
			write(1, " ", 1);
			puttype_32(*symtab, *file_eheader, file_data);
			write(1, " ", 1);
			write(1, name, ft_strlen(name));
			write(1, "\n", 1);
		}
		symtab++;
	}
	return (0);
}

int	show_symbol_64(void *file_data)
{
	Elf64_Ehdr	*file_eheader = file_data;
	Elf64_Shdr	*file_sheader;
	Elf64_Shdr	*file_symtab_header = NULL;
	Elf64_Shdr	*file_str_symtab_header = NULL;

	for (int cursor = 1; cursor < file_eheader->e_shnum; cursor++)
	{
		file_sheader = file_data + file_eheader->e_shoff + file_eheader->e_shentsize * cursor;
		if (file_sheader->sh_type == SHT_SYMTAB)
			file_symtab_header = file_sheader;
	}

	if (!file_symtab_header)
		return (1);

	file_str_symtab_header = file_data + file_eheader->e_shoff + file_eheader->e_shentsize * file_symtab_header->sh_link;

	Elf64_Sym *symtab = file_data + file_symtab_header->sh_offset;

	symtab++;

	for (int cursor = 1; cursor < (int) file_symtab_header->sh_size / 24; cursor++)
	{
		char *name = file_data + file_str_symtab_header->sh_offset + symtab->st_name;
		if (!((name[ft_strlen(name) - 1] == 'o' || name[ft_strlen(name) - 1] == 'c') && name[ft_strlen(name) - 2] == '.') && name[0])
		{
			ft_putptr((void *) (unsigned long) symtab->st_value);
			write(1, " ", 1);
			puttype_64(*symtab, *file_eheader, file_data);
			write(1, " ", 1);
			write(1, name, ft_strlen(name));
			write(1, "\n", 1);
		}
		symtab++;
	}
	return (0);
}

int	show_symbol(char *file_data)
{

	if (file_data[4] == 1)
		return (show_symbol_32(file_data));
	else if (file_data[4] == 2)
		return (show_symbol_64(file_data));
	else
		return (2);
}
