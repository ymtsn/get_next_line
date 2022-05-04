/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:28:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/13 08:50:40 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_howoutput(t_list *lst, char **rtn)
{
	size_t	npos;
	size_t	len;
	char	*temp;

	npos = 0;
	len = ft_strlen(lst->stock);
	while (len && *(lst->stock + npos++) != '\n')
		len--;
	if (len == 0)
		npos = 0;
	if ((npos == ft_strlen(lst->stock) || !npos) && lst->INFO == NOREAD)
		return (ALLOUTPUT);
	if (!npos)
		return (DONOTHING);
	temp = lst->stock;
	*rtn = ft_substr(lst->stock, 0, npos);
	lst->stock = ft_substr(lst->stock, npos, ft_strlen(lst->stock + npos));
	free(temp);
	if (*rtn == NULL || lst->stock == NULL)
	{
		free(*rtn);
		free(lst->stock);
		return (ERROR);
	}
	return (SPLITSTOCK);
}

int	ft_join_stck_rd(t_list *lst)
{
	char	*buf;
	char	*temp;
	size_t	len;

	len = ft_strlen(lst->readbuf) + ft_strlen(lst->stock);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL || lst->INFO == ERROR || len == 0)
	{
		free(buf);
		free(lst->readbuf);
		free(lst->stock);
		return (ERROR);
	}
	temp = lst->stock;
	while (lst->stock != NULL && *(lst->stock))
		*buf++ = *(lst->stock)++;
	free(temp);
	temp = lst->readbuf;
	while (lst->readbuf != NULL && *(lst->readbuf))
		*buf++ = *(lst->readbuf)++;
	free(temp);
	*buf = '\0';
	buf -= len;
	lst->stock = buf;
	return (lst->INFO);
}

int	ft_make_readbuf(t_list *lst, int fd)
{
	ssize_t	readlen;

	lst->readbuf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (lst->readbuf == NULL)
		return (ERROR);
	readlen = read(fd, lst->readbuf, BUFFER_SIZE);
	if (readlen < 0 || readlen == 0)
	{
		free(lst->readbuf);
		lst->readbuf = NULL;
	}
	if (readlen < 0)
		return (ERROR);
	if (readlen == 0)
		return (NOREAD);
	*(lst->readbuf + readlen) = '\0';
	return (CONTINUE);
}

char	*get_next_line(int fd)
{
	static t_list	lst[GUACA_FDMAX];
	char			*rtn;

	if (fd < 0 || fd >= GUACA_FDMAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (lst[fd].INFO != ERROR && lst[fd].INFO != ALLOUTPUT)
	{
		if (lst[fd].INFO != NOREAD)
		{
			lst[fd].INFO = ft_make_readbuf(&lst[fd], fd);
			lst[fd].INFO = ft_join_stck_rd(&lst[fd]);
		}
		if (lst[fd].INFO == ERROR)
			return (NULL);
		lst[fd].INFO = ft_howoutput(&lst[fd], &rtn);
		if (lst[fd].INFO == ALLOUTPUT)
			return (lst[fd].stock);
		if (lst[fd].INFO == SPLITSTOCK)
			return (rtn);
	}
	return (NULL);
}
