/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:12:33 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/11 10:10:27 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define ERROR -1
# define CONTINUE 1
# define NOREAD 2
# define ALLOUTPUT 3
# define SPLITSTOCK 4
# define DONOTHING 5
# define GUACA_FDMAX 256
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_list
{
	char		*readbuf;
	char		*stock;
	char		*init;
	int			INFO;
}	t_list;
size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_join_stck_rd(t_list *lst);
int		ft_make_readbuf(t_list *lst, int fd);
int		ft_howoutput(t_list *lst, char **rtn);
char	*get_next_line(int fd);
#endif
