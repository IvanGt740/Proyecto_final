#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Ventas {
    // Atributos
public:
    int id = 0;
    int noFactura = 0;
    char serie = 'b';
    string fecha_factura;
    int idCliente = 0;
    int idEmpleado = 0;
    string fecha_ingreso;


    // Constructores
public:
    Ventas() {}

    Ventas(int i, int noF, char s, string fechaF, int idC, int idE, string fechaI) {

        id = i;
        noFactura = noF;
        serie = s;
        fecha_factura = fechaF;
        idCliente = idC;
        idEmpleado = idE;
        fecha_ingreso = fechaI;

    }

    // Métodos modificadores
    void setId(int i) { id = i; }
    void setNoFactura(int noF) { noFactura = noF; }
    void setSerie(char s) { serie = s; }
    void setFechaFactura(string fechaF) { fecha_factura = fechaF; }
    void setIdCliente(int idC) { idCliente = idC; }
    void setIdEmpleado(int idE) { idEmpleado = idE; }
    void setFechaIngreso(string fechaI) { fecha_ingreso = fechaI; }

    // Métodos para obtener valores
    int getId() { return id; }
    int getNoFactura() { return noFactura; }
    char getSerie() { return serie; }
    string getFechaFactura() { return fecha_factura; }
    int getIdCliente() { return idCliente; }
    int getIdEmpleado() { return idEmpleado; }
    string getFechaIngreso() { return fecha_ingreso; }




    // Método para crear cliente en la base de datos
    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "Conectado a la base de datos" << endl;

            string fac = to_string(noFactura);
            string idE = to_string(idEmpleado);
            string idC = to_string(idCliente);
            string s(1, serie);  // Corrección para convertir char a string

            string insert = "INSERT INTO Ventas(noFactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES(" + fac + ", '" + s + "', '" + fecha_factura + "', " + idC + ", " + idE + ", '" + fecha_ingreso + "');";


            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso exitoso...." << endl;
            }
            else {
                cout << "XXX ERROR AL INGRESAR XXX" << endl;
            }
        }
        else {
            cout << "XXX Error en la conexion XXX" << endl;
        }
        cn.cerrar_conexion();
    }

    void leer() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();

        if (cn.getConectar()) {

            cout << "------------ Datos de Ventas ------------" << endl;
            string consulta = "select * from Ventas";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << endl;
                }

            }
            else {
                cout << " xxx Error al Consultar  xxx" << endl;
            }

        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();
    }

    void borrar() {
        int q_estado;
        ConexionBD cn = ConexionBD();

        cn.abrir_conexion();
        string ii = to_string(id);
        if (cn.getConectar()) {

            string  borrar = "DELETE FROM Ventas where idVenta = " + ii + "";

            const char* i = borrar.c_str();
            // executar el query
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Eliminacion Exitosa ..." << endl;
            }
            else {
                cout << " xxx Error al Ingresar  xxx" << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();
    }

    void actualizar() {
        int q_estado;
        ConexionBD cn = ConexionBD();

        cn.abrir_conexion();
        
        string fac = to_string(noFactura);
        string idE = to_string(idEmpleado);
        string idC = to_string(idCliente);
        string ii = to_string(id);
        string s(1, serie);

        if (cn.getConectar()) {
            string actualizar = "UPDATE Ventas SET noFactura =" + fac + ", serie = " + s + ", fechafactura = '" + fecha_factura + "', idCliente = " + idC + ", idEmpleado =" + idE + ", fechaingreso='" + fecha_ingreso + "' WHERE idVenta = " + ii + "";
            const char* i = actualizar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Actualizacion Exitosa ..." << endl;
            }
            else {
                cout << " xxx Error al Actualizar xxx" << endl;
            }
        }
        else {
            cout << " xxx Error en la Conexion xxxx" << endl;
        }
        cn.cerrar_conexion();
    }
};