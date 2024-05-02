/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 16:32:18 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:06:58 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char				a[100];
	long long int		j;
	int					i;

	i = -1;
	j = n;
	if (j < 0)
		write(fd, "-", 1);
	if (j < 0)
		j *= -1;
	a[++i] = (j % 10) + '0';
	while (j >= 10)
		a[++i] = ((j /= 10) % 10) + '0';
	a[++i] = j + '0';
	while (i-- > 0)
		write(fd, &a[i], 1);
}
