/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: trikapou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:53:08 by trikapou     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 07:58:08 by tris             ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

int		next_lexicorder(int tab[], size_t n);

typedef struct s_fillit s_fillit;
struct s_fillit
{
	int	nb_tetri;
	int	**tetrxy;
	int	**tetrxy_tmp;
	int	n;
	char	*map;
	int	mapx;
	int	*order;
	int	*order_tmp;
	int	*pos;
	int	l;
};


#endif
