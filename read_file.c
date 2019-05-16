#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
//
//Structs
//
typedef struct Pdi{
	char *name, *info;
	int pop;
	struct Pdi *next;
}PDI;

typedef struct Cities{
	char *name;
	int pop;
	PDI pdi;
	struct Cities *next;
}CITIES;

typedef struct Cities *ptr_Cities; //define um apontador para a primeira cidade

int read_file();
ptr_Cities read_list();


int read_file(){
	char l[MAX];
	FILE *f;
	f= fopen( "C:\\Users\\anabe\\Desktop\\cidades.txt" ,"r");
	char pdi[MAX], info[MAX];
	do {
		fgets (l, MAX, f);
		printf("%s", l);
		if (strcmp(l,"[\n")==0){
			fgets (l, MAX, f);
			//mudar l por cidade.nome
			printf("cidade:%s", l);
			
			do{
				fgets (l, MAX, f);
				if (strcmp(l,"]\n")==0) break;
						//passa para a proxima cidade
				// mudar l por pdi.nome
				printf("pdi: %s",l);
				fgets (l, MAX, f);
				//mudar l por pdi.info
				printf("info: %s",l);
			}while(strcmp(l,"\n")!=0);
		}
		
		
	}while(!strcmp(l,"\n"));
	
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
