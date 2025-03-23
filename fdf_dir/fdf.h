/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:01:48 by throbert          #+#    #+#             */
/*   Updated: 2025/03/23 16:01:17 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define M_PI				3.14159265358979323846
# define WINDOW_WIDTH		2000
# define WINDOW_HEIGHT		1200
# define MOVEMENT_SPEED 1 // Augmente cette valeur pour moves rapides

/* Keyboard keys */
# define KEY_UP				65362  // Flèche haut
# define KEY_DOWN			65364  // Flèche bas
# define KEY_LEFT			65361  // Flèche gauche
# define KEY_RIGHT			65363  // Flèche droite
# define KEY_PAGE_UP		116 /* hauteur T */
# define KEY_PAGE_DOWN		121 /* Y */
# define KEY_ESC			65307
# define KEY_ROTATE_X_UP	119
# define KEY_ROTATE_X_DOWN	115
# define KEY_ROTATE_Y_UP	97
# define KEY_ROTATE_Y_DOWN	100
# define KEY_ROTATE_Z_UP	113
# define KEY_ROTATE_Z_DOWN	101
# define KEY_PROJECTION		112
# define KEY_TOGGLE_COLOR	99  /* Touche 'C' */
# define KEY_TOGGLE_PALETTE	118 /* Touche 'V' */

# define PALETTE_COUNT		3

/* Color structure */
typedef struct s_color
{
	int		color;
	float	position;
}				t_color;

/* Point structure */
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* Map structure */
typedef struct s_map
{
	int		width;
	int		height;
	int		**grid;
	int		**color;
	int		min_z;
	int		max_z;
}	t_map;

/* Data structure */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		color_depth;
	int		size_line;
	int		color_endian_order;
	int		zoom;
	int		offset_x;
	int		offset_y;
	float	z_divisor;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		is_mouse_down;
	int		mouse_prev_x;
	int		mouse_prev_y;
	t_map	*map;
	int		projection;
	int		use_palette;
	int		current_palette;
	float	movement_speed; // Vitesse de déplacement ajustable
	int		needs_redraw;
}	t_data;

/* Line structure */
typedef struct s_line
{
	int	delta_x;
	int	delta_y;
	int	step_x;
	int	step_y;
	int	error_margin;
	int	error_temp;
	int	current_x;
	int	current_y;
}	t_line;

/* Initialization */
int				validate_args(int argc, char **av);
int				initialize_map(char *filename, t_data *data);
int				initialize_mlx(t_data *data);
void			init_data(t_data *data);

/* Parsing */
void			parse_map(char *filename, t_map *map);
int				fill_cell(char *cell_str, t_map *map,
					int line_number, int cell_number);
void			parse_line(char *line, t_map *map, int line_number);
void			count_dimensions(int fd, t_map *map);
void			read_and_fill_grid(int fd, t_map *map);
int				is_valid(char *str);
int				is_valid_number(char *str);
int				is_valid_hexa(char *str, t_map *map);
void			error_exit(t_map *map, char *msg);
void			open_file_and_handle_error(char *filename, int *fd);
void			allocate_map_memory(t_map *map);
void			initialize_map_values(t_map *map);
int				check_inconsistent_row_width(int width, t_map *map);
void			compute_min_max_z(t_map *map);

/* Rendering */
void			draw_map(t_data *data);
void			draw_line(t_point a, t_point b, t_data *data);
void			put_pixel_to_image(t_data *data, int x, int y, int color);
t_point			project(t_point p, t_data *data);
int				compute_color(int z, t_data *data);
void			isometric_projection(float *x, float *y, float z);
void			perspective_projection(float *x, float *y, float z);
void			rotate_x(float *y, float *z, float angle);
void			rotate_y(float *x, float *z, float angle);
void			rotate_z(float *x, float *y, float angle);
void			init_color_point(t_data *data, int x, int y, t_point *point);
void			draw_line_if_valid(t_data *data, t_point *a,
					int offset_x, int offset_y);

/* Event Handling */
int				key_hook(int keycode, t_data *data);
int				mouse_press(int button, int x, int y, t_data *data);
int				mouse_release(int button, int x, int y, t_data *data);
int				mouse_move(int x, int y, t_data *data);
void			handle_key_actions(int keycode, t_data *data);
void			handle_zoom(t_data *data, int x, int y, int direction);
int				loop_hook(t_data *data);

/* Utilities */
void			redraw(t_data *data);
void			display_commands(t_data *data);
void			free_map(t_map *map);
void			allocate_grid_and_row(t_map *map, int row);

/* Setup and Execution */
void			setup_hooks_and_run(t_data *data);

/* Closing */
int				close_window(t_data *data);

/* Main */
int				main(int argc, char **argv);

/* color management */
int				interpolate_two_color(int color1, int color2, float t);
int				get_palette(t_data *data, t_color **palette, int *size);
void			plot_gradient_pixel(t_line pixel_data,
					t_point start, t_point end, t_data *data);

#endif
