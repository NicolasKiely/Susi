#ifndef _SUSI_KERNEL_SETTINGS_H_
#define _SUSI_KERNEL_SETTINGS_H_

#include <map>
#include <string>
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

      /**
       * Retrives setting value. Do not use to check to see if a value
       * is set. It will always return a string regardless.
       * @param key Lookup token
       * @return Setting value, "" if not set
       */
      std::string get(
          std::string key
      );

      /**
       * Returns whether or not a key is set
       * @param key Lookup token
       * @return True if set, false if not
       */
      bool has(
          std::string key
      );

      /**
       * Sets key to a value
       * @param key Lookup token
       * @param value token value
       */
      void set(
          std::string key,
          std::string value
      );

    private:
      /** Key:value settings store */
      std::map<std::string, std::string> settings;
  }; // class Settings

} // namespace kernel
} // namespace settings

#endif
