#include <stdlib.h>
#include "libmy_malloc.h"

t_chunk		*find_chunk(t_chunk *tmp, void *ptr)
{
  if (ptr == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      if (tmp->address == ptr)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
