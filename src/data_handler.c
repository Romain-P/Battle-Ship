/*
** data_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 15:34:25 2017 romain pillot
** Last update Tue Feb  7 19:44:34 2017 Yoann Rey
*/

#include "ship.h"
#include "display.h"
#include "vector.h"
#include <stdlib.h>

bool	is_finished(char data[][WIDTH])
{
  int	i;
  int	j;

}

t_vector	*parse_cell(char *cell, char data[][WIDTH])
{
  int		i;
  int		j;

  i = cell ? *cell - 'A' : -1;
  j = i >= 0 && cell[1] && !(cell[2]) ? cell[1] - '0' - 1 : -1;
  display("attack:  \033[24m");
  display(cell);
  display_char('\n');
  if (i < 0 || j < 0 || i + 1 > WIDTH || j + 1 > HEIGHT)
    {
      display("wrong position");
      return (NULL);
    }
  return (create_vector(i, j));
}

void	attack_cell(t_vector cell, char data[][WIDTH])
{
  data[cell.y][cell.x] = data[cell.y][cell.x] &&data[cell.y][cell.x] != 'o'
    ? 'x' : 'o';
  display_char(cell.y + 1 + 'A');
  display_char(cell.x + 1 + '0');
  display(":  ");
  display(data[cell.y][cell.x] == 'x' ? "hit\n\n\n" : "missed\n\n\n");
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
