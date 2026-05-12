#include "LinuxExecutablePath.hpp"
#include <stdexcept>
#include <string>

#ifdef __linux__
#include <unistd.h>
#endif

std::string LinuxExecutablePath::get() const
{
#ifdef __linux__
    char buffer[4096];

    ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);

    if (length == -1)
    {
        throw std::runtime_error("Failed to get executable path");
    }

    buffer[length] = '\0';

    std::string toReturn(buffer);
    size_t pos = toReturn.rfind('/');

    if (pos != std::string::npos)
    {
        toReturn.erase(pos);
    }
    toReturn += "/";

    return toReturn;
#elif
    throw std::runtime_error("Cannot run linux code on other platform");
#endif
}
