#include <iostream>
#include <fstream>

int main() {

    std::ifstream inputFile("compressed.rlc", std::ios::binary);
    std::ofstream outputFile("output.bin", std::ios::binary);

    char header[5];
    inputFile.read(header, 5);
    if (!(header[0] != 'R' || header[1] != 'L' || header[2] != 'C' || header[3] != 8 || header[4] != 16)) {

        char value;
        short counter;
        unsigned char bytes[2];

        while (inputFile.get(value) && inputFile.read(reinterpret_cast<char*>(&bytes), sizeof(bytes))){
            short counter = (static_cast<short>(bytes[1])) | static_cast<short>(bytes[0] << 8);
            for (int i = 0; i < counter; i++) {
                outputFile.put(value);
            }
        }

        inputFile.close();
        outputFile.close();
    }

    return 0;
}
