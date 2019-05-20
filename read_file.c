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
    head_Cities=Cidades;

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

                count_pdi++;
                num_pdi++;
                // pdi.nome
                //printf("pdi: %s\n",l);

                ptr_Pdi->name=malloc(Max);
                strcpy(ptr_Pdi->name,l);

                //pdi.info
                fgets (l, MAX, f);
                FixInput(l);

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
