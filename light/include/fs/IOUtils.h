
#include <string>

#include "Light.h"

#define MAX_LENGTH 255

class LightAPI IOUtils {
public:
    static std::string getWorkDir();

	static bool isFileExits(const std::string path);
	static bool isDirExits(const std::string path);

	static bool createDir(const std::string path);
	static bool deleteDir(const std::string path);
	static bool deleteFile(const std::string filePath);

	static bool writeToFile(const std::string filePath, std::string text);
	static std::string readAsString(const std::string filePath);
};