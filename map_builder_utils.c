/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_builder_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/02 17:11:19 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/02 21:12:13 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	print_map(char **map, t_vars *vars)
//{
//	int	j;
//
//	j = 0;
//	while (j < vars->msy)
//	{
//		ft_printf("%s\n", *(map + j));
//		j++;
//	}
//}
char	*get_tile(int x, int y, t_vars *vars)
{
	char	type;

	if (x < 0 || x >= vars->msx || y < 0 || y >= vars->msy)
		type = 'N';
	else
		type = (*(*(vars->map + y) + x));
	if (type == '1')
	{
		if (x == 0 || x == vars->msx - 1 || y == 0 || y == vars->msy - 1)
			return (ft_strdup(ROCK));
		else
			return (ft_strdup(WATER));
	}
	else if (type == 'P')
		return (ft_strdup(PLAYER));
	else if (type == 'C')
		return (ft_strdup(COLLECT));
	else if (type == 'E')
		return (ft_strdup(EXIT));
	else
		return (get_grass_type(x, y, vars));
}

char	*get_map_line(int fd, t_vars *vars)
{
	char	*line;
	char	*temp;
	int		x;

	line = get_next_line(fd);
	temp = get_next_line(fd);
	x = 0;
	while (temp != NULL)
	{
		x++;
		line = comb(line, temp);
		temp = get_next_line(fd);
	}
	vars->msy = x + 1;
	if (x > 0)
	{
		vars->map = ft_split(line, '\n');
		vars->msx = ft_strlen(*(vars->map));
	}
	return (line);
}

void	check_map_tile(int x, int y, int *map_valid, t_vars *vars)
{
	char	type;

	if (x < 0 || x >= vars->msx || y < 0 || y >= vars->msy)
		type = 'N';
	else
		type = (*(*(vars->map + y) + x));
	if (((x == 0 || x == vars->msx - 1 || y == 0 || y == vars->msy - 1)
			&& type != '1') || (int)ft_strlen(*(vars->map + y)) != vars->msx)
		*map_valid = -1;
	if (type == 'P')
	{
		if (vars->px != -1)
			*map_valid = -1;
		vars->py = y;
		vars->px = x;
	}
	else if (type == 'C')
		vars->collectables++;
}

char	*get_grass_type(int x, int y, t_vars *vars)
{
	char	*grass_type;

	grass_type = ft_strdup(GRASS);
	if (*(*(vars->map + y - 1) + x) != '0')
		grass_type = comb(grass_type, ft_strdup("N"));
	if (*(*(vars->map + y) + x + 1) != '0')
		grass_type = comb(grass_type, ft_strdup("E"));
	if (*(*(vars->map + y + 1) + x) != '0')
		grass_type = comb(grass_type, ft_strdup("S"));
	if (*(*(vars->map + y) + x - 1) != '0')
		grass_type = comb(grass_type, ft_strdup("W"));
	grass_type = comb(grass_type, ft_strdup(".xpm"));
	return (grass_type);
}

t_vars	*setup_vars(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->collectables = 0;
	vars->movements = 0;
	vars->c_found = 0;
	vars->msx = 0;
	vars->msy = 0;
	vars->px = -1;
	vars->py = -1;
	return (vars);
}
