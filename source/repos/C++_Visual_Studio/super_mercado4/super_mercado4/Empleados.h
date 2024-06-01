#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Empleados {
    // Atributos
public:
    int id = 0;
    string nombres, apellidos, direccion;
    int telefono = 0;
    string DPI, genero, fecha_nacimiento;
    int idPuesto = 0;
    string fecha_inicio_labores, fecha_ingreso;
    // Constructores
public:
    Empleados() {}

    Empleados(int i, string nom, string ape, string dir, int tel, string DP, string gen, string fechaN, int iP, string fechaIL, string fechaI) {

        id = i;
        nombres = nom;
        apellidos = ape;
        direccion = dir;
        telefono = tel;
        DPI = DP;
        genero = gen;
        fecha_nacimiento = fechaN;
        idPuesto = iP;
        fecha_inicio_labores = fechaIL;
        fecha_ingreso = fechaI;
    }

    // Métodos modificadores
    void setId(int i) { id = i; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setDireccion(string dir) { direccion = dir; }
    void setTelefono(int tel) { telefono = tel; }
    void setDPI(string DP) { DPI = DP; }
    void setGenero(string gen) { genero = gen; }
    void setFecha_nacimiento(string fechaN) { fecha_nacimiento = fechaN; }
    void setIdPuesto(int iP) { idPuesto = iP; }
    void setFecha_inicio_labores(string fechaIL) { fecha_inicio_labores = fechaIL; }
    void setFecha_ingreso(string fechaI) { fecha_ingreso = fechaI; }

    // Métodos para obtener valores
    int getId() { return id; }
    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getDireccion() { return direccion; }
    int getTelefono() { return telefono; }
    string getDPI() { return DPI; }
    string getGenero() { return genero; }
    string getFecha_nacimiento() { return fecha_nacimiento; }
    int getIdPuesto() { return idPuesto; }
    string getFecha_inicio_labores() { return fecha_inicio_labores; }
    string getFecha_ingreso() { return fecha_ingreso; }


    // Método para crear cliente en la base de datos
    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "Conectado a la base de datos" << endl;
            string idP = to_string(idPuesto);
            string t = to_string(telefono);
            string insert = "INSERT INTO Empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, idPuesto, fecha_inicio_labores, fecha_ingreso) VALUES('" + nombres + "','" + apellidos + "', '" + direccion + "'," + t + ", '" + DPI + "','" + genero + "','" + fecha_nacimiento + "'," + idP + ",'" + fecha_inicio_labores + "','" + fecha_ingreso + "');";


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

            cout << "------------ Datos de Empleados ------------" << endl;
            string consulta = "SELECT e.idEmpleado,e.nombres, e.apellidos, e.direccion, e.telefono, e.DPI, e.genero, e.fecha_nacimiento, p.puesto, e.fecha_inicio_labores, e.fecha_ingreso FROM empleados e JOIN  puestos p ON e.idPuesto = p.idPuesto;";

            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
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

            string  borrar = "DELETE FROM Empleados where idEmpleado = " + ii + "";

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
        string t = to_string(telefono);
        string ii = to_string(id);
        string idP = to_string(idPuesto);
        if (cn.getConectar()) {
            string actualizar = "UPDATE Empleados SET nombres ='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + t + ", DPI ='" + DPI + "', genero = '" + genero + "', fecha_nacimiento='" + fecha_nacimiento + "', idPuesto=" + idP + ", fecha_inicio_labores = '" + fecha_inicio_labores + "', fecha_ingreso = '" + fecha_ingreso + "' WHERE idEmpleado = " + ii + "";
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