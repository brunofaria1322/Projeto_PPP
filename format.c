#include "func.h"

int format_user(char* ptr, int i) {
	int j = 0;
	// return 1 == esta errado
	// return 0 == esta certo
	
	switch (i) {
		case 1: // nome/address
			for (j = 0; ptr[j] != '\0'; j++) {
				if (!isalpha(ptr[j]) && (ptr[j] != ' ') && (ptr[j] != '.') && (ptr[j] != '-')) {
					return 1;
				}
			}
			return 0;
		
		case 2: //data
			for (j = 0; ptr[j] != '\0'; j++) {
				if ((j==2 || j==5)&& (ptr[j] != '-')) return 1;
				if ((j!=2 && j!=5)&& (isdigit(ptr[i])!=0))  return 1;
				
			}
			//verifica se a data é possivel
			int dd = (ptr[0] - '0') * 10 + (ptr[1] - '0');
			int mm = (ptr[3] - '0') * 10 + (ptr[4] - '0');
			int yy = (ptr[6] - '0') * 1000 + (ptr[7] - '0') * 100 + (ptr[8] - '0') * 10 + (ptr[9] - '0');
			
			if (yy >= 1900 && yy <= 2019) {
				if (mm >= 1 && mm <= 12) {
					if (dd >= 1 && dd <= 30 && mm != 2) return 0;
					if (dd == 31 && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)) return 0;
					if (dd >= 1 && dd <= 28 && mm == 2) return 0;
					if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))) return 0;
				}
				
			}
			return 1;
		
		
		case 3: //Telefone
			for (j = 0; ptr[j] != '\0'; j++) {
				if (!isdigit(ptr[i])) {
					return 1;
				}
			}
			if (j == 9) {
			    User *user;
			    user=head_User;
			    while(user!=NULL) {
			        if (strcmp(ptr,user->phone_number)==0){
			            printf("Já existe um User com esse nuero de telefone!\n");
                        return 1;
			        }
			        user=user->next;
			    }
                return 0;
			}
			return 1;
			
		default:
			return 1;
	}

}