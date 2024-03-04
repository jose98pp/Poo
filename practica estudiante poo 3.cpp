#include <iostream>
#include <string>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <cctype>  // Para tolower()
using namespace std;

// Función para limpiar la pantalla (Windows)
void limpiarPantalla() {
	system("cls"); // Limpia la pantalla en sistemas Windows
}

// Clase base Persona
class Persona {
protected:
	string nombre;
	string apellido;
	string direccion;
	
public:
	Persona() {
		nombre = "";
		apellido = "";
		direccion = "";
	}
	
	string getNombre() { return nombre; } // Devuelve el nombre de la persona
	string getApellido() { return apellido; } // Devuelve el apellido de la persona
	string getDireccion() { return direccion; } // Devuelve la dirección de la persona
	
	void setNombre(string n) { nombre = n; } // Establece el nombre de la persona
	void setApellido(string a) { apellido = a; } // Establece el apellido de la persona
	void setDireccion(string d) { direccion = d; } // Establece la dirección de la persona
};

// Clase derivada Estudiante heredando de Persona
class Estudiante : public Persona {
private:
	string carrera;
	string codigo; // Agregado el atributo código
	
public:
	Estudiante() : Persona() {
		carrera = "";
		codigo = "";
	}
	
	string getCarrera() { return carrera; } // Devuelve la carrera del estudiante
	string getCodigo() { return codigo; } // Devuelve el código del estudiante
	
	void setCarrera(string c) { carrera = c; } // Establece la carrera del estudiante
	void setCodigo(string cod) { codigo = cod; } // Establece el código del estudiante
	
	void mostrarDatos() {
		cout << "Nombre: " << nombre << endl; // Muestra el nombre del estudiante
		cout << "Apellido: " << apellido << endl; // Muestra el apellido del estudiante
		cout << "Dirección: " << direccion << endl; // Muestra la dirección del estudiante
		cout << "Carrera: " << carrera << endl; // Muestra la carrera del estudiante
		cout << "Codigo: " << codigo << endl; // Muestra el código del estudiante
	}
};

// Arrays de nombres, apellidos, direcciones y carreras
string nombres[] = {"José", "Carlos", "Cristian", "Jorge", "Pablo", "María", "Laura", "Ana", "Pedro", "Luisa"};
string apellidos[] = {"García", "Vaca", "Ponce", "Vilca", "Flores", "Martínez", "Gómez", "Sánchez", "López", "Díaz"};
string direcciones[] = {"Av. 6 de Agosto #123", "Calle Sucre #456", "Av. Camacho #789", "Calle Murillo #101", "Av. Ballivián #202", "Av. Arce #404", "Plaza Principal", 
	"Calle Ingavi #707", "Av. Busch #1514", "Calle Junín #1211","Calle España #1817", "Av.Banzer", "Av.Japon","Av.Beni", "Av. Chichuriru"};
string carreras[] = {"Ing. Sistemas", "Ing. Redes", "Medicina", "Derecho", "Administración", "Psicología", "Arquitectura", "Biología", "Marketing", "Informatica",
	"Ing. Comercial", "Contaduria Publica","Relaciones Internacionales","Ing. Civil", "Fisioterapia"};

// Función para generar un índice aleatorio entre 0 y el tamaño del array - 1
int generarIndice(int tamano) {
	return rand() % tamano; // Genera un número aleatorio dentro del rango de tamaño del array
}

// Función para generar un código aleatorio de 6 dígitos
string generarCodigo() {
	string codigo = "";
	for (int i = 0; i < 6; ++i) {
		codigo += to_string(rand() % 10); // Genera un dígito aleatorio y lo concatena al código
	}
	return codigo; // Devuelve el código generado
}

// Función para generar datos aleatorios de estudiante
Estudiante generarDatosEstudiante() {
	Estudiante estudiante;
	estudiante.setNombre(nombres[generarIndice(sizeof(nombres) / sizeof(nombres[0]))]); // Establece un nombre aleatorio del array
	estudiante.setApellido(apellidos[generarIndice(sizeof(apellidos) / sizeof(apellidos[0]))]); // Establece un apellido aleatorio del array
	estudiante.setDireccion(direcciones[generarIndice(sizeof(direcciones) / sizeof(direcciones[0]))]); // Establece una dirección aleatoria del array
	estudiante.setCarrera(carreras[generarIndice(sizeof(carreras) / sizeof(carreras[0]))]); // Establece una carrera aleatoria del array
	estudiante.setCodigo(generarCodigo()); // Genera y establece el código del estudiante
	return estudiante; // Devuelve el estudiante generado
}

// Función para buscar estudiantes por dirección
void buscarEstudiantesPorDireccion(Estudiante estudiantes[], int tamano) {
	string direccionBusqueda;
	cout << "Ingrese la parte de la dirección a buscar: ";
	cin.ignore();
	getline(cin, direccionBusqueda);
	
	// Convertir la dirección de búsqueda a minúsculas usando tolower
	for (char& c : direccionBusqueda) {
		c = tolower(c);
	}
	
	bool encontrado = false;
	for (int i = 0; i < tamano; ++i) {
		// Convertir la dirección del estudiante a minúsculas usando tolower
		string direccionEstudiante = estudiantes[i].getDireccion();
		for (char& c : direccionEstudiante) {
			c = tolower(c);
		}
		// Buscar coincidencias parciales
		if (direccionEstudiante.find(direccionBusqueda) != string::npos) {
			cout << "Estudiante encontrado:" << endl;
			estudiantes[i].mostrarDatos();
			cout << endl; // Añadir un salto de línea después de cada estudiante encontrado
			encontrado = true;
		}
	}
	
	if (!encontrado) {
		cout << "No se encontraron estudiantes en la dirección especificada." << endl;
	}
}

int main() {
	srand(time(0)); // Inicializar la semilla para los números aleatorios
	
	const int NUM_ESTUDIANTES = 10; // Definir la cantidad de estudiantes a generar
	
	Estudiante estudiantes[NUM_ESTUDIANTES];
	
	int opcion;
	
	do {
		limpiarPantalla(); // Limpiar la pantalla en cada iteración del menú
		
		cout << "------ MENU ------" << endl;
		cout << "1. Generar datos de estudiantes" << endl;
		cout << "2. Mostrar datos de estudiantes" << endl;
		cout << "3. Buscar estudiante por dirección" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese la opción deseada: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Generar datos de estudiantes
			for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
				estudiantes[i] = generarDatosEstudiante();
			}
			cout << "Datos de estudiantes generados correctamente." << endl;
			break;
		case 2:
			// Mostrar datos de todos los estudiantes
			cout << "Datos de todos los estudiantes:" << endl;
			for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
				cout << "Estudiante " << i + 1 << ":" << endl;
				estudiantes[i].mostrarDatos();
				cout << endl;
			}
			break;
		case 3:
			// Buscar estudiantes por dirección
			buscarEstudiantesPorDireccion(estudiantes, NUM_ESTUDIANTES);
			break;
		case 4:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
			break;
		}
		
		// Pausa para que el usuario pueda ver la salida antes de limpiar la pantalla en la siguiente iteración
		cout << "Presione Enter para continuar...";
		cin.ignore();
		cin.get();
		
	} while (opcion != 4);
	
	return 0;
}
