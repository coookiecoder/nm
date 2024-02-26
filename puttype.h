/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttype.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abareux <abareux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:03:10 by abareux           #+#    #+#             */
/*   Updated: 2024/02/26 10:57:13 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elf.h>
#include <unistd.h>

#include "utils.h"

void	puttype_64(Elf64_Sym symbole, Elf64_Ehdr file_eheader, void *file_data);
