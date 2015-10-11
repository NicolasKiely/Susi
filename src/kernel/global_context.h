#ifndef _SUSI_KERNEL_GLOBAL_CONTEXT_H_
#define _SUSI_KERNEL_GLOBAL_CONTEXT_H_

#include <string>
#include "context.h"

namespace susi {
namespace kernel {

  class GlobalContext:Context {
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
  }; // class GlobalContext

} // namespace kernel
} // namespace susi

#endif
