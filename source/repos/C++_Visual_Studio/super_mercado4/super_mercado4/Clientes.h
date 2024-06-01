#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Clientes {
    // Atributos
public:
    int id = 0;
    string nombres, apellidos, NIT, genero;
    int telefono = 0;
    string correo_electronico, fecha_ingreso;

    // Constructores
public:
    Clientes() {}

    Clientes(int i, string nom, string ape, string n, string gen, int tel , string correo_e, string fecha_ing) {
        
        id = i;
        nombres = nom;
        apellidos = ape;
        NIT = n;
        genero = gen;
        telefono = tel;
        correo_electronico = correo_e;
        fecha_ingreso = fecha_ing;
    }

    // Métodos modificadores
    void setId(int i) { id = i; }
    void setNombres(string nom) { nombres = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setNit(string n) { NIT = n; }
    void setGenero(string gen) { genero = gen; }
    void setTelefono(int tel) { telefono = tel; }
    void setCorreo(string correo_e) { correo_electronico = correo_e; }
    void setFecha_Ingreso(string fecha_ing) { fecha_ingreso = fecha_ing; }

    // Métodos para obtener valores
    int getId() { return id; }
    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getNit() { return NIT; }
    string getGenero() { return genero; }
    int getTelefono() { return telefono; }
    string getCorreo() { return correo_electronico; }
    string getFecha_Ingreso() { return fecha_ingreso; }

    // Método para crear cliente en la base de datos
    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            cout << "Conectado a la base de datos" << endl;

            string t = to_string(telefono);
            string insert = "INSERT INTO clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso) VALUES('" + nombres + "','" + apellidos + "', '" + NIT + "','" + genero + "'," + t + ", '" + correo_electronico + "','" + fecha_ingreso + "');";

     
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

            cout << "------------ Datos de Clientes ------------" << endl;
            string consulta = "select * from clientes";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] <<endl;
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

            string  borrar = "DELETE FROM clientes where idClientes = " + ii + "";

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
        if (cn.getConectar()) {
            string actualizar = "UPDATE clientes SET nombres ='" + nombres + "', apellidos = '" + apellidos + "', NIT = '" + NIT + "', genero = '" + genero + "', telefono =" + t + ", correo_electronico = '" + correo_electronico + "', fechaingreso='" + fecha_ingreso + "' WHERE idClientes = " + ii + "";
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