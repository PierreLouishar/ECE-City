//
// Created by guill on 27/10/2022.
//

#ifndef SIM_CITY_HEADER_H
#define SIM_CITY_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <string.h>
#include <time.h>
#define W 1024
#define H 768
#define SAISIE_MAX 50

#define redR 255
#define greenR 0
#define blueR 0

#define redB 0
#define greenB 0
#define blueB 255

#define tailleBatiment 9
#define tailleUsine 18





typedef struct flux
{
    int value;
    /*
     * 0 rien
     * 1 route
     * 2 batiment
     * 3 usine elec
     * 4 usine eau
     */

}t_grille_flux;

typedef struct sommet
{
    int num;
    int* nbsucc;
    int explorer;

}t_sommet;

typedef struct arrete
{
    int a;
    int b;
    int poid;
}t_arrete;


typedef struct graph
{
    int ordre;
    int taille;

    t_sommet* tabSommet;
    t_arrete* tabArrete;

}t_graph;

typedef struct usine
{
    int type;
    int capacite_totale;
    int capacite_utilise;

    int x;
    int y;
    int numSommet;

}t_usine;



typedef struct batiment
{
    int niveau;
    char* nom;
    int nombre_habitant;
    int date_creation;
    int elec;
    int eau;

    int x;
    int y;
    int numSommet;

}t_batiment;


typedef struct partie
{
    char* nom;
    int typejeu;
    int argent;
    int nbrBatiment;
    int nbrUsine;
    int nbr_objet;
    t_batiment* tab_batiment;
    t_usine* tab_usine;
    t_grille_flux** grille;

    t_graph** mon_graph;
    int nb_graph;


}t_partie;





//sous programme outils
void saisie(int xcoord, int ycoord,BITMAP* page,int* i,char masaisie[],char lastsaisie[]);

//sous programme de base
void initialisationAllegro();
void menu();
void saisie_nom_ville(t_partie* game,BITMAP* page);


//sous programme principale
void jeu(t_partie* game);

//sous programme gestion données
void niveau_batiment(int i,t_batiment bat[i]);
void nouvelle_usine(t_partie* game,int type,int x,int y);
void nouveau_batiment(t_partie* game,int temps,int x,int y);
void debut_parti(t_partie* game);
int impot(t_partie* game);
void evolution(t_partie* game,int temps);

#endif //SIM_CITY_HEADER_H
