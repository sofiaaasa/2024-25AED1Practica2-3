#include <iostream>
#include <string>
using namespace std;

const int tilde = -61;
const int NUM_TILDES = 7;
const int tablaTil [][NUM_TILDES] = {{-79, -95, -87, -83, -77, -70, -68},        //ñ á é í ó ú ü
                            {-111, -127, -119, -115, -109, -102, -100}};  //Ñ Á É Í Ó Ú Ü
const string tablaSin [] = {"ñ", "a", "e", "i", "o", "u", "u"};  //ñ a e i o u
int contador = 0;

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

void insertar(){
  int relevancia;
  int numpal = 0;
  string palabra, URL, titulo;
  contador+=1;
  cin >> relevancia >> URL;
  cin.ignore();
  getline(cin, titulo);
  cout << contador << ". " << URL << ", " << titulo << ", Rel. " << relevancia << endl;
  while (cin >> palabra && normalizar(palabra) != "findepagina" ){
    numpal+=1;
  }
  cout << numpal << " palabras" << endl;
}


int Interprete(string comando){
  if (comando == "i") insertar();
  else if (comando == "s"){
    cin.ignore();
    if (cin.peek() == -1) cout << "Saliendo..." << endl;  
    return 1;
  } 
  else if (comando == "u") {
    string url;
    cin.ignore();
    getline(cin, url);
    cout << comando << " " << url << endl;
    cout << "Total: 0 resultados" << endl;
  }
  else if (comando == "b") {
    string palabra;
    cin >> palabra;
    cout << comando << " " << normalizar(palabra) << endl;
    cout << "Total: 0 resultados" << endl;
  }
  else if (comando == "a") {
    string palabras;
    cin.ignore();
    getline(cin, palabras);
    cout << comando << " " << normalizar(palabras) << endl;
    cout << "Total: 0 resultados" << endl;
  }
  else if (comando == "o") {
    string palabras;
    cin.ignore();
    getline(cin, palabras);
    cout << comando << " " << normalizar(palabras) << endl;
    cout << "Total: 0 resultados" << endl;
  }
  else if (comando == "p") {
    string palabra;
    cin >> palabra;
    cout << comando << " " << normalizar(palabra) << endl;
    cout << "Total: 0 resultados" << endl;
  }
  return 0;
}

int main(){
  string comando;
  while (cin >> comando){
    if (Interprete(comando) == 1) return 0;
  }
}
