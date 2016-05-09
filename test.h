/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtASM.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 15:16:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/07 16:32:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

#include <string.h>
/*
**	qword			dword		word	byte
** 	64				32			16		[8	8]
** -
** 	rax				eax			ax		ah	al 		Return 1
** 	rbx				ebx			bx		bh	bl 		(Callee saved)
** 	rcx				ecx			cx		ch	cl 		Arg 4 + Counter
** 	rdx				edx			dx		dh	dl 		Arg 3 + Return 2
** 	rsi				esi			si			sil		Arg 2
** 	rdi				edi			di			dil		Arg 1
** 	rbp				ebp			bp			bpl		(Callee saved)
** 	rsp				esp			sp			spl		Stack ptr (Callee saved)
** 	r8				r8d			r8w			r8b		Arg 5
** 	r9				r9d			r9w			r9b		Arg 6
** 	r10				r10d		r10w		r10b	Arg 7
** 	r11				r11d		r11w		r11b	Tmp
** 	r12				r12d		r12w		r12b	(Callee saved)
** 	r13				r13d		r13w		r13b	(Callee saved)
** 	r14				r14d		r14w		r14b	(Callee saved)
** 	r15				r15d		r15w		r15b	(Callee saved)
*/

void	ft_bzero(void *ptr, int n);
char	*ft_strcat(const char *s1, char*s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strlen(const char *s);
int		ft_puts(const char *s);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t len);
char	*ft_strdup(void *s1);
void	ft_cat(int fd);

#endif
