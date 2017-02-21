/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Mon Feb 20 01:54:39 2017 romain pillot
*/

#include "ship.h"
#include "number.h"
#include "signal.h"
#include <stdlib.h>
#include <unistd.h>
#include "ship.h"
#include "display.h"

static void	initialize()
{
  int           i;
  int           j;

  navy = malloc(sizeof(*navy));
  i = (j = -1);
  while (++i < HEIGHT && (j = -1))
    while(++j < WIDTH)
      navy->ally[i][j] = 0;
  i = (j = -1);
  while (++i < HEIGHT && (j = -1))
    while(++j < WIDTH)
      navy->enemy[i][j] = 0;
  navy->cell.x = 0;
  navy->cell.y = 0;
  navy->init = false;
}

static int	end()
{
  free(navy);
  return (84);
}

static void	display_help()
{
  display("TODO");
  free(navy);
}

static void	launch(int pid)
{
  display("my_pid:  ");
  putnbr(getpid());
  display_char('\n');
  if (!pid)
    {
      display("waiting for enemy connexion...\n");
      pause();
    }
  else
    {
      kill(pid, SIGUSR1);
      usleep(10000);
    }
}

int	main(int ac, char **args)
{
  char	*file;
  int	pid;

  if (ac == 1 || ac > 3 || !listen_signals())
    return (end());
  initialize();
  file = ac == 2 ? args[1] : args[2];
  if (!(load_ships(file, ALLY)))
    return (end());
  pid = ac == 2 ? -1 : getnbr(args[1]);
  if (file != NULL && file[0] == '-' && file[1] == 'h')
    display_help();
  else if (!pid)
    return (end());
  else
    launch(pid == -1 ? 0 : pid);
  return (0);
}
