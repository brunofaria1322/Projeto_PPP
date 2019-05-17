#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 256
#define Max 64


/*Structs*/
typedef struct Pdi{
    char *name, *info;
    int pop;
    struct Pdi *next;
}PDI;

typedef struct Cities{
    char *name;
    PDI *pdi;
    int pop;
    struct Cities *next;
}CITIES;


typedef struct UserCity{
    char *name;
    struct UserCity *next;
}USERCity;

typedef struct {
    char *hot;
    PDI *pdi;
    USERCity cities;
}USERInfo;

typedef struct USER{
    char *name, *address, *date_of_birth, *phone_number;
    USERInfo info;
    struct USER *next;
}User;


/*Header - Funçoes*/
User EditUser(User user);
void FixInput(char *string);
User Register();
void UserInterface(User user);
void read_file();

/*Variaveis*/
CITIES *head_Cities; //define um apontador para a primeira cidade