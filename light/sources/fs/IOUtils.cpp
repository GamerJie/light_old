
#include "fs/IOUtils.h"

#if _WIN32
#include <io.h>
#include <direct.h>
#define MODE
#else
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MODE ,0777
#endif

#include <stdio.h>
#include <fstream>
#include <stdlib.h>

std::string IOUtils::getWorkDir() {
    char pwd[MAX_LENGTH];
    _getcwd(pwd, MAX_LENGTH);
    return std::string(pwd);
}

bool IOUtils::isFileExits(const std::string path) {
	return _access(path.c_str(), 0) == 0;
}

bool IOUtils::isDirExits(const std::string path) {
	return _access(path.c_str(), 0) == 0;
}

bool IOUtils::createDir(const std::string path) {
	return _mkdir(path.c_str() MODE) == 0;
}

bool IOUtils::deleteDir(const std::string path) {
	return _mkdir(path.c_str()) == 0;
}

bool IOUtils::deleteFile(const std::string filePath) {
	if (IOUtils::isFileExits(filePath)) {
		return remove(filePath.c_str()) == 0;
	}
	return true;
}

bool IOUtils::writeToFile(const std::string filePath, std::string text) {
	IOUtils::deleteFile(filePath);

	std::ofstream ofs;
    ofs.open(filePath);
    ofs << text;
    ofs.close();

	return true;
}

std::string IOUtils::readAsString(const std::string filePath) {
	if (!IOUtils::isFileExits(filePath))
		return "";

	std::ifstream ifs;
	ifs.open(filePath.c_str());
    std::istreambuf_iterator<char> begin(ifs);
    std::istreambuf_iterator<char> end;
    return std::string(begin, end);
}