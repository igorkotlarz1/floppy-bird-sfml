#include "PathValidator.h"

// Definicja i inicjalizacja mapy dozwolonych rozszerzeñ ze wzorcami regexowaymi

const std::unordered_map<FileType, std::regex> PathValidator::validExtensions = {
    { FileType::TEXTURE, std::regex(R"(\.(png|jpg|jpeg)$)") }, 
    { FileType::FONT, std::regex(R"(\.(ttf|otf)$)") }
};


bool PathValidator::validate(const std::string& path, FileType fileType)
{
    try
    {
        fs::path filePath(path);

        //Walidacja sciezki
        if (!fs::exists(filePath))
        {
            std::cerr << "PathValidator ERROR: '" << path << "' doesn't exist." << std::endl;
            return false;
        }

        //sprawdzenie czy sciezka nie wskazuje na sam folder
        if (fs::is_directory(filePath))
        {
            std::cerr << "PathValidator ERROR: '" << path << "' points to a directory, not a file." << std::endl;
            return false;
        }

        /* fs::path dirPath = filePath.parent_path();

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
        }*/

        //sprawdzenie poprawnosci typu pliku (przekazanego w argumencie funkcji)
        auto it = validExtensions.find(fileType);

        if (it == validExtensions.end())
        {
            std::cerr << "PathValidator ERROR: Unknown file type." << std::endl;
            return false;
        }

        //walidacja rozszerzen przy pomocy regexa
        const std::regex& pattern = it->second;

        if (!std::regex_search(path, pattern))
        {
            std::cerr << "PathValidator ERROR: File '" << path << "' has an invalid extension!" << std::endl;
            return false;
        }
        /*std::string extension = filePath.extension().string();

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
        */
    }
    catch (const fs::filesystem_error& e)
    {
        // w przypadku wyj¹tku rzuconego przez filesystem
        std::cout << "PathValidator FATAL ERROR: " << e.what() << std::endl;
        return false;
    }

    //jezeli kazdy etap walidacji przeszedl
    return true;
}
