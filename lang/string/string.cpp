#include <string>

using namespace std;

class FictoString {
    public:
    int getLength( std::string _str ) { 
        return _str.length(); 
    } 

    bool isEmpty( std::string _str ) { 
        return _str.empty(); 
    } 

    bool equals( std::string _str1, std::string _str2 ) { 
        return (_str1 == _str2); 
    } 
};

FictoString FictoStr; 