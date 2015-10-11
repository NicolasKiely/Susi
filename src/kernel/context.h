#ifndef _SUSI_KERNEL_CONTEXT_H_
#define _SUSI_KERNEL_CONTEXT_H_

#include <vector>
#include <string>

namespace susi {
namespace kernel {
    
  class Context
  {
  public:
    /**
    * Default contructors for context
    * @param newName New name for this context, or empty for no name
    */
    Context(std::string newName): name(newName) {};
    Context(): name("") {};

    /**
    * Returns Context's type name
    * @return Name of this context
    */
    std::string getName();

  protected:
    /** Child contexts */
    std::vector<Context *> children;

  private:
    /* Context type */
    std::string name;
  }; // class Context

} // namespace kernel
} // namespace susi

#endif // _CONTEXT_H_
