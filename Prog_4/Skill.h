

#ifndef Skill_h
#define Skill_h
#include "Creature.h"
#include <iostream>
using namespace std;
namespace laba4{
class Skill {
private:
    string name;
	int energy;
	int min_knowledge;
	int coefficient;
    Creature creature;
public:
    //constructors
    Skill():name(""),energy(0),min_knowledge(0),coefficient(0){
    }
    Skill(string name0, int energy0, int min_knowledge0, int coeficient0,const Creature &cr):name(name0),energy(energy0),min_knowledge(min_knowledge0),coefficient(coeficient0), creature(cr) {
      
    }
    Skill(const Skill&);//copying
    Skill(Skill&&);//moving
    //getters
    string get_name() const { return name;}
	int get_min_knowledge() const {return min_knowledge;}
	int get_coefficient() const {return coefficient;}
	int get_energy() const {return energy;}
    Creature get_creature () const {return creature;}
    //setters
    Skill& set_name(string name0) { name=name0; return *this;}
    Skill& set_min_knowledge(int min_knowledge0){min_knowledge=min_knowledge0; return *this;}
    Skill& set_coefficient(int coeficient0) {coefficient=coeficient0;return *this;}
    Skill &set_creature (Creature creature0)  {creature =creature0; return *this;}
    Skill& set_energy(int energy0){energy=energy0; return *this;}
    //methods
    Skill& operator =(const Skill&);
    friend ostream& operator <<(ostream& s, const Skill& sk);
};
}
#endif /* Skill_h */
