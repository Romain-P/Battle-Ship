/*
** shifts.h for  in /home/romain.pillot/projects/PSU_2016_navy/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Feb  6 22:54:59 2017 romain pillot
** Last update Tue Feb  7 19:24:07 2017 Yoann Rey
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# define ABS(x)	((x) < 0 ? (x) * -1 : (x))

typedef struct	s_vector
{
  int		x;
  int		y;
}		t_vector;

t_vector	*create_vector(int x, int y);

#endif /* !VECTOR_H_ */
