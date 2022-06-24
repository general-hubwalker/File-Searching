To solve the task of finding a path of a file with a particular name we created three source files:
file find_file_path.cpp, file_in_folder.cpp, print_path.cpp.

Function find_file_path(std::string filename_to_find, std::string folder_to_search) is saved in source file find_file_path.cpp.
It has two arguments (filename_to_find and folder_to_search) and it is used to find the file path of a file with name 
filename_to_find in folder with path folder_to_search and its all subfolders.

Two additional source files file_in_folder.cpp and print_path.cpp contain two auxiliary functions used in find_file_path-function.

With the use of these three source files, namely file find_file_path.cpp, file_in_folder.cpp, and print_path.cpp, one obtains static library 
libfindpath.a. Then we can generate executable file with name findpath. It can be easily done by means of makefile and command 
make all.

File header.h contains signatures of the functions from the source files.

An example how to use the static library is in file find_path.cpp. Here its content:

#include "header.h"

int main(){
    find_file_path("header.h", "/home");
    return 0;
}

In this particular example we use function find_file_path("header.h", "/home") from our static librry to find the path to file with name header.h
inside the home directory with the path /home.
