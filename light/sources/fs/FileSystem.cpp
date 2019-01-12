//
// Created by Jie on 19.1.5.
//

#include <direct.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "fs/IOUtils.h"
#include "fs/FileSystem.h"

#if _WIN32
#define SP_CHAR  '\\'
#else
#define SP_CHAR '/'
#endif

FileSystem::FileSystem() {
    console = spdlog::stdout_color_mt("FileSystem");
	m_home = IOUtils::getWorkDir();

	console->info("Home is {}", m_home);
}

FileSystem::FileSystem(const std::vector<std::string> &path) {
    console = spdlog::stdout_color_mt("FileSystem");
    m_pathList = path;
	m_home = IOUtils::getWorkDir();

	console->info("Home is {}", m_home);
}

FileSystem::~FileSystem() {

}

void FileSystem::mount(const std::string &path) {
    m_pathList.push_back(path);
}

void FileSystem::setWritePath(const std::string &path) {

}

std::string FileSystem::openAsString(const std::string &path) {
	auto homePath = fmt::format("{}{}{}", m_home, SP_CHAR, path);
    if(IOUtils::isFileExits(homePath)) {
        return IOUtils::readAsString(homePath);
    }

	for (const auto &pair : m_pathList) {
	    auto filePath = fmt::format("{}{}{}{}{}",m_home, SP_CHAR, pair, SP_CHAR, path );
	    console->info(filePath);
		if(IOUtils::isFileExits(filePath))
		    return IOUtils::readAsString(filePath);
	}

	console->error("File open failed! Not found! {}", path);
    return "";
}

bool FileSystem::writeToFile(const std::string &filePath, const char *data) {
    return IOUtils::writeToFile(filePath, data);
}
