#include <vector>
#include "global_context.h"

namespace susi {
namespace kernel {

  GlobalContext::GlobalContext(
      int argc,
      char *argv[]
  ){
    Logger::info("Initializing global context");

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
        this->setConfig(key, arg);
      }
    }

    if (!readingFlag){
      Logger::warn("Dangling parameter flag: "+ std::string(key));
    }

  }


  GlobalContext::~GlobalContext()
  {
    Logger::info("Shutting down global context");
  }


  std::string &GlobalContext::operator[](
      std::string &key
  ){
    return this->getConfig(key);
  }


  std::string &GlobalContext::operator[](
      char *key
  ){
    return this->getConfig(std::string(key));
  }


  void GlobalContext::setConfig(
      std::string &key,
      std::string &value
  ){
    this->config[key] = value;
  }


  std::string &GlobalContext::getConfig(
      std::string &key
  ){
    std::map<std::string, std::string>::iterator iter =
      this->config.find(key);
    if (iter == this->config.end()){
      this->config[key] = "";
      return this->config[key];

    } else {
      return iter->second;
    }
  }


  std::string &GlobalContext::defaultConfig(
      std::string &key,
      std::string &val
  ){
    std::map<std::string, std::string>::iterator iter =
      this->config.find(key);
    if (iter == this->config.end()){
      this->config[key] = val;
      return this->config[key];

    } else {
      return iter->second;
    }
  }


  bool GlobalContext::hasConfig(
      std::string &key
  ){
    std::map<std::string, std::string>::iterator iter =
      this->config.find(key);
    return !(iter==this->config.end());
  }

} // namespace kernel
} // namespace susi
