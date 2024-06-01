#include "Clientes.h"
#include <iostream>
#include <mysql.h>

using namespace std;

int clientes() {

    while (true) {
        int id = 0;
        string nombres, apellidos, NIT, genero;
        int telefono = 0;
        string correo_electronico, fecha_ingreso;

        cout << "Bienvenido al programa para editar Clientes 'Super Mercado los Juanitos'" << endl;
        cout << "¿Qué deseas realizar o modificar?" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Leer Cliente" << endl;
        cout << "3. Borrar Cliente" << endl;
        cout << "4. Actualizar Cliente" << endl;


        int opcion;
        cout << "Elige la opcion que deseas realizar: " << endl;
        cin >> opcion;
        cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

        // Evaluar la opción seleccionada
        switch (opcion) {
        case 1:
            cout << "Ha seleccionado crear Cliente" << endl;

            cout << "Ingrese nombres: ";
            getline(cin, nombres);

            cout << "Ingrese apellidos: ";
            getline(cin, apellidos);

            cout << "Ingrese NIT: ";
            getline(cin, NIT);

            cout << "Ingrese telefono: ";
            cin >> telefono;
            cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

            cout << "Ingrese genero: ";
            getline(cin, genero);

            cout << "Ingrese correo electronico: ";
            getline(cin, correo_electronico);

            cout << "Ingrese fecha de ingreso: ";
            getline(cin, fecha_ingreso);

            // Crear el cliente y llamar al método para guardar en la base de datos
            {
                Clientes cliente = Clientes(id, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
                cliente.crear();
            }

            break;

        case 2:
            cout << "Ha seleccionado 'Leer Cliente Cliente'" << endl;
            {
                Clientes cliente = Clientes(id, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
                cliente.leer();
            }
            break;

        case 3:
            cout << "Ha seleccionado 'Borrar Cliente '" << endl;

            {
                Clientes cliente = Clientes(id, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
                cliente.leer();

                cout << "Ingrese el ID a eliminar: ";
                cin >> id;
                cin.ignore();
                cliente.setId(id);
                cliente.leer();
                cliente.borrar();
                cliente.leer();
            }

            break;

        case 4:
            cout << "Ha seleccionado 'Actualizar cliente'" << endl;
            {
                Clientes cliente = Clientes(id, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
                cliente.leer();

                cout << "Ingrese el ID del cliente: ";
                cin >> id;
                cin.ignore();
                cliente.setId(id);

                cout << "Ingrese nombres: ";
                getline(cin, nombres);
                cliente.setNombres(nombres);

                cout << "Ingrese apellidos: ";
                getline(cin, apellidos);
                cliente.setApellidos(apellidos);

                cout << "Ingrese NIT: ";
                getline(cin, NIT);
                cliente.setNit(NIT);

                cout << "Ingrese telefono: ";
                cin >> telefono;
                cin.ignore(); // Para ignorar el carácter de nueva línea pendiente
                cliente.setTelefono(telefono);

                cout << "Ingrese genero: ";
                getline(cin, genero);
                cliente.setGenero(genero);

                cout << "Ingrese correo electronico: ";
                getline(cin, correo_electronico);
                cliente.setCorreo(correo_electronico);

                cout << "Ingrese fecha de ingreso: ";
                getline(cin, fecha_ingreso);
                cliente.setFecha_Ingreso(fecha_ingreso);

                cliente.actualizar();
                cliente.leer();
            }
            break;

        default:
            cout << "Error, por favor escriba un número correcto" << endl;
            break;
        }
    }
    return 0;
}
