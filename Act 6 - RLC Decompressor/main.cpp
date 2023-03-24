#include <iostream>
#include <fstream>

int main() {

    std::ifstream archivo("compressed.rlc", std::ios::binary);
    std::ofstream archivoDescomprimido("output.bin", std::ios::binary);

    char cabecera[5];
    archivo.read(cabecera, 5);
    if (!(cabecera[0] != 'R' || cabecera[1] != 'L' || cabecera[2] != 'C' || cabecera[3] != 8 || cabecera[4] != 16)) {

        char dato;
        short contador;
        unsigned char bytes[2];

        while (archivo.get(dato) && archivo.read(reinterpret_cast<char*>(&bytes), sizeof(bytes))){
            short contador = (static_cast<short>(bytes[1])) | static_cast<short>(bytes[0] << 8);
            for (int i = 0; i < contador; i++) {
                archivoDescomprimido.put(dato);
            }
        }

        archivo.close();
        archivoDescomprimido.close();
    }

    return 0;
}
