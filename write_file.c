#include "func.h"

void WriteUserFile(){
    setlocale(LC_ALL, "Portuguese");
    FILE *f;
    f= fopen("users.txt" ,"w");
    if (f == NULL){
        printf("Erro! Não Foi possivel abrir o ficheiro users.txt\n");
        exit(-1);
    }
    User *users;
    users=head_User;
    USERCity *cidades;

    USERPdi *pdi;
    while(users!=NULL){
        //Dados User
        fprintf(f,"%s\n%s\n%s\n%s\n",users->name,users->address,users->date_of_birth,users->phone_number);
        //Cidades
        cidades=users->info.cities;
        while(cidades!=NULL){
            fprintf(f,"%s\n",cidades->name);
            cidades=cidades->next;
        }
        //Hot
        fprintf(f,"[");
        if (users->info.hot!=NULL){
            fprintf(f,"%s\n",users->info.hot);
            fprintf(f,"%s",users->info.hot_city);
        }
        fprintf(f,"\n");

        //Pdi;
        pdi=users->info.pdi;
        while(pdi!=NULL){
            fprintf(f,"%s\n",pdi->name);
            fprintf(f,"%s\n",pdi->city);
            pdi=pdi->next;
        }
        fprintf(f,"]\n");
        users=users->next;
    }
    fclose(f);
}