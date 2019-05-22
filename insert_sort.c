#include "func.c"

int verifica(char palavra[], char palavra2[], int i, int j) {
	if (j==1){
		if (palavra[i]=='\0') return -1;
		if (palavra2[i]=='\0') return 1;
		if (palavra[i] > palavra2[i]) return 1;
		if (palavra[i] == palavra2[i]) {
			
			i++;
			verifica(palavra, palavra2, i);
		}
		
		return -1;
	}}

PDI insert_pdi(PDI l,PDI node) {
	PDI tmp,ant;
	
	if (l==NULL)
		l=node;
	else
	if (verifica(l->name,node->name)>0) { // node< 1º elemento
		node->next=l;
		l=node;
	}
	if (verifica(l->name,node->name)<0){
		//node no meio ou final
		ant=l;
		tmp=l->next;
		while ((tmp!=NULL) && (verifica(tmp->name,node->name)<0)) {
			ant=tmp;
			tmp=tmp->next;
		}
		
		node->next=tmp;
		ant->next=node;
	}
	
	return(l);
}


CITIES insert_city(CITIES l,CITIES node) {
	CITIES tmp,ant;
	
	if (l==NULL)
		l=node;
	else
	if (verifica(l->name,node->name)>0) { // node< 1º elemento
		node->next=l;
		l=node;
	}
	if (verifica(l->name,node->name)<0){
		//node no meio ou final
		ant=l;
		tmp=l->next;
		while ((tmp!=NULL) && (verifica(tmp->name,node->name)<0)) {
			ant=tmp;
			tmp=tmp->next;
		}
		
		node->next=tmp;
		ant->next=node;
	}
	
	return(l);
}
