#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

std::size_t getFileSize(const std::string& fileName){

    struct stat fileInfo;
    if (stat(fileName.c_str(), &fileInfo) != 0){
        return 0;
    }
    else{
        return static_cast<std::size_t>(fileInfo.st_size);
    }
}

bool moveFile(const std::string& fileName){

    std::string filePath = "./";
    filePath += fileName;

    std::string duplicatesDir = "./duplicados";
    std::string newFilePath = duplicatesDir + "/" + fileName;
    rename(filePath.c_str(), newFilePath.c_str());

    return true;
}

bool areFilesEqual(std::string first, std::string second){

    std::ifstream firstFile(first, std::ios::binary);
    std::ifstream secondFile(second, std::ios::binary);

    char firstBuffer[1024];
    char secondBuffer[1024];

    while (true){
        firstFile.read(firstBuffer, 1024);
        secondFile.read(secondBuffer, 1024);

        if (firstFile.gcount() != secondFile.gcount()){
            return false;
        }

        if (firstFile.gcount() == 0){
            return true;
        }

        if (std::memcmp(firstBuffer, secondBuffer, firstFile.gcount()) != 0){
            return false;
        }
    }
}

