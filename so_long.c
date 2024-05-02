/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <fmolenbe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:02:00 by fmolenbe      #+#    #+#                 */
/*   Updated: 2024/05/02 21:11:51 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_tiles(t_vars *vars)
{
	t_list	*lst;
	t_list	*temp;

	if (vars->imgs == NULL)
		return ;
	lst = vars->imgs;
	while (lst)
	{
		temp = lst->next;
		mlx_destroy_image(vars->mlx, lst->content);
		free(lst);
		lst = temp;
	}
	vars->imgs = NULL;
}

int	quit(t_vars *vars, char *error)
{
	clear_tiles(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	if (vars->map != NULL)
		clean_arr(vars->map, vars->msy);
	if (error != NULL)
	{
		error = comb(ft_strdup("Error\n"), ft_strdup(error));
		perror(error);
		free(error);
	}
	free(vars);
	exit(0);
	return (0);
}

void	move_player(int x, int y, t_vars *vars)
{
	if (*(*(vars->map + y) + x) == 'C')
		vars->collectables--;
	else if (*(*(vars->map + y) + x) == 'E' && vars->collectables <= 0)
	{
		ft_printf("Finished in %d moves\n", vars->movements + 1);
		quit(vars, NULL);
	}
	else if (*(*(vars->map + y) + x) != '0')
		return ;
	*(*(vars->map + y) + x) = 'P';
	*(*(vars->map + vars->py) + vars->px) = '0';
	vars->px = x;
	vars->py = y;
	vars->movements++;
	ft_printf("Number of moves: %d\n", vars->movements);
	set_tiles(vars);
}

int	receive_input(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		quit(vars, NULL);
	else if (keycode == UP)
		move_player(vars->px, vars->py - 1, vars);
	else if (keycode == DOWN)
		move_player(vars->px, vars->py + 1, vars);
	else if (keycode == RIGHT)
		move_player(vars->px + 1, vars->py, vars);
	else if (keycode == LEFT)
		move_player(vars->px - 1, vars->py, vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars		*vars;
	int			fd;
	int			map_valid;

	if (argc != 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		perror("Error\n");
		return (0);
	}
	vars = setup_vars();
	map_valid = build_map(fd, vars);
	close(fd);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 32 * vars->msx, 32 * vars->msy, "");
	if (map_valid < 0)
		return (quit(vars, "Invalid map\n"));
	set_tiles(vars);
	mlx_key_hook(vars->win, receive_input, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
