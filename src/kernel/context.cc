#include <string>
#include "context.h"


namespace susi {
namespace kernel {

  Context::Context(
      std::string newName
  ): name(newName)
  {
    Logger::info("Starting "+ newName +" context");
  }


  Context::Context(
  ): name("")
  {
    Logger::info("Starting anonymous context");
  }


  Context::~Context()
  {
    for (unsigned int i=0; i<this->children.size(); i++){
      delete this->children[i];
    }
    if (this->name.size() > 0){
      Logger::info("Shutting down "+ this->name +" context");
    }
  }


  std::string Context::getName()
  {
    return this->name;
  }

} // namespace kernel
} // namespace susi
