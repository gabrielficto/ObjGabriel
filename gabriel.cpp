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

#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

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
    const regex FUNCTION_WITH_PARAMS_STATEMENT =
        regex(".*\\(.{1,}\\) {", std::regex_constants::basic);
    const regex RETURN_STATEMENT = regex("getout .*");
    const regex INCLUDE_STATEMENT = regex("import .*");
    const regex PRINT_STATEMENT = regex("cry << .*;");
    const regex SCANF_STATEMENT = regex("get >> .*;");
    const regex VAR_DECL_STATEMENT = regex(".* \\: .* \\= .*", std::regex_constants::basic);
} GabrielRules;

struct
{
    const string FUNCTION = "act";
    const string PRINT = "std::cout";
    const string SCANF = "std::cin";
    const string INCLUDE = "#include";
    const string IMPORT = "import";
    const string FICTOGEM = "fictogem";
} GabrielKeywords;

typedef struct GabrielFunctions
{
    string return_type;
} Function;

typedef struct GabrielVariable
{
    string identifier;
    string type;
    string value;
} Variable;

typedef struct GabrielFunctionWithParams {
    string identifier;
    string type;
} FunctionWithArgs;

map<string, string> GabrielTypes;

void initializeGabrielTypes()
{
    GabrielTypes.insert(pair<string, string>("bi32", "int"));
    GabrielTypes.insert(pair<string, string>("bi64", "float"));
    GabrielTypes.insert(pair<string, string>("bi", "boolean"));
    GabrielTypes.insert(pair<string, string>("label", "string"));
    GabrielTypes.insert(pair<string, string>("ficto", "void"));
}

string translateTypesToC(string _type)
{
    for (auto _ : GabrielTypes)
    {
        if (_.first == _type)
            return _.second;
    }

    return "unknown";
}

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

    bool checkIfIsFunctionWithParams(string statement){
        return regex_search(statement, match, GabrielRules.FUNCTION_WITH_PARAMS_STATEMENT);
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

    bool isVariableDecl(string statement)
    {
        return regex_search(statement, match, GabrielRules.VAR_DECL_STATEMENT);
    }

    void exec()
    {
        #ifdef _WIN32
                system("g++ -g output.cpp -o program.exe");
                system("./program.exe");
        #endif

        system("g++ -g program.cpp $(pkg-config --cflags --libs x11) -o program");
        system("./program");
    }
};

string importFictoGem(){
    return "#include <string>\n#include <iostream>\nusing namespace std;\n";
}

string importGabrielSTDLibrary(){
    fstream file;
    file.open("./lang/gabrielstd.cpp", ios::in);

    string lib_code[100];
    int len = 0;

    if (file)
    {
        int line = 0;

        while (!file.eof() && getline(file, lib_code[line]))
        {
            line++;
            len++;
        }
    } else {
        cout << "ObjGabriel was unable to find the specified library!";
    }

    string joined;

    for(int i = 0; i < len; i++){
        joined += lib_code[i] + "\n";
    }

    return joined;
}

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
    cout << "🛠️ Compilando ObjGabriel pra C++..." << endl;

    int line = 0;

    while (line < file_len)
    {
        output[line] = parseLine(source[line]);
        line++;
    }

    // for (int i = 0; i < file_len; i++)
    // cout << output[i] << endl;
}

int main(int argc, char *argv[])
{
    initializeGabrielTypes();

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
    Variable var;
    FunctionWithArgs funarg;
    string joined;

    GabrielLang gabriel;

    stringstream ssin(statement);

    if(statement == "import fictogem"){
        return importFictoGem();
    }

    if(statement == "import gabriel"){
        return importGabrielSTDLibrary();
    }

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

    if (gabriel.isVariableDecl(statement))
    {
        var.identifier = tokens[0];
        var.type = tokens[2];

        /*
            Tokens:
            identifier - 0
            : - 1
            type - 2
            assign (=) - 3
            value - 4+
        */

        for(int token = 4; token < 50; token++){
            var.value += tokens[token];
        }

        return translateTypesToC(var.type) + " " + var.identifier + " = " + var.value;
    }

    if (gabriel.checkIfIsFunctionDeclaration(statement))
    {
        isFunction = true;

        for (int token = 0; token < 50; token++)
        {
            if (tokens[token] == GabrielKeywords.FUNCTION)
                tokens[token] = "";

            if(tokens[token] != "" && tokens[token + 1] == ":" && tokens[token] != ""){
                funarg.identifier = tokens[token];
                funarg.type = tokens[token + 2];
                tokens[token + 1] = ""; 
                tokens[token] = translateTypesToC(funarg.type);
                tokens[token + 2] = tokens[token + 3] != ")" ? funarg.identifier + ",": funarg.identifier;
                continue;
            }

            if (tokens[token] == "->")
            {
                func.return_type = translateTypesToC(tokens[token + 1]);
                tokens[token] = "";
                tokens[token + 1] = "";
                break;
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

        if (tokens[i] == "elf")
            tokens[i] = "else if";

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
    file.open("program.cpp", ios::out);

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
