#include "func.h"

void read_file(){
    setlocale(LC_ALL, "Portuguese");
	char l[MAX];
	FILE *f;
	f= fopen("cidades.txt" ,"r");
    if (f == NULL){
        printf("Erro! Não Foi possivel abrir o ficheiro cidades.txt\n");
        exit(-1);
    }
    int first=1;
    CITIES *Cidades;
    Cidades = (CITIES*) malloc(sizeof(CITIES));
    head_Cities=Cidades; // pointer para o primeiro

    num_max_pdi=0;
    num_cities=0;
    num_pdi=0;
    while(fgets (l, MAX, f)!=NULL){

		if (strcmp(l,"[\n")==0){
		    fgets (l, MAX, f);
		    FixInput(l);
		    if (!first){
                Cidades->next= (CITIES*)malloc(sizeof(CITIES));
                Cidades=Cidades->next;
		    }

            Cidades->name=malloc(Max);
            Cidades->pop=0;
		    strcpy(Cidades->name,l);

            //Contador num Cidades
            num_cities++;
            //printf("Cidade: %s\n", l);

            PDI *pdi; //define um apontador para o primeiro pdi
            PDI *ptr_Pdi;
            ptr_Pdi=(PDI*)malloc(sizeof(PDI));

            pdi=ptr_Pdi;
            Cidades->pdi=pdi;
            first=1;

            int count_pdi=0;
            do {
                fgets(l, MAX, f);

                if (l[0]==']'){
                    //passa para a proxima cidade
                    first = 0;
                    break;
                }
                if (!first){
                    ptr_Pdi->next= malloc(sizeof(PDI));
                    ptr_Pdi=ptr_Pdi->next;
                }

                count_pdi++;
                num_pdi++;
                // pdi.nome
                //printf("pdi: %s\n",l);

                ptr_Pdi->name=malloc(Max);
                ptr_Pdi->pop=0;
                ptr_Pdi->hot=0;
                FixInput(l);
                strcpy(ptr_Pdi->name,l);

                //pdi.info
                fscanf(f,"%[^\n]\n",l);

                ptr_Pdi->info=malloc(MAX);
                strcpy(ptr_Pdi->info,l);
                //printf("info: %s\n",l);

                first = 0;
            }while(1);
            ptr_Pdi->next=NULL;

            if (count_pdi>num_max_pdi){
                num_max_pdi=count_pdi;
            }
		}

	}
    Cidades->next=NULL;
	fclose(f);
}


void read_users() {
    int i,primeiro=1;
    setlocale(LC_ALL, "Portuguese");
    char l[MAX];
    FILE *f;
    f = fopen("users.txt", "r");
    if (f == NULL) {
        printf("Erro! Não Foi possivel abrir o ficheiro users.txt\n");
        exit(-1);
    }

    User *user;
    user = (User *) malloc(sizeof(User));
    head_User = user; // pointer para o primeiro

    num_users=0;
    while (fgets(l, Max, f) != NULL) {
        if(!primeiro){
            user->next = (User *) malloc(sizeof(User));
            user = user->next;
        }
        else{
            primeiro=0;
        }

        user->name=(char*)malloc(Max);
        user->address=(char*)malloc(Max);
        user->date_of_birth=(char*)malloc(Max);
        user->phone_number=(char*)malloc(Max);

        FixInput(l);
        strcpy(user->name, l);
        printf("name: %s\n",user->name);

        fgets(l, Max, f);
        FixInput(l);
        strcpy(user->address, l);
        printf("address: %s\n",user->address);

        fgets(l, Max, f);
        FixInput(l);
        strcpy(user->date_of_birth, l);
        printf("data: %s\n",user->date_of_birth);

        fgets(l, Max, f);
        FixInput(l);
        strcpy(user->phone_number, l);
        printf("telemovel: %s\n",user->phone_number);

        //cidades
        int first=1;
        USERCity *cidades;
        user->info.cities=(USERCity*) malloc(sizeof(USERCity));
        cidades=user->info.cities;

        for (i = 0; i < 3; i++) {
            fgets(l, Max, f);
            if (l[0] == '[') {
                if (first){
                    user->info.cities=NULL;
                }
                else{
                    cidades->next=NULL;
                }
                break;
            }
            if (first){
                cidades->name=(char*)malloc(Max);
                FixInput(l);
                strcpy(cidades->name, l);
                printf("user cidade: %s\n", cidades->name);
                first=0;
            }
            else{
                cidades->next = (USERCity *) malloc(sizeof(USERCity));
                cidades = cidades->next;

                cidades->name=(char*)malloc(Max);
                FixInput(l);
                strcpy(cidades->name, l);

                printf("user cidade: %s\n", cidades->name);

            }
        }

        if (i==3){
            cidades->next=NULL;
        }

        //Hot
        if (l[0] != '[') {
            fgets(l, Max, f);
        }
        if(l[1]== '\n'){
            user->info.hot=NULL;
            user->info.hot_city=NULL;
        } else{
            for (i=0;i<strlen(l);i++){
                if (l[i+1]=='\n'){
                    l[i]='\0';
                    break;
                }
                l[i]=l[i+1];
            }
            user->info.hot=(char*)malloc(Max);
            strcpy(user->info.hot, l);
            printf("Hot: %s\n",user->info.hot);

            fgets(l, Max, f);
            FixInput(l);
            user->info.hot_city=(char*)malloc(Max);
            strcpy(user->info.hot_city, l);
            printf("Hot cidade: %s\n",user->info.hot_city);
        }

        //Pdi
        USERPdi *pontos;
        user->info.pdi=(USERPdi*) malloc(sizeof(USERPdi));
        pontos=user->info.pdi;
        first=1;

        do {
            fgets(l, Max, f);
            if (l[0]==']') {
                if (first){
                    user->info.pdi=NULL;
                }
                else{
                    pontos->next=NULL;
                }
                break;
            }
            if (first){
                pontos->name=(char*)malloc(Max);
                FixInput(l);
                strcpy(pontos->name, l);
                printf("pdi user: %s\n", pontos->name);

                pontos->city=(char*)malloc(Max);
                fgets(l, Max, f);
                FixInput(l);
                strcpy(pontos->city, l);
                printf("pdi city user: %s\n", pontos->city);

                first=0;
            }
            else{
                pontos->next=(USERPdi*)malloc(sizeof(USERPdi));
                pontos=pontos->next;

                //Nome
                pontos->name=(char*)malloc(Max);
                FixInput(l);
                strcpy(pontos->name, l);
                printf("pdi user: %s\n", pontos->name);

                //Cidade pertecente
                pontos->city=(char*)malloc(Max);
                fgets(l, Max, f);
                FixInput(l);
                strcpy(pontos->city, l);
                printf("pdi city user: %s\n", pontos->city);
            }
        } while (1);

        num_users++;
    }
    if (num_users){
        user->next=NULL;
    }
    else{
        head_User=NULL;
    }
    fclose(f);
}
