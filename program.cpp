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

class FileHandler {
    std::string filename = "";
    public:
        FileHandler(std::string filename) {
            this -> filename = filename;
        }
    void write(std::string content) {
        std::ofstream File(this -> filename);
        File << content;
        File.close();
    }
    std::string readFirstLine() {
        std::ifstream File(this -> filename);
        std::string content = "";
        getline(File, content);
        File.close();
        return content;
    }
    std::string read() {
        std::ifstream file(this -> filename.c_str());
        std::string line = "", content;
        while (getline(file, line))
            content += line + "\n";
        file.close();
        return content;
    }
};

std::string filename = "";
std::string content = "";
void writeFile() { 
FileHandler file(filename); 
file.write(content); 
std::cout << endl; 
std::cout << "O arquivo foi criado com sucesso!"; 
} 
int main() { 
std::cout << "Insira o nome do arquivo: "; 
std::cin >> filename; 
std::cout << "Insira o conteúdo: "; 
std::cin >> content; 
writeFile(); 
return 0; 
} 
