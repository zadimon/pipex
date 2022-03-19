/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:16:21 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/13 22:40:30 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_gstrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	sym;

	i = 0;
	sym = (unsigned char) c;
	while (s[i] != '\0')
	{
		if (s[i] == sym)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == sym)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_gstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!(s))
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gsubstr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	min_len;

	if (!(s))
		return (0);
	min_len = ft_gstrlen(&s[start]);
	if (start >= ft_gstrlen(s))
		len = 0;
	else if (min_len < len)
		len = min_len;
	str = malloc(sizeof(*str) * (len + 1));
	if (!(str))
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gstrdup(char *src)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!(str))
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	size_t	j;
	size_t	i;
	char	*str;

	if (!(s1))
		return (0);
	str = malloc(sizeof(*str) * (ft_gstrlen(s1) + ft_gstrlen(s2) + 1));
	if (!(str))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
