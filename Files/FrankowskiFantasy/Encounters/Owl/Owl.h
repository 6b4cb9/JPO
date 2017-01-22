//Copyright by Jakub Gizicki
//This encounter is a meeteing with an Owl, the Magic Master. The Master lives in Old Magic Tree so it fits best to placed
//in a forest or other "wooden" location. Level 1 for Character avg lvl 11. You can increase your intelligence and charisma
// == increase your damage for MeeleAttack.

#ifndef OWL_H
#define OWL_H
#include"stdafx.h"
#include "..\..\Encounter.h"
using namespace std;
class Owl:public Encounter
{
    public:
        Owl();
        bool Proceed(Character* Adventurer);
        virtual ~Owl();

    protected:

    private:
        int menu;
};

#endif // ENCOUNTER_H
