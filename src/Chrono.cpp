#include "../include/Chrono.hpp"

/**
 * \file Chrono.cpp
 * \brief interface pour la class chrono en c++
 * \author CHARLOT Rodolphe
 * \version 1.0
 * \date 24 janvier 2016
 * \licence BSD
 *
 * Class destinée à simpifier l'utilisation de la class chrono dans std 
 * Elle permet notamment une pause et reset, et une précision variable
 * Elle peut être réutilisée sous les conditions de sa licence
 *
 */


using namespace std;

Chrono::Chrono(std::string precision,bool automatic_precision_change,float elapsed_time):_precision(precision),_auto(automatic_precision_change),_elapsed_time(elapsed_time),_isCalculing(false)
{}


void
Chrono::start()
{
    _isCalculing=true;
    _start = chrono::system_clock::now();

}

void
Chrono::stop()
{
    if(_isCalculing==true)
    {
        chrono::time_point<chrono::system_clock> end=chrono::system_clock::now();
        _isCalculing=false;
        int precision;
        if(_precision=="nanoseconds")
        {
            _elapsed_time+=chrono::duration_cast<chrono::nanoseconds>(end-_start).count();
            precision=0;
        }
        else if(_precision=="microseconds")
        {
            _elapsed_time+=chrono::duration_cast<chrono::microseconds>(end-_start).count();
            precision=1;
        }
        else if(_precision=="milliseconds")
        {
            _elapsed_time+=chrono::duration_cast<chrono::milliseconds>(end-_start).count();
            precision=2;
        }
        
        else if(_precision=="seconds")
        {
            _elapsed_time+=chrono::duration_cast<chrono::seconds>(end-_start).count();
            precision=3;
        }
        else
        {
            _elapsed_time+=chrono::duration_cast<chrono::milliseconds>(end-_start).count();
            precision=2;
        }
        
        if(_auto==true)
        {
        	while(_elapsed_time>1000 && precision < 3)
        	{
        		_elapsed_time/=1000;
        		precision+=1;
        	}
        	switch(precision)
        	{
        		case 0:_precision="nanoseconds";break;
        		case 1:_precision="microseconds";break;
        		case 2:_precision="milliseconds";break;
        		case 3:_precision="seconds";break;
        	}
        }
                                 
    }
    else
        cerr << "Le chrono n'a pas démarré, vous ne pouvez pas le stopper" << endl;
}
void
Chrono::reset()
{
    _elapsed_time=0;
}
float
Chrono::getDuration()
{
    return _elapsed_time;
}

