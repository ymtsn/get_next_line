/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:29:30 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/10 23:42:04 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	length;

	if (c == NULL)
		return (0);
	length = 0;
	while (*(c + length))
		length++;
	return (length);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	n;

	if (s == NULL)
		return (NULL);
	n = 0;
	if (start > ft_strlen(s))
		len = 0;
	else if ((len + start) > ft_strlen(s))
		len = ft_strlen(s) - start;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (len)
	{
		*(buf + n++) = *(s + start++);
		len--;
	}
	*(buf + n) = '\0';
	return (buf);
}
