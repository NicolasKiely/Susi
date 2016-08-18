#ifndef _SUSI_KERNEL_GLOBAL_CONTEXT_H_
#define _SUSI_KERNEL_GLOBAL_CONTEXT_H_

#include <map>
#include <string>
#include "logger.h"

namespace susi {
namespace kernel {

  /**
   * Root context manager
   * Manages application configuration
   */
  class GlobalContext
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

      /** Application Shutdown */
      ~GlobalContext();

      /**
       * Fetches settings value
       * @param key Lookup token
       * @return Settings value, "" if not set
       */
      std::string &operator[](
          std::string &key
      );

      /**
       * C-string style of setting values
       * @param key Lookup token
       * @return Settings value, "" if not set
       */
      std::string &operator[](
          char *key
      );

      /**
       * Sets config key to a value
       * @param key Lookup token
       * @param value token value
       */
      void setConfig(
          std::string &key,
          std::string &val
      );

      /**
       * Retrieves config value. Do not use to check to see if a value
       * is set. It will always return a string regardless.
       * @param key Lookup token
       * @return Setting value, "" if not set
       */
      std::string &getConfig(
          std::string &key
      );

      /**
       * Sets config value if it hasn't been set already. Returns
       * final set value
       * @param key Configuration key
       * @param val Default value for config key
       * @return Old config value if set, or new value otherwise
       */
      std::string &defaultConfig(
          std::string &key,
          std::string &val
      );

      /**
       * Returns whether or not a config key is set
       * @param key Lookup token
       * @return True if set, false if not
       */
      bool hasConfig(
          std::string &key
      );

    private:
      /** Key:value configuration settings store */
      std::map<std::string, std::string> config;
      std::string empty;

  }; // class GlobalContext

} // namespace kernel
} // namespace susi

#endif
