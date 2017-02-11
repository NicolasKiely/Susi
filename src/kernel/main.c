#include <string.h>
#include <stdlib.h>
#include "kstring.h"
//#include "settings.h"
//#include "context.h"

/* Boot sequence:
 *   -Initialize core context
 *   -Read args
 *   -Process settings file
 *
 * Command args:
 *   -f <file>: Settings file to read (default "settings.txt")
 *   -s <settings line>: Override settings line
 */
int main(int argc, char* argv[])
{
    //char argFlag = '\0';
    //int loadedSettings = 0;

    // Initialize core context
    /*
    struct SLKCTX *pCtx = SLFCTX_new();

    // Process args
    for (int i=0; i<argc; i++){
        if (argv[i][0] == '-'){
            argFlag = argv[i][1];

        } else {
            switch (argFlag){
            case 'f':
                break;
            case 's':
                loadedSettings = -1;
                break;
            }
        }
    }

    // Free context
    SLFCTX_free(pCtx);
    pCtx = NULL;
    */

    return EXIT_SUCCESS;
}
