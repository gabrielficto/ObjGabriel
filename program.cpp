#include  <cstdlib> 
/*
:'#######::'########::::::::'##::'######::::::'###::::'########::'########::'####:'########:'##:::::::
'##.... ##: ##.... ##::::::: ##:'##... ##::::'## ##::: ##.... ##: ##.... ##:. ##:: ##.....:: ##:::::::
 ##:::: ##: ##:::: ##::::::: ##: ##:::..::::'##:. ##:: ##:::: ##: ##:::: ##:: ##:: ##::::::: ##:::::::
 ##:::: ##: ########:::::::: ##: ##::'####:'##:::. ##: ########:: ########::: ##:: ######::: ##:::::::
 ##:::: ##: ##.... ##:'##::: ##: ##::: ##:: #########: ##.... ##: ##.. ##:::: ##:: ##...:::: ##:::::::
 ##:::: ##: ##:::: ##: ##::: ##: ##::: ##:: ##.... ##: ##:::: ##: ##::. ##::: ##:: ##::::::: ##:::::::
. #######:: ########::. ######::. ######::: ##:::: ##: ########:: ##:::. ##:'####: ########: ########:
:.......:::........::::......::::......::::..:::::..::........:::..:::::..::....::........::........::
*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
// #include <X11/Xlib.h>

using namespace std;

class Gabriel
{
public:
    static void print(string arg)
    {
        cout << arg;
    }

    static void print(int arg)
    {
        cout << arg;
    }

    static void print(float arg)
    {
        cout << arg;
    }

    static void println(string arg)
    {
        cout << arg << endl;
    }

    static void println(int arg)
    {
        cout << arg << endl;
    }

    static void println(float arg)
    {
        cout << arg << endl;
    }

    static void clear()
    {
#ifdef _WIN32
        system("cls");
        return;
#endif

        system("clear");
    }
};

class Andrew
{
public:
    static int randomBi32(int min, int max)
    {
        srand(time(0));
        const int BI = (rand() %
                        (min - max + 1)) +
                       min;
        return BI;
    }

    /*static float randomBi64(float min, float max)
    {
        srand(time(0));
        const float BI = ((rand()) %
                          (min - max + 1)) +
                         min;
        return BI;
    }*/
};

const int TAM = 5; 
int vertices[TAM] = {};
int adjac[TAM][TAM] = {};
int itens = 0;
void insereVertice( int valor ) { 
int indice = 0;
if(itens == TAM){ 
Gabriel::println("O vetor está cheio!"); 
return; 
} 
for(indice = 0; indice < itens; indice++){ 
if(vertices[indice] == valor){ 
Gabriel::println("O valor já existe no vetor"); 
return; 
} 
} 
vertices[itens] = valor; 
Gabriel::println("O vértice foi inserido!"); 
itens++; 
} 
void insereAresta( int origem, int destino ) { 
int i = 0,origExiste=-1,destExiste=-1;
for(i = 0; i < itens; i++){ 
if(vertices[i] == origem) 
origExiste = i; 
if(vertices[i] == destino) 
destExiste = i; 
} 
if(origExiste == -1 && destExiste == -1){ 
Gabriel::println("Origem e destino não existem!!!"); 
return; 
} 
if(origExiste == -1){ 
Gabriel::println("Origem não existe!!!"); 
return; 
} 
if(destExiste == -1){ 
Gabriel::println("Destino não existe!!!"); 
return; 
} 
if(adjac[origExiste][destExiste] == 1){ 
Gabriel::println("A aresta já existe no grafo!!!"); 
return; 
} 
adjac[origExiste][destExiste] = 1; 
Gabriel::println("A aresta foi inserida no grafo!!!"); 
return; 
} 
void imprime() { 
if(itens == 0){ 
Gabriel::println("O grafo não existe!!!"); 
return; 
} 
int j = 0,i=0;
std::cout << endl; 
for(j = 0; j < itens; j++){ 
std::cout << "" << vertices[j]; 
for(i = 0; i < itens; i++){ 
if(adjac[j][i] == 1) 
std::cout << " <" << vertices[j] << "," << vertices[i] << "> "; 
} 
std::cout << endl; 
} 
} 
int main() { 
int i = 0,j=0;
for(i = 0; i < TAM; i++){ 
for(j = 0; j < TAM; j++) 
adjac[i][j] = 0; 
} 
insereVertice(10); 
insereVertice(21); 
insereVertice(32); 
insereVertice(15); 
insereAresta(10, 21); 
insereAresta(10, 32); 
insereAresta(21, 10); 
insereAresta(15, 21); 
imprime(); 
return 0; 
} 
