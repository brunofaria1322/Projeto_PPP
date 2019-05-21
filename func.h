#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 256
#define Max 64
#define MaxCity 3


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
int Len(char** array,int limit);
void AddUserCP(char *word, char **list,int limit);
void FixInput(char *string);
void read_file();

User Register();
User EditUser(User user);
void UserInterface(User user, int num[], char **user_cities,char **user_pdi);    //num[0]=num cidades do user, num[1]==num pdi do user
void PrintUserInfo(User user);

//AddCity
User AddCity(User user,int num[],char** user_cities);
void GetCities(char **cities, char **user_cities);

//RemoveCity
User RemoveCity(User user,int num[],char **user_cities);
void GetUserCities(User user, char **user_cities);


//AddPdi
User AddPdi(User user,int num[],char** user_pdi);
void GetPdiByCity( char **user_pdi,char **cities);
void GetPdi(char **pdi,char *city,char **user_pdi);

//RemovePdi
User RemovePdi(User user,int num[],char **user_pdi);
void GetUserPdi(User user, char **user_pdi);

//AddHot
User AddHot(User user,int num[]);
//RemoveHot
User RemoveHot(User user, int num[]);

/*Variaveis*/
CITIES *head_Cities; //define um apontador para a primeira cidade
int num_cities, num_max_pdi,num_pdi;