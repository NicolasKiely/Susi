#ifndef _SUSI_KERNEL_CONTEXT_H_
#define _SUSI_KERNEL_CONTEXT_H_

#include <vector>
#include <string>
#include "logger.h"

namespace susi {
namespace kernel {
    
  class Context
  {
  public:
    /**
     * Contructor for named contexts
     * @param newName New name for this context
     */
    Context(std::string newName);
    
    /**
     * Constructor for anonymous contexts
     */
    Context();

    ~Context();

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
