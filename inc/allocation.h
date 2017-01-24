/*
** allocation.h for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/inc/allocation.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 12:29:30 2017 Maxime PILLON
** Last update Tue Jan 24 12:42:43 2017 Sylvain CORSINI
*/

#ifndef PSU_2016_MALLOC_ALLOCATION_H
# define PSU_2016_MALLOC_ALLOCATION_H

void *my_malloc(size_t size);

struct block {
  size_t        size;
  struct block  *next;
  int           free;
  char          data[1];
};

typedef struct block t_block;

# define	BLOCK_SIZE (12)
# define  ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)


#endif //PSU_2016_MALLOC_ALLOCATION_H
