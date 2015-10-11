#ifndef _SUSI_KERNEL_SETTINGS_H_
#define _SUSI_KERNEL_SETTINGS_H_

#include "context.h"

namespace susi {
namespace kernel {
  
  /**
   * Manages configurable settings
   */
  class Settings:public Context
  {
    public:
      /**
       * Instantiates settings
       * @param argc Number of arguments
       * @param argv Array of argument strings
       */
      Settings(
          int argc,
          char *argv[]
      );
  }; // class Settings

} // namespace kernel
} // namespace settings

#endif
