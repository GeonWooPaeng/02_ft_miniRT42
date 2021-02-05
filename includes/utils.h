/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:46:00 by gpaeng            #+#    #+#             */
/*   Updated: 2021/02/05 13:42:38 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	struct	s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *str, size_t num);
char	*ft_strjoin(const char *a, const char *b);
char	*ft_strchr(const char *str, int c);
int		get_next_line(int fd, char **line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

#endif