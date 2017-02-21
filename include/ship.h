/*
** shift.h for  in /home/romain.pillot/projects/PSU_2016_navy/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 00:34:26 2017 romain pillot
** Last update Mon Feb 20 04:33:15 2017 romain pillot
*/

#ifndef SHIP_H_
# define SHIP_H_

# include "config.h"
# include <stdbool.h>
# include "cell.h"

typedef enum	e_side
{
  ALLY,
  ENEMY
}		t_side;

bool		load_ships(char *file_name, t_side side);

void		display_map(t_side side);

bool		attack_cell(t_cell cell, t_side side, bool force);

t_cell		*read_parse_cell();

bool		alive(t_side side, bool display);

bool		listen_signals();

#endif /* !SHIP_H_ */
