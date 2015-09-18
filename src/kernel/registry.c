#include <stdlib.h>
#include "registry.h"


/**
 * Allocates and initalizes new registry
 * @return Newly allocated registry struct, or null on failure
 * @memory Needs to be freed by caller
 */
struct SLKREG *SLFREG_new()
{
    struct SLKREG *pReg = calloc(1, sizeof(struct SLKREG));

    return pReg;
}

/**
 * Frees memory allocated to a registry
 * @param pReg Registry to deallocate
 * @memory Any pointers to pReg will be dangling
 */
void SLFREG_free(struct SLKREG *pReg)
{
    if (pReg == NULL){
        return;
    }
    free(pReg);
}
