#include <iostream>
#include <filesystem>

std::filesystem::path file_in_folder(std::filesystem::path, std::string);

void print_path(std::filesystem::path p, std::string s) { 
        std::filesystem::path pth = file_in_folder(p, s); 
        if (pth != "") std::cout << pth << '\n';
}
