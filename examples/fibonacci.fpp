import std

n1 : bi32 = 0, n2 = 1, n3 = 0, i = 0, number = 0;

fun fibonacci() -> ficto {
    for(i = 2; i < number; ++i){
        n3 = n1 + n2;
        write << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
}

fun main() -> bi32 {
    write << "Insira o número de elementos: ";
    read >> number;

    write << n1 << " " << n2 << " ";

    fibonacci();

    ret 0;
}