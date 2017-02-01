/*
** show_mem_alloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/show_mem_alloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed Feb 01 10:21:42 2017 Maxime PILLON
** Last update Wed Feb 01 10:21:42 2017 Maxime PILLON
*/

#include <stdio.h>
#include <unistd.h>
#include "allocation.h"

void show_alloc_mem()
{
  t_block *tmp;

  printf("break : %p\n", sbrk(0));
  if (g_base_heap == NULL)
    return ;
  tmp = g_base_heap;
  while(tmp != NULL)
  {
    printf("%p - %p : %d bytes -- free %d\n",
	   tmp + BLOCK_SIZE,
	   tmp + BLOCK_SIZE + tmp->required_size,
	   (int)tmp->required_size,
	   tmp->free);
    tmp = tmp->next;
  }

}
