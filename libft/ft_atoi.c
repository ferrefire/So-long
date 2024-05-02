/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:25:28 by fmolenbe      #+#    #+#                 */
/*   Updated: 2023/08/28 16:03:40 by fmolenbe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	total;
	int	i;
	int	m;

	total = 0;
	i = -1;
	m = 1;
	while (str[++i])
		if (!((str[i] > 8 && str[i] < 14) || str[i] == 32))
			break ;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		else
			m = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		total *= 10;
		total += (str[i] - '0');
		i++;
	}
	return (total * m);
}
