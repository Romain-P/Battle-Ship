/*
** display.c for  in /home/romain.pillot/projects/PSU_2016_navy/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue Feb  7 14:39:21 2017 romain pillot
** Last update Tue Feb  7 15:49:28 2017 Yoann Rey
*/

static int	strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] && ++i);
  return (i);
}

void	display(char *str)
{
  write(1, str, strlen(str));
}
