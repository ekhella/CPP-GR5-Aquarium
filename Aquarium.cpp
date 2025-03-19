#include "Aquarium.h"

#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {
      int bestiole_gregaire = 0;
      int bestiole_peureuse = 0;
      int bestiole_prevoyante = 0;
      int bestiole_kamikaze = 0;
      int bestiole_multi = 0;

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      // Définir les stratégies :
      
      std::cout<<"Bestioles Kamikazes: "<<bestiole_kamikaze<<std::endl;
      std::cout<<"Bestioles Peureuses: "<<bestiole_peureuse<<std::endl;
      std::cout<<"Bestioles Prevoyantes: "<<bestiole_peureuse<<std::endl;
      std::cout<<"Bestioles Gregaires: "<<bestiole_gregaire<<std::endl;
      std::cout<<"Bestioles avec comportement multiple: "<<bestiole_multi<<std::endl;
      std::cout<<"Bestioles totales: "<<total<<std::endl; // À définir
      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}
