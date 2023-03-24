#include <fstream>

int main() {
    
    std::ofstream archivo("../data.bin", std::ios::binary);

    for (int i = 0; i < 200; ++i) {
        archivo.write("A", sizeof(char));
    }

    for (int i = 0; i < 100; ++i) {
        archivo.write("B", sizeof(char));
    }

    for (size_t i = 0; i < 500; i++){
        archivo.write("C", sizeof(char));
    }
    
    archivo.close();
    return 0;
}
