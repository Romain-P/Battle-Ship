/*
** data_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 15:34:25 2017 romain pillot
** Last update Mon Feb 20 12:30:36 2017 romain pillot
*/

#include "ship.h"
#include "display.h"
#include "cell.h"
#include <stdlib.h>
#include "gnl.h"

bool	alive(t_side side, bool disp)
{
  char  (*data)[HEIGHT][WIDTH];
  int   i;
  int   j;
  int   k;
  bool  alive;

  data = side == ALLY ? &navy->ally : &navy->enemy;
  i = (j = -1);
  k = 0;
  alive = true;
  while (alive && i++ < HEIGHT && (j = -1))
    while (alive && ++j < WIDTH)
      if ((*data)[i][j] == 'x' && ++k == 14)
	alive = false;
  if (!alive && disp)
    display(side == ALLY ? "Enemy won" : "I won");
  return (alive);
}

t_cell	*read_parse_cell()
{
  char	*cell;
  int	i;
  int	j;

  display("attack:  \e[3m");
  cell = get_next_line(0);
  display("\e[0m");
  i = cell ? *cell - 'A' : -1;
  j = i >= 0 && cell[1] && !(cell[2]) ? cell[1] - '0' - 1 : -1;
  free(cell);
  if (i < 0 || j < 0 || i + 1 > WIDTH || j + 1 > HEIGHT)
    {
      display("wrong position\n");
      return (NULL);
    }
  return (create_cell((navy->holder.x = i), (navy->holder.y = j)));
}

bool		attack_cell(t_cell cell, t_side side, bool force)
{
  bool		hit;
  char		(*data)[HEIGHT][WIDTH];

  data = side == ALLY ? &navy->ally : &navy->enemy;
  (*data)[cell.y][cell.x] = force ||
    ((*data)[cell.y][cell.x] && (*data)[cell.y][cell.x] != 'o') ? 'x' : 'o';
  display_char(cell.y + 'A');
  display_char(cell.x + 1 + '0');
  display(":  ");
  hit = (*data)[cell.y][cell.x] == 'x';
  display(hit ? "hit\n\n\n" : "missed\n\n\n");
  return (hit);
}

void	display_map(t_side side)
{
  char	(*data)[HEIGHT][WIDTH];
  int   i;
  int   j;
  char	c;

  data = side == ALLY ? &navy->ally : &navy->enemy;
  i = (j = -1);
  display(side == ALLY ? "my positions:\n" : "enemy's positions\n");
  display(" |A B C D E F G H\n-+---------------\n");
  while (++i < HEIGHT && (j = -1))
    {
      display_digit(i + 1);
      display_char('|');
      while (++j < WIDTH)
	{
	  if (j > 0)
	    display_char(' ');
	  display_char(!(c = (*data)[i][j]) ? '.' : c);
	}
      display_char('\n');
    }
  display("\n\n");
}
