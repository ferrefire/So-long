/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:28:53 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:05:22 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	if (!src && !dst)
		return (NULL);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
