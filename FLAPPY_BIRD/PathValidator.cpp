#include "PathValidator.h"

// Definicja i inicjalizacja mapy dozwolonych rozszerzeñ ze wzorcami regexowaymi

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

        //sprawdzenie poprawnosci typu pliku (przekazanego w argumencie metody)
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
    }
    catch (const fs::filesystem_error& e)
    {
        // w przypadku wyjatku rzuconego przez filesystem
        std::cerr << "PathValidator FATAL ERROR: " << e.what() << std::endl;
        return false;
    }

    //jezeli kazdy etap walidacji przeszedl
    return true;
}
