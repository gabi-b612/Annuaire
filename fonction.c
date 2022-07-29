/*
  ############################################ 
  ###                                      ### 
  ###     TRAVAIL PRATIQUE EN LANGAGE C    ###   
  ###                                      ###
  ############################################

      Realisation d'un annuaire telephonique
 -----------------------------------------------

    Realiser Par :
    
    KABOMBO MUKADI GABRIEL L1 A2 20KM095
    FURAHA MULAMBA LINDA   L1 A2 20FM053
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fonction.h"


// Notre structure 
typedef struct Personne
{
    char name[40];
    char number[15];
} user;

/* ======= Saisie au clavier de l'utilisateur du nom et du numero =======*/
void Acquisition(user *p)
{
    int len_name, len_number,i;

    printf("Entrez votre nom : ");
    scanf("%s", (*p).name);

    // Verification du nom avant d'etre valider
    len_name = strlen((*p).name);

    while (len_name > 30)
    {
        printf("\n\nVotre nom depasse le nombre de caractere attendu. 30 ...\n");
        printf("\nVeuillez entrer un nom valide s'il vous plait : ");
        scanf("%s", (*p).name);
        len_name = strlen((*p).name);
    }

    // Mettre le nom en majuscule
    for ( i = 0; (*p).name[i] !='\0'; i++)
    {
        if ((*p).name[i] >= 'a' && (*p).name[i] <= 'z')
        {
            (*p).name[i] = (*p).name[i] - 32;
        }
    }
    
    printf("Entrez votre numero de telephone : ");
    scanf("%s", (*p).number);
    len_number = strlen((*p).number);

    // Verication du numero avant d'etre valider
    while (len_number != 10 || (*p).number[0] != '0')
    {
        printf("\nImpossible d'enregistre votre numero....\n");
        printf("Verifier que votre numero commence par 08 ou 09 et qu'il a 10 chiffres\n");
        printf("\nEntrez a nouveau votre numero :");
        scanf("%s", (*p).number);
        len_number = strlen((*p).number);
    }

    if (len_number == 10)
    {
        while ((*p).number[1] != '8' && (*p).number[1] != '9')
        {
            printf("\nImpossible d'enregistre votre numero....\n");
            printf("Verifier que votre numero commence par 08 ou 09 et qu'il a 10 chiffres\n");
            printf("\nEntrez a nouveau votre numero :");
            scanf("%s", (*p).number);
        }   
    }
}

void Ajoute(user rep[], int indice)
{
    printf("\nEnregistrement d'une personne....\n");
    Acquisition(&rep[indice]);
}

/* ======= alphabetic try & Affichage de la liste de contact ========== */
void Alphabetics_tris(user rep[], int indice)
{
    user tem;
    int i,j;
    if (indice > 1)
    {
        for ( i = 0; i < indice - 1; i++)
        {
            for (j = i + 1 ; j < indice; j++)
            {
                if (strcmp(rep[i].name, rep[j].name) > 1)
                {
                    tem = rep[i];
                    rep[i] = rep[j];
                    rep[j] = tem;
                } 
            }   
        }   
    }
}

void Affiche(user rep[], int indice)
{
    int i;

    if (indice == 0)
    {
        printf("\nNous ne pouvons pas affiche vos contact si votre repertoire est vide .....\n");
        printf("Merci de bien vouloire ajouter un contact...\n\n");
    }
    else
    {
        printf("\nTOUS VOS CONTACT \n");
        printf("\n\tNom ------------- Numero\n");
        for ( i = 0; i < indice; i++)
        {
            printf("\t%s ------- %s\n", rep[i].name , rep[i].number);
        }
    }
}

/* ========= Recherche du numero et du nom ========= */

char *rechercheTel (user rep[], char *nom, int indice)
{
    int i;
    for ( i = 0; i < indice; i++)
    {
        if (strcmp(nom, rep[i].name) == 0)
        {
            return rep[i].number;
        }
    }
    return NULL;
}

char *rechercheNom(user rep[], char *numero, int indice)
{
    int i;
    for ( i = 0; i < indice; i++)
    {
        if (strcmp(numero, rep[i].number) == 0)
        {
            return rep[i].name;
        }
    }
    return NULL;
}

/* ======== Suppression d'un contact dans l'annuaire ====== */
int Efface(user rep[], char *nom, int indice)
{
    int i, j;
    int n = 1;
    if (indice == 0)
    {
        printf("La liste de contact est vide....\n");
    }
    else
    {
        // Trouver l'indice a supprimer
        for ( i = 0; i < indice; i++)
        {
            if(strcmp(nom, rep[i].name) == 0)
            {
                j = i;
                n = 2;
            }
        }
        // Supprimer l'element
        for ( i = j; i < indice; i++)
        {
            rep[i] = rep[i + 1];
        }
        return n;
    }   
}