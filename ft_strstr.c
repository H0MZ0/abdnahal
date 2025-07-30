#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int (i), (j);
	i = 0;
	if (!to_find || !str)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && to_find[j] == str[i])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i - j]);
		i++;
	}
	return (NULL);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int (s_len), (d_len), (k), (i);
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	i = d_len;
	k = 0;
	if (!dest)
	{
		dest = src;
		if (s_len < size)
			return (s_len);
		return (size);
	}
	if (size <= d_len)
		return (size + s_len);
	while (src[k] && (d_len + k + 1) < size)
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (s_len + d_len);
}
