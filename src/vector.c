/*
** vector.c for  in /home/yoann.rey/System_Unix/PSU_2016_navy/src
** 
** Made by Yoann Rey
** Login   <yoann.rey@epitech.net>
** 
** Started on  Tue Feb  7 19:15:13 2017 Yoann Rey
** Last update Tue Feb  7 19:28:47 2017 Yoann Rey
*/

#include "vector.h"
#include <stdlib.h>

t_vector	*create_vector(int x, int y)
{
  t_vector	*vector;
  
  if (!(vector = malloc(sizeof(*vector))))
    return (NULL);
  vector->x = x;
  vector->y = y;
  return (vector);
}
