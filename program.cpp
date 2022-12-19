/*
'########:'####::'######::'########::'#######:::'######::::::::::::::::::
 ##.....::. ##::'##... ##:... ##..::'##.... ##:'##... ##:::'##:::::'##:::
 ##:::::::: ##:: ##:::..::::: ##:::: ##:::: ##: ##:::..:::: ##::::: ##:::
 ######:::: ##:: ##:::::::::: ##:::: ##:::: ##: ##:::::::'######:'######:
 ##...::::: ##:: ##:::::::::: ##:::: ##:::: ##: ##:::::::.. ##.::.. ##.::
 ##:::::::: ##:: ##::: ##:::: ##:::: ##:::: ##: ##::: ##::: ##::::: ##:::
 ##:::::::'####:. ######::::: ##::::. #######::. ######::::..::::::..::::
..::::::::....:::......::::::..::::::.......::::......:::::::::::::::::::
*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Ficto
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
    static int randomI32(int min, int max)
    {
        srand(time(0));
        const int _int = (rand() %
                        (min - max + 1)) +
                       min;
        return _int;
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

const int x = 0;
int array[10] = {1,7,13,19,25,31,37,43,49,55};
class Numbers{
public:
void getNumbers() { 
int i = 0;
for(i; i < 10; i++) 
Ficto::print(array[i]); 
} 
}; 
void Conditions() { 
bool greetUserAgain = true;
if(greetUserAgain) 
Ficto::println("Olá, novamente!"); 
} 
int main() { 
std::string name = "";
Ficto::print("Olá, insira seu nome: "); 
std::cin >> name; 
Ficto::println("Olá, " + name + "!"); 
Ficto::print("Números no array: "); 
Numbers num; 
num.getNumbers(); 
Conditions(); 
return 0; 
} 
