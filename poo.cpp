#include <iostream>
using namespace std;

class ejemplo {
	int iprivado;
	int isegundo; // Agregar isegundo como un miembro de la clase
public:
	ejemplo() // constructor de clases
	{
		iprivado = 0;
		isegundo = 0; 
	}
	int get_iprivado() // método para retornar el valor del atributo iprivado
	{
		return iprivado;
	}
	int get_isegundo() // método para retornar el valor del atributo isegundo
	{
		return isegundo; // Devolver isegundo en lugar de iprivado
	}
	void set_iprivado(int valor) // método para asignar el valor del atributo iprivado
	{
		if(valor > 0)
			iprivado = valor;
	}
	void set_isegundo(int valor) // método para asignar el valor del atributo isegundo
	{
		if(valor > 0)
			isegundo = valor;
	}
	void set_ejemplo(int valor, int valor2) // para asignar valores a los atributos 
	{
		if(valor > 0 && valor2 > 0) {
			iprivado = valor;
			isegundo = valor2;
		}
	}
	~ejemplo() // destructor
	{
		this->iprivado=-1;
		this->isegundo=-1;
		cout << "se esta ejecutando el >Destructor<" << endl;
	}
};

int main(int argc, char *argv[]) {
	/*ejemplo objeto1(0, 0); // Debes pasar dos valores al constructor
	cout << "Valor del atributo iprivado: " << objeto1.get_iprivado() << endl;
	objeto1.set_iprivado(100);
	cout << "Valor del atributo iprivado: " << objeto1.get_iprivado() << endl;
	objeto1.set_iprivado(-20); // Esto no cambiará el valor del atributo porque es menor que 0
	cout << "Valor del atributo iprivado: " << objeto1.get_iprivado() << endl;*/
	
	const int TAM=2;
	ejemplo arrObjeto[TAM];
	arrObjeto[0].set_iprivado(100);
	arrObjeto[0].set_isegundo(200);
	cout<<"Primer objeto : iprivado="<<arrObjeto[0].get_iprivado()<<endl;
	cout<<"Primer objeto : isegundo="<<arrObjeto[0].get_isegundo()<<endl;
	
	cout<<"segundo objeto : iprivado="<<arrObjeto[1].get_iprivado()<<endl;
	cout<<"segundoobjeto : isegundo="<<arrObjeto[1].get_isegundo()<<endl;
	return 0;
	
}
