import std

filename : str = "";
isRunning : boo = true;

fun runProject() -> ficto {
    system(("cd release && ./" + filename).c_str());
}

fun compileProject() -> ficto {
    system(("./ficto " + filename + ".fpp -cpp " + filename).c_str());
}

fun createNewProject() -> ficto {
    Ficto::print("Insira o nome do arquivo (sem a extensão): ");
    filename = Ficto::readStr();
    system(("touch " + filename + ".fpp && nano " + filename + ".fpp").c_str());
    Ficto::println("Projeto criado com sucesso!");
}

fun installDeps() -> ficto {
    system("sudo apt-get install gcc-mingw-w64 && sudo apt install build-essential");
    Ficto::println("Instalação OK...");
}

fun handleChoice( option : bi32 ) -> ficto {
    Ficto::clear();
    switch(option){
        case 1:
            installDeps();
            break;
        case 2:
            createNewProject();
            break;
        case 3:
            compileProject();
            break;
        case 4:
            runProject();
            break;
        case 5:
            system(("code " + filename + ".fpp").c_str());
            break;
        case 6:
            Ficto::print("Insira o nome do projeto (sem a extensão final): ");
            filename = Ficto::readStr();
            break;
        case 7:
            isRunning = false;
            break;
    }
}

fun main() -> bi32 {
    while(isRunning){
        Ficto::println("\n🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️🛠️⚙️🔧️🔨️");
        Ficto::println("BEM-VINDO AO FICTOZARD, ASSISTENTE DE CRIAÇÃO DE PROJETOS EM FICTOC++");
        Ficto::println("🎮️ OPÇÕES:");
        Ficto::println("🌐️ 1-Baixar dependências e configurar o FictoC++");
        Ficto::println("✨️ 2-Criar novo projeto");
        Ficto::println("🏗️ 3-Compilar projeto");
        Ficto::println("▶️  4-Executar projeto");
        Ficto::println("✏️  5-Editar no Visual Studio Code");
        Ficto::println("📁️ 6-Adicionar projeto existente");
        Ficto::println("🚪️ 7-Sair");
        Ficto::print("->");

        choice : bi32 = Ficto::readBi32();

        handleChoice(choice);
    }
    ret 0;
}