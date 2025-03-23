/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 02:14:58 by throbert          #+#    #+#             */
/*   Updated: 2025/02/10 02:14:58 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	init_palette1(t_color *palette)
{
	palette[0] = (t_color){0x0000FF, 0.0f};
	palette[1] = (t_color){0x00FF00, 0.33f};
	palette[2] = (t_color){0xFFFF00, 0.66f};
	palette[3] = (t_color){0xFF0000, 1.0f};
}

static void	init_palette2(t_color *palette)
{
	palette[0] = (t_color){0xFF00FF, 0.0f};
	palette[1] = (t_color){0xFFA500, 0.5f};
	palette[2] = (t_color){0xFFFFFF, 1.0f};
}

static void	init_palette_pastel(t_color *palette)
{
	palette[0] = (t_color){0xAEC6CF, 0.0f};
	palette[1] = (t_color){0xFFB347, 0.5f};
	palette[2] = (t_color){0xB39EB5, 1.0f};
}

int	get_palette(t_data *data, t_color **palette, int *size)
{
	static t_color	palette1[4];
	static t_color	palette2[3];
	static t_color	palette_pastel[3];

	init_palette1(palette1);
	init_palette2(palette2);
	init_palette_pastel(palette_pastel);
	if (data->current_palette == 1 || data->current_palette > 3)
	{
		*palette = palette1;
		*size = 4;
	}
	else if (data->current_palette == 2)
	{
		*palette = palette2;
		*size = 3;
	}
	else
	{
		*palette = palette_pastel;
		*size = 3;
	}
	return (1);
}
