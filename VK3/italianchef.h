#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <string>
using namespace std;
#include "chef.h"

class ItalianChef: public Chef
{
public:
    ItalianChef(string chefName);
    ~ItalianChef();
    bool askSecret(string triedPassword,int flour,int water);

private:
    string password = "pizza";
    int flour;
    int water;
    int makepizza();


};

#endif // ITALIANCHEF_H
