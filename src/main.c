/*
1;4600;0c** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Tue Feb  7 20:32:11 2017 romain pillot
*/

#include "ship.h"

int	main()
{
  char	ally[HEIGHT][WIDTH];
  char	enmy[HEIGHT][WIDTH];
  int	i;
  int	j;

  i = (j = -1);
  while (++i < HEIGHT && (j = -1))
    while(++j < WIDTH)
      ally[i][j] = 0;
  i = (j = -1);
  while (++i < HEIGHT && (j = -1))
    while(++j < WIDTH)
      enmy[i][j] = 0;
  load_ships("pos1", ally);
  parse_cell("B2");
  display_ships(ally, ALLY);
  display_ships(enmy, ALLY);
  alive(enmy);
  return (0);
}
