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

  std::string GlobalContext::operator[](
      std::string key
  )
  {
    return ((Settings *) this->children[0])->get(key);
  }

} // namespace kernel
} // namespace susi
