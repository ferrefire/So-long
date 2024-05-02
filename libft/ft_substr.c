/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 15:52:39 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:10:21 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	a[100000];
	size_t	i;

	i = -1;
	start--;
	while (ft_strlen(s) > ++start && ((i + 1) < len) && s[start])
		a[++i] = s[start];
	a[++i] = '\0';
	p = ft_strdup((char *)a);
	return (p);
}
