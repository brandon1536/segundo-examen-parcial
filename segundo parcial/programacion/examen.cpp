#include<stdlib.h>
#include <iostream>
#include<mysql.h>
#include<string.h>
using namespace std;
int q_estado;
MYSQL_ROW fila;
MYSQL_RES * resultado;
MYSQL* conectar;


 int main()
{
	 // INICIAMOS EL PROCESO DE CONECCION 
	 
	 int opciones;
	 cout << "\t\t\t\t-----Brandon Antonio Roca  3590-20-16408-----\n" << endl;
	 cout << "\t\t-----OPCIONES-----\n" << endl;
		 cout << "1. ANOTAR DATOS EN LA TABLA \n" << endl;
			 cout << "2.VER DATOS EN LA TABLA\n" << endl;
				cout << "3.ELIMINAR DATOS EN LA TABLA \n"<<endl;
					 cout << "4. VER DATOS ACTUALIZADOS EN LA TABLA\n" << endl;
						cout << "\n5. salir\n" << endl;
					 cin >> opciones;
					
					 conectar = mysql_init(0);
					 conectar = mysql_real_connect(conectar, "localhost", "root", "12345", "exam", 3306, NULL, 0);
					 string producto, descripcion, imagen, precio_costo, precio_venta, existencia;
					
					 switch (opciones)
					 {
					 case 1:
						 if (conectar) {
							 //cout << "conexion exitosa"<<endl;

							 cout << "\t-----Complete los siguientes datos----- \n" << endl;
							 cout << "coloque nombre del producto" << endl;
							 cin >> producto;
							 cout << "coloque la descripcion" << endl;
							 cin >> descripcion;
							 cout << "coloque imagen" << endl;
							 cin >> imagen;
							 cout << "ingrese el precio del producto  (Costo)" << endl;
							 cin >> precio_costo;
							 cout << "Ingrese el precio del producto (Venta)" << endl;
							 cin >> precio_venta;
							 cout << "STOCK" << endl;
							 cin >> existencia;
							 //string insert ="insert into productos(producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)values('" + producto + "','" + descripcion + "','" + imagen + "',' + precio_costo + ',' + precio_venta + ',' + existencia + ','fecha_ingres')";
							 string insert = "insert into productos (producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)values('" + producto + "', '" + descripcion + "', '" + imagen + "', '" + precio_costo + "', '" + precio_venta + "', '" + existencia + "', current_time())";
							 const char* i = insert.c_str();
							 //realizamos consulta 
							 q_estado = mysql_query(conectar, i);
							 if (!q_estado) {
								 cout << "DATOS INGRESADOS" << endl;
								 return main();
							 }
							 else { cout << "NO SE INBRESARON DATOS" << endl; }
						 } break;
					 case 2:
						 if (!q_estado) {

							 cout << "\t-----DATOS DE LA TABLA----- \n" << endl;
							 string consul = "select*from productos";
							 const char* c = consul.c_str();
							 q_estado = mysql_query(conectar, c);
							 resultado = mysql_store_result(conectar);
							 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
							 while (fila = mysql_fetch_row(resultado)) {

								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								
							 }
							 return main();
						 }break;

					 case 3:
						 if (!q_estado) {
							 cout << "\t-----Eliminar datos en tabla por Nombre de producto----- \n" << endl;
							 string consuls = "delete  from productos where producto='" + producto + "'";
							 const char* d = consuls.c_str();
							 q_estado = mysql_query(conectar, d);
							 resultado = mysql_store_result(conectar);
							 cout << "ingrese el Nombre del producto para eliminar el resgistro" << endl;
							 cin >> producto;
							 cout << "\t-----Datos eliminados-----\n" << endl;
							 return main();
						 }
						 else {
							 cout << "No se lograron eliminar los datos" << endl;
						 }break;
					 case 4:
						 if (!q_estado) {
							 cout << "\t-----DATOS DE LA TABLA ACTUALIZADOS----- \n" << endl;
							 string consultar = "select*from productos";
							 const char* n = consultar.c_str();
							 q_estado = mysql_query(conectar, n);
							 resultado = mysql_store_result(conectar);
							 while (fila = mysql_fetch_row(resultado)) {
								 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								 return main();

							 }
						 }break;

					 case 5:
						 cout << "¿DESEA SALIR? PRECIONE 0 PARA VOLVER AL MENU PRECIONE 6" << endl;
						 if (opciones == 0) { return 0; }
						 break;

					 default: cout << "NUMERO INVALIDO" << endl;
						 return main(); break;


						 }


						 
						 system("pause");
						 return 0;
						 
					 }
