import std

stable REM_DEFAULT_SIZE : bi64 = 16;

fun main() -> bi32 {
    Ficto::clear();
    rem : bi32 = 0;
    total : bi64 = 0.0;

    Ficto::print("Insira o valor em PX: ");
    read >> rem;
    total = rem/REM_DEFAULT_SIZE;
    Ficto::print("Valor em REM: ");
    Ficto::print(total);
    Ficto::print("rem");
    ret 0;
}