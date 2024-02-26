/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:01:38 by abareux           #+#    #+#             */
/*   Updated: 2024/02/26 12:53:46 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puttype.h"
#include <elf.h>

void	puttype_64(Elf64_Sym symbol, Elf64_Ehdr file_eheader, void *file_data)
{
//	unsigned char	type = ELF64_ST_TYPE(symbol.st_info);
	unsigned char	bind = ELF64_ST_BIND(symbol.st_info);
//	unsigned char	info = ELF64_ST_INFO(bind, type);
	Elf64_Shdr		*linked_section_header = file_data + file_eheader.e_shoff + file_eheader.e_shentsize * symbol.st_shndx;
	Elf64_Shdr		*str_section_header = file_data + file_eheader.e_shoff + file_eheader.e_shentsize * file_eheader.e_shstrndx;

	if (linked_section_header->sh_name > 0)
	{
		if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".bss") == 0 && bind == STB_GLOBAL)
			write(1, "B", 1);
		else if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".bss") == 0 && bind == STB_LOCAL)
			write(1, "b", 1);
		else if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".data") == 0 && bind == STB_GLOBAL)
			write(1, "D", 1);
		else if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".data") == 0 && bind == STB_LOCAL)
			write(1, "d", 1);
		else if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".stab") == 0)
			write(1, "N", 1);
		else if (ft_strncmp(file_data + str_section_header->sh_offset + linked_section_header->sh_name, ".stabstr") == 0)
			write(1, "N", 1);
		else
			write(1, "?", 1);
	}
}
