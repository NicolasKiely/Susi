/* Central repository of application runtime data
 */
#ifndef KERNEL_CONTEXT_H
#define KERNEL_CONTEXT_H

#include "registry.h"

/* Top-level context data structure */
struct SLKCTX
{
    /* Settings registry */
    struct SLKREG settings;
};

/* Creates a brand new context data structure */
struct SLKCTX *SLFCTX_new();

/* Frees context */
void SLFCTX_free(struct SLKCTX *pCtx);

#endif
