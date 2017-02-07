/*
** shift.h for  in /home/romain.pillot/projects/PSU_2016_navy/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 00:34:26 2017 romain pillot
** Last update Tue Feb  7 16:16:24 2017 romain pillot
*/

#ifndef SHIP_H_
# define SHIP_H_

# include "config.h"
# include <stdbool.h>

typedef enum	e_side
{
  ALLY,
  ENNEMY
}		t_side;

bool	load_ships(char *file_name, char data[][WIDTH]);

void	display_ships(char data[][WIDTH], t_side side);

void	attack_cell(char *cell, char data[][WIDTH]);

#endif /* !SHIP_H_ */
