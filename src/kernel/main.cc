#include <iostream>
#include "logger.h"


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
  using namespace susi::kernel;

  /* Just use stdout for logging for now. May change later, but this must
     always be set first before Contexts are initialized, since they use this
     logger class too */
  Logger::setStream(&std::cout);
}
