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


typedef struct UserCity{
    char *name;
    struct City *next;
}USERCity;

typedef struct {
    char *hot;
    PDI pdi;
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