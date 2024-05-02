/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 16:01:58 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:04:28 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char			a[100];
	long long int	j;
	int				i;
	char			*p;
	int				k;

	i = -1;
	k = -1;
	j = n;
	if (j < 0)
		k += ((j *= -1) * 0) + 1;
	a[++i] = (j % 10) + '0';
	while (j >= 10)
		a[++i] = ((j /= 10) % 10) + '0';
	a[++i] = j + '0';
	a[++i] = '\0';
	p = malloc(--i + k + 2);
	if (!p)
		return (NULL);
	if (k == 0)
		p[k] = '-';
	while (i-- > 0)
		p[++k] = a[i];
	p[++k] = '\0';
	return (p);
}
