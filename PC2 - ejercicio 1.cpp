#include <iostream>
#include <vector>
#include <string>

using namespace std;

string enfermedades[10] = {"gripe", "indigesti�n", "catarro", "alergia", "migra�a", "diabetes", "hipertensi�n", "asma", "anemia", "bronquitis"};
string sintomas[10] = {"fiebre", "tos", "dolor de cabeza", "n�useas", "fatiga", "dolor de garganta", "dolor abdominal", "mareo", "p�rdida de apetito", "dificultad para respirar"};

// Se coloca uno cuando el usuario dice que si tuvo la enfermedad (osea Verdadero) y cero cuando no la tuvo (En este caso se pone automaticamente porque mas adelante se declarara automaticamente como Falso)
bool sintomatologias[10][10] = {
    {1, 1, 1, 0, 0, 1, 0, 0, 0, 0}, // gripe
    {0, 0, 0, 1, 1, 0, 1, 1, 1, 0}, // indigesti�n
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0}, // catarro
    {0, 0, 1, 0, 0, 1, 0, 1, 0, 1}, // alergia
    {0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, // migra�a
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0}, // diabetes
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, // hipertensi�n
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, // asma
    {0, 0, 1, 0, 1, 0, 0, 1, 1, 0}, // anemia
    {0, 1, 0, 0, 1, 1, 0, 0, 0, 1}  // bronquitis
};

void diagnosticar() {
    vector<int> respuestas(10, 0);
    string respuesta;
    cout<<"Responda a las siguientes preguntas con 's�' o 'no':" << endl;
    
    for(int i=0; i<10; ++i) {
        cout<<"�Usted sintio "<<sintomas[i]<<"? ";
        cin>>respuesta;

        if(respuesta=="s�" || respuesta=="si" || respuesta=="S�" || respuesta=="Si" || respuesta=="S" || respuesta=="s") {
            respuestas[i]=1;
        }
    }

    vector<string> coincidencias;

	//Se comparan los booleanos con la base de datos
	
    for (int i=0; i<10; ++i) {
        bool coincide=true;
        for (int j=0; j<10; ++j) {
            if (respuestas[j]!=sintomatologias[i][j]) {
                coincide=false;
                break;
            }
        }
        //Esta parte se usa para a�adir una enfermedad a la lista de posibles enfermedades coincidentes.
        if(coincide){
        	coincidencias.push_back(enfermedades[i]); 
        }
    }
		
		//Cuando la lista de posibles enfermedades est� vac�a indicara una respuesta en bool para seguir con el proceso
    if (!coincidencias.empty()) {
        cout<<"Usted podr�a tener la siguiente enfermedad:"<<endl;
        for(size_t i=0; i<coincidencias.size(); ++i) {
            cout<<coincidencias[i]<<endl;
        }
    } else {
        cout<<"No se puede determinar una enfermedad con los datos recopilados."<<endl;
    }
}

int main(){
    diagnosticar();
    return 0;
}

