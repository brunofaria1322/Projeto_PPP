#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int main() {
    int choice,exit=0;
    User user;
    do{
        scanf("%d",&choice);
        switch (choice){
            case (0):
                exit=1;
                break;
            case (1):
                user =Register();
                break;
            case (2):
                break;
            case (3):
                break;
            case (4):
                break;
            case (5):
                break;
            case (6):
                break;
            default:
                break;

        }
    }while (!exit);
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
