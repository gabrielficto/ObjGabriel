import std
import fictostring

stable x : bi32 = 0;

array[10] : bi32 = {1, 7, 13, 19, 25, 31, 37, 43, 49, 55};

class Numbers {
  --publ
    fun getNumbers() -> ficto {
      i : bi32 = 0;

      for(i; i < 10; i++)
        Ficto::print(array[i]);
    }
};

fun Conditions() -> ficto {
  greetUserAgain : boo = true;

  if(greetUserAgain)
    Ficto::println("Olá, novamente!");

  if(FictoStr.equals("abc", "abc"))
    Ficto::println("As strings são iguais!");
}

fun main() -> bi32 {
  name : str = "";

  Ficto::print("Olá, insira seu nome: ");
  read >> name;
  Ficto::println("Olá, " + name + "!");
  Ficto::println("Números no array: ");
  Ficto::println("Teu nome tem ");
  Ficto::print(FictoStr.getLength(name));
  Ficto::println(" caracteres");
  Numbers num;
  num.getNumbers();
  Conditions();
  ret 0;
}