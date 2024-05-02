/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 17:20:25 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:08:52 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = -1;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[++i])
		p[i] = (*f)(i, s[i]);
	p[i] = '\0';
	return (p);
}
