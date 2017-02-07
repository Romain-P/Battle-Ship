/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Tue Feb  7 15:59:36 2017 romain pillot
*/

#include "ship.h"

int	main(int ac, char **args)
{
  char	data[HEIGHT][WIDTH];
  int	i;
  int	j;

  i = (j = -1);
  while (++i < HEIGHT && (j = -1))
    while(++j < WIDTH)
      data[i][j] = 0;
  load_ships("pos2", data);
  display_ships(data, ALLY);
  return (0);
}
