#ifndef CHEF_H
#define CHEF_H
#include <string>
using namespace std;
class Chef
{
public:
    Chef(string name);
    ~Chef();
    string getName();
    int makeSalad(int ainekset);
    int makeSoup(int ainekset);

protected:
    string chefName;

};

#endif // CHEF_H
