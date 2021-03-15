#include <iostream>

#include <stdio.h>

#include <string.h>

using namespace std;

const char *name_archivo = "archivo.dat";


struct Empleado{

	int codigo;

	char nombres[50];

	char apellidos[50];
	
	char puesto[50];

	float salario;
	
	float bono;
	
	float total;
	

};

void abrir();

void ingresar();

void modificar();

void buscar_codigo();

void eliminar_emp();

main(){
	
	int sw;
	char continuar;
	do{	
	cout<<"************************************"<<endl;
	cout<<"Ingrese la opcion que desee"<<endl;
	cout<<"1. Leer archivo"<<endl;
	cout<<"2. Registrar Empleado"<<endl;
	cout<<"3. Modificar datos del Empleado"<<endl;
	cout<<"4. Buscar Empleado por ID"<<endl;
	cout<<"5. Buscar Empleado por codigo"<<endl;
	cout<<"6. Eliminar Dato de estudiante"<<endl;
	cout<<"  ";
	cin>>sw;
    
	switch(sw){
		
	
case 1:	abrir(); break;
case 2:	ingresar(); break;
case 3:	modificar(); break;
case 4:	buscar_codigo();break;
case 6: eliminar_emp();break;
}
cout<<"Desea realizar otra operacion (s/n):";
		cin>>continuar;
} while (continuar=='s' || continuar=='S');
}

void abrir(){

	system("cls");

	FILE* archivo = fopen(name_archivo,"rb");

	if (!archivo){

		archivo = fopen(name_archivo,"w+b");

	}

	Empleado empleado;

	int id= 0;

	fread(&empleado,sizeof(Empleado),1,archivo);

	cout<<"id |"<<"Codigo de Empleado (CDE)|"<<"Nombres   |"<<"Apellidos   |"<<"Puesto	|"<<"Salario Base	|"<<"Bonificacion	|"<<"Sueldo a recibir	|"<<endl;

	do{

	cout<<id<<"		|"<<empleado.codigo<<" 	    |"<<empleado.nombres<<" 	 |"<<empleado.apellidos<<"    |"<<empleado.puesto<<"  	|"<<empleado.salario<<" 	 |"<<empleado.bono<<"  	|"<<empleado.total<<endl;

	fread(&empleado,sizeof(Empleado),1,archivo);

		id+=1;

	} while(feof(archivo) ==0);

	fclose(archivo);

}



void ingresar(){
	
	char continuar;

	FILE* archivo = fopen(name_archivo,"ab");

	Empleado empleado;

	string nombre,apellido,puesto;

	do{

		fflush(stdin);

		cout<<"Ingrese CDE: ";

		cin>>empleado.codigo;

		cin.ignore();

		

		cout<<"Ingrese Nombres: ";

		getline(cin,nombre);

		strcpy(empleado.nombres,nombre.c_str());

		

		cout<<"Ingrese Los Apellidos: ";

		getline(cin,apellido);

		strcpy(empleado.apellidos,apellido.c_str());
		

		cout<<"Ingrese El Puesto: ";

		getline(cin,puesto);

		strcpy(empleado.puesto,puesto.c_str());	
		
		
		cout<<"Ingrese El Salario Base: ";

		cin>>empleado.salario;
		
		
		cout<<"Ingrese Bonificaciones: ";

		cin>>empleado.bono;
		
		empleado.total=empleado.salario+empleado.bono;

		fwrite(&empleado,sizeof(Empleado),1,archivo);

		cout<<"Desea ingresar otro dato (s/n):";

		cin>>continuar;
		
	} while (continuar=='s' || continuar=='S');

	fclose(archivo);

	abrir();

}

void modificar(){

	FILE* archivo = fopen(name_archivo,"r+b");

	
	int id=0;

	Empleado empleado;

	string nombre,apellido,puesto;

	cout<<"Ingrese el ID a Modificar:";

	cin>>id;

	fseek(archivo,id*sizeof(Empleado),SEEK_SET);

		cout<<"Modificar CDE:";

		cin>>empleado.codigo;

		cin.ignore();

		

		cout<<"Modificar Los Nombres: ";

		getline(cin,nombre);

		strcpy(empleado.nombres,nombre.c_str());

		

		cout<<"Modificar Los Apellidos: ";

		getline(cin,apellido);

		strcpy(empleado.apellidos,apellido.c_str());

		
		cout<<"Modificar El Puesto: ";

		getline(cin,puesto);

		strcpy(empleado.puesto,puesto.c_str());
		

		cout<<"Modificar Salario Base:";

		cin>>empleado.salario;

		cin.ignore();
		
		
		cout<<"Modificar Bonificaciones:";

		cin>>empleado.bono;

		cin.ignore();
		
		fwrite(&empleado,sizeof(Empleado),1,archivo);

		fclose(archivo);

		abrir();
}

void buscar_codigo(){

	FILE* archivo = fopen(name_archivo,"rb");	

	int codigo;
	
	float salario;
	
	float bono;
	
	float total;

	cout<<"Ingrese CDE: ";

	cin>>codigo;

	

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	do{

		if(empleado.codigo == codigo){

			cout<<"______________________"<<endl;

			cout<<"Codigo: "<<empleado.codigo<<endl;

			cout<<"Nombres: "<<empleado.nombres<<endl;

			cout<<"Apellidos: "<<empleado.apellidos<<endl;

			cout<<"Puesto: "<<empleado.puesto<<endl;
			
			cout<<"Salario Base: "<<empleado.salario<<endl;
			
			cout<<"Bonificaciones: "<<empleado.bono<<endl;
			
			cout<<"Sueldo a Recibir: "<<empleado.total<<endl;
		}

		fread(&empleado,sizeof(Empleado),1,archivo);

	} while (feof(archivo)==0);

	

	

	fclose(archivo);

}

void eliminar_emp(){
	
	FILE* archivo = fopen(name_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Eliminar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET ); 
			remove("archivo.dat");
		
	fclose(archivo);
	abrir();
		system("PAUSE");
}
