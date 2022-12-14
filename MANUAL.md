# OBJGABRIEL CHEATSHEET

Documentação do LGBTScript escrita pelo Gabriel e pelo Andrew. Se tiver ficado uma bosta, a culpa é do Gabriel (minha), já que eu não manjo bem de português e o meu vocabulário é bem das ruas mesmo, mas tentei dar o meu melhor.

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

## 🍌🍑 CLASSES, OBJETOS E CONSTRUTORES

**AINDA FALTA ADICIONAR SUPORTE PARA ATRIBUTOS E PARA A PALAVRA-CHAVE THIS (QUE AINDA ESTAMOS DECIDINDO COMO VAMOS REPRESENTÁ-LA EM OBJGABRIEL).**

```cpp
//Declarando uma classe
closet Person {
	//Definindo os atributos
	name : label = "";
	age : bi32 = 0;

	//Criando um construtor
	//Os construtores têm o mesmo nome da classe
	Person(){
		Gabriel::print("Objeto Person criado");
	}

	//Definindo um método
	act introduceHimself() -> ficto {
		Gabriel::print("Olá, eu sou o " + this->name + "!");
	}
}

act main() -> bi32 {
	//Instanciando um objeto de uma classe
	Person Gabriel;
}
```

---

## 🔑 MODIFICADORES DE ACESSO

```cpp
closet Person {
	//Se você não especificar nenhum modificador de acesso,
	//os atributos e métodos serão considerados privados
	//por padrão!!

  //Tudo o que for closeted, é privado (acessível só na classe)
  --closeted
    name : label = "Vinicius";
    age : bi32 = 0;

  //Tudo o que for polyamorous, é público (acessível de fora da classe)
  --polyamorous
    //Criando um construtor
    //Os construtores têm o mesmo nome da classe
    Person(){
      Gabriel::println("Objeto Person criado");
    }

    //Definindo um método
    act introduceHimself() -> ficto {
      Gabriel::print("Olá, eu sou o " + this->name + "!");
    }
}
```

## 👪 HERANÇA

```cpp
import gabriel

closet Person {
  --closeted
    name : label = "Vinicius";
    age : bi32 = 0;

  --polyamorous
    Person(){
      Gabriel::println("Objeto Person criado");
    }

    act introduceHimself() -> ficto {
      Gabriel::println("Olá, eu sou o " + this->name + "!");
    }
};

//Classe que herda da classe Person
closet Person2 fucks Person {
  --polyamorous
    
    //Sobrescreve o método da classe pai
    act introduceHimself() -> ficto {
      Gabriel::println("Olá, eu sou o Emmanuel!");
    }
};

act main() -> bi32 {
	//Instanciando um objeto de uma classe
	Person Vinicius;
  Person2 Emmanuel;

  Vinicius.introduceHimself();
  Emmanuel.introduceHimself();
}
```

Outros conceitos de POO não serão explicados nem exemplificados aqui pois eles funcionam exatamente como em C++ e linguagens descendentes e relacionadas a ela.

---

# 🗃️ MANIPULAÇÃO DE ARQUIVOS

Eu e o Gabriel sabemos que manipular arquivos em C ou C++ é uma tarefa árdua: é necessário importar diversas bibliotecas, ler o conteúdo do arquivo linha a linha com laços de repetição, etc. Para auxiliar os programadores, ele inclui uma biblioteca nativa com uma classe FileHandler que contém os métodos mais comuns para manipular arquivos (escrever, ler, verificar se existe, etc…). 

Comece adicionando um `import file` no começo do arquivo (lembrando que, como ele tem como dependência a biblioteca padrão da linguagem, é necessário colocá-lo depois do `import gabriel`).

```cpp
import gabriel
import file

act main() -> bi32 {
  const std::string filename = "example";
  
	//Instanciando a classe FileHandler e passando
	//o nome do arquivo como construtor
  FileHandler file(filename);

  content : label = "";

  Gabriel::print("Write here what you want to save in the file: ");
  get >> content;

	//Escrevendo no arquivo
  file.write(content);

  Gabriel::print("Here's what you wrote in the file: ");

	//Lendo o conteúdo do arquivo
  Gabriel::print(file.read());

  getout 0;
}
```

---

# 🐞 TRATAMENTO DE EXCEÇÕES

Essa parte nem vale a pena explicar porque ela é igual em C++, as mesmas palavras-chave e a mesma sintaxe. Na verdade, eu e o Andrew estávamos com preguiça de explicar também, porque escrever documentação é meio paia, ainda mais que eu não manjo muito bem de português, então ferrou.