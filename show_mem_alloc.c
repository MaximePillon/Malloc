/*
** show_mem_alloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/show_mem_alloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Wed Feb 01 10:21:42 2017 Maxime PILLON
** Last update Wed Feb 01 10:21:42 2017 Maxime PILLON
*/

#include 	<stdio.h>
#include 	<unistd.h>
#include 	"allocation.h"

void 		show_alloc_mem()
{
  t_block 	*tmp;

  printf("break : %p\n", sbrk(0));
  if (g_base_heap == NULL)
    return ;
  tmp = g_base_heap;
  while(tmp != NULL)
  {
    printf("%p - %p : %d bytes\n",
	   tmp + BLOCK_SIZE,
	   tmp + BLOCK_SIZE + tmp->required_size,
	   (int)tmp->required_size);
    tmp = tmp->next;
  }
}

void extend_show_alloc_mem()
{
  t_block *tmp;

  dprintf(1, "base : %p\n", g_base_heap);
  dprintf(1, "break : %p\n", sbrk(0));
  if (g_base_heap == NULL)
    return ;
  tmp = g_base_heap;
  while(tmp != NULL)
    {
      dprintf(1, "block : %p; ", tmp);
      dprintf(1, "max_size : %lu; ", tmp->max_size);
      dprintf(1, "required_size : %lu; ", tmp->required_size);
      dprintf(1, "prev : %p; ", tmp->prev);
      dprintf(1, "next : %p; ", tmp->next);
      dprintf(1, "free : %d.\n", tmp->free);
      tmp = tmp->next;
    }
}
