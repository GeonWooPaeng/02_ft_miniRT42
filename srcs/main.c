/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:36:51 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/27 17:09:15 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define ESC 0xFF1B

//키보드 번호를 알수 있게 해주는 것

typedef struct s_data
{
	void *mlx;
	void *win;
	int width, height;
	void *img;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
}t_data;

int key_press(int key, t_data data)
{
	printf("pre_key: %d\n", key);
	if (key == ESC)
		exit(0);
}

int key_release(int key, t_data data)
{
	printf("rel_key: %d\n", key);
}

int mouse_press(int button, int x, int y, void *p)
{
	printf("button_num: %d , press at %dx%d\n", button, x, y);
}

int mouse_release(int button, int x, int y, void *p)
{
	printf("button_num: %d, release at %dx%d\n", button, x, y);
}

int mouse_pos(int x, int y, t_data *data)
{
	printf("mouse_pos %dx%d\n", x, y);
	mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

int main(void)
{
	t_data data;

	data.width = 600;
	data.height = 400;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width, data.height, "minirt_test");
	data.img = mlx_new_image(data.mlx, 600, 400);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.size_line, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	mlx_hook(data.win, 2, 1L<<0, key_press, 0);
	mlx_hook(data.win, 3, 1L<<1, key_release, 0);
	mlx_loop(data.mlx);
	return (0);
}