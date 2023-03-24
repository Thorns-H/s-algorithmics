#include <iostream>
#include <dirent.h>
#include "LinkedList.cpp"
#include "Helpers.cpp"

int main(){

    DIR* dir = opendir(".");
    LinkedList listedDirectory;

    if (dir != nullptr){
        struct dirent* entry = readdir(dir);

        while (entry != nullptr){
            if (getFileSize(entry->d_name) != 0){
                listedDirectory.Insert(entry->d_name, getFileSize(entry->d_name));
            }
            entry = readdir(dir);
        }

        closedir(dir);
        listedDirectory.Show();

    }
    return 0;
}
