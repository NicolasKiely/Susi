#include <stdlib.h>
#include "kkvmap.h"


struct SLUkkvMap *SLUkkvMap_new(void (*onRemove)(struct SLUktuple *))
{
  struct SLUkkvMap *map;

  map = (struct SLUkkvMap *) malloc(sizeof(struct SLUkkvMap));
  if (!map)
    return NULL;

  map->len = 0;
  map->tuples = NULL;
  map->onRemove = onRemove;
  map->size = 0;

  return map;
}


void SLUkkvMap_dstruct(struct SLUkkvMap *map)
{
  if (!map)
    return;

  if (map->tuples){
    uint32_t i;
    if (map->onRemove){
      for (i=0; i<map->len; i++)
        map->onRemove(map->tuples + i);
    }
    for (i=0; i<map->len; i++){
      if (map->onRemove)
        map->onRemove(map->tuples + i); // callback
      SLUkstr_free(&(map->tuples + i)->key);
    }
    free(map->tuples);
    map->tuples = NULL;
  }
}


void SLUkkvMap_free(struct SLUkkvMap **map)
{
  if (!map)
    return;

  SLUkkvMap_dstruct(*map);

  if (*map)
    free(*map);

  *map = NULL;
}
