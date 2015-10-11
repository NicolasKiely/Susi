#include <map>
#include <string>
#include "logger.h"
#include "settings.h"

namespace susi {
namespace kernel {

  Settings::Settings(
      int argc,
      char *argv[]
  ): Context("settings")
  {
    bool readingFlag = true;
    char *key;

    /* Read program arguments */
    for (int i=1; i<argc; i++){
      char *arg = argv[i];

      if (readingFlag){
        if (arg[0] == '-') {
          /* Read arg flag */
          if (arg[1] != '\0'){
            /* Set setting key */
            key = arg + 1;
            readingFlag = false;

          } else {
            Logger::warn("Empty flag passed as parameter");
          }

        } else {
          Logger::warn("Expecting flag argument, got "+ std::string(arg));
        }

      } else {
        /* Read arg value */
        readingFlag = true;
        this->set(key, arg);
      }
    }

    if (!readingFlag){
      Logger::warn("Dangling parameter flag: "+ std::string(key));
    }
  }


  std::string Settings::get(
      std::string key
  )
  {
    std::map<std::string, std::string>::iterator iter =
      this->settings.find(key);
    if (iter == this->settings.end()){
      return "";
    } else {
      return iter->second;
    }
  }


  bool Settings::has(
      std::string key
  )
  {
    std::map<std::string, std::string>::iterator iter =
      this->settings.find(key);
    return !(iter==this->settings.end());
  }


  void Settings::set(
      std::string key,
      std::string value
  )
  {
    this->settings[key] = value;
  }

} // namespace kernel
} // namespace susi
