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
#include "allocation.h"

int main()
{
  char *tmp;
  char *tmp1;
  char *tmp2;
  char *tmp3;

  if ((tmp = malloc(sizeof(20))) == NULL)
    return (-1);
  if ((tmp1 = malloc(sizeof(40))) == NULL)
    return (-1);
  if ((tmp2 = malloc(sizeof(80))) == NULL)
    return (-1);
  if ((tmp3 = malloc(sizeof(5000))) == NULL)
    return (-1);

  show_alloc_mem();
  printf("----\n\n----");
  free(tmp);
  show_alloc_mem();
  printf("----\n\n----");
  free(tmp1);
  show_alloc_mem();
  printf("----\n\n----");
  free(tmp2);
  show_alloc_mem();
  printf("----\n\n----");
  free(tmp3);
  show_alloc_mem();


}
