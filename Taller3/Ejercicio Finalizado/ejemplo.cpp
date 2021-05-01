#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <dir.h>
using namespace std;

#define MAX_PRODUCTS 50

// Estructura de cada producto
struct Producto{
	int status;
	char codigo[20];
	char nombre[20];
	char precio[20];
	char cantidad[20];
	char descripcion[100];
} productos [MAX_PRODUCTS]; //Array de productos

// Variable que indica la posicion disponible de nuestro array de productos
int posicionDisponible = 0;

// FUNCIONES PARA INGRESAR PRODUCTOS +++++++++++++++++++++++++++++++++++++++++
void ingresarProducto(){
	Producto p;
	//Obteniendo el codigo del producto
	system("cls");
	cout<< "\tIngrese el codigo del producto:\n\t";
	string codigo;
	getline (cin, codigo);
	strcpy( p.codigo, codigo.c_str());
	//Obteniendo el nombre del producto
	system("cls");
	cout<< "\tIngrese el nombre del producto:\n\t";
	string nombre;
	getline (cin, nombre);
	strcpy( p.nombre, nombre.c_str());
	
	//Obteniendo la descripcion del producto
	system("cls");
	cout<< "\tIngrese la descripcion del producto:\n\t";
	string descripcion;
	getline (cin, descripcion);
	strcpy( p.descripcion, descripcion.c_str());
	
	//Obteniendo el precio del producto
	system("cls");
	cout<< "\tIngrese el precio del producto:\n\t";
	string precio;
	getline (cin, precio);
	strcpy( p.precio, precio.c_str());
		
	//Obteniendo la cantidad del producto del producto
	system("cls");
	cout<< "\tIngrese la cantidad de producto:\n\t";
	string cantidad;
	getline (cin, cantidad);
	strcpy( p.cantidad, cantidad.c_str());
	
	//Agregando el producto a nuestro array
	p.status = 1;
	productos[posicionDisponible] = p;
	posicionDisponible++;
	system("cls");
	cout<< "\t<-- El producto se registro con exito -->\n\t";
	getch();
	system("cls");	
}

// FUNCIONES PARA VER PRODUCTOS +++++++++++++++++++++++++++++++++++++++++
void verProductos(){
	system("cls");
	int count = 0;
	Producto aux;
	for(int i = 0; i < MAX_PRODUCTS; i++){
		aux = productos[i];
		if(aux.status == 1){
			cout << "    Producto "<<(i+1)<<"  --------------------------------------"<<endl;
			cout << "\tCodigo: \t"		<<aux.codigo<<endl;
			cout << "\tNombre: \t"		<<aux.nombre<<endl;
			cout << "\tPrecio: \t"		<<aux.precio<<endl;
			cout << "\tCantidad: \t"	<<aux.cantidad<<endl;
			cout << "\tDescripcion: \t"	<<aux.descripcion<<endl;
			cout <<endl;			
			count++;
		}		
	}
	if(count == 0){
		cout<< "\t <-- No hay productos registrados -->\n\t";
	}
	getch();
	system("cls");
}

// FUNCIONES PARA GENERAR HTML +++++++++++++++++++++++++++++++++++++++++++++++
string getHtmlText(){
  string html = "<!DOCTYPE html>\n";
  html = html + "<html>\n";
  html = html + "<head>\n";
  html = html + "   <title>Reporte de Productos</title>\n";
  html = html + "   <link href= \"style.css\" type= \"text/css\" rel=\"stylesheet\">\n";
  html = html + "</head>\n";
  html = html + "<body>\n";
  html = html + " <div class= \"menu\">\n";
  html = html + "       <ul> <li><a href=\"#\">Home</a></li> </ul>\n";
  html = html + " </div>\n";
  html = html + " <h1>Reporte: \"Productos\"</h1>";
  html = html + "<table>\n";
  html = html + " <tbody>\n";
  html = html + "        <tr> <th width = \"100px\">Codigo</th>  <th width = \"250px\">Nombre</th>  <th width = \"50px\">Precio</th> <th width = \"50px\">Cantidad</th> <th width = \"250px\">Descripción</th> </tr> ";
  //Generamos el cuerpo de la tabla con los datos de los productos
  for(int i = 0; i < MAX_PRODUCTS; i++){
  	Producto aux = productos[i];
	if(aux.status == 1){
		html = html + "<tr>   <td>"+aux.codigo+"</td> <td>"+aux.nombre+"</td>  <td>"+aux.precio+"</td>  <td>"+aux.cantidad+"</td> <td>"+aux.descripcion+"</td> </tr> \n";
	}
  }
  
  //Generamos html faltante  
  html = html + "    </tbody>\n";
  html = html + "</table>\n";
  html = html + "<div id=\"pie-pagina\">\n";
  html = html + "       <p>Universidad de San Carlos de Guatemala, Facultad de Ingenieria <br>www.ingenieria.usac.edu.gt</br><br>Todos los derechos reservados 2021</br></p>\n";
  html = html + "</div>\n";
  html = html + "</body>\n";
  html = html + "</html>\n";
  return html;
}

void exportar(){
	ofstream file;
    string directory = "Report";
    mkdir(directory.c_str());
    directory = directory + "/index.html";
    file.open(directory.c_str());
    system("cls");
  	if(file.fail()){
    	cout<<"\t>>>>Failed to writte html file.\n";
    	getch();
    	system("cls");
  	}else{
  		string html = getHtmlText();
    	file << html.c_str();
    	file.close();
    	
    	cout<<"\t>>>>El reporte se genero correctamente.\n";
    	getch();
    	system("cls");
  	}
}



// METODOS PARA EL MENU ++++++++++++++++++++++++++++++++++++++++++++++++++++++
void imprimirMenu(){
	cout <<"     <<<<<<< CONTROL DE INVENTARIOS >>>>>>>" << endl;
	cout <<"\t1. Ingresar Producto" <<endl;
	cout <<"\t2. Ver Productos" <<endl;
	cout <<"\t3. Exportar Html" <<endl;
	cout <<"\t4. Exit" <<endl;
	cout <<"\tIngrese una opcion: ";
}

int main(){
	char opcion;
	while(opcion != '4'){
		//Imprimimos menú
		imprimirMenu();
		//Obtenemos caracter del teclado
		opcion = getch();
		//Revisamos opciones
		switch(opcion){
			case '1': //Ingresar producto
				ingresarProducto();
				break;
			case '2': //Ver productos 
				verProductos();
				break;
			case '3': //Exportar html
				exportar();
				break;
			case '4':
				system("cls");
				cout <<"\tFinalizando Ejecucion"<<endl;
				break;
			default:
	           	system("cls");
	           	std::cout << "\n\t<-- Opcion no disponible -->" << '\n';
	           	getch();
	           	system("cls");
	        	break;
		}
	}
	
	
	
	
	return 0;
}

