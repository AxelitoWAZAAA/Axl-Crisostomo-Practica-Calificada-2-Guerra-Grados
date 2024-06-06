#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    string codigo;
    string nombre;
    float nota1,nota2,nota3,promedio=0;
};

int main() {

    Estudiante estud[100];
    int cant,desap=0;

    cout<<"Cantidad de estudiantes: ";
    cin>>cant;

    for(int i=0 ; i<cant; ++i) {
        cout<<"Código, nombre y notas del estudiante "<<i+1<<": "<<endl;
        cout<<"Ingrese código de estudiante: "<<endl;
        cin>>estud[i].codigo;
        cout<<"Ingrese nombre del estudiante: "<<endl;
		cin>>estud[i].nombre;
		cout<<"Ingrese nota 1: "; cin>>estud[i].nota1;
		cout<<"Ingrese nota 2: "; cin>>estud[i].nota2;
		cout<<"Ingrese nota 3: "; cin>>estud[i].nota3;
		
        estud[i].promedio=(estud[i].nota1+estud[i].nota2+estud[i].nota3)/3.0;
        if (estud[i].promedio<10.0) {
			desap++;
		}
    }

    for (int i=0; i<cant-1; ++i) {
        for (int j = 0; j<cant-i-1; ++j) {
            if (estud[j].promedio<estud[j+1].promedio) {
                Estudiante temp=estud[j];
                estud[j]=estud[j+1];
                estud[j+1]=temp;
            }
        }
    }

    cout<<"\nPromedio y cantidad de estudiantes desaprobados:\n";
    for (int i=0; i<cant; ++i) {
        cout<<"Estudiante "<<i+1<<": "<<estud[i].nombre<<" - Promedio: "<<estud[i].promedio<<endl;
    }
    cout<<"Desaprobados: "<<desap<<endl;

    return 0;
}
