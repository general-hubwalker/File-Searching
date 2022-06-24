#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include <algorithm>


void print_path(std::filesystem::path, std::string);
std::filesystem::path file_in_folder(std::filesystem::path, std::string);


void find_file_path(std::string filename_to_find, std::string folder_to_search)
{


    std::vector<std::filesystem::path> list_of_files;
    std::vector<std::filesystem::path> list_of_folders;
    std::vector<std::filesystem::path> files_in_root;
    
    const std::filesystem::path sandbox{ folder_to_search };

for (auto const& dir_entry : std::filesystem::directory_iterator{ sandbox, std::filesystem::directory_options::skip_permission_denied })
        {
            if (dir_entry.is_regular_file()){
                list_of_files.push_back(std::filesystem::path(dir_entry));
                files_in_root.push_back(std::filesystem::path(dir_entry).filename());
            }
            if (dir_entry.is_directory())
                list_of_folders.push_back(std::filesystem::path(dir_entry));
	}


     bool in_root = 0;
     if (files_in_root.size() != 0){
     	in_root = (std::find(files_in_root.begin(), files_in_root.end(), filename_to_find) != files_in_root.end());
     }
     if (in_root){
     	std::cout << folder_to_search + "/" + filename_to_find << "\n";}
     
     if (in_root == 0){
     // begin reshape---
     std::vector <std::vector <std::filesystem::path>> list_of_folders_reshaped;
     int s = list_of_folders.size();
     std::vector <std::filesystem::path> temp;
     for (int i = 0; i < s / 8; i++) {
         //temp.clear(); //= {};
         temp = {};
         for (int j = 0; j < 8; j++) {
             temp.push_back(list_of_folders[8 * i + j]);
         }
         list_of_folders_reshaped.push_back(temp);
     }
     temp.clear();
     for (int i = (s / 8) * 8; i < s; i++) { 
         temp.push_back(list_of_folders[i]); }
     list_of_folders_reshaped.push_back(temp);
     // end reshape---

     std::vector<std::thread> threads;  
     
     std::filesystem::path pth;      
     
     try{
     for (int i = 0; i < list_of_folders_reshaped.size(); i++) {
         threads.clear();
         for (
             auto it = list_of_folders_reshaped[i].begin();
             it != list_of_folders_reshaped[i].end(); it++) {
             pth = file_in_folder(*it, filename_to_find);
             threads.push_back(std::thread(print_path, *it, filename_to_find));
         }

        for (auto& th : threads) {
            th.join();
        }
        
        if (pth != "")
            break;
     }
     }
     catch(std::filesystem::filesystem_error& fse){
     std::cout << "\nCaught fatal exception: \n";
     }
     
    }
}
