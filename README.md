# ObjGabriel

<img src="OBJGABRIEL.png">
Linguagem de programação sem sentido nem finalidade baseada em C criada por mim e pelo @Redwars22


[📚️ LER MANUAL DA LINGUAGEM]("https://leoandrew.notion.site/OBJGABRIEL-CHEATSHEET-7e55b3eecce343f6abdb92d955c18478")

# Como usar

No Linux, as instruções são as seguintes:

> ```bash
> ./gabriel nome_do_arquivo.gabriel   
> ```

No Windows, só executar o `gabriel.exe` pelo CMD e passar como argumento o arquivo ou o caminho até o arquivo .gabriel. Também é necessário ter o compilador G++ instalado.

Só criar um arquivo com a extensão .gabriel, ir até a pasta onde tá o executável do ObjGabriel, e digitar ./gabriel no terminal seguido pelo caminho até o arquivo .gabriel que você criou. Se tudo estiver ok, ele vai compilar para C++ usando o g++ e daí vai executar automaticamente o seu programa e gerar um executável dele.

Exemplo de programa Hello World:

> ```c++
> import gabriel
>
> act main() -> bi32 {
>    Gabriel::print("Hello world!");
>    getout 0;
>}
> ```