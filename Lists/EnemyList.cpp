#include "EnemyList.h"
#include <algorithm>

Enemy* EnemyList::operator[](int i)
{
    try{
        if (i < int(getSize())){
            return vector[i];
        }
        else throw 1255;
    }
    catch (unsigned int warning){
        if (warning == 1255){
            std::cerr << "Tentou acessar posicao inacessivel do vetor." << std::endl;
            exit(1255);
        }
    }
    return 0;
}
