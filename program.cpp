#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <X11/Xlib.h>

using namespace std;

class Gabriel {
    public:
        static void print(string arg){
            cout << arg;
        }
};

class Andrew {
    public:
        static int randomBi(int min, int max){
            srand(time(0));
            const int BI = (rand() % (min - max + 1)) + min;
            return BI;
        }

        static int initializeRainbow(int width, int height){ 
            Display *d; int s; Window w; XEvent ev;
            int should_quit = 0;

            d = XOpenDisplay(NULL);
            s = XDefaultScreen(d);

            w = XCreateSimpleWindow(d, XRootWindow(d, s), 0, 0,
                                    width, height, 0,
                                    XBlackPixel(d, s),
                                    XWhitePixel(d, s));

            XSelectInput(d, w, ButtonPressMask);
            XMapWindow(d, w);

            while(!should_quit)
            {
            XNextEvent(d, &ev);
            switch(ev.type)
                {
                case ButtonPress:
                should_quit = 1;
                break;
                default:
            break;
                }
            }

            return 0;
        }
};

int main() { 
int num = 0;
std::cin >> num; 
if(num < 5) 
Gabriel::print("O número que você digitou é menor que 5"); 
else if (num > 5 && num < 16) 
Gabriel::print("O número informado é maior que 5 e menor que 16"); 
else 
Gabriel::print("O número que vocẽ digitou é maior que 5"); 
std::cout << "Número aleatório: " << Andrew::randomBi(1, 1000); 
Andrew::initializeRainbow(480, 800); 
} 
