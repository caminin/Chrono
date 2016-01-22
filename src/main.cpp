#include "../include/Chrono.hpp"
#include <iostream>

int main()
{
    Chrono c(0,"microseconds");
    
   c.start();
   for(float i=0;i<5000000;i++)
   {
       //j'attends un peu
   }
   c.stop();
   std::cout << c.getDuration() << " microseconds" << std::endl;
   return 0;
}
