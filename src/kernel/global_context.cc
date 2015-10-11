#include "global_context.h"

namespace susi {
namespace kernel {

  GlobalContext::GlobalContext(
      int argc,
      char *argv[]
  ): Context("global")
  {
  }

} // namespace kernel
} // namespace susi
