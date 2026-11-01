#include "PathValidator.h"

// Allowed file extensions per asset type, as regex patterns

const std::unordered_map<FileType, std::regex> PathValidator::validExtensions =
{
    { FileType::TEXTURE, std::regex(R"(\.(png|jpg|jpeg)$)") },
    { FileType::FONT, std::regex(R"(\.(ttf|otf)$)") }
};

bool PathValidator::validate(const std::string& path, FileType fileType)
{
    try
    {
        fs::path filePath(path);
        // Path must exist
        if (!fs::exists(filePath))
        {
            std::cerr << "PathValidator ERROR: '" << path << "' doesn't exist." << std::endl;
            return false;
        }

        // Path must not be a directory
        if (fs::is_directory(filePath))
        {
            std::cerr << "PathValidator ERROR: '" << path << "' points to a directory, not a file." << std::endl;
            return false;
        }

        // Asset type must be known
        auto it = validExtensions.find(fileType);
        if (it == validExtensions.end())
        {
            std::cerr << "PathValidator ERROR: Unknown file type." << std::endl;
            return false;
        }

        // Extension must match the asset type
        const std::regex& pattern = it->second;
        if (!std::regex_search(path, pattern))
        {
            std::cerr << "PathValidator ERROR: File '" << path << "' has an invalid extension!" << std::endl;
            return false;
        }
    }
    catch (const fs::filesystem_error& e)
    {
        // filesystem error
        std::cerr << "PathValidator FATAL ERROR: " << e.what() << std::endl;
        return false;
    }

    // every check passed
    return true;
}
