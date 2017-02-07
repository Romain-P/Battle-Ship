/*
** data_handler.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 15:34:25 2017 romain pillot
** Last update Tue Feb  7 16:03:25 2017 romain pillot
*/

#include "ship.h"
#include "display.h"

void	display_ships(char data[][WIDTH], t_side side)
{
  int   i;
  int   j;

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
	  display_char(!(data[i][j]) ? '.' : data[i][j]);
	}
      display_char('\n');
    }
  display_char('\n');
}
