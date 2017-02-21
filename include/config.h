/*
** config.h for  in /home/romain.pillot/projects/PSU_2016_navy/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Feb  6 21:01:34 2017 romain pillot
** Last update Mon Feb 20 00:13:44 2017 romain pillot
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# define WIDTH (8)
# define HEIGHT (8)
# define SHIPS (4)
# define FIRST_SHIP_LENGTH (2)

#include "cell.h"
#include <stdbool.h>

typedef struct	s_navy
{
  char		ally[HEIGHT][WIDTH];
  char		enemy[HEIGHT][WIDTH];
  t_cell	cell;
  t_cell	holder;
  bool		init;
}		t_navy;

t_navy		*navy;

#endif /* CONFIG_H_ */
