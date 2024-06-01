#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Puestos {
    // Atributos
public:
    int id = 0;
    string puesto;
    

    // Constructores
public:
    Puestos() {}

    Puestos(int i,string pue) {
        
        id = i;
        puesto = pue;
    }

    // Métodos modificadores
    void setId(int i) { id = i; }
    void setPuesto(string pue) { puesto = pue; }
    

    // Métodos para obtener valores
    int getId() { return id; }
    string getPuesto() { return puesto; }
    

    // Método para crear cliente en la base de datos
    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "Conectado a la base de datos" << endl;

            string insert = "INSERT INTO Puestos(puesto) VALUES('" + puesto + "');";

     
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

            cout << " " << endl;
            cout << "------------ Datos de Puestos ------------" << endl;
            string consulta = "select * from Puestos";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "  |  " << fila[1]   <<endl;
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

            string  borrar = "DELETE FROM Puestos where idClientes = " + ii + "";

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
        string ii = to_string(id);
        if (cn.getConectar()) {
            string actualizar = "UPDATE Puestos SET puesto ='" + puesto + "' WHERE idPuesto = " + ii + "";
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