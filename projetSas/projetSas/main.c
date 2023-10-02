#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;

struct date{
   int day;
   int month;
   int year;
};

struct tache{
    int id;
    char title[50];
    char desc[50];
    struct date deadLine;
    char statut[50];

};





int ajouterTache(struct tache listTaches[], int count) {
   char titre[50];
   char desc[50];
   char statut[50];
   int dd,mm,yy;
   int maxId = 0;


   for(int i=0;i<count; i++){
     if(maxId<listTaches[i].id){
        maxId=listTaches[i].id;
     }
   }

   int id = maxId+1;


   printf("donner le titre de la tache-%i \n", id);
   scanf(" %49[^\n]",titre);
   printf("donner la description de la tache-%i \n", id);
   scanf(" %49[^\n]",desc);
   printf("donner la date de deadLine de la tache sous format dd-mm-yy: \n");
   printf("donner le jour: \n");
   scanf("%i", &dd);
    while(dd>31||dd==0){
    printf("la date du jour ne peut pas etre superieur a 31, veullez reassayer! \n");
    scanf("%i", &dd);
   }
    printf("donner le mois: \n");
    scanf("%i", &mm);
    while(mm>12||mm==0){
    printf("le mois ne peut pas etre superieur a 12 et differenet de 0, veullez reassayer! \n");
    scanf("%i", &mm);
   }
   printf("donner l'annee: \n");
   scanf("%i", &yy);
    while(yy != 2023){
    printf("ce programme peut gerer que les taches de 2023");
    scanf("%i", &yy);
   }

   listTaches[count].deadLine.day= dd;
   listTaches[count].deadLine.month= mm;
   listTaches[count].deadLine.year= yy;



   printf("donner le statut de la tache-%i \n", id);
   scanf("%s",statut);
   while (strcmp(statut,"todo")!=0&&strcmp(statut,"doing")!=0&&strcmp(statut,"done")!=  0 ){
    printf("le statut doit etre soit {todo} soit {doing} soit {done} pour etre valider\n");
    scanf("%s", statut);
   }





   listTaches[count].id = id;
   strcpy(listTaches[count].title, titre);
   strcpy(listTaches[count].desc, desc);
   strcpy(listTaches[count].statut, statut);

   return count + 1;
}

int AjouterTaches(struct tache listTaches[],int count, int colsNumber) {
   for (int i = 0; i < colsNumber; i++) {
      count = ajouterTache(listTaches, count);
   }
   return count;
}

int searchById(struct tache listTaches[],int id, int count){
  for (int i=0; i<count;i++){
    if(listTaches[i].id==id){
        return i;
    }
  }
  return -1;

}

int searchByName(struct tache listTaches[],char name[], int count){
  for (int i=0; i<count;i++){
    if(strcmp(listTaches[i].title,name) == 0){

        return i;
    }
  }
  return -1;


}

int deleteTask(struct tache listTaches[], int count, int id) {
    int index = searchById(listTaches, id, count);

    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            listTaches[i] = listTaches[i + 1];

        }
        count--;
        printf("Tache numéro %i supprimée avec succès.\n", id);
    } else {
        printf("Aucune tache avec cet ID n'a été trouvée.\n");
    }

    return count;
}



void showTasksNumber(int count){
     printf("le nombre totale de taches est : %i \n",count);
}

void showIncompleteTasks(struct tache listTaches[], int count){
   int uncompleted = 0;
   for(int i=0;i<count;i++){
     if(strcmp(listTaches[i].statut,"doing")==0){
        uncompleted++;
     }
   }


   printf("le nombre de taches incompletes est : %i\n", uncompleted);
}
void showCompletedTasks(struct tache listTaches[], int count){
   int completed = 0;
   for(int i=0;i<count;i++){
     if(strcmp(listTaches[i].statut,"done")==0){
        completed++;
     }
   }


   printf("le nombre de taches completes est : %i\n", completed);
}

void SortByName(struct tache listTaches[], int count){
     struct tache swapper;
     for (int i=0; i<count-1; i++){
        for(int j=0;j<count-i-1;j++){
            if(strcmp(listTaches[j].title,listTaches[j+1].title)>0){
               swapper = listTaches[j];
               listTaches[j] = listTaches[j+1];
               listTaches[j+1] = swapper;

            }
        }
     }
     Afficher(listTaches,count);

}

int returnDayStanding(int dd, int mm, int yy){
    int daysPerMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int dayNumber = dd;

    for (int i = 1 ; i < mm ;i++){
        dayNumber += daysPerMonth[i];
    }


    return dayNumber;

}

void sortByDeadLine(struct tache listTaches[], int count){
   struct tache swapper;

   for (int i=0; i<count-1; i++){
        for(int j=0;j<count-i-1;j++){
            int pos1 = returnDayStanding(listTaches[j].deadLine.day,listTaches[j].deadLine.month,listTaches[j].deadLine.year);
            int pos2 = returnDayStanding(listTaches[j+1].deadLine.day,listTaches[j+1].deadLine.month,listTaches[j+1].deadLine.year);
            if(pos2 < pos1){
               swapper = listTaches[j];
               listTaches[j] = listTaches[j+1];
               listTaches[j+1] = swapper;
            }
            }

     }
     Afficher(listTaches,count);

}


void showDlUnderThree(struct tache listTaches[], int count){
     int dd,yy,mm,res;
     printf("donner la date d'ajourdhui sous format DD-MM-YY : \n");
     printf("donner le jour :");
     scanf("%i",&dd);
     while(dd>31||dd==0){
     printf("la date du jour ne peut pas etre superieur a 31, veullez reassayer! \n");
     scanf("%i", &dd);
    }
     printf("donner le mois: \n");
     scanf("%i", &mm);
     while(mm>12||mm==0){
     printf("le mois ne peut pas etre superieur a 12 et differenet de 0, veullez reassayer! \n");
     scanf("%i", &mm);
   }
     printf("donner l'annee: \n");
     scanf("%i", &yy);
     while(yy != 2023){
     printf("ce programme peut gerer que les taches de 2023");
     scanf("%i", &yy);
   }
     int current=returnDayStanding(dd,mm,yy);

     printf("les taches avec une deadline de mois de 3 jrs :\n");
     printf("------------------------------------------------\n");

     for(int i=0; i<count ; i++){
        int pos = returnDayStanding(listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year);
        if(current<pos){
            res = pos-current;
            if( res <= 3){
               printf("Id: %d \n Titre: %s \n Description: %s \n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[i].id, listTaches[i].title,
               listTaches[i].desc,listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year,
               listTaches[i].statut);
            }
        }
     }
}

void showAllTasksDeadline(struct tache listTaches[], int count){
     int dd,yy,mm,res;
     printf("donner la date d'ajourdhui sous format DD-MM-YY : \n");
     printf("donner le jour :");
     scanf("%i",&dd);
     while(dd>31||dd==0){
     printf("la date du jour ne peut pas etre superieur a 31, veullez reassayer! \n");
     scanf("%i", &dd);
    }
     printf("donner le mois: \n");
     scanf("%i", &mm);
     while(mm>12||mm==0){
     printf("le mois ne peut pas etre superieur a 12 et differenet de 0, veullez reassayer! \n");
     scanf("%i", &mm);
   }
     printf("donner l'annee: \n");
     scanf("%i", &yy);
     while(yy != 2023){
     printf("ce programme peut gerer que les taches de 2023");
     scanf("%i", &yy);
   }
     int current=returnDayStanding(dd,mm,yy);

     printf("les deadLine de toutes les taches :\n");
     printf("------------------------------------------------\n");

     for(int i=0; i<count ; i++){
        int pos = returnDayStanding(listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year);
        if(current<pos){
            res = pos-current;
            printf("Id: %d \n Titre: %s \n Description: %s \n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[i].id, listTaches[i].title,
            listTaches[i].desc,listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year,
            listTaches[i].statut);
            printf("------------------------------------------------\n");
            printf("le nombre de jour restant a cette tache est : %i\n", res);
            printf("------------------------------------------------\n");

        }
        else if(strcmp(listTaches[i].statut,"done")!=0){
            res= pos-current;
            printf("Id: %d \n Titre: %s \n Description: %s \n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[i].id, listTaches[i].title,
            listTaches[i].desc,listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year,
            listTaches[i].statut);
            printf("------------------------------------------------\n");
            printf("le nombre de joirs restants a cette tache : %i\n", res);
            printf("------------------------------------------------\n");
        }
     }


}





void Afficher(struct tache listTaches[], int count){
    printf("\n");

    for (int i = 0; i < count; i++) {
       printf("Id: %d \n Titre: %s \n Description: %s \n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[i].id, listTaches[i].title,
               listTaches[i].desc,listTaches[i].deadLine.day,listTaches[i].deadLine.month,listTaches[i].deadLine.year,
               listTaches[i].statut);
    }

}







int main() {


    int choice = 10;
    int secondChoice, colsNumber, identifiant,thirdChoice,m,d,y,Id;
    struct tache listTaches[100];
    char title[50];
    char description[50];
    char state[50];

    while(choice != 0){
        out:
        printf("-----------------------------Menu----------------------------------\n");
        printf("\n");
        printf("1.Ajouter\n2.Afficher liste de taches\n3.Modifier une tache\n4.Supprimer une tache\n5.Rechercher tache\n6.Stats\n0.Quitter\n");
        printf("\n");
        printf("---------------------------------------------------------------\n");
        scanf("%i", &choice);




        switch (choice)
        {
        case 1:
            printf("1.Ajouter une seule tache\n2.Ajouter plusieurs taches\n");
            scanf("%i", &secondChoice);
            switch (secondChoice)
            {
            case 1:

                count = ajouterTache(listTaches,count);
                printf("ajouter avec succes \n");
                printf("\n");


                break;
            case 2:
                printf("donner le nombre de taches que vus vouler ajouter: \n");
                scanf("%i",&colsNumber);
                count = AjouterTaches(listTaches, count, colsNumber);
                printf("taches ajouter avec succes \n");
                printf("\n");
                Afficher(listTaches,count);

                break;
            default:
                printf("choix non valide \n");

                break;
            }
            break;

        case 2:
            printf("1.Afficher par ordre alphabetique\n2.Afficher par deadLine\n3.tâches dont le deadline est dans 3 jours ou moins\n");
            scanf("%i", &secondChoice);
            switch(secondChoice){
                case 1:
                    if(count == 0){
                        printf("aucune tach disponible pour le moment :\n" );
                    }
                    SortByName(listTaches,count);
                    break;

                case 2:
                    printf("taches avant tri : \n");
                    printf("------------------------------------------\n");
                    Afficher(listTaches,count);
                    printf("apres tri: ");
                    printf("------------------------------------------\n");
                    sortByDeadLine(listTaches,count);
                    break;

                case 3:
                    showDlUnderThree(listTaches,count);
                    break;


            }
            break;



        case 3:

            printf("1.modifier par id\n2.modifier par titre\n");
            scanf("%i", &secondChoice);
            switch(secondChoice){
                case 1:
                    printf("1.modifier la description\n2.modifier statut\n3.modifier deadLine\n4.menu precedent\n");
                    scanf("%i", &thirdChoice);
                    switch(thirdChoice){
                        case 1:
                            printf("donner l'indentifiant de la tache que vous voulez modifier \n");
                            scanf("%i", &identifiant);
                            int pos = searchById(listTaches,identifiant,count);
                            if (pos != -1){
                                printf("donner la nouvelle description de la tache-%i :\n", identifiant);
                                scanf(" %49[^\n]", description);
                                strcpy(listTaches[pos].desc,description);

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");
                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos].id, listTaches[pos].title,
                                listTaches[pos].desc,listTaches[pos].deadLine.day,listTaches[pos].deadLine.month,listTaches[pos].deadLine.year,
                                listTaches[pos].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }
                            break;
                        case 2:
                            printf("donner l'indentifiant de la tache que vous voulez modifier \n");
                            scanf("%i", &identifiant);
                            int pos2 = searchById(listTaches,identifiant,count);

                            if (pos2 != -1){
                                printf("donner le nouveau statut de la tache-%i :\n", identifiant);
                                scanf(" %s", state);
                                 while (strcmp(state,"todo")!=0&&strcmp(state,"doing")!=0&&strcmp(state,"done")!=  0 ){
                                        printf("le statut doit etre soit {todo} soit {doing} soit {done} pour etre valider\n");
                                        scanf("%s", state);
                                       }

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");

                                strcpy(listTaches[pos2].statut,state);
                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos2].id, listTaches[pos2].title,
                                listTaches[pos2].desc,listTaches[pos2].deadLine.day,listTaches[pos2].deadLine.month,listTaches[pos2].deadLine.year,
                                listTaches[pos2].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }
                            break;

                            case 3:
                            printf("donner l'indentifiant de la tache que vous voulez modifier \n");
                            scanf("%i", &identifiant);
                            int pos3 = searchById(listTaches,identifiant,count);

                            if (pos3 != -1){
                                printf("donner la nouvelle deadLine de la tache-%i sous format DD-MM-YY :\n", identifiant);
                                printf("donner le jour : \n");
                                scanf(" %d", &d);
                                while(d>31||d==0){
                                    printf("donner une valeur inferieru a 31");
                                    scanf("%i",&d);
                                }
                                 printf("donner le mois : \n");
                                scanf(" %d", &m);
                                while(m>12||m==0){
                                    printf("donner une valeur inferieru a 12 ");
                                    scanf("%d",&m);
                                }
                                printf("donner l'annee : \n");
                                scanf(" %d", &y);
                                while(y != 2023){
                                    printf("ce programme peut gerer que les taches de 2023");
                                    scanf("%d",&y);
                                }
                                 listTaches[pos3].deadLine.day= d;
                                 listTaches[pos3].deadLine.month= m;
                                 listTaches[pos3].deadLine.year= y;

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");

                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos3].id, listTaches[pos3].title,
                                listTaches[pos3].desc,listTaches[pos3].deadLine.day,listTaches[pos3].deadLine.month,listTaches[pos3].deadLine.year,
                                listTaches[pos3].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }

                            break;



                    }
                    break;
                    case 2:
                    printf("1.modifier la description\n2.modifier statut\n3.modifier deadLine\n4.menu precedent\n");
                    scanf("%i", &thirdChoice);
                    switch(thirdChoice){
                        case 1:
                            printf("donner le titre de la tache que vous voulez modifier :\n");
                            scanf(" %49[^\n]", &title);
                            int pos = searchByName(listTaches,title,count);
                            if (pos != -1){
                                printf("donner la nouvelle description de la tache :\n");
                                scanf(" %49[^\n]", description);
                                strcpy(listTaches[pos].desc,description);

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");
                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos].id, listTaches[pos].title,
                                listTaches[pos].desc,listTaches[pos].deadLine.day,listTaches[pos].deadLine.month,listTaches[pos].deadLine.year,
                                listTaches[pos].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }
                            break;
                        case 2:
                            printf("donner le titre de la tache que vous voulez modifier \n");
                            scanf(" %49[^\n]", &title);
                            int pos2 = searchByName(listTaches,title,count);

                            if (pos2 != -1){
                                printf("donner le nouveau statut de la tache :\n");
                                scanf("%s", state);
                                 while (strcmp(state,"todo")!=0&&strcmp(state,"doing")!=0&&strcmp(state,"done")!=  0 ){
                                        printf("le statut doit etre soit {todo} soit {doing} soit {done} pour etre valider\n");
                                        scanf("%s", state);
                                       }

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");

                                strcpy(listTaches[pos2].statut,state);
                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos2].id, listTaches[pos2].title,
                                listTaches[pos2].desc,listTaches[pos2].deadLine.day,listTaches[pos2].deadLine.month,listTaches[pos2].deadLine.year,
                                listTaches[pos2].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }
                            break;

                        case 3:
                            printf("donner le titre de la tache que vous voulez modifier \n");
                            scanf(" %49[^\n]", &title);
                            int pos3 = searchByName(listTaches,title,count);

                            if (pos3 != -1){
                                printf("donner la nouvelle deadLine de la tache sous format DD-MM-YY :\n");
                                printf("donner le jour : \n");
                                scanf(" %d", &d);
                                while(d>31||d==0){
                                    printf("donner une valeur inferieru a 31");
                                    scanf("%i",&d);
                                }
                                 printf("donner le mois : \n");
                                scanf(" %d", &m);
                                while(m>12||m==0){
                                    printf("donner une valeur inferieru a 12 ");
                                    scanf("%d",&m);
                                }
                                printf("donner l'annee : \n");
                                scanf(" %d", &y);
                                while(y>2024||y<2022){
                                    printf("ce programme peut gerer que les taches avec une dealine de 1 an , et le meme pour les taches deja faites! , veuillez entrer une date entre 2022 et 2024");
                                    scanf("%d",&y);
                                }
                                 listTaches[pos3].deadLine.day= d;
                                 listTaches[pos3].deadLine.month= m;
                                 listTaches[pos3].deadLine.year= y;

                                printf("\n");
                                printf("Tache modifier qvec succes! \n");

                                printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos3].id, listTaches[pos3].title,
                                listTaches[pos3].desc,listTaches[pos3].deadLine.day,listTaches[pos3].deadLine.month,listTaches[pos3].deadLine.year,
                                listTaches[pos3].statut);
                        }
                            else {
                                printf("tache non trouver !\n");
                            }
                            break;


                    }
                    break;


            }
            break;
        case 4:
            printf("donner l'identifiant de la tache que vous vouler supprimer : \n");
            scanf("%i", &Id);
            count=deleteTask(listTaches,count,Id);
            break;

        case 5:
            printf("1.Chercher par id\n2.chercher par titre\n");
            scanf("%i", &secondChoice);
            switch (secondChoice)
            {
            case 1:
                printf("donner l'identifiant de la tache :\n");
                scanf("%i", &identifiant);
                int pos = searchById(listTaches,identifiant,count);
                if (pos != -1){
                    printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos].id, listTaches[pos].title,
                    listTaches[pos].desc,listTaches[pos].deadLine.day,listTaches[pos].deadLine.month,listTaches[pos].deadLine.year,
                    listTaches[pos].statut);
                }
                else {
                    printf("tache non trouver !\n");
                }

                break;
            case 2:
                printf("donner le titre  de la tache :\n");
                scanf(" %49[^\n]s",title);
                int pos2 = searchByName(listTaches,title,count);
                if (pos2 != -1){
                    printf("Id: %d \n Titre: %s\n Description: %s\n deadLine: %i/%i/%i \n Statut: %s\n", listTaches[pos2].id, listTaches[pos2].title,
                    listTaches[pos2].desc,listTaches[pos2].deadLine.day,listTaches[pos2].deadLine.month,listTaches[pos2].deadLine.year,
                    listTaches[pos2].statut);
                }
                else {
                    printf("tache non trouver !\n");
                }
                break;
            default :
                printf("choix indispo!\n");
                break;
         }
          break;
        case 6:
            printf("1.Afficher nombre totale de taches\n2.afficher nombre de taches completes et celui des taches incompletes\n3. Afficher le nombre de jours restants jusqu au délai de chaque tâche\n4.menu precedent\n");

            scanf("%i", &secondChoice);
            switch(secondChoice){

                case 1:
                    showTasksNumber(count);
                    break;
                case 2:
                    showCompletedTasks(listTaches,count);
                    printf("---------------------------------------------\n");
                    showIncompleteTasks(listTaches,count);
                    break;
                case 3:
                    showAllTasksDeadline(listTaches,count);
                    break;
                case 4:
                    goto out;

                default:
                    printf("choix invalide! \n");
                    break;


            }
            break;

        case 0:
            return 0;


        default:
            printf("choix indisponible :\n");
            break;
    }

    }
}

