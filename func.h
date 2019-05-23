#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define MAX 256
#define Max 64
#define MaxCity 3


/*Structs*/
typedef struct Pdi{
    char *name, *info;
    int pop,hot;
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
    char *name, *city;
    struct UserPdi *next;
}USERPdi;


typedef struct {
    char *hot, *hot_city;
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
int format(char* ptr);

void read_file();
void read_users();
void WriteUserFile();

//User func
User FindUser(char* tlm);
User Register();
User EditUser(User user);
void UserInterface(User user, int num[], char **user_cities,char **user_pdi);    //num[0]=num cidades do user, num[1]==num pdi do user
void PrintUserInfo(User user);
void SaveUser(User user);
void AddUserToList(User user,User *list);
User GetUserFromPointer(User *pointer);
int format_user(char* ptr, int i);

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

//Caminho
void GetPopularity();
void AddPopularityToCity(char *cidade);
void AddPopularityToPDI(char *cidade,char *pdi);
void AddHotToPDI(char *cidade,char *pdi);
void MakeTrip(User user);
void RateTrip(CITIES *trip);

/*Variaveis*/
CITIES *head_Cities; //define um apontador para a primeira cidade
User *head_User; //define um apontador para o primeiro User
int num_cities, num_max_pdi,num_pdi,num_users;

