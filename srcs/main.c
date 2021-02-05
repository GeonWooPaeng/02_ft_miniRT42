/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:36:51 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/05 15:33:28 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <mlx.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include "vector.h"

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3

// // //키보드 번호를 알수 있게 해주는 것

// typedef struct s_data
// {
// 	void *mlx;
// 	void *mlx_win;
// 	int width;
// 	int height;
// 	void *img;
// 	char *addr; //mlx_get_data_addr()로 생성한 이미지의 시작 주소
// 	int bits_per_pixel; //픽셀 당 비트의 수
// 	int word_length; //이미지의 가로 한줄의 바이트 수
// 	int endian;
// }				t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
// {
// 	char *dst;
// 	// y * data->word_length : y좌표만큼의 메모리 주소로 이동
// 	// data->bits_per_pixel / 8 : 픽셀당 바이트 수를 구하기 위해 /8 해줍니다.
// 	// x * (data->bits_per_pixel / 8) : x 좌표만큼의 메모리 주소를 이동
// 	// => (x,y)좌표의 픽셀의 메모리 주소 구할 수 있다.
// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
// }

// int ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }


// int ft_draw(t_data *data)
// {
// 	int i;
// 	int j;
// 	t_vec3 color;

// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining: ");
// 		printf("%d", j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			ft_vec3_set_xyz(&color, (double)i / (data->width - 1), (double)j / (data->height - 1), 0.25);
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }


// int main(void)
// {
// 	t_data data;

// 	data.mlx = mlx_init();
// 	data.width = 600;
// 	data.height = 400;
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, 600, 400);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);

// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data);
// 	mlx_loop(data.mlx);
// 	return (0);
// }



// ----------------------------------------------------------------------------------------------------
// 하늘 색 배경 파악
// 광선 추적기는 픽셀을 통해 광선을 보내고 광선 방향에서 보이는 생상을 계산한다.
//1. 눈(카메라)에서 픽셀까지의 광선을 계산 2. 광선이 교차하는 물체를 결정 3. 해당 교차점의 색상을 계산

// #include <mlx.h>
// #include "vector.h"
// #include "ray.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "camera.h"

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3

// typedef struct s_data
// {
// 	void *mlx;
// 	void *mlx_win;
// 	double aspect_ratio;
// 	int width, height;
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int word_length;
// 	int endian;
// }				t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
// }

// int ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// t_color *ft_ray_color(t_color *target, t_ray *r)
// {
// 	t_vec3 unit_dir;
// 	double t;
// 	t_color cal1;
// 	t_color cal2;

// 	ft_vec_unit(&unit_dir, &(r->dir));
// 	printf("unit_y = %f\n", unit_dir.y);
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	ft_vec_multi_double(&cal1, (1.0 - t), ft_vec3_set_xyz(&cal1, 1.0, 1.0, 1.0));
// 	ft_vec_multi_double(&cal2, t, ft_vec3_set_xyz(&cal2, 0.5, 0.7, 1.0));
// 	return (ft_vec_add(target, &cal1, &cal2));
// }

// int ft_draw(t_data *data, t_camera *cam)
// {
// 	int i;
// 	int j;
// 	t_vec3 color;
// 	t_ray r;
// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining: ");
// 		printf("%d", j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			ft_camera_cal_ray(&r, cam, (double)i / (data->width - 1), (double)j / (data->height - 1));
// 			ft_ray_color(&color, &r);
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;
// 	t_camera cam;

// 	data.aspect_ratio = 16.0 / 9.0; //가로세로비
// 	data.width = 600;
// 	data.height = (int)(data.width / data.aspect_ratio);
// 	ft_camera_set(&cam, data.aspect_ratio);

// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, 600, 400);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);
// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data, &cam);
// 	mlx_loop(data.mlx);
// 	return (0);
// }


// -----------------------------------------------------------------------------------------
//원그리기 
// #include <mlx.h>
// #include "vector.h"
// #include "ray.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "camera.h"

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3

// typedef struct s_data
// {
// 	void *mlx;
// 	void *mlx_win;
// 	double aspect_ratio;
// 	int width, height;
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int word_length;
// 	int endian;
// }				t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
// }

// int ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// int ft_hit_sphere(t_point3 *center, double radius, t_ray *r)
// {
// 	t_vec3 oc;
// 	double a;
// 	double b;
// 	double c;

// 	ft_vec_sub(&oc,  &(r->origin), center);
// 	a = ft_vec_dot(&(r->dir), &(r->dir));
// 	b = 2.0 * ft_vec_dot(&oc, &(r->dir));
// 	c = ft_vec_dot(&oc, &oc) - radius * radius; 
// 	if (b * b - 4 * a * c > 0) 
// 		return (1);//근이 2개
// 	else
// 		return (0);
// }

// t_color *ft_ray_color(t_color *target, t_ray *r)
// {
// 	t_vec3 unit_dir;
// 	double t;
// 	t_color cal1;
// 	t_color cal2;
// 	t_point3 sp_center;

// 	if (ft_hit_sphere(ft_vec_set_xyz(&sp_center, 0, 0, -1), 0.5, r))
// 		return (ft_vec_set_xyz(target, 1, 0, 0));
// 	ft_vec_unit(&unit_dir, &(r->dir));
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	ft_vec_multi_double(&cal1, (1.0 - t), ft_vec_set_xyz(&cal1, 1.0, 1.0, 1.0));
// 	ft_vec_multi_double(&cal2, t, ft_vec_set_xyz(&cal2, 0.5, 0.7, 1.0));
// 	return (ft_vec_add(target, &cal1, &cal2));
// }

// int ft_draw(t_data *data, t_camera *cam)
// {
// 	int i;
// 	int j;
// 	t_vec3 color;
// 	t_ray r;

// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining");
// 		printf("%d", j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			ft_camera_cal_ray(&r, cam, (double)i / (data->width - 1), (double)j / (data->height - 1));
// 			ft_ray_color(&color, &r);
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;
// 	t_camera cam;

// 	data.aspect_ratio = 16.0 / 9.0;
// 	data.width = 600;
// 	data.height = (int)(data.width / data.aspect_ratio);
// 	ft_camera_set(&cam, data.aspect_ratio);
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, data.width, data.height);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);
// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data, &cam);
// 	mlx_loop(data.mlx);
// 	return (0);
// }

// ----------------------------------------------------------------------
// 표면 법선으로 음영 처리
//- 구의 경우 바깥 쪽 법선은 히트 포인트엥서 중심을 뺀 방향
//## 음영처리
// - 법선을 시각화 하는데 사용되는 일반적인 트릭은 단위 길이 벡터
// (각 구성 요소는 -1 과 1 사이에 있다.)
// - 각 구성 요소를 0에서 1까지의 간격에 매핑한 다음 x / y / z를 r / g / b에 매핑합니다.
// - 노멀의 경우 히트 여부, 히트 포인트 필요
// - 장면에 구가 하나만 있고 카메라 바로 앞에 있으므로 음수는 생각 X

// #include "vector.h"
// #include "ray.h"
// #include "camera.h"
// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3

// typedef struct s_data
// {
// 	void *mlx;
// 	void *mlx_win;
// 	double aspect_ratio;
// 	int width, height;
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int word_length;
// 	int endian;
// }				t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
// }

// int ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// double ft_hit_sphere(t_point3 *center, double radius, t_ray *r)
// {
// 	t_vec3 oc;
// 	double a;
// 	double b;
// 	double c;
// 	double discriminant; //판별

// 	ft_vec_sub(&oc, &(r->origin), center);
// 	a = ft_vec_dot(&(r->dir), &(r->dir));
// 	b = 2.0 * ft_vec_dot(&oc, &(r->dir));
// 	c = ft_vec_dot(&oc, &oc) - radius * radius;
// 	discriminant = b * b - 4 * a * c;
// 	if (discriminant < 0)
// 		return (-1.0);
// 	else
// 		return ((-b - sqrt(discriminant)) / (2.0 * a));
// }

// t_color *ft_ray_color(t_color *target, t_ray *r)
// {
// 	t_vec3 unit_dir;
// 	double t;//hit point
// 	t_color cal1;
// 	t_color cal2;
// 	t_point3 sp_center; //중심
// 	t_vec3 normal_vec;
// 	t_vec3 ray_at;

// 	t = ft_hit_sphere(ft_vec_set_xyz(&sp_center, 0, 0, -1), 0.5, r);
// 	if (t > 0.0)
// 	{
// 		ft_ray_at(&ray_at, r, t);
// 		ft_vec_set_xyz(&normal_vec, 0, 0, -1);
// 		ft_vec_sub(&normal_vec, &ray_at, &normal_vec);
// 		ft_vec_unit(&normal_vec, &normal_vec);
// 		target->x = 0.5 * (normal_vec.x + 1);
// 		target->y = 0.5 * (normal_vec.y + 1);
// 		target->z = 0.5 * (normal_vec.z + 1);
// 		return (target);
// 	}
// 	ft_vec_unit(&unit_dir, &(r->dir));
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	ft_vec_multi_double(&cal1, (1.0 - t), ft_vec_set_xyz(&cal1, 1.0, 1.0, 1.0));
// 	ft_vec_multi_double(&cal2, t, ft_vec_set_xyz(&cal2, 0.5, 0.7, 1.0));
// 	return (ft_vec_add(target, &cal1, &cal2));
// }

// int ft_draw(t_data *data, t_camera *cam)
// {
// 	int i;
// 	int j;
// 	t_vec3 color;
// 	t_ray r;

// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining: ");
// 		printf("%d",j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			ft_camera_cal_ray(&r, cam, (double)i / (data->width - 1), (double)j / (data->height - 1));
// 			ft_ray_color(&color, &r);
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;
// 	t_camera cam;

// 	data.aspect_ratio = 16.0 / 9.0;
// 	data.width = 600;
// 	data.height = (int)(data.width / data.aspect_ratio);
// 	ft_camera_set(&cam, data.aspect_ratio);
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, data.width, data.height);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);

// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data, &cam);
// 	mlx_loop(data.mlx);
// 	return (0);
// }

// ------------------------------------------------------------------------

// 밑 장판 + 원 
// 광선이 외부에서 구와 교차하는 경우
// : 법선(normal point)은 광선(ray)의 반대를 가리킨다.
// : 법선이 outward를 가리키지만 만약 광선이 구 안에 있을 경우 법선은 inward를 가리킨다.

// 광선이 내부에서 구와 교차하는 경우
// : 법선(which always points out)은 광선과 같은 방향을 가리킨다.

// ray와 normal face(법사면)이 같은 방향이면 ray는 물체 내부에 있고 
// ray와 normal face이 반대 방향이면 ray는 물체 외부에 있습니다.
// => 두 벡터의 내적으로 결정됩니다.(양수: ray는 구 내부)
// #include <mlx.h>
// #include "utils.h"
// #include "vector.h"
// #include "ray.h"
// #include "hittable_list.h"
// #include "sphere.h"
// #include "ft_camera.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <float.h>

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3
// #define PI	3.1415926535897932385

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	double	aspect_ratio;
// 	int		width, height;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		word_length;
// 	int		endian;
// }			t_data;

// double	degress_to_radians(double degrees)
// {
// 	return (degrees * PI / 180.0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = create_trgb(0, 255.999 * color->x, 255.999 * color->y, 255.999 * color->z);
// }

// int	ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// t_color *ft_ray_color(t_color *target, t_ray *r, t_obj **obj_lst)
// {
// 	t_vec3		unit_dir;
// 	double		t;
// 	t_color		cal1;
// 	t_color		cal2;
// 	t_hit_rec	rec;
// 	t_t			t_minmax;

// 	t_minmax.min = 0;
// 	t_minmax.max = FLT_MAX;
// 	if (ft_hit_lst_hit(obj_lst, r, t_minmax, &rec))
// 	{
// 		ft_vec_set_xyz(target, 1, 1, 1);
// 		ft_vec_add(target, target, &rec.normal);
// 		return (ft_vec_multi_double(target, 0.5, target));
// 	}
// 	ft_vec_unit(&unit_dir, &(r->dir));
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	ft_vec_multi_double(&cal1, (1.0 - t), ft_vec_set_xyz(&cal1, 1.0, 1.0, 1.0));
// 	ft_vec_multi_double(&cal2, t, ft_vec_set_xyz(&cal2, 0.5, 0.7, 1.0));
// 	return (ft_vec_add(target, &cal1, &cal2));
// }

// int	ft_draw(t_data *data, t_camera *cam, t_obj *world)
// {
// 	int		i;
// 	int		j;
// 	t_vec3	color;
// 	t_ray	r;

// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining: ");
// 		printf("%d",j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			ft_camera_cal_ray(&r, cam, (double)i / (data->width - 1), (double)j / (data->height - 1));
// 			ft_ray_color(&color, &r, &world);
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_data		data;
// 	t_camera	cam;
// 	t_obj		*world;
// 	t_point3	center;
// 	t_sphere	*sp;

// 	//표현할 화면, 카메라 setting
// 	data.aspect_ratio = 16.0 / 9.0;
// 	data.width = 600;
// 	data.height = (int)(data.width / data.aspect_ratio);
// 	ft_camera_set(&cam, data.aspect_ratio);
	
// 	world = NULL;
// 	//원 만들기
// 	sp = (t_sphere *)malloc(sizeof(t_sphere));
// 	ft_vec_set_xyz(&center, 0, 0, -1);//(0,0,-1)에 구체 위치
// 	ft_sphere_set(sp, &center, 0.5);//중심이랑 반지름 setting
// 	ft_hit_lst_add(&world, ft_hit_lst_newnode(sp));
// 	//바닥 만들기
// 	sp = (t_sphere *)malloc(sizeof(t_sphere));
// 	ft_vec_set_xyz(&center, 0, -100.5, -1);
// 	ft_sphere_set(sp, &center, 100);
// 	ft_hit_lst_add(&world, ft_hit_lst_newnode(sp));

// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, data.width, data.height);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);

// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data, &cam, world);
// 	mlx_loop(data.mlx);
// 	return (0);
// }

// ---------------------------------------------------------------------------------------------

// #include <mlx.h>
// #include "utils.h"
// #include "vector.h"
// #include "ray.h"
// #include "hittable_list.h"
// #include "sphere.h"
// #include "ft_random.h"
// #include "ft_camera.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <float.h>

// #define ESC		65307
// #define KeyPress	2
// #define KeyRelease	3
// #define PI	3.1415926535897932385

// typedef struct s_data
// {
// 	void *mlx;
// 	void *mlx_win;
// 	double aspect_ratio;
// 	int width, height;
// 	int samples_per_pixel;
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int word_length;
// 	int endian;
// }t_data;

// double degrees_to_radians(double degrees)
// {
// 	return (degrees * PI / 180.0);
// }

// void my_mlx_pixel_put(t_data *data, int x, int y, t_vec3 *color, int samples_per_pixel)
// {
// 	char *dst;
// 	double r;
// 	double b;
// 	double g;
// 	double scale;

// 	scale = 1.0 / samples_per_pixel;
// 	r = color->x * scale;
// 	g = color->y * scale;
// 	b = color->z * scale;
// 	dst = data->addr + (y * data->word_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = create_trgb(0, 256 * ft_clamp(r, 0.0, 0.999), 256 * ft_clamp(g, 0.0, 0.999), 256 * ft_clamp(b, 0.0, 0.999));
// }

// int ft_key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }

// t_color *ft_ray_color(t_color *target, t_ray *r, t_obj **obj_lst)
// {
// 	t_vec3 unit_dir;
// 	double t;
// 	t_color cal1;
// 	t_color cal2;
// 	t_hit_rec rec;
// 	t_t t_minmax;

// 	t_minmax.min = 0;
// 	t_minmax.max = FLT_MAX;
// 	if (ft_hit_lst_hit(obj_lst, r, t_minmax, &rec))
// 	{
// 		ft_vec_set_xyz(target, 1, 1, 1);
// 		ft_vec_add(target, target, &rec.normal);
// 		return (ft_vec_multi_double(target, 0.5, target));
// 	}
// 	ft_vec_unit(&unit_dir, &(r->dir));
// 	t = 0.5 * (unit_dir.y + 1.0);
// 	ft_vec_multi_double(&cal1, (1.0 - t), ft_vec_set_xyz(&cal1, 1.0, 1.0, 1.0));
// 	ft_vec_multi_double(&cal2, t, ft_vec_set_xyz(&cal2, 0.5, 0.7, 1.0));
// 	return (ft_vec_add(target, &cal1, &cal2));
// }

// int ft_draw(t_data *data, t_camera *cam, t_obj *world)
// {
// 	int i;
// 	int j;
// 	int k;
// 	t_vec3 color;
// 	t_vec3 tmp_color;
// 	t_ray r;
// 	j = data->height - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		printf("\rScanwords remaining ");
// 		printf("%d",j);
// 		printf(" ");
// 		while (i < data->width)
// 		{
// 			k = 0;
// 			ft_vec_set_xyz(&color, 0, 0, 0);
// 			while (k < data->samples_per_pixel)
// 			{
// 				ft_camera_get_ray(&r, cam, ((double)i + ft_random_double()) / (data->width - 1), ((double)j + ft_random_double()) / (data->height - 1));
// 				ft_ray_color(&tmp_color, &r, &world);
// 				ft_vec_add(&color, &color, &tmp_color);
// 				k++;
// 			}
// 			my_mlx_pixel_put(data, i, data->height - 1 - j, &color, data->samples_per_pixel);
// 			i++;
// 		}
// 		j--;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;
// 	t_camera cam;
// 	t_obj *world;
// 	t_point3 center;
// 	t_sphere *sp;

// 	data.aspect_ratio = 16.0 / 9.0;
// 	data.width = 600;
// 	data.height = (int)(data.width / data.aspect_ratio);
// 	data.samples_per_pixel = 100;

// 	world = NULL;
// 	sp = (t_sphere *)malloc(sizeof(t_sphere));
// 	ft_vec_set_xyz(&center, 0, 0, -1);
// 	ft_sphere_set(sp, &center, 0.5);
// 	ft_hit_lst_add(&world, ft_hit_lst_newnode(sp));
// 	sp = (t_sphere *)malloc(sizeof(t_sphere));
// 	ft_vec_set_xyz(&center, 0, -100.5, -1);
// 	ft_sphere_set(sp, &center, 100);
// 	ft_hit_lst_add(&world, ft_hit_lst_newnode(sp));
// 	ft_camera_set(&cam);
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
// 	data.img = mlx_new_image(data.mlx, data.width, data.height);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.word_length, &data.endian);

// 	mlx_hook(data.mlx_win, 2, 1L<<0, ft_key_press, &data);
// 	ft_draw(&data, &cam, world);
// 	mlx_loop(data.mlx);
// 	return (0);
// }

// --------------------------------------------------------------------

#include <mlx.h>
#include "utils.h"
#include "vector.h"
#include "ray.h"
#include "hittable_list.h"
#include "sphere.h"
#include "ft_random.h"
#include "ft_camera.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

void ft_parse_resolution()
{
}

void ft_make_word(char **line)
{
}

void ft_parse_value(char **words)
{
	if (ft_strncmp(*words, "R", 2) == 0)
		ft_parse_resolution();
	// else if (ft_strncmp(*words, "A", 2) == 0)
	// 	ft_parse_amb_light();
	// else if (ft_strncmp(*words, "c", 2) == 0)
	// 	ft_parse_camera();
	// else if (ft_strncmp(*words, "l", 2) == 0)
	// 	ft_parse_light();
	// else if (ft_strncmp(*words, "sp", 3) == 0)
	// 	ft_parse_sphere();
	// else if (ft_strncmp(*words, "pl", 3) == 0)
	// 	ft_parse_plane();
	// else if (ft_strncmp(*words, "sq", 3) == 0)
	// 	ft_parse_square();
	// else if (ft_strncmp(*words, "cy", 3) == 0)
	// 	ft_parse_cylinder();
	// else if (ft_strncmp(*words, "tr", 3) == 0)
	// 	ft_parse_triangle();
	else
		printf("[Error] No match .rt files");
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int		fd;
		int		ret;
		char	*line;
		char	**words;
		
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			printf("Error");
			return (0);
		}
		while ((ret = get_next_word(fd, &line)) > 0)
		{
			words = ft_make_word(&line);
			ft_parse_value(words);
			printf("line >> %s\n", line);
			free(line);
		}
		printf("line >> %s\n", line);
		free(line);
	}
	return (0);
}