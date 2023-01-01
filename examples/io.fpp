import std

fun main() -> bi32 {
    val : bi32 = Ficto::readBi32();
    name : str = Ficto::readStr();
    if(val) Ficto::print(val);
    if(name != "") Ficto::println("Seu nome é: " + name);
    ret 0;
}