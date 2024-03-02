/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:01:38 by abareux           #+#    #+#             */
/*   Updated: 2024/03/02 12:46:05 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puttype.h"

#include <stdio.h>
#include <elf.h>

void	puttype_64(Elf64_Sym symbol, Elf64_Ehdr file_eheader, void *file_data)
{
//	unsigned char	type = ELF64_ST_TYPE(symbol.st_info);
	unsigned char	bind = ELF64_ST_BIND(symbol.st_info);
//	unsigned char	info = ELF64_ST_INFO(bind, type);
	Elf64_Shdr		*linked_section_header = file_data + file_eheader.e_shoff + file_eheader.e_shentsize * symbol.st_shndx;
//	Elf64_Shdr		*str_section_header = file_data + file_eheader.e_shoff + file_eheader.e_shentsize * file_eheader.e_shstrndx;
	
	if (symbol.st_shndx == SHN_ABS)
		write(1, "A", 1);

	else if (linked_section_header->sh_type == SHT_NOBITS && bind == STB_GLOBAL)
		write(1, "B", 1);
	else if (linked_section_header->sh_type == SHT_NOBITS && bind == STB_LOCAL)
		write(1, "b", 1);
	
	else if (bind == STB_WEAK && linked_section_header->sh_flags != 0)
		write(1, "W", 1);
	else if (bind == STB_WEAK)
		write(1, "w", 1);

	else if (symbol.st_shndx == SHN_UNDEF)
		write(1, "U", 1);

	else if (!(linked_section_header->sh_flags & SHF_WRITE))
	{
		if (linked_section_header->sh_flags & SHF_ALLOC && linked_section_header->sh_flags & SHF_EXECINSTR && bind == STB_GLOBAL)
			write(1, "T", 1);
		else if (linked_section_header->sh_flags & SHF_ALLOC && linked_section_header->sh_flags & SHF_EXECINSTR && bind == STB_LOCAL)
			write(1, "t", 1);
		else if (bind == STB_GLOBAL)
			write(1, "R", 1);
		else if (bind == STB_LOCAL)
			write(1, "r", 1);
	}
	
	else if (symbol.st_shndx && bind == STB_GLOBAL)
		write(1, "D", 1);
	else if (symbol.st_shndx && bind == STB_LOCAL)
		write(1, "d", 1);
}
