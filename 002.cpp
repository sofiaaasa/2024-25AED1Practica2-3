#include <iostream>
#include <string>
using namespace std;

int tilde = -61;
const int NUM_TILDES = 7;
int tablaTil [][NUM_TILDES] = {{-79, -95, -87, -83, -77, -70, -68},        //ñ á é í ó ú ü
                            {-111, -127, -119, -115, -109, -102, -100}};  //Ñ Á É Í Ó Ú Ü
string tablaSin [] = {"ñ", "a", "e", "i", "o", "u", "u"};  //ñ a e i o u



string normalizar(string cadena){
  string cad = cadena;
  string normalizada = "";
  for (unsigned i=0; i<cad.length(); i++){         
    if (cad[i] >= 'A' && cad[i] <= 'Z') normalizada+=tolower(cad[i]);   // Letras mayúsculas sin tildes
    else if (int(cadena[i]) == tilde){                      // Comprueba si el código decimal del carácter corresponde a una letra con tilde.
      int j=0;
      bool continuar = true;
      while (j<NUM_TILDES && continuar){    // Va buscando cual es la letra con tilde que hay
        if (int(cad[i+1]) == tablaTil[0][j] || int(cad[i+1]) == tablaTil[1][j]){     
          normalizada+=tablaSin[j];
          continuar = false;
          i++;
        }
        j++;
      }
      if (continuar == true) normalizada+=cad[i]; //Por si es cualquier carácter raro que use 2 bytes en vez de 1 pero que no esté en la tabla
    } else normalizada+=cad[i];     
  }
  return normalizada;
}

int main(){
  string cadena;
  int numPet = 0;
  while (cin >> cadena){
    //cout << cadena << endl;
    numPet+=1;
    cout << numPet << ". " << cadena << " -> " << normalizar(cadena) << endl;
    /*
    for (unsigned i=0; i<cadena.length(); i++){
      cout << int(cadena[i]) << endl;
    }
    */
  }
}
