import std

stable MIN : bi32 = 3;
stable MAX : bi32 = 57;

fun main() -> bi32 {
    Ficto::print("Número aleatório pra você: ");
    Ficto::println(Andrew::randomI32(MIN, MAX));

    ret 0;
}