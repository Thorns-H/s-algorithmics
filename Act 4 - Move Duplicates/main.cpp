#include <iostream>
#include <dirent.h>
#include "LinkedList.cpp"

int main(){

    DIR* dir = opendir(".");
    LinkedList listedDirectory;

    std::string duplicatesDir = "./duplicados";

    struct stat dirInfo;
    if (stat(duplicatesDir.c_str(), &dirInfo) != 0){
        mkdir(duplicatesDir.c_str());
    }

    if (dir != nullptr){
        struct dirent* file = readdir(dir);

        while (file != nullptr){
            if (getFileSize(file->d_name) != 0){
                listedDirectory.Insert(file->d_name, getFileSize(file->d_name));
            }
            file = readdir(dir);
        }

        closedir(dir);

        listedDirectory.BubbleSort();
        listedDirectory.clearDuplicates();
        listedDirectory.Show();

    }
    return 0;
}
