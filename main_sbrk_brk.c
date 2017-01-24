/*
** main_sbrk_brk.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/main_sbrk_brk.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:16:32 2017 Maxime PILLON
** Last update Mon Jan 23 10:16:33 2017 Maxime PILLON
*/

#include <unistd.h>
#include <stdio.h>
#include "inc/allocation.h"

int main()
{
  int *toto;
  char *var;

//sizeof(int) * 4
  if ((toto = my_malloc(sizeof(int) * 4)) == NULL)
    write(1, "tamere", 6);
  if ((var = my_malloc(sizeof(char) * 6)) == NULL)
    write(1, "tamere2", 7);

  toto[0] = 12;
  toto[1] = 24;
  toto[2] = 36;
  toto[18] = 42;


  var[0] = 'L';
  var[1] = 'O';
  var[2] = 'L';
  var[3] = '\0';
  printf("%d %d %d %d, %s\n", toto[0], toto[1], toto[2], toto[18], var);
}
