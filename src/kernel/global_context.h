#ifndef _SUSI_KERNEL_GLOBAL_CONTEXT_H_
#define _SUSI_KERNEL_GLOBAL_CONTEXT_H_

#include <string>
#include "context.h"

namespace susi {
namespace kernel {

  /**
   * Root context manager
   */
  class GlobalContext:Context
  {
    public:
      /**
       * Instantiate context as "Global"
       * @param argc Number of arguments
       * @param argv Array of argument strings
       */
      GlobalContext(
          int argc,
          char *argv[]
      );

      /**
       * Fetches settings value
       * @param key Lookup token
       * @return Settings value, "" if not set
       */
      std::string operator[](
          std::string key
      );
  }; // class GlobalContext

} // namespace kernel
} // namespace susi

#endif
