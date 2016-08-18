#ifndef _KSTRING_H_
#define _KSTRING_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/** Default initial buffer size for kstrings */
#define SLUkstr_DEFAULT_BUFFER_SIZE 16

/**
 * String object used for kernel. Designed to store up to 2^32 characters.
 */
struct SLUkstr {
  /** String length */
  uint32_t len;

  /** Size of allocated buffer */
  uint32_t size;

  /** String buffer */
  char *buf;

  /** Whether or not struct "owns" buffer **/
  bool isOwner;
};


/**
 * Allocates and initializes a new string. Copies a c-string, and this
 * structure will own the buffer, with just enough length to hold the string.
 * @param buf String buffer to copy
 */
struct SLUkstr *SLUkstr_new(char *buf);


/**
 * Constructs a new string structure from scratch. If buf is null, then an
 * empty struct is initialized with a null buffer. Otherwise, if isOwner is
 * true, then the struct's buffer pointer is assigned to buf, and size and len
 * are assigned to size. If isOwner is false, the buffer is copied up to size
 * bytes with strncpy, and will attempt to append a null char, given that size>len.
 * @param buf Buffer to copy or own
 * @param len Length of string
 * @param size Amount of memory to allocate for char buffer
 * @param isOwner Whether or not structure owns the buffer
 */
struct SLUkstr *SLUkstr_cstruct(char *buf, uint32_t len, uint32_t size, bool isOwner);


/**
 * Deconstructor for k-string. Frees internal members of struct.
 * Use for freeing up k-strings created on a stack.
 * @param sstr K-string to clean up
 */
void SLUkstr_dstruct(struct SLUkstr *sstr);


/**
 * Frees allocated k-string, and buffer if struct owns it.
 * Use for freeing up k-strings allocated on the heap. DO NOT use on k-strings
 * created on the stack.
 * @param sstr Double pointer to k-string to free. Will be nulled
 */
void SLUkstr_free(struct SLUkstr **sstr);

#endif
