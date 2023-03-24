#include <iostream>
#include <fstream>
#include "linked_list.cpp"

int main(){

    std::ifstream originalFile("data.bin", std::ios::binary);
    std::ofstream outputFile("compressed.rlc", std::ios::binary);

    outputFile << "RLC";
    outputFile.put(8);    
    outputFile.put(16);   

    linkedList data; 
    char byte;

    while (originalFile.get(byte)) {
        data.insert(static_cast<unsigned char>(byte));
    }

    int values = data.size();
    int i = 0;
    while (i < values) {
        
        int j = i + 1;
        while (j < values && data[j] == data[i]) {
            j++;
        }
        
        outputFile.put(data[i]);                   
        outputFile.put(j - i >> 8 & 0xff);             
        outputFile.put(j - i & 0xff);

        i = j;
    }

    originalFile.close();
    outputFile.close();

    return 0;
}