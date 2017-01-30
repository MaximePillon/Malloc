/*
** realloc.c for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/realloc/realloc.c
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 10:29:30 2017 Maxime PILLON
** Last update Mon Jan 23 10:29:30 2017 Maxime PILLON
*/

#include <unistd.h>
#include <memory.h>
#include "allocation.h"

static void *extend_block(t_block *block, size_t size)
{
  size_t sufficient_size;

  sufficient_size = size + BLOCK_SIZE;//sufficient_size = get_sufficient_size_of_malloc(size);
  if (sbrk(sufficient_size - block->max_size) == NULL)
    return (NULL);
  block->max_size = sufficient_size - BLOCK_SIZE;
  block->required_size = size;
  return (block);
}

static void *check_neighbor(t_block *block, size_t size)
{
  if (block->next != NULL && block->next->free == 1)
    {
      if (block->max_size + block->next->max_size + BLOCK_SIZE >= size)
	return (split_block(fusion_block(block), size));
      else if (block->prev != NULL && block->prev->free == 1)
	return (split_block(fusion_block(fusion_block(block->prev)), size));
    }
  if (block->prev != NULL && block->prev->free == 1)
    {
      if (block->max_size + block->prev->max_size + BLOCK_SIZE >= size)
	return (split_block(fusion_block(block->prev), size));
      else if (block->next == NULL)
	return (extend_block(fusion_block(block->prev), size));
    }
  if (block->next == NULL)
    return (extend_block(block, size));
  return (NULL);
}

void *realloc(void *ptr, size_t size)
{
  t_block *block;
  t_block *new_block;

  if (ptr == NULL)
    return (malloc(size));
  if (valid_block(ptr) == 1)
    {
      block = get_block(ptr);
      if (block->max_size >= size)
	return (split_block(block, size));
      new_block = check_neighbor(block, size);
      if (new_block != NULL)
	return (new_block);
      new_block = malloc(size);
      if (new_block == NULL)
	{
	  free(ptr);
	  return (NULL);
	}
      memcpy(block, new_block, block->max_size + BLOCK_SIZE);
      free(ptr);
      return (new_block);
    }
  return (NULL);
}
