/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:34:29 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:04:56 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;
	unsigned char	val;

	i = 0;
	p = (unsigned char *)s1;
	val = c;
	while ((int)n-- > 0)
	{
		if (p[i] == val)
			return (p + i);
		i++;
	}
	return (NULL);
}
