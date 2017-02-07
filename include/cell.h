/*
** shifts.h for  in /home/romain.pillot/projects/PSU_2016_navy/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Feb  6 22:54:59 2017 romain pillot
** Last update Tue Feb  7 20:08:45 2017 romain pillot
*/

#ifndef CELL_H_
# define CELL_H_

# define ABS(x)	((x) < 0 ? (x) * -1 : (x))

typedef struct	s_cell
{
  int		x;
  int		y;
}		t_cell;

t_cell		*create_cell(int x, int y);

#endif /* !CELL_H_ */
