/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmolenbe <fmolenbe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:04:44 by fmolenbe      #+#    #+#                 */
/*   Updated: 2024/05/02 21:12:17 by ferre         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# define ESC 65307
# define GRASS "./textures/grasstile"
# define WATER "./textures/watertile.xpm"
# define ROCK "./textures/rocktile.xpm"
# define PLAYER "./textures/playertile.xpm"
# define COLLECT "./textures/collectabletile.xpm"
# define EXIT "./textures/exittile.xpm"
# define UP 119
# define RIGHT 100
# define LEFT 97
# define DOWN 115

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		msx;
	int		msy;
	t_list	*imgs;
	int		px;
	int		py;
	int		collectables;
	int		c_found;
	int		movements;
	int		img_h;
	int		img_w;
}				t_vars;
int				build_map(int fd, t_vars *vars);
void			set_tiles(t_vars *vars);
void			clear_tiles(t_vars *vars);
//void			print_map(char **map, t_vars *vars);
char			*get_tile(int x, int y, t_vars *vars);
char			*get_map_line(int fd, t_vars *vars);
void			is_map_valid(int *map_valid, char *line, t_vars *vars);
void			check_map_tile(int x, int y, int *map_valid, t_vars *vars);
char			*get_grass_type(int x, int y, t_vars *vars);
int				flood_fill_e(int x, int y, char **floodMap, t_vars *vars);
void			flood_fill_c(int x, int y, char **floodMap, t_vars *vars);
t_vars			*setup_vars(void);
#endif