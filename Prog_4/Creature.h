

#ifndef Creature_h
#define Creature_h
#include <iostream>
using namespace std;
namespace laba4{
class Creature {
private:
    string name;
    unsigned damage;
    unsigned protection;
    unsigned health;
public:
    //getters
    string get_name()  const{return name;}
	int get_damage() const {return damage;}
	int get_protection()  const{return protection;}
	int get_health ()const {return health;}
    //setters
    Creature& set_name(string name0){ name=name0; return *this; }
    Creature& set_damage(int damage0){damage=damage0; return *this;}
    Creature& set_protection(int protection0){protection=protection0; return *this;}
    Creature& set_health (int health0){health=health0; return *this;}
    //constructors
    Creature():name(""), damage(0),protection(0),health(0){}
    Creature(string name0, int damage0, int protection0, int health0 );
    Creature(const Creature &cr);//copying construction
    Creature (Creature &&cr);//moving construction
    //methods
    
    Creature& operator =(const Creature& cr);
    friend ostream& operator <<(ostream& s,const Creature& cr);
};
}
#endif /* Creature_h */
