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

    static void println()
    {
        cout << endl;
    }

    static void clear()
    {
#ifdef _WIN32
        system("cls");
        return;
#endif

        system("clear");
    }

    static int readBi32(){
        int val;
        cin >> val;
        return val;
    }

    static float readBi64(){
        float val;
        cin >> val;
        return val;
    }

    static double readDoub(){
        double val;
        cin >> val;
        return val;
    }

    static string readStr(){
        string val;
        cin >> val;
        return val;
    }

    static char readCh(){
        char val;
        cin >> val;
        return val;
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