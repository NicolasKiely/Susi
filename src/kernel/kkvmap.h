/**
 * Handler for key-value maps
 */
#ifndef _KKVMAP_H_
#define _KKVMAP_H_

#include <stdint.h>
#include "kstring.h"


/**
 * Key value tuple
 */
struct SLUktuple {
  /** String-based key */
  struct SLUkstr *key;

  /** Value */
  void *value;
};


/**
 * Wrapper struct for key-value maps
 * Maps unqiue strings to objects
 */
struct SLUkkvMap {
  /** Number of objects in map */
  uint32_t len;

  /** Size of allocated buffer */
  uint32_t size;

  /** List of tuples */
  struct SLUktuple *tuples;

  /** Callback function when item is removed */
  void (*onRemove)(struct SLUktuple *);
};


/**
 * Returns an allocated and initialized new kv map
 */
struct SLUkkvMap *SLUkkvMap_new(void (*onRemove)(struct SLUktuple *));

/**
 * Destructor for kv map. Free internal allocated data in struct
 * @param map Map object to clean up
 */
void SLUkkvMap_dstruct(struct SLUkkvMap *map);


void SLUkkvMap_free(struct SLUkkvMap **map);


#endif
