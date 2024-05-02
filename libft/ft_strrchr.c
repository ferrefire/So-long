/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:34:29 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:26:30 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	val;
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = -1;
	val = c;
	p = (char *)s;
	while (p[i])
	{
		if (p[i] == val)
			j = i;
		i++;
	}
	if (p[i] == val)
		j = i;
	if (j != -1)
		return (p + j);
	return (NULL);
}
