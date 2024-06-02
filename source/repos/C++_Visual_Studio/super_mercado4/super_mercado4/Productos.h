#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Productos {
    // Atributos
public:
    int idproducto = 0;
    string producto;
    int idMarca = 0;
    string descripcion;
    string imagen;
    double precioCosto = 0.0;
    double precioVenta = 0.0;
    int existencia = 0;
    string fecha_ingreso;

    // Constructores
public:
    Productos() {
    }

    Productos(int iP, string pdt, int iM, string dsc, string IMG, double PC, double PV, int EX, string fechaI) {
        idproducto = iP;
        producto = pdt;
        idMarca = iM;
        descripcion = dsc;
        imagen = IMG;
        precioCosto = PC;
        precioVenta = PV;
        existencia = EX;
        fecha_ingreso = fechaI;
    }

    // M�todos modificadores
    void setIdProducto(int iP) { idproducto = iP; }
    void setProducto(string pdt) { producto = pdt; }
    void setIdMarca(int iM) { idMarca = iM; }
    void setDescripcion(string dsc) { descripcion = dsc; }
    void setImagen(string IMG) { imagen = IMG; }
    void setPrecioCosto(double PC) { precioCosto = PC; }
    void setPrecioVenta(double PV) { precioVenta = PV; }
    void setExistencia(int EX) { existencia = EX; }
    void setFechaIngreso(string fechaI) { fecha_ingreso = fechaI; }

    // M�todos para obtener valores
    int getIdProducto() { return idproducto; }
    string getProducto() { return producto; }
    int getIdMarca() { return idMarca; }
    string getDescripcion() { return descripcion; }
    string getImagen() { return imagen; }
    double getPrecioCosto() { return precioCosto; }
    double getPrecioVenta() { return precioVenta; }
    int getExistencia() { return existencia; }
    string getFechaIngreso() { return fecha_ingreso; }

    // M�todo para crear producto en la base de datos
    void crear() {
        int q_estado;
        ConexionBD cn = ConexionBD();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string insert = "INSERT INTO Productos(producto, descripcion, imagen, precioCosto, precioVenta, existencia, fechaingreso, idMarca) VALUES('" + producto + "', '" + descripcion + "', '" + imagen + "', " + to_string(precioCosto) + ", " + to_string(precioVenta) + ", " + to_string(existencia) + ", '" + fecha_ingreso + "', " + to_string(idMarca) + ");";
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
            cout << "------------ Datos de Productos ------------" << endl;
            string consulta = "SELECT * FROM Productos";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado)) {
                    cout << fila[0] << "  |  " << fila[1] << "  |  " << fila[2] << "  |  " << fila[3] << "  |  " << fila[4] << "  |  " << fila[5] << "  |  " << fila[6] << "  |  " << fila[7] << "  |  " << fila[8] << endl;
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
        string ii = to_string(idproducto);
        if (cn.getConectar()) {
            string borrar = "DELETE FROM Productos WHERE idProducto = " + ii + "";
            const char* i = borrar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Eliminacion Exitosa ..." << endl;
            }
            else {
                cout << " xxx Error al Borrar xxx" << endl;
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
        if (cn.getConectar()) {
            string update = "UPDATE Productos SET producto = '" + producto + "', descripcion = '" + descripcion + "', imagen = '" + imagen + "', precioCosto = " + to_string(precioCosto) + ", precioVenta = " + to_string(precioVenta) + ", existencia = " + to_string(existencia) + ", fechaingreso = '" + fecha_ingreso + "', idMarca = " + to_string(idMarca) + " WHERE idProducto = " + to_string(idproducto) + "";
            const char* i = update.c_str();
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

