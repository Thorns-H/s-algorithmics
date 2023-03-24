#include <iostream>
#include <sys/stat.h>

std::size_t getFileSize(const std::string& fileName){

    struct stat fileInfo;
    if (stat(fileName.c_str(), &fileInfo) != 0){
        return 0;
    }
    else{
        return static_cast<std::size_t>(fileInfo.st_size);
    }
}