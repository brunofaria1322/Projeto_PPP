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

typedef struct UserPdi{
    char *name;
    struct UserPdi *next;
}USERPdi;


typedef struct {
    char *hot;
    USERPdi *pdi;
    USERCity *cities;
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

void GetCities( char **citties);
User AddCity(User user);


/*Variaveis*/
CITIES *head_Cities; //define um apontador para a primeira cidade
int num_cities, num_max_pdi;
char **cities;