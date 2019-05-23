#ifndef PPP_MASTER_INSERT_SORT_H
#define PPP_MASTER_INSERT_SORT_H

#include "func.h"


// Troca Nodes
//CIDADES

CITIES* SwapCity(CITIES* ptr1,CITIES* ptr2){
    CITIES *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

//PDI
PDI* SwapPdi(PDI* ptr1,PDI* ptr2){
    PDI *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}



/*SORT BY POPOLARITY*/

void PopBubbleSort(){
    PopBubbleSortCity(num_cities);
    CITIES *teste;
    PDI *pontos;
    teste=head_Cities;
    int i;
    while(teste!=NULL){
        i=0;
        pontos=teste->pdi;
        while(pontos!=NULL){
            i++;
            pontos=pontos->next;
        }
        PopBubbleSortPdi(&teste->pdi,i);
        teste=teste->next;
    }
}

//Sort City
void PopBubbleSortCity(int count){
    CITIES** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = &head_Cities;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

            CITIES* p1 = *h;
            CITIES* p2 = p1->next;

            if (p1->pop < p2->pop) {

                //Troca
                *h = SwapCity(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        //Caso nao tenham sido feitas alteraçoes
        if (swapped == 0)
            break;
    }
}

// Sort Pdi
void PopBubbleSortPdi(PDI **head,int count){
    PDI** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

            PDI* p1 = *h;
            PDI* p2 = p1->next;

            if (p1->pop < p2->pop) {
                //Troca
                *h = SwapPdi(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        //Caso nao tenham sido feitas alteraçoes
        if (swapped == 0)
            break;
    }
}

/*ALFABETIC SORT*/


void AlfabeticBubbleSort(){
    AlfabeticBubbleSortCity(num_cities);
    CITIES *teste;
    PDI *pontos;
    teste=head_Cities;
    int i;
    while(teste!=NULL){
        i=0;
        pontos=teste->pdi;
        while(pontos!=NULL){
            i++;
            pontos=pontos->next;
        }
        AlfabeticBubbleSortPdi(&teste->pdi,i);
        teste=teste->next;
    }
}

//Sort CITY
void AlfabeticBubbleSortCity(int count){
    CITIES** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = &head_Cities;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

            CITIES* p1 = *h;
            CITIES* p2 = p1->next;

            if (strcmp(p1->name,p2->name)>0) {
                //Troca
                *h = SwapCity(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        //Caso nao tenham sido feitas alteraçoes
        if (swapped == 0)
            break;
    }
}

// Sort Pdi
void AlfabeticBubbleSortPdi(PDI **head,int count){
    PDI** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++) {

            PDI* p1 = *h;
            PDI* p2 = p1->next;

            if (strcmp(p1->name,p2->name)>0) {

                //Troca
                *h = SwapPdi(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        //Caso nao tenham sido feitas alteraçoes
        if (swapped == 0)
            break;
    }
}

#endif //PPP_MASTER_INSERT_SORT_H
