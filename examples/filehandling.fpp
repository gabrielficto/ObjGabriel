import std
import file

filename : str = "";
content : str = "";

fun writeFile() -> ficto {
    FileHandler file(filename);
    file.write(content);
    write << endl;
    write << "O arquivo foi criado com sucesso!";
}

fun main() -> bi32 {
    write << "Insira o nome do arquivo: ";
    read >> filename;
    write << "Insira o conteúdo: ";
    read >> content;
    writeFile();
    ret 0;
}