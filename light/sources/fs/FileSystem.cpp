//
// Created by Jie on 19.1.5.
//

#include <filesystem>

#include "fs/FileSystem.h"

FileSystem::FileSystem(const std::vector<std::string> &path) {
    m_pathList = path;
}

FileSystem::~FileSystem() {

}

void FileSystem::mount(const std::string &path) {
    m_pathList.push_back(path);
}

void FileSystem::setWritePath(const std::string &path) {

}

std::string FileSystem::openAsString(const std::string &path) {
    return "";
}

bool FileSystem::writeToFile(const std::string &filePath, const char *data) {
    return true;
}
