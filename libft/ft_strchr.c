/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:34:29 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:07:22 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	val;
	int		i;
	char	*p;

	i = 0;
	val = c;
	p = (char *)s;
	while (p[i])
	{
		if (p[i] == val)
			return (p + i);
		i++;
	}
	if (p[i] == val)
		return (p + i);
	return (NULL);
}
