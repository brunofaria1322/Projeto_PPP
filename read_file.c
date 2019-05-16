#include "func.h"

//CITIES read_list();


int read_file(){
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
    head_Cities=Cidades;
    do {
		if (fgets (l, MAX, f)==NULL){
		    break;}

		if (strcmp(l,"[\n")==0){
		    fgets (l, MAX, f);
		    FixInput(l);
		    if (!first){
                Cidades->next= (CITIES*)malloc(sizeof(CITIES));
                Cidades=Cidades->next;
		    }
            char *city_name;
            city_name= malloc(Max);
		    strcpy(city_name,l);
            Cidades->name=city_name;
            printf("Cidade: %s\n", l);

            PDI *pdi; //define um apontador para o primeiro pdi
            PDI *ptr_Pdi;
            ptr_Pdi=(PDI*)malloc(sizeof(PDI));

            pdi=ptr_Pdi;
            Cidades->pdi=pdi;
            first=1;

            do {
                fgets(l, MAX, f);
                FixInput(l);

                if (strcmp(l, "]") == 0) {
                //passa para a proxima cidade
                first = 0;
                break;
                }

                if (!first){
                    ptr_Pdi->next= malloc(sizeof(PDI));
                    ptr_Pdi=ptr_Pdi->next;
                }

                // pdi.nome
                printf("pdi: %s\n",l);
                char *pdi_name;
                pdi_name= malloc(Max);
                strcpy(pdi_name,l);
                ptr_Pdi->name=pdi_name;

                //pdi.info
                fgets (l, MAX, f);
                FixInput(l);


                char *pdi_info;
                pdi_info= malloc(MAX);
                strcpy(pdi_info,l);
                ptr_Pdi->info=pdi_info;
                printf("info: %s\n",l);

                first = 0;
            }while(1);
		}
		
		
	}while(1);
	
	fclose(f);
}

/*ptr_cities read_list() {
	ptr_Cities K=NULL,Pdi;
	Pdi=malloc(sizeof(PDI));
	if (Pdi==NULL)
		exit(-1);
		
		scanf("%s",Pdi->name);
		Pdi->next=NULL;
		
		//addnode(); falta fazer
	}
	
	return(l);
	
}
*/
