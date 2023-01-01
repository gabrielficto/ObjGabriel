//Baseado no vídeo abaixo:
//https://www.youtube.com/watch?v=wccZgjs90S8
//Código escrito pelo @gabrielficto

import std

fun showMenu() -> ficto {
    Ficto::println("************** MENU **************");
    Ficto::println("1-Saldo");
    Ficto::println("2-Depósito");
    Ficto::println("3-Empréstimo");
    Ficto::println("4-Sair");
    Ficto::println("**********************************");
}

fun main() -> bi32 {
    option : bi32 = 0;
    balance : doub = 500;
    isRunning : boo = true;
    withdrawAmount : doub = 0;
    depositAmount : doub = 0;

    while(isRunning)
    {
        showMenu();
        Ficto::print("Escolha uma opção: ");
        option = Ficto::readBi32();

        switch(option){
            case 1:
                Ficto::println("O saldo é: R$" + to_string(balance));
                break;
            case 2:
                Ficto::println("Quantia do depósito: ");
                depositAmount = Ficto::readBi64();
                balance += depositAmount;
                break;
            case 3:
                Ficto::println("Quantia do empréstimo: ");
                withdrawAmount = Ficto::readBi64();
                if(withdrawAmount <= balance)
                    balance -= withdrawAmount;
                else Ficto::println("Você não pode emprestar a quantia informada!!");
                break;
            case 4:
                isRunning = false;
                break;
            default:
                Ficto::println("Opção inválida");
                break;
        }
    }

    ret 0;
}