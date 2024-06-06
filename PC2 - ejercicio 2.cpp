#include <iostream>
#include <string>
using namespace std;

struct Alumno{
    int codigo;
    string nombre;
    char genero;
    int edad;
    float notas[3];
    float promedio;
};

// Funciones que iran en el switch
void regAlu(Alumno alumnos[], int& cantidad);
void mostrarAlus(const Alumno alumnos[], int cantidad);
void mostrarNotas(const Alumno alumnos[], int cantidad, int curso);
void calcPromGral(const Alumno alumnos[], int cantidad);
void mostrarPrimUlt(const Alumno alumnos[], int cantidad);

//Priorizar primero registrar alumnos porque esta hace depender de su informacion a las demas opciones del menú
int main() {
	
    Alumno alumnos[100];
    int cantidad = 0;
    int opcion;
    do {
        cout<<"\t\tMenu:\n";
        cout<<"1. Registrar Alumno\n";
        cout<<"2. Ver Lista de Alumnos\n";
        cout<<"3. Ver Notas por Asignatura\n";
        cout<<"4. Calcular Promedio General\n";
        cout<<"5. Mostrar Primer y Ultimo Alumno\n";
        cout<<"0. Salir\n";
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                regAlu(alumnos,cantidad);
                break;
            case 2:
                mostrarAlus(alumnos,cantidad);
                break;
            case 3:{
                int curso;
                cout<<"Ingrese el numero del curso (1, 2 o 3): ";
                cin>>curso;
                mostrarNotas(alumnos,cantidad,curso);
                break;
            }
            case 4:
                calcPromGral(alumnos,cantidad);
                break;
            case 5:
                mostrarPrimUlt(alumnos,cantidad);
                break;
            case 0:
                cout<<"Cerrando aplicación"<<endl;
                break;
            default:
                cout<<"ERROR. Intentar de nuevo"<<endl;
        }
    } while(opcion!=0);
    return 0;
}

void regAlu(Alumno alumnos[],int& cantidad) {
    Alumno nuevo;
    cout<<"Ingrese el codigo del alumno: ";
    cin>>nuevo.codigo;
    cout<<"Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin, nuevo.nombre);
    cout<<"Ingrese el genero del alumno (M/F): ";
    cin>>nuevo.genero;
    cout<<"Ingrese la edad del alumno: ";
    cin>>nuevo.edad;
    cout<<"Ingrese las notas para los tres cursos: ";
    float suma=0;
    for (int i=0; i<3; i++) {
        cin>>nuevo.notas[i];
        suma+=nuevo.notas[i];
    }
    nuevo.promedio=suma/3.0;
    alumnos[cantidad++]=nuevo;
}

void mostrarAlus(const Alumno alumnos[], int cantidad) {
    cout<<"Lista de Alumnos: "<<endl;
    for (int i=0;i<cantidad;++i){
        cout<<"Codigo: "<<alumnos[i].codigo<<endl;
		cout<<"Nombre: "<<alumnos[i].nombre<<endl;
        cout<<"Genero: "<<alumnos[i].genero <<endl;
		cout<<"Edad: "<<alumnos[i].edad<<endl;
        cout<<"Promedio: "<<alumnos[i].promedio<<endl;
    }
}

void mostrarNotas(const Alumno alumnos[], int cantidad, int curso) {
    cout<<"Notas para el Curso "<<curso<<":"<< endl;
    for(int i=0; i<cantidad; ++i) {
        cout<<"Código: "<<alumnos[i].codigo<<endl;
		cout<<"Nota: "<<alumnos[i].notas[curso-1]<<endl;
    }
}

void calcPromGral(const Alumno alumnos[], int cantidad) {
    float suma=0;
    for (int i=0; i<cantidad; i++) {
        suma+=alumnos[i].promedio;
    }
    float promT=suma/cantidad;
    cout <<"Promedio de todas las notas: "<<promT<<endl;
}

void mostrarPrimUlt(const Alumno alumnos[], int cantidad) {
    if (cantidad==0) {
        cout<<"No se registro a nadie."<<endl;
        return;
    }
    cout<<"Primer Alumno: "<<alumnos[0].nombre<<endl;
    cout<<"Ultimo Alumno: "<<alumnos[cantidad-1].nombre<<endl;
}

