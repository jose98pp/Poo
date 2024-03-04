#include <iostream>
using namespace std;
//CLASE PIRNCIPAL PERSONA ->ESTUDINATE
class persona{
	string nombre,direccion;
public:
	persona(){
		nombre="anonimo";
		direccion="sin direcion";
		
	}
	string get_nombre(){return nombre;};
	string get_direccion(){return direccion;};
	void set_nombre(string n){nombre=n;}
	void set_direccion(string d){direccion=d;}
	//completar los atributos
	void mostrarDatos(){
		cout<<"Nombre :"<<nombre<<endl;
		cout<<"Direcion: "<<direccion<<endl;
		
	}
};
class estudiante:public persona{
	string cod_estudiante;
	string carrera;
public :
	estudiante(){
		cod_estudiante ="sin codigo";
		carrera ="sin carrera";
	}
	string get_cod_estudiante(){return cod_estudiante;};
	string get_carrera(){return carrera;};
	void set_cod_estudiante(string c){cod_estudiante=c;}
	void set_carrera(string cr){carrera=cr;}
	void mostrarDatos(){
		persona ::mostrarDatos();
		cout<<"Codigo Estudiante : "<<cod_estudiante<<endl;
		cout<<"Carrera : "<<carrera<<endl;
		
	}
};

int main(int argc, char *argv[]) {
	/*persona p1,p2;
	p1.mostrarDatos();
	p2.set_nombre("Juan Perez");
	p2.set_direccion("c3 zona norte ");
	p2.mostrarDatos();*/
	
	estudiante e1,e2;
	//e1.mostrarDatos();
	e2.set_nombre("Cristian");
	e2.set_direccion("calle 4");
	e2.set_cod_estudiante("11362573");
	e2.set_carrera(" Medicina ");
	e2.mostrarDatos();
	
	return 0;
}

