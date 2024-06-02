#include "Clientes.h"
#include "Puestos.h"
#include "Empleados.h"
#include "Ventas.h"
#include "Productos.h"

#include <iostream>
#include <mysql.h>

using namespace std;

int main() {
    
    while (true) {

        cout << " " << endl;
        cout << "Bienvenido al programa 'Super Mercado los Juanitos'" << endl;
        cout << "Elige la opcion que deseas realizar: " << endl;
        cout << " " << endl;
        cout << "1. Emitir factura" << endl;
        cout << "2. Crear o modificar Clientes" << endl;
        cout << "3. Crear o modificar Puestos" << endl;
        cout << "4. Crear o modificar Empleados" << endl;
        cout << "5. Crear o modificar Ventas" << endl;
        cout << "6. Crear o modificar Producto" << endl;
        cout << "7. Salir" << endl;

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
                    cout << " " << endl;
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
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Leer Cliente Cliente'" << endl;
                    {
                        Clientes cliente = Clientes(id, nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
                        cliente.leer();
                    }
                    break;

                case 3:
                    cout << " " << endl;
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
                    cout << " " << endl;
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
                    cout << " " << endl;
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal


        case 3:
            // Menú de puestos
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
                    cout << " " << endl;
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
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Leer Puestos'" << endl;
                    {
                        Puestos Npuesto = Puestos(id, puesto);
                        Npuesto.leer();
                    }
                    break;

                case 3:
                    cout << " " << endl;
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
                    cout << " " << endl;
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
                    cout << " " << endl;
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << " " << endl;
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal


        case 4:
            //Menu de Empleados
            do {
                int id = 0;
                string nombres, apellidos, direccion;
                int telefono = 0;
                string DPI, genero, fecha_nacimiento;
                int idPuesto = 0;
                string fecha_inicio_labores, fecha_ingreso;

                cout << " " << endl;
                cout << "Bienvenido al programa para editar Empleados 'Super Mercado los Juanitos'" << endl;
                cout << "¿Que deseas realizar o modificar?" << endl;
                cout << " " << endl;
                cout << "1. Crear Empleado" << endl;
                cout << "2. Leer Empleados" << endl;
                cout << "3. Borrar Empleado" << endl;
                cout << "4. Actualizar Empleado" << endl;
                cout << "5. Volver al menu principal" << endl;


                cout << "Elige la opcion que deseas realizar: ";
                cin >> opcion;
                cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                // Evaluar la opción seleccionada
                switch (opcion) {
                case 1:
                    cout << " " << endl;
                    cout << "Ha seleccionado crear Empleado" << endl;

                    cout << "Ingrese nombres: " << endl;
                    getline(cin, nombres);

                    cout << "Ingrese apellidos: " << endl;
                    getline(cin, apellidos);

                    cout << "Ingrese direccion: " << endl;
                    getline(cin, direccion);

                    cout << "Ingrese telefono: " << endl;
                    cin >> telefono;
                    cin.ignore();

                    cout << "Ingrese DPI: " << endl;
                    getline(cin, DPI);

                    cout << "Ingrese genero: " << endl;
                    getline(cin, genero);

                    cout << "Ingrese fecha nacimiento: " << endl;
                    getline(cin, fecha_nacimiento);

                    cout << "Ingrese id del Puesto: " << endl;
                    cin >> idPuesto;
                    cin.ignore();

                    cout << "Ingrese fecha inicio de labores: " << endl;
                    getline(cin, fecha_inicio_labores);

                    cout << "Ingrese fecha de ingreso: " << endl;
                    getline(cin, fecha_ingreso);


                    // Crear el Empleado y llamar al método para guardar en la base de datos
                    {
                        Empleados empleado = Empleados(id, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
                        empleado.crear();
                    }

                    break;

                case 2:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Leer Puestos'" << endl;
                    {
                        Empleados empleado = Empleados(id, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
                        empleado.leer();
                    }
                    break;

                case 3:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Borrar Empleado '" << endl;

                    {
                        Empleados empleado = Empleados(id, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
                        empleado.leer();

                        cout << "Ingrese el ID a eliminar: ";
                        cin >> id;
                        cin.ignore();
                        empleado.setId(id);
                        empleado.leer();
                        empleado.borrar();
                        empleado.leer();
                    }

                    break;

                case 4:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Actualizar Puestos'" << endl;
                    {
                        Empleados empleado = Empleados(id, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso);
                        empleado.leer();

                        cout << "Ingrese el ID del puesto: ";
                        cin >> id;
                        cin.ignore();
                        empleado.setId(id);

                        cout << "Ingrese nombres: " << endl;
                        getline(cin, nombres);

                        cout << "Ingrese apellidos: " << endl;
                        getline(cin, nombres);

                        cout << "Ingrese direccion: " << endl;
                        getline(cin, nombres);

                        cout << "Ingrese telefono: " << endl;
                        cin >> telefono;
                        cin.ignore();

                        cout << "Ingrese DPI: " << endl;
                        getline(cin, DPI);

                        cout << "Ingrese genero: " << endl;
                        getline(cin, genero);

                        cout << "Ingrese fecha nacimiento: " << endl;
                        getline(cin, fecha_nacimiento);

                        cout << "Ingrese id del Puesto: " << endl;
                        cin >> idPuesto;
                        cin.ignore();

                        cout << "Ingrese fecha inicio de labores: " << endl;
                        getline(cin, fecha_inicio_labores);

                        cout << "Ingrese fecha de ingreso: " << endl;
                        getline(cin, fecha_ingreso);

                        empleado.actualizar();
                        empleado.leer();
                    }
                    break;

                case 5:
                    cout << " " << endl;
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << " " << endl;
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal

        case 5:

            do {
                int id = 0;
                int noFactura = 0;
                char serie = 'b';
                string fecha_factura;
                int idCliente = 0;
                int idEmpleado = 0;
                string fecha_ingreso;

                cout << " " << endl;
                cout << "Bienvenido al programa para editar Ventas 'Super Mercado los Juanitos'" << endl;
                cout << "¿Que deseas realizar o modificar?" << endl;
                cout << " " << endl;

                cout << "1. Crear Venta" << endl;
                cout << "2. Leer Venta" << endl;
                cout << "3. Borrar Venta" << endl;
                cout << "4. Actualizar Venta" << endl;
                cout << "5. Volver al menu principal" << endl;

                cout << "Elige la opcion que deseas realizar: ";
                cin >> opcion;
                cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                // Evaluar la opción seleccionada
                switch (opcion) {
                case 1:
                    cout << " " << endl;
                    cout << "Ha seleccionado crear Venta" << endl;

                    cout << "Ingrese numero de Factura: ";
                    cin >> noFactura;
                    cin.ignore();

                    cout << "Ingrese serie: ";
                    cin >> serie;
                    cin.ignore();

                    cout << "Ingrese Fecha de Factura: ";
                    getline(cin, fecha_factura);

                    cout << "Ingrese id de cliente: ";
                    cin >> idCliente;
                    cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                    cout << "Ingrese id de Empleado: ";
                    cin >> idEmpleado;
                    cin.ignore();

                    cout << "Ingrese fecha de ingreso: ";
                    getline(cin, fecha_ingreso);

                    // Crear el cliente y llamar al método para guardar en la base de datos
                    {
                        Ventas venta = Ventas(id, noFactura, serie, fecha_factura, idCliente, idEmpleado, fecha_ingreso);
                        venta.crear();
                    }

                    break;

                case 2:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Leer Ventas'" << endl;
                    {
                        Ventas venta = Ventas(id, noFactura, serie, fecha_factura, idCliente, idEmpleado, fecha_ingreso);
                        venta.leer();
                    }
                    break;

                case 3:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Borrar Venta '" << endl;

                    {
                        Ventas venta = Ventas(id, noFactura, serie, fecha_factura, idCliente, idEmpleado, fecha_ingreso);
                        venta.leer();

                        cout << "Ingrese el ID a eliminar: ";
                        cin >> id;
                        cin.ignore();
                        venta.setId(id);
                        venta.leer();
                        venta.borrar();
                        venta.leer();
                    }

                    break;

                case 4:
                    cout << " " << endl;
                    cout << "Ha seleccionado 'Actualizar Ventas'" << endl;
                    {
                        Ventas venta = Ventas(id, noFactura, serie, fecha_factura, idCliente, idEmpleado, fecha_ingreso);
                        venta.leer();

                        cout << "Ingrese el ID de la Venta: ";
                        cin >> id;
                        cin.ignore();
                        venta.setId(id);

                        cout << "Ingrese numero de Factura: ";
                        cin >> noFactura;
                        cin.ignore();

                        cout << "Ingrese serie: ";
                        cin >> serie;
                        cin.ignore();

                        cout << "Ingrese Fecha de Factura: ";
                        getline(cin, fecha_factura);

                        cout << "Ingrese id de cliente: ";
                        cin >> idCliente;
                        cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                        cout << "Ingrese id de Empleado: ";
                        cin >> idEmpleado;
                        cin.ignore();

                        cout << "Ingrese fecha de ingreso: ";
                        getline(cin, fecha_ingreso);

                        venta.actualizar();
                        venta.leer();
                    }
                    break;

                case 5:
                    cout << " " << endl;
                    cout << "Volviendo al menu principal..." << endl;
                    break;

                default:
                    cout << "Error, por favor escribe un numero correcto" << endl;
                    break;
                }
            } while (opcion != 5); // Salir del bucle cuando se selecciona la opción 5
            break; // Salir del switch y volver al menú principal


            break;



            cout << "Error, por favor escribe un número correcto" << endl;
            break;

              case 6:
                  // Menú de productos
                  do {
                      int idproducto = 0;
                      string producto, descripcion, imagen; // Agregué 'imagen' aquí
                      double precioCosto, precioVenta;
                      int existencia, idMarca; // Agregué 'idMarca' aquí
                      string fecha_ingreso;

                      cout << " " << endl;
                      cout << "Bienvenido al programa para editar Productos 'Super Mercado los Juanitos'" << endl;
                      cout << "¿Que deseas realizar o modificar?" << endl;
                      cout << " " << endl;
                      cout << "1. Crear Producto" << endl;
                      cout << "2. Leer Productos" << endl;
                      cout << "3. Borrar Producto" << endl;
                      cout << "4. Actualizar Producto" << endl;
                      cout << "5. Volver al menu principal" << endl;

                      cout << "Elige la opcion que deseas realizar: ";
                      cin >> opcion;
                      cin.ignore(); // Para ignorar el carácter de nueva línea pendiente

                      // Evaluar la opción seleccionada
                      switch (opcion) {
                      case 1:
                          cout << " " << endl;
                          cout << "Ha seleccionado crear Producto" << endl;

                          cout << "Ingrese nombre del producto: ";
                          getline(cin, producto);

                          cout << "Ingrese descripción: ";
                          getline(cin, descripcion);

                          cout << "Ingrese imagen: "; // Solicito la imagen
                          getline(cin, imagen);

                          cout << "Ingrese precio de costo: ";
                          cin >> precioCosto;

                          cout << "Ingrese precio de venta: ";
                          cin >> precioVenta;

                          cout << "Ingrese existencia: ";
                          cin >> existencia;

                          cout << "Ingrese fecha de ingreso: ";
                          cin.ignore(); // Para limpiar el buffer
                          getline(cin, fecha_ingreso);

                          cout << "Ingrese ID de marca: "; // Solicito el ID de la marca
                          cin >> idMarca;

                          // Crear el producto y llamar al método para guardar en la base de datos
                          {
                              Productos producto2 = Productos(idproducto, producto, idMarca, descripcion, imagen, precioCosto, precioVenta, existencia, fecha_ingreso); // Pasa 'idMarca' y 'imagen' al constructor
                              producto2.crear();
                          }

                          break;

                      case 2:
                          cout << " " << endl;
                          cout << "Ha seleccionado 'Leer Productos'" << endl;
                          {
                              Productos producto2 = Productos(idproducto, producto, idMarca, descripcion, imagen, precioCosto, precioVenta, existencia, fecha_ingreso); // Pasa 'idMarca' y 'imagen' al constructor
                              producto2.leer();
                          }
                          break;

                      case 3:
                          cout << " " << endl;
                          cout << "Ha seleccionado 'Borrar Producto '" << endl;

                          {
                              Productos producto2 = Productos(idproducto, producto, idMarca, descripcion, imagen, precioCosto, precioVenta, existencia, fecha_ingreso); // Pasa 'idMarca' y 'imagen' al constructor
                              producto2.leer();

                              cout << "Ingrese el ID a eliminar: ";
                              cin >> idproducto;
                              cin.ignore();
                              producto2.setIdProducto(idproducto);
                              producto2.leer();
                              producto2.borrar();
                              producto2.leer();
                          }

                          break;

                      case 4:
                          cout << " " << endl;
                          cout << "Ha seleccionado 'Actualizar Productos'" << endl;
                          {
                              Productos producto2 = Productos(idproducto, producto, idMarca, descripcion, imagen, precioCosto, precioVenta, existencia, fecha_ingreso); // Pasa 'idMarca' y 'imagen' al constructor
                              producto2.leer();

                              cout << "Ingrese el ID del producto: ";
                              cin >> idproducto;
                              cin.ignore();
                              producto2.setIdProducto(idproducto);

                              cout << "Ingrese nombre del producto: ";
                              string nombreProducto;
                              getline(cin, nombreProducto);
                              producto2.setProducto(nombreProducto);

                              cout << "Ingrese descripción: ";
                              getline(cin, descripcion);
                              producto2.setDescripcion(descripcion);

                              cout << "Ingrese imagen: "; // Solicito la imagen
                              getline(cin, imagen);
                              producto2.setImagen(imagen);

                              cout << "Ingrese precio de costo: ";
                              cin >> precioCosto;
                              producto2.setPrecioCosto(precioCosto);

                              cout << "Ingrese precio de venta: ";
                              cin >> precioVenta;
                              producto2.setPrecioVenta(precioVenta);

                              cout << "Ingrese existencia: ";
                              cin >> existencia;
                              producto2.setExistencia(existencia);

                              cout << "Ingrese fecha de ingreso: ";
                              cin.ignore(); // Para limpiar el buffer
                              getline(cin, fecha_ingreso);
                              producto2.setFechaIngreso(fecha_ingreso);

                              cout << "Ingrese ID de marca: "; // Solicito el ID de la marca
                              cin >> idMarca;
                              producto2.setIdMarca(idMarca);

                              producto2.actualizar();
                              producto2.leer();
                          }
                          break;

                      case 5:
                          cout << " " << endl;
                          cout << "Volviendo al menu principal..." << endl;
                          break;

                      default:
                          cout << "Error, por favor escribe un numero correcto" << endl;
                          break;
                      }
                  } while (opcion != 5); 
                  break; 
                  
              case 7:
                  cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                  return 0; 

              default:
                  cout << "Error, por favor escribe un número correcto" << endl;
                  break;
        }
    }
    return 0;
}


       