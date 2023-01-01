import std

class Example {
    --priv
        message : str = "";

    --publ
        Example(){
            Ficto::println("Objeto instanciado!!!");
        }

        fun setMessage( msg : str ) -> ficto {
            this->message = msg;
        }

        fun getMessage() -> str {
            ret this->message;
        }

        fun write() -> ficto {
            Ficto::print(getMessage());
        }
};

fun main() -> bi32 {
    Example example;
    example.setMessage("Essa é uma mensagem de exemplo!");
    example.write();
    ret 0;
}