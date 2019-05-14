/*Structs*/
typedef struct Pdi{
    char *name, *info;
    struct Pdi *next;
}PDI;

typedef struct Cities{
    char *name;
    PDI pdi;
    struct Cities *next;
}CITIES;


typedef struct City{
    char *name;
    struct City *next;
}CITY;

typedef struct {
    char *hot;
    PDI pdi;
    CITY cities;
}UserInfo;

typedef struct USER{
    char *name, *address, *date_of_birth, *phone_number;
    UserInfo info;
    struct USER *next;
}User;


/*Header - Funçoes*/
User EditUser(User user);
void FixInput(char *string);
User Register();
void UserInterface(User user);