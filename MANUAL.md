# OBJGABRIEL CHEATSHEET

---

# 🖥️ ENTRADA E SAÍDA DE DADOS

```cpp
import gabriel

act main() -> bi32 {
	//Pra escrever na tela, dá pra usar tanto a função print 
	//ou println da classe Gabriel ou o cry, sintática e 
	//semanticamente equivalente ao cout do C++
	Gabriel::println("Hello world!");
	cry << "Insira seu nome: ";
	nome : label = "";
	get >> nome;
	cry << "Seu nome é " << nome;
}
```

---

# 🔖 COMENTÁRIOS

```cpp
//Essa linha é um comentário
#Essa linha também é um comentário
//Você pode comentar de qualquer um dos jeitos
```

---

# 🔣 VARIÁVEIS E TIPOS DE DADOS

| TIPO EM OBJGABRIEL | DESCRIÇÃO | EQUIVALENTE EM C++ |
| --- | --- | --- |
| gay32/bi32 | números inteiros positivos e negativos | int |
| gay64/bi64 | números com vírgula | float |
| ???? | números com vírgula (não sabemos explicar a diferença, mas esse seria o double em outras linguagens kksksk) | double |
| label | uma string, ué! | string |
| ???? | caractere | char |
| bi | verdadeiro ou falso | boolean |
| ficto | retorna vazio, tão vazio quanto a alma de quem acabou de ver o/a crush beijando outro/a | void |

```cpp
//Criar uma variável é simples...
//Informe seu nome, coloque dois pontos
//E por último informe seu tipo e valor
//E OS ESPAÇOS SÃO IMPORTANTES EM OBJGABRIEL!!!!
//NÃO SE ESQUEÇA DELES OU VAI DAR RUIM NA HORA DE COMPILAR!!!

nome_variavel : bi32 = 
exemplo1 : bi = false;
exemplo2 : label = "Gabriel Idiota" 
//Desculpa amigão, mas... é só um exemplo rsrs

//Não vamos dar mais exemplos, a partir daí você usuário se vira 
//e toca o barco jsks
```

**AINDA NÃO DEFINIMOS COMO VÃO SER AS CONSTANTES, MAS… EM BREVE FAREMOS ISSO, OU NÃO, DEPENDE DA NOSSA BOA VONTADE RSRSRS E POR ENQUANTO TODA E QUALQUER VARIÁVEL PRECISA JÁ SER INICIALIZADA COM UM VALOR. VAMOS CORRIGIR ISSO, TALVEZ, FUTURAMENTE.**

---

# 🔃 ESTRUTURAS CONDICIONAIS

Bom, essa parte não vamos explicar detalhadamente, pois muita coisa aqui é idêntica às outras linguagens de programação. A única coisa que muda é o **else if** que vira somente **elf**. De resto, tudo igual!

```cpp
if (produto.validade > 7) {
	Gabriel::println("O produto tá dentro da validade");
} elf (produto.validade < 7 && produto.validade > 0) {
	Gabriel::println("O produto tá na validade, mas tá quase vencendo");
} else {
	Gabriel::println("O produto tá vencido, jogue fora!");
}
```

As mesmas regras se aplicam aqui: se tiver só um comando, dá pra deixar de lado as chaves. **E NÃO SE ESQUEÇA DOS ESPAÇOS!!!** O ObjGabriel também suporta o incrível ternário:

```cpp
isLogado : bi = user ? true : false;

user.setLogado(isLogado);
```

Também tem o **switch** em ObjGabriel, mas nem vou explicar aqui porque ele é IDÊNTICO. Se você sabe fazer um **switch** em C++, consegue fazer nessa linguagem também!

---

# 📏 FUNÇÕES

As funções em ObjGabriel são precedidas da palavra `act`. Todo programa deve ter PELO MENOS a função `main`, e está deve retornar um número do tipo `bi32`. Vejamos um exemplo de um programa básico que pede ao usuário que digite um número:

```cpp
import gabriel

act main() -> bi32 {
	Gabriel::print("Hello world!");
	getout 0;
}
```

Você também pode criar sua própria função e ela pode ser chamada e retornar um valor. O tipo do retorno deve ser declarado com `->` seguido pelo tipo do dado que ela vai retornar. Exemplo:

```cpp
import gabriel

age : label = "69";

act getUserName() -> label {
  getout "Matheus";
}

act getAge() -> label {
  getout age;
}

act getStatus( age : label ) -> label {
  vivo : label = age > "60" ? "falecido" : "vivo";
  getout vivo;
}

act main() -> bi32 {
  Gabriel::println("Nome: " + getUserName());
  Gabriel::println("Idade: " + getAge());
  Gabriel::println("Situação: " + getStatus(getAge()));
}
```

Para retornar um valor, usa-se `getout` seguido pelo valor que ele retorna (lembrando que o tipo deve corresponder àquele declarado. Os argumentos da função podem ser passados entre parênteses: lembrando que os espaços são obrigatórios (ao menos por enquanto, pois ainda não descobri como removê-los e fazer a manipulação de strings em C++ do código fonte em ObjGabriel antes de transpilá-lo). Também não há vírgulas caso haja mais de um parâmetro (devido ao motivo citado acima ksksks).

---

# 💽 ARRAYS E VETORES

Aqui acho que também não precisa explicar como funciona, é igual em C++… a única diferença é a sintaxe pra declarar a bagaça, que o tamanho do vetor vem entre colchetes depois do nome dele, seguido pela tipagem. Pra acessar um elemento do vetor, o processo é o mesmo. Exemplo:

```cpp
import Gabriel

const int arrSize = 7;
numbers[arrSize] : bi64 = {1.75, 2.0, 2.25, 2.50, 2.75, 3.0};

act main() -> bi32 {
	i : bi32 = 0;

	for(i; i < arrSize - 1; i)
		Gabriel::println(numbers[i]);
}
```

---

# 🍌 PROGRAMAÇÃO ORIENTADA A OBJETOS

## 🍌🍑 CLASSES E OBJETOS

## 🏗️ CONSTRUTORES

## 🔑 MODIFICADORES DE ACESSO

## 👪 HERANÇA E POLIMORFISMO

---

# 🗃️ MANIPULAÇÃO DE ARQUIVOS

# 🐞 TRATAMENTO DE EXCEÇÕES

# 🧩 IMPORTS E MÓDULOS