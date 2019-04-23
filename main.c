#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int main() {
    char choice ='', out=''; //assim inclui qualquer tecla que seja um erro pro default
    User user;
    do{
        printf("Por favor preencha as informações de user\n");
        user =Register();
        do{
        printf("escolha uma opção:\n0-exit\n1-editar user\n2-escolher cidade\n3-remover cidade\n");
        printf("4-escolher pdi\n5-remover pdi\n2-escolher hot\n3-remover hot\n");
        printf("opção: ");
            scanf("%c",&choice);
            switch (choice){
                case '1': //editar o que esta guardado
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
                    break;
                default: printf("opção não valida, por favor introduza um valor entre 0 e 8\n");
                    break;

            }
        }while (choice!='0');
        printf("acabou de preencher os dados de %s, se pretender sair selecione 0 caso contrario enter/outra tecla\n", user.name);
        scanf("%c", &out);
    }while (out!='0');
    printf("\nobrigado");
    return 0;
}

User Register() {
    User user;
    printf("\nNome: ");
    scanf("%s",user.name);
    printf("\nMorada: ");
    scanf("%s",user.address);
    printf("\nData de Nascimento (DD-MM-AAAA): ");
    scanf("%s",user.date_of_birth);
    printf("\nTelefone: ");
    scanf("%s",user.phone_number);
    return user;
}
