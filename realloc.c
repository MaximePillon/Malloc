/*
** realloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/realloc/realloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:29:30 2017 Maxime PILLON
** Last update Mon Jan 23 10:29:30 2017 Maxime PILLON
*/

#include 	<unistd.h>
#include 	<memory.h>
#include 	"allocation.h"

void 		*thread_realloc(void *ptr, size_t size, t_block *block, void *new_block)
{
  if (ptr == NULL)
    return (thread_malloc(size));
  if (valid_block(ptr) == 1)
    {
      block = get_block(ptr);
      if (block->max_size >= size)
	{
	  block = split_block(block, size);
	  return ((void *) block + BLOCK_SIZE);
	}
      if (block->next != NULL && block->next->free == 1
	  && block->max_size + block->next->max_size + BLOCK_SIZE >= size)
	{
	  block = split_block(fusion_block(block), size);
	  return ((void *) block + BLOCK_SIZE);
	}
      new_block = thread_malloc(size);
      if (new_block == NULL)
	return (NULL);
      memcpy(new_block, ptr, block->max_size);
      thread_free(ptr);
      return (new_block);
    }
  return (ptr);
}

void 		*realloc(void *ptr, size_t size)
{
  t_block	*block;
  void		*new_block;

  block = NULL;
  new_block = NULL;
  pthread_mutex_lock(&lock);
  ptr = thread_realloc(ptr, size, block, new_block);
  pthread_mutex_unlock(&lock);
  return (ptr);
}
