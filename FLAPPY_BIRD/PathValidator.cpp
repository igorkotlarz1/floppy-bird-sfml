#include "PathValidator.h"

// Definicja i inicjalizacja mapy dozwolonych rozszerzeñ
const std::unordered_map<FileType, std::vector<std::string>> PathValidator::validExtensions = {
    {FileType::TEXTURE, {".png", ".jpg", ".jpeg"}}, 
    {FileType::FONT, {".ttf", ".otf"}},
};


bool PathValidator::validate(const std::string& path, FileType fileType)
{
    fs::path filePath(path);

    //Walidacja sciezki
    if (!std::filesystem::exists(filePath))
    {
        std::cerr << "PathValidator ERROR: " << path << "doesn't exist exist." << std::endl;
        return false;
    }

    fs::path dirPath = filePath.parent_path();

    //Walidacja katalogu nadrzednego
    if (!dirPath.empty() && !fs::exists(dirPath))
    {
        std::cout << "PathValidator ERROR: Directory " << dirPath.string() << " doesn't exist for file " << path << "!\n";
        return false;
    }

    if (!fs::is_directory(dirPath)) //!dirPath.empty() &&
    {
        std::cout << "PathValidator ERROR: Directory " << dirPath.string() << " is not a directory!\n";
        return false;
    }

    // Walidacja rozszerzen
    std::string extension = filePath.extension().string();

    if (extension.empty())
    {
        std::cout << "PathValidator ERROR: File path " << path << " has no extension!\n";
        return false;
    }

    //Walidacja podanego typu pliku do wczytania w argumencie
    auto it = validExtensions.find(fileType);

    if (it == validExtensions.end())
    {
        std::cout << "PathValidator ERROR: Unknown file type!\n";
        return false;
    }

    //Walidacja rozszerzenia pliku
    const std::vector<std::string>& allowedExtensions = it->second;
    bool isValidExtension = false;

    for (const auto& ext : allowedExtensions)
    {
        if (extension == ext)
            return true;
    }

    std::cout << "PathValidator ERROR: " << extension <<" is not a valid extension for this file!\n";
    return false;
   
}
