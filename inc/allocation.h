/*
** allocation.h for PSU_2016_malloc in /home/god/TEK2/PSU_MEMOIRE/PSU_2016_malloc/inc/allocation.h
**
** Made by Maxime PILLON
** Login   <maxime.pillon@epitech.eu>
**
** Started on  Mon Jan 23 12:29:30 2017 Maxime PILLON
** Last update Mon Jan 23 12:29:30 2017 Maxime PILLON
*/

#ifndef PSU_2016_MALLOC_ALLOCATION_H
# define PSU_2016_MALLOC_ALLOCATION_H

# include <glob.h>

void *malloc(size_t size);

typedef struct block {
  size_t 	dataSize;
}		t_struct;

# define	BLOCK_SIZE 4

#endif //PSU_2016_MALLOC_ALLOCATION_H
