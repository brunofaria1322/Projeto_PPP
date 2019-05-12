/*Structs*/
typedef struct {
    char *name, *address, *date_of_birth, *phone_number;
}User;

/*Header - Funçoes*/
User EditUser(User user);
void FixInput(char *string);
User Register();
void UserInterface(User user);