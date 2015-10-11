#include <vector>
#include "context.h"
#include "global_context.h"
#include "settings.h"

namespace susi {
namespace kernel {

  GlobalContext::GlobalContext(
      int argc,
      char *argv[]
  ): Context("global")
  {
    this->children = std::vector<Context *>(1);

    this->children[0] = new Settings(argc, argv);
  }

} // namespace kernel
} // namespace susi
