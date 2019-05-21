#include "func.h"

void read_users() {
	int i;
	setlocale(LC_ALL, "Portuguese");
	char l[MAX];
	FILE *f;
	f = fopen("C:\\Users\\anabe\\Desktop\\PPPbea\\PROJETO\\PPP-master\\PPP-master\\users.txt", "r");
	if (f == NULL) {
		printf("Erro! Não Foi possivel abrir o ficheiro cidades.txt\n");
		exit(-1);
	}
	
	User *user;
	// pointer para o primeiro
	user = (User *) malloc(sizeof(User));
	head_Users = user;
	
	
	while (fgets(l, MAX, f) != NULL) {
		
		FixInput(l);
		strcpy(user->name, l);
		
		fgets(l, MAX, f);
		FixInput(l);
		strcpy(user->address, l);
		printf("address: %s\n",user->name);
		
		fgets(l, MAX, f);
		FixInput(l);
		strcpy(user->date_of_birth, l);
		
		fgets(l, MAX, f);
		FixInput(l);
		strcpy(user->phone_number, l);
		
		printf("chegou aqui informacao do user\n");
		//
		//
		//
		
		for (i = 0; i < 3; i++) {
			fgets(l, MAX, f);
			if (l[0] == '[') {
				break;
			}
			FixInput(l);
			strcpy(user->info.cities->name, l);
			printf("user 1cidade %s\n", user->info.cities->name);
			//
			//remover o print
			//
			//
			user->info.cities->next = (USERCity *) malloc(sizeof(USERCity));
			user->info.cities = user->info.cities->next;
			// cria novo citie e avanca o ponteiro
			
		}
		
		if (l[0] != '[') {
			fgets(l, MAX, f);
		}
		sprintf(user->info.hot, "[%s\n", l);
		//se %s=="" ??????
		//
		//
		
		do {
			fgets(l, MAX, f);
			if (strcmp(l, "]\n") == 0) break;
			FixInput(l);
			strcpy(user->info.pdi->name, l);
			printf("pdi user: %s\n", user->info.pdi->name);
			//
			//
			//
			user->info.pdi->next = (USERPdi *) malloc(sizeof(USERPdi));
			user->info.pdi = user->info.pdi->next;
			// cria novo pdi e avanca o ponteiro;
			
			
			user->next = (User *) malloc(sizeof(User));
			user = user->next;
			
		} while (!(strcmp(l, "]\n")));
		
		
		user->info.cities = NULL;
		user->info.pdi = NULL;
		fclose(f);
	}
}
