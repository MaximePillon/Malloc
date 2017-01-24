/*
** allocation.h for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/inc/allocation.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 12:29:30 2017 Maxime PILLON
** Last update Tue Jan 24 13:49:34 2017 Sylvain CORSINI
*/

#ifndef PSU_2016_MALLOC_ALLOCATION_H
# define PSU_2016_MALLOC_ALLOCATION_H

void *malloc(size_t size);
void free(void *ptr);

struct block {
  size_t        size;
  struct block  *next;
  struct block  *prev;
  int           free;
  void          *ptr;
};

typedef struct block t_block;

# define	BLOCK_SIZE (sizeof(struct block))

extern void *g_base_heap;

#endif //PSU_2016_MALLOC_ALLOCATION_H
