/*
** shift_parser.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Feb  6 20:52:39 2017 romain pillot
** Last update Tue Feb  7 00:36:14 2017 romain pillot
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gnl.h"
#include "vector.h"
#include "shift.h"

static bool	insert_shift(int size, t_vector a, t_vector b, char data[][WIDTH])
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

static bool	valid_shift(int size, t_vector a, t_vector b, int prev_size)
{
  return (size == prev_size + 1 &&
	  a.x == b.x ? ABS(a.y - b.y) + 1 == size : ABS(a.x - b.x) + 1 == size &&
	  a.x > 0 && a.y > 0 && b.x > 0 && b.y > 0 &&
	  a.x <= WIDTH && a.y <= HEIGHT && b.x <= WIDTH && b.y <= HEIGHT);
}

static int	parse_shift_data(char *str, char data[][WIDTH], int prev_size)
{
  int		size;
  t_vector	a;
  t_vector	b;

  size = *str ? str[0] - '0' : 0;
  a.x = size && str[1] && str[2] ? str[2] - 'A' + 1 : 0;
  a.y = a.x && str[3] ? str[3] - '0' : 0;
  b.x = a.y && str[4] && str[5] ? str[5] - 'A' + 1 : 0;
  b.y = b.x && str[6] ? str[6] - '0' : 0;
  free(str);
  return (valid_shift(size, a, b, prev_size) &&
	  insert_shift(size,
		       a.x > b.x || a.y > b.y ? a : b,
		       a.x > b.x || a.y > b.y ? b : a, data) ? size : 0);
}

bool	load_shifts(char *file_name, char data[][WIDTH])
{
  char	*str;
  int	shifts;
  int	fd;
  int	prev_size;
  
  fd = open(file_name, O_RDONLY);
  shifts = -1;
  prev_size = FIRST_SHIFT_LENGTH - 1;
  while (++shifts < SHIFTS)
    if (fd == -1 || !(str = get_next_line(fd)) ||
	!(prev_size = parse_shift_data(str, data, prev_size)))
      return (false);
  return (true);
}
