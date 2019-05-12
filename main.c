#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#define Max 64

int main() {
    int exit=0;
    char choice = 'i';
    do{
        User user;
        printf("\nEscolha uma opcao:\n0-Sair\n1-Novo user\n2-User existente\nOpcao: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
            case '1': //Registar novo user
                user = Register();
                UserInterface(user);
                break;
            case '2'://User já existente
                //procurar e ir buscar o (user)
                // depois UserInterface(user);
                break;
            case '0': //sair das opcoes
                exit=1;
                break;

            default: printf("Opcao invalida. Por favor introduza um valor entre 0 e 2.\n");
                break;
        }

    }while (!exit);
    return 0;
}

//Remove o /n do input no fgets
void FixInput(char *string){
    string[strlen(string)-1]='\0';
}

void UserInterface(User user){
    int exit_user=0;
    char choice= 'i';
    do{
        printf("\nEscolha uma opcao:\n0-Sair/Mudar de User\n1-Editar user\n2-Escolher cidade\n3-Remover cidade\n4-Escolher pdi\n5-Remover pdi\n6-Mais Informacao\n7-Escolher hot\n8-Remover hot\nOpcao: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
            case '1': //editar o que esta guardado
            user=EditUser(user);
                break;
            case '2'://addcity();
                break;
            case '3'://removecity();
                break;
            case '4'://addpdi()
                break;
            case '5'://removepdi();
                break;
            case '6'://moreinfo();
                break;
            case '7'://addhot();
                break;
            case '8'://removehot();
                break;
            case '0': //sair das opcoes
                exit_user=1;
                break;
            default: printf("Opcao invalida. Por favor introduza um valor entre 0 e 8.\n");
                break;

        }
        //Salvar User

        printf("\n%s , %s , %s , %s\n",user.name,user.address,user.date_of_birth,user.phone_number);
    }while (!exit_user);
}

User EditUser(User user){
    int exit_edituser=0;
    char choice= 'i';
    do{
        printf("\nEscolha uma opcao:\n0-Sair da edicao de User\n1-Alterar Nome\n2-Alterar Morada\n3-Alterar Data de Nascimento\n4-Alterar Numero de Telefone\nOpcao: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
            case '1': //Mudar Nome
                printf("Nome: ");
                fgets(user.name,Max,stdin);
                FixInput(user.name);
                break;
            case '2'://Mudar morada
                printf("Morada: ");
                fgets(user.address,Max,stdin);
                FixInput(user.address);
                break;
            case '3'://Mudar data de nascimento
                printf("Data de Nascimento (DD-MM-AAAA): ");
                fgets(user.date_of_birth,Max,stdin);
                FixInput(user.date_of_birth);
                break;
            case '4'://Mudar Telefone
                printf("Telefone: ");
                fgets(user.phone_number,Max,stdin);
                FixInput(user.phone_number);
                break;
            case '0': //sair das opcoes
                exit_edituser=1;
                break;
            default: printf("Opcao invalida. Por favor introduza um valor entre 0 e 4.\n");
                break;

        }
    }while (!exit_edituser);
    return user;
}

User Register() {
    User user;
    user.name= (char*) malloc(Max);
    user.address= (char* )malloc(Max);
    user.date_of_birth= (char*) malloc(Max);
    user.phone_number= (char*) malloc(Max);
    printf("Nome: ");
    fgets(user.name,Max,stdin);
    FixInput(user.name);
    printf("Morada: ");
    fgets(user.address,Max,stdin);
    FixInput(user.address);
    printf("Data de Nascimento (DD-MM-AAAA): ");
    fgets(user.date_of_birth,Max,stdin);
    FixInput(user.date_of_birth);
    printf("Telefone: ");
    fgets(user.phone_number,Max,stdin);
    FixInput(user.phone_number);
    return user;
}