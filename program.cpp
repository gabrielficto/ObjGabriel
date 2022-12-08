#include <string>
#include <iostream>
using namespace std;

class Gabriel {
    public:
        static void print(string arg){
            cout << arg;
        }
};

void sumTwoNumbers( int num1, int num2 ) { 
std::cout << num1 + num2; 
} 
void greetUser() { 
std::cout << "Hello world!"; 
sumTwoNumbers(16, 16); 
} 
int main() { 
int num = 2;
int num2 = 2;
greetUser(); 
std::cout << "O resultado é: " << num + num2; 
Gabriel::print("Hello"); 
return 0; 
} 
