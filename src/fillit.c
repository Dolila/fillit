/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit .c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trikapou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 17:24:58 by trikapou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 08:39:04 by tris             ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef __PARSING__
# define __PARSING__
# include "../inc/fillit.h"
#endif

int		*set_order(int n)
{
	int		*order;
	int		i;

	order = (int *)malloc(sizeof(order) * n);
	i = -1;
	while (++i < n)
		order[i] = i;
	return (order);
}

int		hash_nb(char *s)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (s[++i])
	{
		if (s[i] == '#')
		{
			n++;
			if (s[i - 1] != '#' && s[i + 1] != '#' && \
					s[i - 5] != '#' && s[i + 5] != '#')
				return (1);
		}
	}
	return (n != 4);
}

int		*tetrxy_pos(char *s, int l)
{
	int		i;
	int		j;
	int		*tab;

	i = -1;
	j = 0;
	tab = (int *)malloc(sizeof(int) * 5);
	while (++i < 20 && j < 4)
		if (s[i] == '#')
			tab[j++] = i;
	tab[4] = l;
	i = 4;
	while (i-- > 0)
		tab[i] = tab[i] - tab[0];
	i = 4;
	while (i-- > 0)
		if (tab[i] % 5 == 4)
		{
			j = -1;
			i = 4;
			while (++j < 4)
				tab[j]++;
		}
	return (tab);
}

char	*build_map(int mapx)
{
	char	*map;
	int		mapl;
	int		i;
	int		j;

	mapl = mapx * (mapx + 1);
	map = ft_strnew(mapl + 1);
	map = ft_memset(map, '.', mapl - 1);
	i = 0;
	j = -1;
	while (++j < mapl - 1)
	{
		if (++i == mapx + 1)
		{
			map[j] = '\n';
			i = 0;
		}
	}
	return (map);
}

int	reduc(int pos, int gap, int *tetrxy, int mapx, int i)
{
	if (mapx <= 4)
		gap = pos + tetrxy[i] + ((mapx - 4) * (tetrxy[i] / 4));
	else if (i == 0)
		gap = tetrxy[i] + pos;
	else if (tetrxy[i - 1] == tetrxy[i] - 1)
		gap++;
	else
		gap = pos + tetrxy[i] + ((mapx - 4) * (tetrxy[i] / 4));
	return (gap);
}


char	*place_tetri(int pos, int *tetrxy, char *map, int mapx)
{
	char	*map2;
	int	gap;
	int	i;

	ft_strcpy(map2 = ft_strnew(ft_strlen(map)), map);
	i = -1;
	while (++i < 4)
	{
		gap = reduc(pos, gap, tetrxy, mapx, i);
		if (gap > (int)ft_strlen(map))
		{
			free(map2);
			return (NULL);
		}
		if ((map2[gap] >= 'A' && map2[gap] <= 'Z') || map[gap] == '\n' || map[gap] == '\0' || pos > ((mapx + 1) * (mapx + 1)))
		{
			free(map2);
			pos++;
			return (place_tetri(pos, tetrxy, map, mapx));
		}
		map2[gap] = tetrxy[4];
	}
	return (map2);
}

int		check_tetri_file(int fd, int nb_tetri, int **tetrxy, int l)
{
	char	tmp[20];
	char	c;
	int	i;

	i = -1;
	while (++i >= -1)
	{
		if (read(fd, &c, 1) == 0)
			return (nb_tetri);
		if (i == 20 && c != '\n')
			return (0);
		if (i == 20)
			i = -1;
		if (i != -1 && i % 5 == 4 && c != '\n')
			return (0);
		if (i != -1 && i % 5 < 4 && c != '.' && c != '#')
			return (0);
		if (i != -1 && i < 20)
			tmp[i] = c;
		if (i == 19 && hash_nb(tmp) != 0)
			return (0);
		if (i == 19 && (nb_tetri++) >= 0)
			tetrxy[nb_tetri - 1] = tetrxy_pos(tmp, l++);
	}
	return (0);
}

int		h_sqrt(int n)
{
	while (ft_sqrt(n) == -1)
	{
		n++;
	}
	return (ft_sqrt(n));
}

int		**tetrxy_malloc()
{
	int		**tetrxy;
	int		n;

	if (!(tetrxy = (int **)malloc(sizeof(*tetrxy) * 27)))
		return (0);
	n = -1;
	while (++n < 27)
	{
		if (!(tetrxy[n] = (int *)malloc(sizeof(**tetrxy) * 5)))
			return (0);
	}
	return (tetrxy);
}

int		**sort_tetrxy(int **tetrxy, int *order, int nb_tetri)
{
	int		**tetrxy_tmp;
	int		i;

	i = -1;
	tetrxy_tmp = tetrxy_malloc();
	while (++i < nb_tetri)
		tetrxy_tmp[i] = tetrxy[order[i]];
	i = -1;
	return (tetrxy_tmp);
}

int		main(int ac, char **av)
{
	int				fd;
	int				nb_tetri;
	int				**tetrxy;
	int				**tetrxy_tmp;
	int				n;
	char				*map;
	int				mapx;
	int				*order;
	int				*order_tmp;
	int				*pos;
	int				l;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sample\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!(tetrxy = tetrxy_malloc()))
		return (0);
	nb_tetri = 0;
	l = 'A';
	if ((nb_tetri = check_tetri_file(fd, nb_tetri, tetrxy, l)) == 0)
		return (0);
	mapx = h_sqrt(nb_tetri * 4);
	map = build_map(mapx);
	n = -1;
	order = set_order(nb_tetri);
	order_tmp = set_order(nb_tetri);
//	order_tmp = order;
//	tetrxy_tmp = tetrxy_malloc();
	tetrxy_tmp = tetrxy;
	pos = (int *)malloc(sizeof(pos));
	*pos = 0;
	while (++n < nb_tetri)
	{
		if (!(map = place_tetri(*pos, tetrxy[n], map, mapx)))
		{
			*pos = 0;
			if (next_lexicorder(order, nb_tetri))
				tetrxy = sort_tetrxy(tetrxy_tmp, order, nb_tetri);
			else
			{
				++mapx;
				order = order_tmp;
				tetrxy = tetrxy_tmp;
			}
			if (mapx < 4)
				mapx++;
			free(map);
			map = build_map(mapx);
			n = -1;
		}
	}
	ft_putendl(map);
	free(tetrxy);
	free(tetrxy_tmp);
	free(map);
	free(order);
	free(order_tmp);
	free(pos);
	close(fd);
	return (0);
}

