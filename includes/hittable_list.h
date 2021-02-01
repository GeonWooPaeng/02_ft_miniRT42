/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:38:14 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/01 14:47:50 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HITTABLE_LIST_H
# define	HITTABLE_LIST_H
# include	"hittable.h"
# include	"sphere.h"
# include	"utils.h"

typedef t_list	t_obj;
void			ft_obj_del(void *node);
t_obj			*ft_hit_lst_newnode(void *newnode);
void			ft_hit_lst_add(t_obj **obj_lst, t_obj *node);
void			ft_hit_lst_delone(t_obj **obj_lst);
void			ft_hit_lst_clear(t_obj **obj_lst);
int				ft_hit_lst_hit(t_obj **obj_lst, t_ray *r, t_t t, t_hit_rec *rec);

#endif