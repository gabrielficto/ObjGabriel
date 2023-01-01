#include <string>

using namespace std;

class FictoString
{
public:
    int getLength(std::string _str)
    {
        return _str.length();
    }
    bool isEmpty(std::string _str)
    {
        return _str.empty();
    }
    bool equals(std::string _str1, std::string _str2)
    {
        return (_str1 == _str2);
    }
    int find(std::string text, std::string query)
    {
        return text.find(query);
    }
    std::string replace(std::string orig, std::string repl, std::string replWith)
    {
        return orig.replace(orig.find(repl), repl.length(), replWith);
    }
};
FictoString FictoStr;