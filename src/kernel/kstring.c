#include <stdlib.h>

// Primary header file
#include "kstring.h"


struct SLUkstr *SLUkstr_new(char *buf)
{
  if (buf){
    uint32_t blen = strlen(buf);
    return SLUkstr_cstruct(buf, blen);

  } else {
    return SLUkstr_cstruct(NULL, 0);
  }
}


struct SLUkstr *SLUkstr_cstruct(char *buf, uint32_t len)
{
  if (len >= (1 << 31))
    return NULL; // Check max size

  struct SLUkstr *sstr = (struct SLUkstr *) malloc(sizeof(struct SLUkstr));
  if (!sstr)
    return NULL; // Check allocation success

  // Calculate size
  uint32_t logSize;
  uint32_t tempLen = len;
  for (logSize=0; tempLen>0; logSize++)
    tempLen = tempLen >> 1;
  sstr->size = 1 << logSize;
  
  if (sstr->size < SLUkstr_DEFAULT_BUFFER_SIZE)
    sstr->size = SLUkstr_DEFAULT_BUFFER_SIZE; // Set minimum size


  if (!buf){
    // No string given; initialize empty string
    sstr->len = 0;
    sstr->buf = (char *) calloc(1, sstr->size);

  } else {
    // Copy from buffer
    sstr->len = len;
    sstr->buf = (char *) malloc(sstr->size);
    uint32_t i = 0;
    for (; i<len && buf[i]; i++){
      sstr->buf[i] = buf[i];
    }
    sstr->buf[len] = '\0'; // len < size, so this is allowed
  }

  return sstr;
}


void SLUkstr_dstruct(struct SLUkstr *sstr)
{
  if (!sstr)
    return;

  if (sstr->buf)
    free(sstr->buf);

  sstr->buf = NULL;
  sstr->len = 0;
  sstr->size = 0;
}


void SLUkstr_free(struct SLUkstr **sstr)
{
  if (!sstr)
    return;

  SLUkstr_dstruct(*sstr);

  if (*sstr)
    free(*sstr);

  *sstr = NULL;
}
