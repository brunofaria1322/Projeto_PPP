#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct UserCity{
	char *name;
	struct UserCity *next;
}USERCity;

typedef struct UserPdi{
	char *name;
	struct UserPdi *next;
}USERPdi;

typedef struct User{
	char *name, *address, *date_of_birth, *phone_number;
	char *hot;
	USERCity *user_city;
	USERPdi *user_Pdi;
	struct User *next;
}USER;

int write_file() {
	int i;
	FILE *f;
	f = fopen("dados.txt", "w");
	
	do {
		fprintf(f, "%s\n%s\n%s\n%s", user->name, user->address, user->date_of_birth, user->phone_number;);
		for (i = 0, i < 3, i++) {
			fprintf(f, "%s\n", user->UserCity->name);
			if (user->UserCity->next != NULL) {
				user->UserCity = user->UserCity->next;
			}
		}
		if (user->hot != "") fprintf("[%s\n", user->hot);
		else fprintf("[\n");
		do {
			fprintf(f, "%s\n", user->UserPdi->name);
			if (user->UserPdi->next == NULL) break;
			
			user->UserPdi = user->UserPdi->next;
		}
		fprinf("]\n");
		if (user->next != NULL) {
			user = user->next;
			else break;
		}
		
	} while (user->next != NULL);
	
	
	fclose(f);
	
}