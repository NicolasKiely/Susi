#include <stdlib.h>
#include "context.h"
#include "registry.h"
#include "settings.h"


/**
 * Allocates and initalizes new context
 * @return Newly allocated context struct, or null on failure
 * @memory Needs to be freed by caller
 */
struct SLKCTX *SLFCTX_new()
{
    struct SLKCTX *pCtx = calloc(1, sizeof(struct SLKCTX));
    if (pCtx == NULL){
        return NULL;
    }
    pCtx->pSettings = SLFREG_new();
    if (pCtx->pSettings == NULL){
        SLFCTX_free(pCtx);
        return NULL;
    }
    return pCtx;
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
    SLFREG_free(pCtx->pSettings);
    free(pCtx);
}
