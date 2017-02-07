/*
** ship_loader.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Feb  6 20:52:39 2017 romain pillot
** Last update Tue Feb  7 14:36:07 2017 romain pillot
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "gnl.h"
#include "vector.h"
#include "ship.h"

static bool	insert_ship(int size, t_vector a, t_vector b, char data[][WIDTH])
{
  int		*from;
  int		to;

  from = a.x == b.x ? &(a.y) : &(a.x);
  to = a.x == b.x ? b.y : b.x;
  while (*from <= to)
    {
      if (data[a.y - 1][a.x - 1])
	return (false);
      else
	data[a.y - 1][a.x - 1] = size;
      (*from)++;
    }
  return (true);
}

static bool	valid_ship(int size, t_vector a, t_vector b, int prev_size)
{
  return (size == prev_size + 1 &&
	  (a.x == b.x || a.y == b.y) &&
	  (a.x == b.x ? ABS(a.y - b.y) + 1 == size : ABS(a.x - b.x) + 1 == size) &&
	  a.x > 0 && a.y > 0 && b.x > 0 && b.y > 0 &&
	  a.x <= WIDTH && a.y <= HEIGHT && b.x <= WIDTH && b.y <= HEIGHT);
}

static int	parse_ship_data(char *str, char data[][WIDTH], int prev_size)
{
  int		size;
  t_vector	a;
  t_vector	b;

  size = *str ? str[0] - '0' : 0;
  a.x = size && str[1] == ':' && str[2] ? str[2] - 'A' + 1 : 0;
  a.y = a.x && str[3] ? str[3] - '0' : 0;
  b.x = a.y && str[4] == ':' && str[5] ? str[5] - 'A' + 1 : 0;
  b.y = b.x && str[6] && !(str[7]) ? str[6] - '0' : 0;
  free(str);
  return (valid_ship(size, a, b, prev_size) &&
	  insert_ship(size,
		       a.x > b.x || a.y > b.y ? a : b,
		       a.x > b.x || a.y > b.y ? b : a, data) ? size : 0);
}

bool	load_ships(char *file_name, char data[][WIDTH])
{
  char	*str;
  int	ships;
  int	fd;
  int	prev_size;
  
  fd = open(file_name, O_RDONLY);
  ships = -1;
  prev_size = FIRST_SHIP_LENGTH - 1;
  while (++ships < SHIPS)
    if (fd == -1 || !(str = get_next_line(fd)) ||
	!(prev_size = parse_ship_data(str, data, prev_size)))
      return (false);
  return (true);
}

void	display_ships(char data[][WIDTH])
{
  
}
