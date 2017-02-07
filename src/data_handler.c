/*
** data_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 15:34:25 2017 romain pillot
** Last update Tue Feb  7 20:31:33 2017 romain pillot
*/

#include "ship.h"
#include "display.h"
#include "cell.h"
#include <stdlib.h>

bool	alive(char data[][WIDTH])
{
  int	i;
  int	j;
  bool	alive;
  char	c;

  i = (j = -1);
  alive = false;
  while (!alive && ++i < HEIGHT && (j = -1))
    while(++j < WIDTH && !(alive = (c = data[i][j]) && c != 'o' && c != 'x'));
  if (!alive)
    display("Enemy won");
  return (alive);
}

t_cell	*parse_cell(char *cell)
{
  int	i;
  int	j;

  i = cell ? *cell - 'A' : -1;
  j = i >= 0 && cell[1] && !(cell[2]) ? cell[1] - '0' - 1 : -1;
  display("attack:  \e[3m");
  display(cell);
  display("\e[0m");
  display_char('\n');
  if (i < 0 || j < 0 || i + 1 > WIDTH || j + 1 > HEIGHT)
    {
      display("wrong position");
      return (NULL);
    }
  return (create_cell(i, j));
}

void		attack_cell(t_cell *cellp, char data[][WIDTH])
{
  t_cell	cell;

  cell = *cellp;
  data[cell.y][cell.x] = data[cell.y][cell.x] && data[cell.y][cell.x] != 'o'
    ? 'x' : 'o';
  display_char(cell.y + 1 + 'A');
  display_char(cell.x + 1 + '0');
  display(":  ");
  display(data[cell.y][cell.x] == 'x' ? "hit\n\n\n" : "missed\n\n\n");
  free(cellp);
}

void	display_ships(char data[][WIDTH], t_side side)
{
  int   i;
  int   j;
  char	c;

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
	  display_char(!(c = data[i][j]) ? '.' : c);
	}
      display_char('\n');
    }
  display("\n\n");
}
