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
#include <stdlib.h>
#include <string.h>

#include "fonction.h"

typedef struct Personne
{
    char name[40];
    char number[15];
} user;

int main()
{
    user annuaire[1];
    int indice = 0, retour_efface, i,j;
    int choix_user;
    char name_delete[35], name_search[35], number_search[15];
    char *phone_number;
    char *phone_name;

    printf("\n\n ###### BIENVENU DANS NOTRE PROGRAMME ########\n");
    printf("\nVoici le Menu : \n\n");
    do
    {
        do
        {
            printf("\n1. Ajouter une personne a l'annuaire\n");
            printf("2. Afficher le contenu de l'annuaire\n");
            printf("3. Supprimer une personne de l'annuaire\n");
            printf("4. Consulter le numero de telephone d'une personne\n");
            printf("5. Trouver a qui appartient un certain numero\n");
            printf("6. Sortir du programme\n");

            printf("\nVotre choix : ");
            scanf("%d", &choix_user);
        } while (choix_user < 1 || choix_user > 6);
        switch (choix_user)
        {
        case 1 :
            Ajoute(annuaire, indice);
            indice ++;
            printf("\nVous avez ajouter un contact :)\n");
            break;

        case 2:
            Alphabetics_tris(annuaire, indice);
            Affiche(annuaire, indice);
            break;

        case 3:
            if (indice == 0)
            {
                printf("\nNous ne pouvons pas supprimer un contact si votre repertoire est vide .....\n");
                printf("Merci de bien vouloire ajouter un contact...\n");
            }
            else
            {
                printf("\nQuel est le nom du contact a supprimer ... ? : ");
                scanf("%s", name_delete);
                for ( i = 0; name_delete[i] != '\0'; i++)
                {
                    if (name_delete[i] >= 'a' && name_delete[i] <= 'z')
                    {
                        name_delete[i] = name_delete[i] - 32;
                    }
                }

                retour_efface = Efface(annuaire, name_delete, indice);
                if (retour_efface  == 2)
                {
                    indice -= 1;
                    printf("\nVous avez retirer un contact .!\n");
                }
                else
                {
                    printf("\nPas de personne a ce nom\n");
                }  
            }
            break;
        
        case 4:
            printf("\n\nRetrouver le numero d'un contact par son nom\n");
            printf("\nQuel est le nom : ");
            scanf("%s", name_search);
            for ( j = 0; name_search[j] != '\0'; j++)
            {
                if (name_search[j] >= 'a' && name_search[j] <= 'z')
                {
                    name_search[j] = name_search[j] - 32;
                }
            }
            

            phone_number = rechercheTel(annuaire, name_search, indice);
            if (phone_number == NULL)
            {
                printf("\nPas de personne a ce nom\n");
            }
            else
            {
                printf("\nResultat de la recherche : \n");
                printf("\n* le numero de telephon de %s est le : %s \n", name_search, phone_number);
            }
            break;
        
        case 5:
            printf("\nRetrouver le nom d'un contact avec son numero de telephone\n");
            printf("Quel est le numero de telephone : ");
            scanf("%s", number_search);
            phone_name = rechercheNom(annuaire, number_search, indice);
            if (phone_name == NULL)
            {
                printf("\nPas ce numero dans l'annuaire \n");
            }
            else
            {
                printf("Resultat de la recherche : \n");
                printf("\n* le nom du numero %s est  %s\n",number_search, phone_name);
            }
            break;
            
        default:
        printf("\n\nFin du programme .....\nA bientot..... :)\n\n\n");
            break;
        }
        
    } while (choix_user != 6);
    
    EXIT_SUCCESS;
}