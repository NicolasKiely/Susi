#include <stdlib.h>

// Primary header file
#include "kstring.h"


struct SLUkstr *SLUkstr_new(char *buf)
{
  if (buf){
    uint32_t blen = strlen(buf);
    return SLUkstr_cstruct(buf, blen, blen+1, true);
  } else {
    return SLUkstr_cstruct(NULL, 0, 0, true);
  }
}


struct SLUkstr *SLUkstr_cstruct(char *buf, uint32_t len, uint32_t size, bool isOwner)
{
  struct SLUkstr *sstr = (struct SLUkstr *) malloc(sizeof(struct SLUkstr));
  if (sstr == NULL)
    return NULL;

  sstr->size = size;

  if (buf == NULL){
    sstr->len = 0;

    if (size > 0){
      /* Initialize empty string. Struct must own string */
      sstr->isOwner = true;
      sstr->buf = (char *) calloc(1, size);

    } else {
      /* Initialize null string */
      sstr->isOwner = isOwner;
      sstr->buf = NULL;
    }

  } else {
    sstr->isOwner = isOwner;
    sstr->len = len;

    if (isOwner){
      /* Assign as buffer */
      sstr->buf = buf;

    } else {
      /* Copy from buffer (note: not the same as strncpy) */
      sstr->buf = (char *) malloc(size);
      uint32_t i = 0;
      for (; i < len; i++){
        sstr->buf[i] = buf[i];
      }
      if (i < size){
        /* Append null char, if space is left over */
        sstr->buf[i] = '\0';
      }
    }
  }
}


void SLUkstr_dstruct(struct SLUkstr *sstr)
{
  if (!sstr)
    return;

  if (sstr->isOwner && sstr->buf){
    free(sstr->buf);
  }
  sstr->buf = NULL;
  sstr->size = 0;
  sstr->len = 0;
}


void SLUkstr_free(struct SLUkstr **sstr)
{
  if (!sstr)
    return;

  SLUkstr_dstruct(*sstr);

  if (!*sstr)
    free(*sstr);

  *sstr = NULL;
}
