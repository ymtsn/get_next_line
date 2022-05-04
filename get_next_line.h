/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:29:25 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/11 10:10:43 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
size_t	ft_strlen(const char *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_join_stck_rd(char **stockdata, char **readbuf, int INFO);
int		ft_make_readbuf(int fd, char **readbuf);
int		ft_howoutput(char **stockdata, char **rtn, int INFO);
char	*get_next_line(int fd);
#endif
