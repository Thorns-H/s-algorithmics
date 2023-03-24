import os
from headers.linked_list import contact, linked_list

def main():
    
    opc: int = None
    directory: linked_list = linked_list()

    while opc != 0:

        os.system("cls")

        print("\n\tMenu - Directiorio de Contactos\n")
        print("\t1.- Agregar (Contacto)")
        print("\t2.- Eliminar (Contacto)")
        print("\t3.- Buscar (Contacto)")
        print("\t4.- Vaciar (Directorio)")
        print("\t5.- Mostrar (Directorio)\n")
        print("\t0.- Salir\n")
        
        opc = int(input("\t~ "))

        if opc == 1:

            os.system("cls")

            print("\n\tAgregar un Nuevo Contacto\n")
            id: int = int(input("\tID del Contacto: "))
            name: str = input("\tNombre del Contacto: ")
            address: str = input("\tDireccion del Contacto: ")
            phone: str = input("\tCelular del Contacto: ")
            email: str = input("\tEmail del Contacto: ")

            new_contact: contact = contact(id, name, address, phone, email)
            directory.insert(new_contact)

        elif opc == 2:

            os.system("cls")

            print("\n\tEliminar un Contacto\n")
            name: str = input("\tNombre del Contacto: ")

            directory.erase(name)

        elif opc == 3:

            os.system("cls")

            print("\n\tBuscar un Contacto\n")
            name: str = input("\tNombre del Contacto: ")

            contact_info: dict = directory.find(name)

            if contact_info['status']:
                print("\n\t¡Se ha encontrado el contacto!\n\t")
                print(contact_info['data'])
            else:
                print("\n\t¡No se ha encontrado el contacto!\n")

            input()

        elif opc == 4:
            directory.erase_all()

        elif opc == 5:
            if not directory.empty():
                print("\n\tLista de Contactos en el Directorio\n")
                directory.show_contacts()
            else:
                os.system("cls")
                print("\n\t¡No hay contactos para Mostrar!\n")

            input()
    
    os.system("cls")

if __name__ == '__main__':
    main()