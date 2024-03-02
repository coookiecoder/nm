/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:03:10 by abareux           #+#    #+#             */
/*   Updated: 2024/03/02 12:51:05 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elf.h>
#include <unistd.h>

#include "utils.h"

void	puttype_32(Elf32_Sym symbole, Elf32_Ehdr file_eheader, void *file_data);
void	puttype_64(Elf64_Sym symbole, Elf64_Ehdr file_eheader, void *file_data);
