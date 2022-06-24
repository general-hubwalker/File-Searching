#include <filesystem>

std::filesystem::path file_in_folder(std::filesystem::path p, std::string s) {

    const std::filesystem::path sandbox{ p };
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ sandbox, std::filesystem::directory_options::skip_permission_denied })
    {
        if (dir_entry.is_regular_file() && std::filesystem::path(dir_entry).filename() == s) {
            
            return std::filesystem::path(dir_entry);
            
        }
    }

    return std::filesystem::path("");
    
    }
