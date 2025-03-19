#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <memory>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const double CHAMP_ANGULAIRE_MAX;
   static const double CHAMP_ANGULAIRE_MIN;
   static const double DISTANCE_YEUX_MAX;
   static const double DISTANCE_YEUX_MIN;
   static const double CAPACITE_DETECTION_YEUX_MAX;
   static const double CAPACITE_DETECTION_YEUX_MIN;
   static const double PLAGE_OREILLES_MAX;
   static const double PLAGE_OREILLES_MIN;
   static const double CAPACITE_DETECTION_OREILLE_MAX;
   static const double CAPACITE_DETECTION_OREILLE_MIN;
   static const double MULTIPLICATEUR_NAGEOIRE_MAX;
   static const double REDUCTEUR_CARAPACE_MAX;
   static const double REDUCTEUR_CARAPACE_MORT_MAX;
   static const double CAMOUFLAGE_MAX;
   static const double CAMOUFLAGE_MIN;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
