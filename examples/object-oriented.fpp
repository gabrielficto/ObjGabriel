import std

class Example {
    --publ
        Example() {
            Ficto::print("Hello!!!!");
        }
};

fun main() -> bi32 {
    Example example;
    ret 0;
}