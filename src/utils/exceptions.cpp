#include "exceptions.hpp"

namespace Utils {
    Exception::Exception(bool fatal, int returnId)
        : fatal(fatal),
          returnId(returnId) {}

    LoadingException::LoadingException(std::string path, bool fatal)
        : Exception(fatal, 2),
          path(path) {}

    const std::string LoadingException::desc() const noexcept {
        return "LoadingException: can't load " + path;
    }

}
