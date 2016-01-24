#include "../include/Chrono.hpp"
#include <iostream>

/**
 * \file main.cpp
 * \brief main avec exemple de Chrono
 * \author CHARLOT Rodolphe
 * \version 1.0
 * \date 24 janvier 2016
 *
 * main destiné à expliquer brièvement l'utilisation du chrono
 *
 */

int main()
{
    Chrono c(0,"microseconds");// déclaration du chrono avec un temps de départ de 0 et une précision en microseconds
    
   c.start();//démarrage du chrono
   for(float i=0;i<5000000;i++)
   {
       //j'attends un peu
   }
   c.stop();//arrêt du chrono
   std::cout << c.getDuration() << " microseconds" << std::endl;//on affiche de résultat du chrono
   return 0;
}
