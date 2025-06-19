#ifndef PATHVALIDATOR_H
#define PATHVALIDATOR_H

#include <string>
#include <vector>
#include <filesystem>
#include <regex>
#include <unordered_map>

#include "Definitions.h"

namespace fs = std::filesystem;

enum class FileType
{
	TEXTURE = 0,
	FONT
};

class PathValidator
{
private:
	static const std::unordered_map<FileType, std::regex> validExtensions;
public:
	static bool validate(const std::string& path, FileType fileType);
};


#endif 


