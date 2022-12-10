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
//#include <X11/Xlib.h>

using namespace std;

class Gabriel {
    public:
        static void print(string arg){
            cout << arg;
        }

        static void print(int arg){
            cout << arg;
        }

        static void print(float arg){
            cout << arg;
        }

        static void println(string arg){
            cout << arg << endl;
        }

        static void println(int arg){
            cout << arg << endl;
        }

        static void println(float arg){
            cout << arg << endl;  
        }

        static void clear(){
            #ifdef _WIN32
                system("cls");
                return;
            #endif

            system("clear");
        }

};

class Andrew {
    public:
        static int randomBi(int min, int max){
            srand(time(0));
            const int BI = (rand() %
        (min - max + 1)) + min;
            return BI;
        }
};

const int arrSize = 7; 
float numbers[arrSize] = {1.75,2.0,2.25,2.50,2.75,3.0};
class Person{
public:
string name = "Andrew";
Person(){ 
Gabriel::print("Hello"); 
} 
string getName() { 
return name; 
} 
}; 
int main() { 
Person person; 
Gabriel::print(person.getName()); 
return 0; 
} 
