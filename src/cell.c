/*
** vector.c for  in /home/yoann.rey/System_Unix/PSU_2016_navy/src
** 
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
** 
** Started on  Tue Feb  7 19:15:13 2017 Yoann Rey
** Last update Tue Feb  7 20:06:20 2017 romain pillot
*/

#include "cell.h"
#include <stdlib.h>

t_cell		*create_cell(int x, int y)
{
  t_cell	*cell;
  
  if (!(cell = malloc(sizeof(*cell))))
    return (NULL);
  cell->x = x;
  cell->y = y;
  return (cell);
}
