#include "func.c"
// add na func.h  CITIES *head_pop;
//pra usar depois na viagem



int sort_pop(char* head_Cities){
	CITIES *Cidades;
	Cidades=head_Cities;
	
	CITIES *head_pop;
	CITIES *cidade=NULL;//nova lista vazia
	Head_pop =cidade;
	CITIES *pdi;
	
	
	while(Cidades->next!=NULL){
		cid=(CITIES*) malloc(sizeof(CITIES));
		cid->name=Cidades->name;
		cid->pop=Cidades->pop;
		insert_popcity(Head_pop,cid);
		
		PDI *head_pop_pdi;
		PDI *ponto=NULL;//nova lista vazia
		Head_pop_pdi =ponto;
		PDI *pdi;
		
		while(Cidades.pdi->next!=NULL) {
			pdi = (PDI *) malloc(sizeof(PDI));
			pdi->name=Cidades.pdi->name;
			pdi->pop=Cidades.pdi->pop;
			insert_poppdi(Head_pop_pdi,pdi);
			
			Cidades.pdi= Cidades.pdi->next;
		}
		
		Cidades= Cidades->next;
		
	}
	
}


PDI insert_poppdi(PDI l,PDI node) {
	PDI tmp,ant;
	
	if (l==NULL)
		l=node;
	else
	if (l->pop > node->pop) { // node< 1º elemento
		node->next=l;
		l=node;
	}
	if (l->pop <= node->pop){
		//node no meio ou final
		ant=l;
		tmp=l->next;
		while ((tmp!=NULL) && (l->pop <= node->pop)) {
			ant=tmp;
			tmp=tmp->next;
		}
		
		node->next=tmp;
		ant->next=node;
	}
	
	return(l);
}


CITIES insert_popcity(CITIES l,CITIES node) {
	CITIES tmp,ant;
	
	if (l==NULL)
		l=node;
	else
	if (l->pop > node->pop) { // node< 1º elemento
		node->next=l;
		l=node;
	}
	if (l->pop <= node->pop){
		//node no meio ou final
		ant=l;
		tmp=l->next;
		while ((tmp!=NULL) && (l->pop <= node->pop)) {
			ant=tmp;
			tmp=tmp->next;
		}
		
		node->next=tmp;
		ant->next=node;
	}
	
	return(l);
}
