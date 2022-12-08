#include <iostream>
#include <string>

using namespace std;

class Gabriel {
    public:
        static void print(string arg){
            cout << arg;
        }
};

int main() { 
Gabriel::print("Hello zworld!"); 
return 0; 
} 
