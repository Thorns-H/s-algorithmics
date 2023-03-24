#include <iostream>
#include <fstream>
#include <vector>

int main(){

    std::ifstream archivoEntrada("data.bin", std::ios::binary);
    std::ofstream archivoSalida("compressed.rlc", std::ios::binary);

    archivoSalida << "RLC";
    archivoSalida.put(8);    
    archivoSalida.put(16);   

    std::vector<unsigned char> datos;
    char byte;
    while (archivoEntrada.get(byte)) {
        datos.push_back(static_cast<unsigned char>(byte));
    }

    int numDatos = datos.size();
    int i = 0;
    while (i < numDatos) {
        int j = i + 1;
        while (j < numDatos && datos[j] == datos[i]) {
            j++;
        }
        
        archivoSalida.put(datos[i]);                   
        archivoSalida.put(j - i >> 8 & 0xff);             
        archivoSalida.put(j - i & 0xff);

        i = j;
    }

    archivoEntrada.close();
    archivoSalida.close();

    return 0;
}