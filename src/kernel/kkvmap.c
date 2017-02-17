#include <stdlib.h>
#include "kkvmap.h"


struct SLUkkvMap *SLUkkvMap_new(void (*onRemove)(struct SLUktuple *))
{
  struct SLUkkvMap *map;

  // Allocate struct
  map = (struct SLUkkvMap *) malloc(sizeof(struct SLUkkvMap));
  if (!map)
    return NULL;

  map->onRemove = onRemove;
  SLUkkvMap_cstruct(map);

  return map;
}


void SLUkkvMap_cstruct(struct SLUkkvMap *m)
{
  m->len = 0;

  m->size = SLUkstr_DEFAULT_BUFFER_SIZE;
  m->tuples = (struct SLUktuple *) malloc(m->size*sizeof(struct SLUktuple));
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


bool SLUkkvMap_setk(struct SLUkkvMap *map, struct SLUkstr *key, void *val)
{
  if (!map || !key)
    return false;

  // Find tuple
  for (int i=0; i<map->len; i++){
    struct SLUktuple *tuple = map->tuples + i;
    if (SLUkstr_eq(key, tuple->key)){
      // Found match
      if (map->onRemove)
        map->onRemove(tuple); // Remove old value

      tuple->value = val; // Assign new value
      return true;
    }
  }

  // Key not found, add it
  if (map->len+1 == map->size){
    // Grow map
    map->size *= 2;
    map->tuples = (struct SLUktuple *) realloc(
        map->tuples, map->size*sizeof(struct SLUktuple)
    );
  }

  struct SLUktuple *tuple = map->tuples + map->len;
  map->len += 1;
  tuple->key = key;
  tuple->value = val;

  return false;
}


void *SLUkkvMap_getk(struct SLUkkvMap *map, struct SLUkstr *key)
{
  for (uint32_t i=0; i<map->len; i++){
    struct SLUktuple *tuple = map->tuples + i;
    if (SLUkstr_eq(key, tuple->key))
      return tuple->value;
  }
  return NULL;
}
