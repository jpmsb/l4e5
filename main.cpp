#include <iostream>
#include <fstream>
#include <string>
#include "prglib.h" 

using namespace std;
using prglib::lista;
using prglib::arvore;

struct Dados {
    string palavra;
    int valor;
    
    Dados(){
        valor = 0;
    }
    
    Dados(const string & umaPalavra, int umValor){
        palavra = umaPalavra;
        valor = umValor;
    }
    
    bool operator<(const Dados & o){
        return valor < o.valor;
        //if (palavra == o.palavra){
        //    return valor < o.valor;
        //}
        //return palavra < o.palavra;
    }
    
    bool operator==(const Dados & o){
        //return valor == o.valor;
        if (palavra == o.palavra){
            return valor == o.valor;
        }
        return valor == o.valor;
        //return palavra == o.palavra;
    }
};

ostream & operator<<(ostream & out, const Dados & x){
    out << x.palavra << ", " << x.valor;
    return out;
}

int main(int argc, char * argv[]) {
    string nome_do_arquivo, palavra;
    int n = 0;
    nome_do_arquivo = argv[1];
    //getline(cin, nome_do_arquivo);
    
    ifstream arquivo(nome_do_arquivo);
    
    arquivo >> palavra;
    
    arvore<Dados> * arv = new arvore<Dados>(Dados(palavra, n));
    lista<Dados> lista_da_arv;
    //lista<string> lista_da_arv;
    
    while (arquivo >> palavra){
        n++;
        try {
            arv->obtem(palavra);
        } catch (...) {
            
        }

        arv->adiciona(Dados(palavra, n));
        cout << n << endl;
        //lista_da_arv.anexa(palavra);
    }
    arv->iniciaPeloFim();
    
    int c = 0;
    while(! arv->inicio()){
        //if (c == 5) break;
        lista_da_arv.insere(arv->anterior());
        c++;
    }
    
    //lista_da_arv.ordena();
    lista_da_arv.escrevaSe(cout);
}
