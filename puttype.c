/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:01:38 by abareux           #+#    #+#             */
/*   Updated: 2024/02/24 17:39:31 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puttype.h"
#include <elf.h>

void	puttype_64(Elf64_Sym symbol)
{
	unsigned char type = ELF64_ST_TYPE(symbol.st_info);
	unsigned char bind = ELF64_ST_BIND(symbol.st_info);
//	unsigned char info = ELF64_ST_INFO(bind, type);

	if (symbol.st_shndx == SHN_ABS)
		write(1, "A", 1);
	else if (0)
		write(1, "B", 1);
	else if (0)
		write(1, "b", 1);
	else if (type == STT_COMMON && bind == STB_GLOBAL)
		write(1, "C", 1);
	else if (type == STT_COMMON && bind == STB_LOCAL)
		write(1, "c", 1);
	else if (type == STT_OBJECT && bind == STB_GLOBAL)
		write(1, "D", 1);
	else if (type == STT_OBJECT && bind == STB_LOCAL)
		write(1, "d", 1);
	else if (0)
		write(1, "G", 1);
	else if (0)
		write(1, "g", 1);
	else if (0)
		write(1, "i", 1);
	else if (0)
		write(1, "I", 1);
	else if (0)
		write(1, "N", 1);
	else if (0)
		write(1, "n", 1);
	else if (0)
		write(1, "p", 1);
	else if (0)
		write(1, "R", 1);
	else if (0)
		write(1, "r", 1);
	else if (0)
		write(1, "S", 1);
	else if (0)
		write(1, "s", 1);
	else if (0)
		write(1, "T", 1);
	else if (0)
		write(1, "t", 1);
	else if (0)
		write(1, "U", 1);
	else if (0)
		write(1, "u", 1);
	else if (0)
		write(1, "V", 1);
	else if (0)
		write(1, "v", 1);
	else if (0)
		write(1, "W", 1);
	else if (0)
		write(1, "w", 1);
	else if (0)
		write(1, "-", 1);
	else	
		write(1, "?", 1);
}
