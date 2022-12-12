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
#include <fstream>
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

class FileHandler   {
    std::string filename = "";

    public:
        FileHandler(std::string filename){ 
            this->filename = filename; 
        }

        void write( std::string content ) { 
            std::ofstream File(this->filename); 
            File << content; 
            File.close(); 
        } 

        std::string readLine() { 
            std::ifstream File(this->filename); 
            std::string content = "";
            getline(File, content); 
            File.close(); 
            return content; 
        } 
}; 

const int arrSize = 7; 
float numbers[arrSize] = {1.75,2.0,2.25,2.50,2.75,3.0};
class Person{
public:
std::string name = "Andrew";
Person(){ 
Gabriel::print("Hello"); 
} 
std::string getName() { 
return name; 
} 
}; 
int main() { 
Person person; 
Gabriel::print(person.getName()); 
return 0; 
} 
