/*
** data_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 15:34:25 2017 romain pillot
** Last update Tue Feb  7 18:21:58 2017 Yoann Rey
*/

#include "ship.h"
#include "display.h"

bool	attack_cell(char *cell, char data[][WIDTH])
{
  int	i;
  int	j;
 
  i = cell ? *cell - 'A' : -1;
  j = i >= 0 && cell[1] && !(cell[2]) ? cell[1] - '0' - 1 : -1;

  display("attack:  ");
  display(cell);
  display_char('\n');
  if (i < 0 || j < 0 || i + 1 > WIDTH || j + 1 > HEIGHT)
    {
      display("wrong position\n");
      return (false);
    }
  data[j][i] = data[j][i] && data[j][i] != 'o' ? 'x' : 'o';
  display(cell);
  display(":  ");
  display(data[j][i] == 'x' ? "hit\n\n\n" : "missed\n\n\n");
  return (true);
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
	  display_char(!(c = data[i][j]) ||
		       (side == ENEMY && c != 'o' && c != 'x') ? '.' : c);
	}
      display_char('\n');
    }
  display("\n\n");
}
