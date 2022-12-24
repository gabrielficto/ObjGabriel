# FictoC++

<img src="assets/fictoc++.png">

O FictoC++ é fork do ObjGabriel, um projeto de linguagem de programação para ser sucessora do C++ criado pelo @Redwars22 e pelo @gabrielficto. Ele possui uma sintaxe mais moderna, seguindo as tendências de linguagens como Rust, Kotlin e TypeScript e ao mesmo tempo sendo familiar ao bom e velho C/C++. O código em FictoC++ é transpilado para C++ e em seguida compilado com o g++ para gerar executáveis Linux ou .exe que podem ser executados no Windows. Ele é interoperável com o C++, então você pode usar todas as suas bibliotecas e inclusive usar código C++ intercambiavelmente ao longo do código em FictoC++. Basicamente, qualquer c

<img src="assets/fictocpp_example.png">

### SOBRE O PROJETO

- Descrição curta: Uma linguagem orientada a objetos interoperável com C++, derivada do ObjGabriel
- Categoria: Linguagens (inúteis) de programação
- Site oficial: [FictoC++](https://redwars22.github.io/andrewnation/fictocpp/)
- Status do projeto: Em beta

### DESENVOLVIMENTO

- Linguagem de programação: C++ e ObjGabriel
- Repositório: [https://github.com/Redwars22/fictocpp](https://github.com/Redwars22/fictocpp)

### LANÇAMENTOS

- Download (versão beta): [https://github.com/Redwars22/fictocpp/tags](https://github.com/Redwars22/fictocpp/tags)

# Como usar

No Linux, as instruções são as seguintes:

> ```bash
> ./ficto nome_do_arquivo.fpp
> ```

No Windows, só executar o `ficto.exe` pelo CMD e passar como argumento o arquivo ou o caminho até o arquivo `.fpp`. Também é necessário ter o compilador G++ instalado.

Só criar um arquivo com a extensão .fpp, ir até a pasta onde tá o executável do FictoC++, e digitar ./ficto no terminal seguido pelo caminho até o arquivo .fpp que você criou. Se tudo estiver ok, ele vai compilar para C++ usando o g++ e daí vai executar automaticamente o seu programa e gerar um executável dele.

Exemplo de programa Hello World:

> ```c++
> import std
>
> fun main() -> bi32 {
>    Ficto::print("Hello world!");
>    ret 0;
> }
> ```

# Diferenças entre FictoC++ e C++

Eu e o Gabriel até faríamos uma documentação explicando sobre o FictoC++, mas como ele é muito semelhante ao C++ e supondo que você já o domine, decidimos explanar aqui somente as diferenças entre os dois.

1-A declaração de variáveis coloca o tipo depois do nome delas, separado por dois pontos. Exemplo:

```cpp
numero1 : bi32 = 16;
nome : str = "Hello, world!"
numero2 : bi64 = 16.7;
numero3 : doub = 9.9187171516781;
caractere : ch = 'a';
```

Tabela de equivalência de tipos:

| FictoC++ | C++ |
| --- | --- |
| bi32/i32 | int |
| bi64/i64 | float |
| str | string |
| doub | double |
| boo | boolean |
| ch | char |
| ficto | void |

---

2-As constantes são declaradas de forma parecida, porém com a palavra-chave *stable*:

```cpp
stable ARR_SIZE : bi32 = 12;
array[ARR_SIZE] : bi32 = {};
```

---

3-As funções são identificadas pela palavra-chave *fun* e o tipo de retorno é colocado após os parênteses. Essa sintaxe é semelhante à do Carbon, Swift e TypeScript.

```cpp
fun main() -> bi32 {
	ret 0;
}
```

---

4-O retorno das funções que não são do tipo *ficto* (equivalente a *void*) é feito com a palavra-chave *ret*, versão abreviada de return.

```cpp
fun sumTwoNumbers() -> bi64 {
	ret 2.3 + 2.1;
}
```

---

5-Os argumentos das funções em FictoC++ são passados entre parênteses. Eles devem ser tipados e separados por espaços (ainda não descobrimos como separar os tokens que estão entre vírgulas durante a tokenização, então por enquanto serão separados por espaços).

```cpp
fun subtractTwoNumbers(x : bi32 y : bi32) -> bi32 {
	ret x + y;
}
```

---

6-As estruturas de controle de lógica e repetição são iguais às do C++, mas no caso do ****for**** a variável deve ser declarada fora do bloco.

---

7-É recomendável começar qualquer programa em FictoC++ com `import std`, que lhe dá acesso às funções da classe Ficto e importa automaticamente algumas bibliotecas C++ que são usadas frequentemente, como iostream, namespace std, etc. Falando no *******import,******* você pode importar arquivos, headers e bibliotecas do C++ com ele. Ele equivale ao `#include`. No FictoC++ optamos pelo `import`porque é a palavra-chave mais usual nas linguagens de programação modernas.

---

8-A parte de orientação a objetos funciona de forma quase idêntica, exceto por uma coisa: os atributos públicos e privados, respectivamente, usam as palavras-chave `--publ` e `--priv`, e ficam agrupados dentro deles. 

```cpp
class Human {
	--priv
		dna : ch = "🧬";

	--publ
		fun getDNA() -> ch {
			return this->dna;
		}
}
```
