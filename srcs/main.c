/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:36:51 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/29 14:38:17 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/vector.h"

#define ESC		65307
#define KeyPress	2
#define KeyRelease	3

// //키보드 번호를 알수 있게 해주는 것

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	int width;
	int height;
	void *img;
	char *addr; //mlx_get_data_addr()로 생성한 이미지의 시작 주소
	int bits_per_pixel; //픽셀 당 비트의 수
	int line_length; //이미지의 가로 한줄의 바이트 수
	int endian;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
{
	char *dst;
	// y * data->line_length : y좌표만큼의 메모리 주소로 이동
	// data->bits_per_pixel / 8 : 픽셀당 바이트 수를 구하기 위해 /8 해줍니다.
	// x * (data->bits_per_pixel / 8) : x 좌표만큼의 메모리 주소를 이동
	// => (x,y)좌표의 픽셀의 메모리 주소 구할 수 있다.
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
}

int ft_key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (0);
}


int ft_draw(t_data *data)
{
	int i;
	int j;
	t_vec3 color;

	j = data->height - 1;
	while (j >= 0)
	{
		i = 0;
		printf("\rScanlines remaining: ");
		printf("%d", j);
		printf(" ");
		while (i < data->width)
		{
			ft_vec3_set_xyz(&color, (double)i / (data->width - 1), (double)j / (data->height - 1), 0.25);
			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
			i++;
		}
		j--;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}


int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.width = 600;
	data.height = 400;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, 600, 400);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
	ft_draw(&data);
	mlx_loop(data.mlx);
	return (0);
}
