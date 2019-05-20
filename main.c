#include "func.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    read_file();

    int exit=0;
    char choice = 'i';
    char **user_cities, **user_pdi;

    do{
        user_cities= (char**) malloc(num_cities* sizeof(char*));
        user_pdi= (char**) malloc(num_pdi* sizeof(char*));

        int i=0,num[2]={0,0};;
        for (i=0;i<num_cities;i++){
            user_cities[i]= (char*) calloc(1,Max);
        }

        for (i=0;i<num_pdi;i++){
            user_pdi[i]= (char*) calloc(1,Max);
        }
        User user;
            printf("Escolha uma opção:\n0-Sair\n1-Novo user\n2-User existente\nOpção: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
             case '1': //Registar novo user
                 user = Register();
                 UserInterface(user,num,user_cities,user_pdi);
                 break;
             case '2'://User já existente
                 //procurar e ir buscar o (user) e o numero de pdi e cidades (num)
                 //void GetUserCities(User user,char **user_cities){
                 // depois UserInterface(user,num);
                 break;
             case '0': //sair das opcoes
                 exit=1;
                 break;

             default: printf("Opção inválida. Por favor introduza um valor entre 0 e 2.\n");
                 break;
         }

        free(user_cities);
    }while (!exit);

    return 0;
}

//Remove o /n do input no fgets
void FixInput(char *string){
    string[strlen(string)-1]='\0';
}

void UserInterface(User user, int num[],char **user_cities,char **user_pdi){
    int exit_user=0;
    char choice= 'i';

    do{
        printf("\nEscolha uma opção:\n0-Sair/Mudar de User\n1-Editar user\n2-Escolher cidade\n3-Remover cidade\n4-Escolher pdi\n5-Remover pdi\n6-Mais Informação\n7-Escolher hot\n8-Remover hot\nOpção: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
            case '1': //editar o que esta guardado
                user=EditUser(user);
                break;

            case '3'://removecity();
                if (num[0]==0){
                    printf("Ainda não escolheu nenhuma cidade\nDeseja adicionar uma cidade?\n1-Sim\n2-Não\nOpção: ");
                    scanf("%c",&choice);
                    getchar();
                    if (choice!='1'){
                        break;
                    }
                }
                else{
                    user=RemoveCity(user, num,user_cities);
                    break;
                }

            case '2'://addcity();
                user=AddCity(user, num,user_cities);
                break;

            case '5'://removepdi();
                if (num[1]==0){
                    printf("Ainda não escolheu nenhum pdi\nDeseja adicionar um pdi?\n1-Sim\n2-Não\nOpção: ");
                    scanf("%c",&choice);
                    getchar();
                    if (choice!='1'){
                        break;
                    }
                }
                else{
                    user=RemovePdi(user, num,user_pdi);
                    break;
                }

            case '4'://addpdi()
                user=AddPdi(user, num,user_pdi);
                break;

            case '6'://moreinfo();
                break;

            case '7'://addhot();
                break;

            case '8'://removehot();
                break;

            case '0': //sair das opcoes
                exit_user=1;
                break;

            default: printf("Opção inválida. Por favor introduza um valor entre 0 e 8.\n");
                break;

        }
    }while (!exit_user);
    //Salvar User
}



User EditUser(User user){
    int exit_edituser=0;
    char choice= 'i';
    do{
        printf("\nEscolha uma opção:\n0-Sair da edição de User\n1-Alterar Nome\n2-Alterar Morada\n3-Alterar Data de Nascimento\n4-Alterar Número de Telefone\nOpção: ");
        scanf("%c",&choice);
        getchar();
        switch (choice){
            case '1': //Mudar Nome
                printf("Nome: ");
                fgets(user.name,Max,stdin);
                FixInput(user.name);
                break;
            case '2'://Mudar morada
                printf("Morada: ");
                fgets(user.address,Max,stdin);
                FixInput(user.address);
                break;
            case '3'://Mudar data de nascimento
                printf("Data de Nascimento (DD-MM-AAAA): ");
                fgets(user.date_of_birth,Max,stdin);
                FixInput(user.date_of_birth);
                break;
            case '4'://Mudar Telefone
                printf("Telefone: ");
                fgets(user.phone_number,Max,stdin);
                FixInput(user.phone_number);
                break;
            case '0': //sair das opcoes
                exit_edituser=1;
                break;
            default: printf("Opção inválida. Por favor introduza um valor entre 0 e 4.\n");
                break;

        }
    }while (!exit_edituser);
    return user;
}


//ADD City
User AddCity(User user,int num[],char** user_cities) {
    char **cities;
    cities = (char**) malloc(num_cities* sizeof(char*));
    GetCities(cities,user_cities);
    int exit=0, i, len;
    char choice= 'i';
    USERCity *cidades;
    do{
        len=Len(cities,num_cities);
        printf("%d",len);
        printf("\nEscolha uma opção:\n0-Voltar\n");
        for (i=1;i<len+1;i++){
            printf("%d-%s\n",i,cities[i-1]);
        }
        printf("Opção: ");
        scanf("%c",&choice);
        getchar();
        if (choice=='0') {
            exit = 1;
        }
        else{
            choice=(int) choice-'0';
            if (choice>0 && choice<=len){
                choice-=1;

                if(user.info.cities==NULL){
                    user.info.cities=(USERCity*)malloc(sizeof(USERCity));
                    cidades=user.info.cities;
                }
                else{
                    cidades=user.info.cities;
                    while (cidades->next!=NULL){
                        cidades=cidades->next;
                    }
                    cidades->next=(USERCity*) malloc(sizeof(USERCity));
                    cidades=cidades->next;
                }

                cidades->next=NULL;
                cidades->name=malloc(Max);
                strcpy(cidades->name,cities[choice]);

                AddUserCP(cities[choice],user_cities,num_cities);
                num[0]+=1;

                for (i = choice ;i < len-1; i++) {
                    cities[i] = cities[i + 1];
                }
                cities[len-1]="";
            }
        }

    }while (!exit);
    printf("\n---\n%s\n%s\n---\n",user_cities[0],user_cities[1]);
    return user;
}

void GetCities(char **cities, char **user_cities){
    CITIES *cid;
    cid = head_Cities;

    int count = 0;
    int passa,i;
    while (cid != NULL) {

        passa=1;
        for (i=0;i<num_cities;i++){
            if (strlen(user_cities[i])==0){
                break;
            }
            if (strcmp(user_cities[i],cid->name)==0){
                passa=0;
                break;
            }
        }

        if (passa) {
            cities[count] = cid->name;
            count++;
        }

        cid = cid->next;
    }
    if (num_cities!=count){
        cities[count]="";
    }
}

//Remove City
User RemoveCity(User user,int num[],char **user_cities) {

    int exit=0;
    char choice= 'i';
    USERCity *cidades;
    do{
        printf("\nEscolha uma opção:\n0-Voltar\n");
        int i;
        for (i=1;i<num[0]+1;i++){
            printf("%d-%s\n",i,user_cities[i-1]);
        }
        printf("Opção: ");
        scanf("%c",&choice);
        getchar();
        if (choice=='0') {
            exit = 1;
        }
        else{
            choice=(int) choice-'0';
            if (choice>0 && choice<=num[0]){
                choice-=1;
                //se só houver uma cidade
                if (num[0]==1){
                    free(user.info.cities);
                    user.info.cities=NULL;
                }
                else{
                    cidades=user.info.cities;
                    //se for a primeira cidade
                    if (strcmp(user_cities[choice],cidades->name)==0){
                        cidades=cidades->next;
                        free(user.info.cities);
                        user.info.cities=cidades;
                    }
                    //se não for a primeira cidade
                    else{
                        USERCity *cidade_anterior;
                        cidades=user.info.cities;
                        cidade_anterior=cidades;
                        cidades=cidades->next;
                        user.info.cities=cidade_anterior;

                        for (i=0;i<num[0];i++){
                            if (strcmp(user_cities[choice],cidades->name)==0) {
                                cidade_anterior->next = cidades->next;
                                free(cidades);
                                break;
                            }
                            cidades=cidades->next;
                            cidade_anterior=cidade_anterior->next;
                        }
                    }
                }
                for (i = choice; i < num[0] - 1; i++){
                    user_cities[i] = user_cities[i + 1];
                }
                user_cities[num[0]-1]="";
                num[0] -= 1;
            }
        }

    }while (!exit);

    return user;
}


void GetUserCities(User user,char **user_cities){
    USERCity *user_city;
    user_city=user.info.cities;

    while (user_city != NULL) {
        *user_cities = (char *) malloc(Max);

        *user_cities = user_city->name;

        user_city = user_city->next;
        user_cities++;
    }
}


//ADD PDI
User AddPdi(User user,int num[],char** user_pdi) {
    char **pdi, **cities;
    cities = (char**) malloc(num_cities* sizeof(char*));

    pdi = (char**) malloc(num_pdi* sizeof(char*));
    int exit=0, i, len,exit_pdi;
    char choice= 'i';
    USERPdi *pontos;

    //
    do{
        GetPdiByCity(user_pdi,cities);
        printf("\n0-Voltar\nEscolha a cidade à qual pertence o pdi desejado:\n");
        len=Len(cities,num_cities);
        printf("Opção: ");
        scanf("%c",&choice);
        getchar();
        if (choice=='0') {
            exit = 1;
        }
        else{
            choice=(int) choice-'0';
            if (choice>0 && choice<=len) {
                choice -= 1;
                char *cidade;
                cidade=cities[choice];
                exit_pdi = 0;
                do {
                    GetPdi(pdi, cidade,user_pdi);
                    len=Len(pdi,num_max_pdi);
                    printf("Opção: ");
                    scanf("%c", &choice);
                    getchar();

                    if (choice == '0') {
                        exit_pdi = 1;
                    }
                    else {
                        choice = (int) choice - '0';
                        if (choice > 0 && choice <= len) {
                            choice -= 1;

                            if (user.info.pdi == NULL) {
                                user.info.pdi = (USERPdi *) malloc(sizeof(USERPdi));
                                pontos = user.info.pdi;
                            } else {
                                pontos = user.info.pdi;
                                while (pontos->next != NULL) {
                                    pontos = pontos->next;
                                }
                                pontos->next = (USERPdi *) malloc(sizeof(USERPdi));
                                pontos = pontos->next;
                            }

                            pontos->next = NULL;
                            pontos->name = malloc(Max);
                            strcpy(pontos->name, pdi[choice]);

                            AddUserCP(pdi[choice], user_pdi,num_pdi);
                            num[1] += 1;

                            for (i = choice; i < len - 1; i++) {
                                pdi[i] = pdi[i + 1];
                            }
                            pdi[len - 1] = "";
                        }
                    }
                }while (!exit_pdi);
            }
        }
    }while (!exit);
    //printf("\n---\n%s\n%s\n---\n",user_cities[0],user_cities[1]);
    return user;
}

void GetPdiByCity(char **user_pdi,char **cities){
    CITIES *cid;
    cid = head_Cities;
    PDI *ponto;

    char **local_pdi;

    int count = 0;
    int passa,i,count2;
    while (cid != NULL) {
        ponto=cid->pdi;
        count2=0;
        local_pdi=(char**)malloc(num_max_pdi* sizeof(char*));
        for (i=0;i<num_max_pdi;i++){
            local_pdi[i]=(char*)calloc(1,Max);
        }
        while (ponto != NULL) {
            passa = 1;
            for (i = 0; i < num_max_pdi; i++) {
                if (strlen(user_pdi[i]) == 0) {
                    break;
                }
                if (strcmp(user_pdi[i], ponto->name) == 0) {
                    passa = 0;
                    break;
                }
            }

            if (passa) {
                local_pdi[count2] = ponto->name;
                count2++;
            }
            ponto = ponto->next;
        }
        if (count2){
            printf("%d-%s\n",count+1,cid->name);
            for (i=0;i<count2;i++){
                printf("\t%s\n",local_pdi[i]);
            }
            cities[count]=cid->name;
            count++;
        }
        cid = cid->next;
        free(local_pdi);
    }
    if (num_cities!=count){
        cities[count]="";
    }
}

void GetPdi(char **pdi,char *city, char **user_pdi){
    CITIES *cid;
    cid = head_Cities;
    PDI *ponto;

    int count = 0;
    int passa,i;
    while (strcmp(cid->name,city)!=0) {
        cid=cid->next;
    }
    ponto=cid->pdi;
    while (ponto != NULL) {
        passa = 1;
        for (i = 0; i < num_max_pdi; i++) {
            if (strlen(user_pdi[i]) == 0) {
                break;
            }
            if (strcmp(user_pdi[i], ponto->name) == 0) {
                passa = 0;
                break;
            }
        }

        if (passa) {
            printf("%d- %s\n",count+1,ponto->name);
            printf("\tinfo: %s\n",ponto->info);
            pdi[count] = ponto->name;
            count++;
        }
        ponto = ponto->next;
    }
    if (num_pdi!=count){
        pdi[count]="";
    }
}

//baixo
//Remove Pdi
User RemovePdi(User user,int num[],char **user_pdi) {

    int exit=0;
    char choice= 'i';
    USERPdi *pontos;
    do{
        printf("\nEscolha uma opção:\n0-Voltar\n");
        int i;
        for (i=1;i<num[1]+1;i++){
            printf("%d-%s\n",i,user_pdi[i-1]);
        }
        printf("Opção: ");
        scanf("%c",&choice);
        getchar();
        if (choice=='0') {
            exit = 1;
        }
        else{
            choice=(int) choice-'0';
            if (choice>0 && choice<=num[1]){
                choice-=1;
                //se só houver um pdi
                if (num[1]==1){
                    free(user.info.pdi);
                    user.info.pdi=NULL;
                }
                else{
                    pontos=user.info.pdi;
                    //se for o primeiro pdi
                    if (strcmp(user_pdi[choice],pontos->name)==0){
                        pontos=pontos->next;
                        free(user.info.pdi);
                        user.info.pdi=pontos;
                    }
                        //se não for o primeiro pdi
                    else{
                        USERPdi *ponto_anterior;
                        pontos=user.info.pdi;
                        ponto_anterior=pontos;
                        pontos=pontos->next;
                        user.info.pdi=ponto_anterior;

                        for (i=0;i<num[1];i++){
                            if (strcmp(user_pdi[choice],pontos->name)==0) {
                                ponto_anterior->next = pontos->next;
                                free(pontos);
                                break;
                            }
                            pontos=pontos->next;
                            ponto_anterior=ponto_anterior->next;
                        }
                    }
                }
                for (i = choice; i < num[1] - 1; i++){
                    user_pdi[i] = user_pdi[i + 1];
                }
                user_pdi[num[1]-1]="";
                num[1] -= 1;
            }
        }

    }while (!exit);

    return user;
}

void GetUserPdi(User user,char **user_pdi){
    USERPdi *user_ponto;
    user_ponto=user.info.pdi;

    while (user_ponto != NULL) {
        *user_pdi = (char *) malloc(Max);

        *user_pdi = user_ponto->name;

        user_ponto = user_ponto->next;
        user_pdi++;
    }
}

//cima
User Register() {
    User user;
    user.info.cities= NULL;
    user.info.pdi= NULL;
    user.info.hot= NULL;
    user.name= (char*) malloc(Max);
    user.address= (char* )malloc(Max);
    user.date_of_birth= (char*) malloc(Max);
    user.phone_number= (char*) malloc(Max);
    printf("Nome: ");
    fgets(user.name,Max,stdin);
    FixInput(user.name);
    printf("Morada: ");
    fgets(user.address,Max,stdin);
    FixInput(user.address);
    printf("Data de Nascimento (DD-MM-AAAA): ");
    fgets(user.date_of_birth,Max,stdin);
    FixInput(user.date_of_birth);
    printf("Telefone: ");
    fgets(user.phone_number,Max,stdin);
    FixInput(user.phone_number);
    return user;
}


int Len(char** array,int limit){
    int i,len=limit;
    for(i=0;i<limit;i++){
        if (strlen(array[i])==0){
            len=i;
            break;
        }
    }
    return len;
}

void AddUserCP(char *word, char **list,int limit){
    int i;
    for(i=0;i<limit;i++){
        if (strlen(list[i])==0){
            list[i]=word;
            break;
        }
    }
}