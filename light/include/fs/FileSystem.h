//
// Created by Jie on 19.1.5.
//

#ifndef light_file_system_h
#define light_file_system_h

#include <string>
#include <vector>

#include "Light.h"

class LightAPI FileSystem {
public:
    FileSystem() = default;

    explicit FileSystem(const std::vector<std::string>& path);
    ~FileSystem() noexcept;

    void mount(const std::string& path);
    void setWritePath(const std::string& path);

    std::string openAsString(const std::string& path);
    bool writeToFile(const std::string& filePath, const char* data);


private:
    std::vector<std::string> m_pathList;
};

#endif //light_file_system_h
