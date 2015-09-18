#include <string.h>
#include "settings.h"
#include "context.h"

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
    char argFlag = '\0';
    int loadedSettings = 0;

    /* Process args */
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
}
