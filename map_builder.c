/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_builder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ferre <ferre@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 17:16:28 by ferre         #+#    #+#                 */
/*   Updated: 2024/05/02 21:46:36 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_valid(int *mv, char *line, t_vars *v)
{
	char	**flood_map;

	if (v->map == NULL)
	{
		*mv = -1;
		v->msx = 1;
		v->msy = 1;
		return ;
	}
	flood_map = ft_split(line, '\n');
	if (v->px == -1 || v->collectables <= 0)
		*mv = -1;
	else if (*mv != -1 && flood_fill_e(v->px, v->py, flood_map, v) == 1)
	{
		clean_arr(flood_map, v->msy);
		flood_map = ft_split(line, '\n');
		flood_fill_c(v->px, v->py, flood_map, v);
		if (v->c_found != v->collectables)
			*mv = -1;
	}
	else
		*mv = -1;
	clean_arr(flood_map, v->msy);
}

int	flood_fill_e(int x, int y, char **floodMap, t_vars *vars)
{
	char	tile;

	if (x < 0 || x >= vars->msx || y < 0 || y >= vars->msy)
		return (0);
	tile = *(*(floodMap + y) + x);
	*(*(floodMap + y) + x) = 'F';
	if (tile == '1' || tile == 'F')
		return (0);
	else if (tile == 'E')
		return (1);
	else if (flood_fill_e(x, y - 1, floodMap, vars) == 1)
		return (1);
	else if (flood_fill_e(x + 1, y, floodMap, vars) == 1)
		return (1);
	else if (flood_fill_e(x, y + 1, floodMap, vars) == 1)
		return (1);
	else if (flood_fill_e(x - 1, y, floodMap, vars) == 1)
		return (1);
	return (0);
}

void	flood_fill_c(int x, int y, char **floodMap, t_vars *vars)
{
	char	tile;

	if (x < 0 || x >= vars->msx || y < 0 || y >= vars->msy)
		return ;
	tile = *(*(floodMap + y) + x);
	*(*(floodMap + y) + x) = 'F';
	if (tile == 'C')
		vars->c_found++;
	if (!(tile == '1' || tile == 'F' || tile == 'E'))
	{
		flood_fill_c(x, y - 1, floodMap, vars);
		flood_fill_c(x + 1, y, floodMap, vars);
		flood_fill_c(x, y + 1, floodMap, vars);
		flood_fill_c(x - 1, y, floodMap, vars);
	}
}

int	build_map(int fd, t_vars *vars)
{
	char	*line;
	int		map_valid;
	int		x;
	int		y;

	line = get_map_line(fd, vars);
	y = -1;
	while (++y < vars->msy && map_valid != -1)
	{
		x = -1;
		while (++x < vars->msx && map_valid != -1)
		{
			check_map_tile(x, y, &map_valid, vars);
		}
	}
	is_map_valid(&map_valid, line, vars);
	free(line);
	return (map_valid);
}

void	set_tiles(t_vars *v)
{
	int		y;
	int		x;
	char	*path;
	void	*img;

	clear_tiles(v);
	y = 0;
	while (y < v->msy)
	{
		x = 0;
		while (x < v->msx)
		{
			path = get_tile(x, y, v);
			img = mlx_xpm_file_to_image(v->mlx, path, &v->img_w, &v->img_h);
			free(path);
			mlx_put_image_to_window(v->mlx, v->win, img, 32 * x, 32 * y);
			ft_lstadd_back(&(v->imgs), ft_lstnew(img));
			x++;
		}
		y++;
	}
}
