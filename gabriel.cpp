#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string source[1000];
string output[1000];
string input;
int file_len = 0;

struct
{
    const regex LINE_COMMENT = regex("\/\/(.*)");
    const regex FUNCTION_STATEMENT =
        regex("act .*\\(\\) -> .* {", std::regex_constants::basic);
    const regex RETURN_STATEMENT = regex("getout .*");
    const regex INCLUDE_STATEMENT = regex("import .*");
    const regex PRINT_STATEMENT = regex("cry << .*;");
    const regex SCANF_STATEMENT = regex("get >> .*;");
} GabrielRules;

struct
{
    const string FUNCTION = "act";
    const string PRINT = "std::cout";
    const string SCANF = "std::cin";
    const string INCLUDE = "#include";
} GabrielKeywords;

typedef struct GabrielFunction
{
    string return_type;
} Function;

class GabrielLang
{
public:
    smatch match;

    bool checkIfIsComment(string statement)
    {
        return regex_search(statement, match, GabrielRules.LINE_COMMENT);
    }

    bool ReturnStatement(string statement)
    {
        return regex_search(statement, match, GabrielRules.RETURN_STATEMENT);
    }

    bool checkIfIsFunctionDeclaration(string statement)
    {
        return regex_search(statement, match, GabrielRules.FUNCTION_STATEMENT);
    }

    bool isIncludeStatement(string statement)
    {
        return regex_search(statement, match, GabrielRules.INCLUDE_STATEMENT);
    }

    bool isPrintf(string statement)
    {
        return regex_search(statement, match, GabrielRules.PRINT_STATEMENT);
    }

    bool isScanf(string statement)
    {
        return regex_search(statement, match, GabrielRules.SCANF_STATEMENT);
    }

    void exec()
    {
        #ifdef _WIN32
            system("g++ -g output.cpp -o program.exe");
            system("./program.exe");
        #endif

        system("g++ -g program.cpp -o program");
        system("./program");
    }
};

void parse();
string tokenizer(string);
string parseLine(string);
void compileToCpp();

void readFromFile(string filename)
{
    fstream file;
    file.open(filename, ios::in);

    if (file)
    {
        int line = 0;

        while (!file.eof() && getline(file, source[line]))
        {
            line++;
            file_len++;
        }
    }

    parse();
    compileToCpp();
}

void parse()
{
    cout << "⚙️ Compilando ObjGabriel pra C++..." << endl;

    int line = 0;

    while (line < file_len)
    {
        output[line] = parseLine(source[line]);
        line++;
    }

    //for (int i = 0; i < file_len; i++)
        //cout << output[i] << endl;
}

int main(int argc, char *argv[])
{
    input = argv[1];
    readFromFile(input);
    return 0;
}

string parseLine(string statement)
{
    GabrielLang gabriel;

    if (gabriel.checkIfIsComment(statement))
        return "";

    return tokenizer(statement);
}

string tokenizer(string statement)
{
    string tokens[50];
    string output_statement;
    string function_statement;
    bool isFunction = false;
    Function func;

    GabrielLang gabriel;

    stringstream ssin(statement);

    int i = 0;

    while (ssin.good() && i < 50)
    {
        ssin >> tokens[i];
        ++i;
    }

    if (gabriel.isPrintf(statement))
    {
        tokens[0] = GabrielKeywords.PRINT;
    }

    if (gabriel.isScanf(statement))
    {
        tokens[0] = GabrielKeywords.SCANF;
    }

    if (gabriel.checkIfIsFunctionDeclaration(statement))
    {
        isFunction = true;

        for (int token = 0; token < 50; token++)
        {

            if (tokens[token] == GabrielKeywords.FUNCTION)
                tokens[token] = "";

            if (tokens[token] == "->")
            {
                if (tokens[token + 1] == "bi32")
                {
                    func.return_type = "int";
                    tokens[token] = "";
                    tokens[token + 1] = "";
                    break;
                }
                throw "⚠️ Return type is missing, but required in ObjGabriel...";
            }
        }
    }

    if (gabriel.isIncludeStatement(statement))
    {
        if (tokens[0] != "")
        {
            tokens[0] = GabrielKeywords.INCLUDE;
            tokens[1] = " <" + tokens[1] + ">";
        }
        else
        {
            throw "Hm, it looks like you've missed the argument of the import statement";
        }
    }

    for (i = 0; i < 50; i++)
    {
        if (gabriel.ReturnStatement(statement))
            if (tokens[i] == "getout")
            {
                tokens[i] = "return";
            }

        if (tokens[i] != "")
        {
            output_statement += tokens[i] + " ";
        }
    }

    if (isFunction)
        output_statement = func.return_type + " " + output_statement;

    return output_statement;
}

void compileToCpp()
{
    GabrielLang gabriel;

    fstream file;
    file.open("output.cpp", ios::out);

    for (int i = 0; i < 1000; i++)
    {
        if (output[i] != "")
        {
            file << output[i] << endl;
        }
    }

    file.close();
    gabriel.exec();
}
