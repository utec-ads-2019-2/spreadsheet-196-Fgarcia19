#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

int x, y;
vector<vector<string>>matriz;
string abecedario="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int get_letra(char letra){
    for (int i=0;i<abecedario.size();i++){
        if (abecedario[i]==letra){
            return i;
        }
    }
}

int valor_palabra(string palabra){
    int contador=0;
    for (int i=0;i<palabra.size();i++){
        if(i!=palabra.size()-1){
            contador+=(get_letra(palabra[i])+1)*pow(26,palabra.size()-i-1);
        }
        else {

            contador += get_letra(palabra[i]);
        }
    }
    return contador;
}

string ecuacion(string palabra){
    int cantidad=0;
    string letras;
    string numero;
//    cout<<palabra<<endl;

    for(int i=1;i<palabra.size();i++) {
        if (palabra[i] != '+') {
            if (!isdigit(palabra[i])) {
                letras += palabra[i];
            } else {
                numero += palabra[i];
            }

        } else {

            if(matriz[stoi(numero) - 1][valor_palabra(letras)][0]=='='){
                matriz[stoi(numero) - 1][valor_palabra(letras)]=ecuacion(matriz[stoi(numero) - 1][valor_palabra(letras)]);
            }
            cantidad += stoi(matriz[stoi(numero) - 1][valor_palabra(letras)]);
            letras = "";
            numero = "";
        }
    }
    if(matriz[stoi(numero) - 1][valor_palabra(letras)][0]=='='){
        matriz[stoi(numero) - 1][valor_palabra(letras)]=ecuacion(matriz[stoi(numero) - 1][valor_palabra(letras)]);
    }
        cantidad+=stoi(matriz[stoi(numero)-1][valor_palabra(letras)]);
        letras="";
        numero="";
    return to_string(cantidad);
}

void crear_matriz(){
    vector<string> temp;
    for(int i=0;i<y;i++){

        for(int j=0;j<x;j++){
            string aux;
            cin>>aux;
            temp.push_back(aux);

        }
        matriz.push_back(temp);
        temp={};
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(matriz[i][j][0]!='=')
                cout<<matriz[i][j];
            else {
                matriz[i][j] = ecuacion(matriz[i][j]);
                cout << matriz[i][j];
            }
            if(j<x-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }



}


int main() {
    int cantidad;
    cin>>cantidad;
    for(int i=0;i<cantidad;i++){
        cin>>x>>y;
        crear_matriz();
        matriz={};
    }

}