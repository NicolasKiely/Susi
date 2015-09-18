#include <stdlib.h>
#include "context.h"


/**
 * Allocates and initalizes new context
 * @return Newly allocated context struct, or null on failure
 * @memory Needs to be freed by caller
 */
struct SLKCTX *SLFCTX_new()
{
    return calloc(1, sizeof(struct SLKCTX));
}

/**
 * Frees memory allocated to a context
 * @param pCtx Context to deallocate
 * @memory Any pointers to pCtx will be dangling
 */
void SLFCTX_free(struct SLKCTX *pCtx)
{
    if (pCtx == NULL){
        return;
    }
    free(pCtx);
}
