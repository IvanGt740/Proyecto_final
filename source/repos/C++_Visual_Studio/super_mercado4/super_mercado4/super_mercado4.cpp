#include "Clientes.h"
#include "Puestos.h"

#include <iostream>
#include <mysql.h>

using namespace std;

int main() {
    
    while (true) {
        cout << "Bienvenido al programa 'Super Mercado los Juanitos'" << endl;
        cout << "Elige la opcion que deseas realizar: " << endl;
        cout << " " << endl;
        cout << "1. Emitir factura" << endl;
        cout << "2. Crear o modificar Clientes" << endl;
        cout << "3. Crear o modificar Puestos" << endl;

        int opcion;
        cin >> opcion;
        cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

        // Evaluar la opción seleccionada
        switch (opcion) {
        case 1:
            cout << "Selecciono factura" << endl;
            // Código para emitir factura
            break;

        case 2: 
            // Menú de clientes
            do {
                int id = 0;
                string nombres, apellidos, NIT, genero;
                int telefono = 0;
                string correo_electronico, fecha_ingreso;
                cout << " " << endl;
                cout << "Bienvenido al programa para editar Clientes 'Super Mercado los Juanitos'" << endl;
                cout << "¿Que deseas realizar o modificar?" << endl;
                cout << " " << endl;

                cout << "1. Crear Cliente" << endl;
                cout << "2. Leer Cliente" << endl;
                cout << "3. Borrar Cliente" << endl;
                cout << "4. Actualizar Cliente" << endl;
                cout << "5. Volver al menu principal" << endl;

                cout << "Elige la opcion que deseas realizar: ";
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

                case 5:
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal

        
        case 3:
            // Menú de clientes
            do {
                int id = 0;
                string puesto;
                cout << " " << endl;
                cout << "Bienvenido al programa para editar Puestos 'Super Mercado los Juanitos'" << endl;
                cout << "¿Que deseas realizar o modificar?" << endl;
                cout << " " << endl;
                cout << "1. Crear Puesto" << endl;
                cout << "2. Leer Puestos" << endl;
                cout << "3. Borrar Puesto" << endl;
                cout << "4. Actualizar Puesto" << endl;
                cout << "5. Volver al menu principal" << endl;

                
                cout << "Elige la opcion que deseas realizar: ";
                cin >> opcion;
                cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                // Evaluar la opción seleccionada
                switch (opcion) {
                case 1:
                    cout << "Ha seleccionado crear Puesto" << endl;

                    cout << "Ingrese puesto: " << endl;
                    getline(cin, puesto);


                    // Crear el puesto y llamar al método para guardar en la base de datos
                    {
                        Puestos Npuesto = Puestos(id, puesto);
                        Npuesto.crear();
                    }

                    break;

                case 2:
                    cout << "Ha seleccionado 'Leer Puestos'" << endl;
                    {
                        Puestos Npuesto = Puestos(id, puesto);
                        Npuesto.leer();
                    }
                    break;

                case 3:
                    cout << "Ha seleccionado 'Borrar Puesto '" << endl;

                    {
                        Puestos Npuesto = Puestos(id, puesto);
                        Npuesto.leer();

                        cout << "Ingrese el ID a eliminar: ";
                        cin >> id;
                        cin.ignore();
                        Npuesto.setId(id);
                        Npuesto.leer();
                        Npuesto.borrar();
                        Npuesto.leer();
                    }

                    break;

                case 4:
                    cout << "Ha seleccionado 'Actualizar Puestos'" << endl;
                    {
                        Puestos Npuesto = Puestos(id, puesto);
                        Npuesto.leer();

                        cout << "Ingrese el ID del puesto: ";
                        cin >> id;
                        cin.ignore();
                        Npuesto.setId(id);

                        cout << "Ingrese el Puesto: ";
                        getline(cin, puesto);
                        Npuesto.setPuesto(puesto);

                        Npuesto.actualizar();
                        Npuesto.leer();
                    }
                    break;

                case 5:
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal


       




















        default:
            cout << "Error, por favor escribe un numero correcto" << endl;
            break;
        }
    }




    return 0;
}
