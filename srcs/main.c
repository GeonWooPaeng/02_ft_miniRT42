/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:36:51 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/28 17:31:04 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/vector.h"

#define UP		126
#define DOWN	125
#define LEFT	123
#define RIGHT	124
#define ESC		53
#define KeyPress	2
#define KeyRelease	3

//키보드 번호를 알수 있게 해주는 것

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	int width, height;
	int x, y;
	int up, down, left, right;
	void *img;
	char *addr; //mlx_get_data_addr()로 생성한 이미지의 시작 주소
	int bits_per_pixel; //픽셀 당 비트의 수
	int line_length; //이미지의 가로 한줄의 바이트 수
	int endian;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	// y * data->line_length : y좌표만큼의 메모리 주소로 이동
	// data->bits_per_pixel / 8 : 픽셀당 바이트 수를 구하기 위해 /8 해줍니다.
	// x * (data->bits_per_pixel / 8) : x 좌표만큼의 메모리 주소를 이동
	// => (x,y)좌표의 픽셀의 메모리 주소 구할 수 있다.
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_move(t_data *data)
{//시작이 좌측 상단입니다.
	if (data->left == 1 && data->x > 0)
	{
		data->x -= 3;
		printf("%x = %d, y = %d\n", data->x, data->y);
	}
	if (data->right == 1 && data->x + 100 < data->width)
	{//삼각형의 너비를 고려해서 100해준 것입니다.
		data->x += 3;
		printf("x = %d, y = %d\n", data->x, data->y);
	}
	if (data->up == 1 && data->y > 0)
	{
		data->y -= 3;
		printf("x = %d, y = %d\n", data->x, data->y);
	}
	if (data->down == 1 && data->y + 100 < data->height)
	{
		data->y += 3;
		printf("x = %d, y = %d\n", data->x, data->y);
	}
	return (0);
}

int ft_key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == LEFT)
		data->left = 1;
	if (keycode == RIGHT)
		data->right = 1;
	if (keycode == UP)
		data->up = 1;
	if (keycode == DOWN)
		data->down = 1;
	return (0);
}

int ft_key_release(int keycode, t_data *data)
{
	
}
int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int i;
	int j;
	int k;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "miniRT");
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (i = 250, k = 99; i < 300; i++, k -= 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	for (i = 300, k = 0; i < 350; i++, k+= 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}