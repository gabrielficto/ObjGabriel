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

#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

string source[32000];
string output[32000];
string input;
string out_filename;
int file_len = 0;

struct
{
    const regex LINE_COMMENT = regex("\/\/(.*)");
    const regex FICTO_FILE = regex(".*[A-Za-z_0-9]\\.fpp", std::regex_constants::basic);
    const regex LINE_COMMENT_ALT_RULE = regex("#(.*)");
    const regex FUNCTION_STATEMENT =
        regex("fun .*\\(\\) -> .* {", std::regex_constants::basic);
    const regex FUNCTION_WITH_PARAMS_STATEMENT =
        regex(".*\\(.{1,}\\) {", std::regex_constants::basic);
    const regex RETURN_STATEMENT = regex("ret .*");
    const regex INCLUDE_STATEMENT = regex("import .*");
    const regex PRINT_STATEMENT = regex("write << .*;");
    const regex SCANF_STATEMENT = regex("read >> .*;");
    const regex CLASS_DECLARATION = regex("class .* (\\{)");
    const regex VAR_DECL_STATEMENT = regex(".* \\: .* \\= .*", std::regex_constants::basic);
    const regex CONST_DECL_STATEMENT = regex("stable .* \\: .* \\= .*", std::regex_constants::basic);
} FictoRules;

struct
{
    const string FUNCTION = "fun";
    const string PRINT = "std::cout";
    const string SCANF = "std::cin";
    const string INCLUDE = "#include";
    const string IMPORT = "import";
    const string FICTOGEM = "fictogem";
    const string CPP_CLASS = "class";
    const string CLASS = "class";
    const string INHERITS = "childof";
    const string CPP_INHERITS = ": public ";
    const string PUBLIC_ATTR = "--publ";
    const string CPP_PUBLIC_ATTR = "public:";
    const string PRIVATE_ATTR = "--priv";
    const string CPP_PRIVATE_ATTR = "private:";
    const string STRUCT = "data";
    const string CPP_STRUCT = "struct";
    const string THIS_KEYWORD = "bitch";
    const string CPP_THIS_KEYWORD = "this";
    const string CONST = "stable";
    const string CPP_CONST = "const";
} FictoKeywords;

typedef struct FictoFunctions
{
    string return_type;
} Function;

typedef struct FictoVariable
{
    string identifier;
    string type;
    string value;
} Variable;

typedef struct FictoFunctionWithParams
{
    string identifier;
    string type;
} FunctionWithArgs;

map<string, string> FictoTypes;

void initializeFictoTypes()
{
    FictoTypes.insert(pair<string, string>("i32", "int"));
    FictoTypes.insert(pair<string, string>("bi32", "int"));
    FictoTypes.insert(pair<string, string>("i64", "float"));
    FictoTypes.insert(pair<string, string>("bi64", "float"));
    FictoTypes.insert(pair<string, string>("boo", "bool"));
    FictoTypes.insert(pair<string, string>("str", "std::string"));
    FictoTypes.insert(pair<string, string>("ficto", "void"));
    FictoTypes.insert(pair<string, string>("ch", "char"));
    FictoTypes.insert(pair<string, string>("doub", "double"));
}

string translateTypesToC(string _type)
{
    for (auto _ : FictoTypes)
    {
        if (_.first == _type)
            return _.second;
    }

    return "unknown";
}

class FictoLang
{
public:
    smatch match;

    bool checkIfIsComment(string statement)
    {
        if (regex_search(statement, match, FictoRules.LINE_COMMENT))
            return true;

        if (regex_search(statement, match, FictoRules.LINE_COMMENT_ALT_RULE))
            return true;

        return false;
    }

    bool ReturnStatement(string statement)
    {
        return regex_search(statement, match, FictoRules.RETURN_STATEMENT);
    }

    bool checkIfIsFunctionDeclaration(string statement)
    {
        return regex_search(statement, match, FictoRules.FUNCTION_STATEMENT);
    }

    bool checkIfIsFunctionWithParams(string statement)
    {
        return regex_search(statement, match, FictoRules.FUNCTION_WITH_PARAMS_STATEMENT);
    }

    bool isIncludeStatement(string statement)
    {
        return regex_search(statement, match, FictoRules.INCLUDE_STATEMENT);
    }

    bool isPrintf(string statement)
    {
        return regex_search(statement, match, FictoRules.PRINT_STATEMENT);
    }

    bool isScanf(string statement)
    {
        return regex_search(statement, match, FictoRules.SCANF_STATEMENT);
    }

    bool isVariableDecl(string statement)
    {
        return regex_search(statement, match, FictoRules.VAR_DECL_STATEMENT);
    }

    bool isConstDecl(string statement){
        return regex_search(statement, match, FictoRules.CONST_DECL_STATEMENT);
    }

    bool isClassDeclaration(string statement)
    {
        return regex_search(statement, match, FictoRules.CLASS_DECLARATION);
    }

    void exec()
    {

#ifdef _WIN32
        system(("g++ -g program.cpp -o release/" + out_filename + ".exe").c_str());
        system("program.exe");
        return;
#endif

        system(("g++ -g program.cpp -o release/" + out_filename + " && rm program.cpp").c_str());
    }
};

string importFictoGem()
{
    return "#include <string>\n#include <iostream>\nusing namespace std;\n";
}

string importLibrary(string filename)
{
    fstream file;
    file.open("./lang/" + filename + ".cpp", ios::in);

    string lib_code[500];
    int len = 0;

    if (file)
    {
        int line = 0;

        while (!file.eof() && getline(file, lib_code[line]))
        {
            line++;
            len++;
        }
    }
    else
    {
        cout << "FictoC++ was unable to find the specified library!";
    }

    string joined;

    for (int i = 0; i < len; i++)
    {
        joined += lib_code[i] + "\n";
    }

    return joined;
}

string importfictoSTDLibrary()
{
    fstream file;
    file.open("./lang/std/fictostd.cpp", ios::in);

    string lib_code[500];
    int len = 0;

    if (file)
    {
        int line = 0;

        while (!file.eof() && getline(file, lib_code[line]))
        {
            line++;
            len++;
        }
    }
    else
    {
        cout << "FictoC++ was unable to find the specified library!";
    }

    string joined;

    for (int i = 0; i < len; i++)
    {
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
    cout << endl << "🛠️ Compiling FictoC++ to C++..." << endl;

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
    smatch match;

    initializeFictoTypes();

    if(argv[1])
    {
        if(argv[2]){
            cout << argv[2];
            if(argv[3])
                input = argv[1];
                out_filename = argv[3];
                if (regex_search(input, match, FictoRules.FICTO_FILE))
                {
                    readFromFile(input);
                }
        }
        else {
            cout << "🛑️ FATAL: NO INPUT FILE PROVIDED TO COMPILE OR IT DOESN'T END WITH THE .fpp EXTENSION!!!" << endl;
            cout << "Also consider if you have forgotten to provide the output filename!";
        }
    }
    return 0;
}

string parseLine(string statement)
{
    FictoLang ficto;

    if (ficto.checkIfIsComment(statement))
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

    FictoLang ficto;

    stringstream ssin(statement);

    if (statement == "import fictogem")
    {
        return importFictoGem();
    }

    if (statement == "import std")
    {
        return importfictoSTDLibrary();
    }

    if (statement == "import file")
    {
        return importLibrary("file/file");
    }

    string statement_with_trim = statement;

    statement_with_trim.erase(std::remove_if(statement_with_trim.begin(), statement_with_trim.end(), ::isspace),
                              statement_with_trim.end());

    if (statement_with_trim == FictoKeywords.PUBLIC_ATTR)
    {
        return FictoKeywords.CPP_PUBLIC_ATTR;
    }

    if (statement_with_trim == FictoKeywords.PRIVATE_ATTR)
    {
        return FictoKeywords.CPP_PRIVATE_ATTR;
    }

    int i = 0;

    while (ssin.good() && i < 50)
    {
        ssin >> tokens[i];
        ++i;
    }

    if (tokens[0] == FictoKeywords.STRUCT)
    {
        tokens[0] = FictoKeywords.CPP_STRUCT;
    }

    if (ficto.isPrintf(statement))
    {
        tokens[0] = FictoKeywords.PRINT;
    }

    if (ficto.isScanf(statement))
    {
        tokens[0] = FictoKeywords.SCANF;
    }

    if (ficto.isConstDecl(statement))
    {

        var.identifier = tokens[1];
        var.type = tokens[3];

        for (int token = 5; token < 50; token++)
        {
            var.value += tokens[token];
        }

        return FictoKeywords.CPP_CONST + " " +  translateTypesToC(var.type) + " " + var.identifier + " = " + var.value;
    }

    if (ficto.isVariableDecl(statement))
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

        for (int token = 4; token < 50; token++)
        {
            var.value += tokens[token];
        }

        return translateTypesToC(var.type) + " " + var.identifier + " = " + var.value;
    }

    if (ficto.checkIfIsFunctionDeclaration(statement))
    {
        isFunction = true;

        for (int token = 0; token < 50; token++)
        {
            if (tokens[token] == FictoKeywords.FUNCTION)
                tokens[token] = "";

            if (tokens[token] != "" && tokens[token + 1] == ":" && tokens[token] != "")
            {
                funarg.identifier = tokens[token];
                funarg.type = tokens[token + 2];
                tokens[token + 1] = "";
                tokens[token] = translateTypesToC(funarg.type);
                tokens[token + 2] = tokens[token + 3] != ")" ? funarg.identifier + "," : funarg.identifier;
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

    if (ficto.isClassDeclaration(statement))
    {
        bool inheritsFromAnotherClass;

        for (int token = 0; token < 50; token++)
        {
            if (tokens[token] == FictoKeywords.INHERITS)
            {
                tokens[token] = FictoKeywords.CPP_INHERITS;
                inheritsFromAnotherClass = true;
                break;
            }
        }

        if (tokens[0] == FictoKeywords.CLASS)
            tokens[0] = FictoKeywords.CPP_CLASS;

        if (!inheritsFromAnotherClass)
            return tokens[0] + " " + tokens[1] + (tokens[2] != "" ? tokens[2] : "");
        else
            return tokens[0] + " " + tokens[1] + tokens[2] + tokens[3] + (tokens[4] == "{" ? tokens[4] : "");
    }

    if (ficto.isIncludeStatement(statement))
    {
        if (tokens[0] != "")
        {
            tokens[0] = FictoKeywords.INCLUDE;
            tokens[1] = " <" + tokens[1] + ">";
        }
        else
        {
            throw "⚠️ Hm, it looks like you've missed the argument of the import statement";
        }
    }

    for (i = 0; i < 50; i++)
    {
        if (ficto.ReturnStatement(statement))
            if (tokens[i] == "ret")
            {
                tokens[i] = "return";
            }
            else if (tokens[i] == "ret;")
                tokens[i] = "return;";

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
    FictoLang ficto;

    fstream file;
    file.open("program.cpp", ios::out);

    for (int i = 0; i < file_len; i++)
    {
        //cout << output[i] << endl;
        if (output[i] != "")
        {
            file << output[i] << endl;
        }
    }

    file.close();
    ficto.exec();
}
