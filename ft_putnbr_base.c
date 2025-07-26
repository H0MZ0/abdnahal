#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	char	c;
	int		i;

	i = 0;
	if (!base)
		return (1);
	while (base[i])
	{
		if (base[i + 1] && base[i + 1] == base[i]
			|| base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

void ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	if (check_base(base))
		return ;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < base_len)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
}

int	main(int ac, char **av)
{
	char base[] = "0123456789ABCDEF";
	if (ac == 2)
		ft_putnbr_base(atoi(av[1]), base);
	return 0;
}
