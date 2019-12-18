

#ifndef Ordinary_Troop_h
#define Ordinary_Troop_h
#include "Immoral_Troop.h"
namespace laba4 {
class Ordinary_Troop : public Immoral_Troop{
protected:
    int moral;
public:
    //constructors
    Ordinary_Troop():Immoral_Troop(){moral=0;}//default
    Ordinary_Troop(int moral0, int speed0, int experience0, int count0, Creature cr, School* sch,Coordinates p0):
    Immoral_Troop(speed0,experience0,count0,cr,sch,p0){
        moral=moral0;
    }
    Ordinary_Troop(const Ordinary_Troop& O_Troop);
   
    //setters
    Ordinary_Troop& set_moral(int a) { moral = a; return *this; }
    //getters
	int get_moral() const {return moral;};
    //methods
    Ordinary_Troop& operator=(const Ordinary_Troop& O_Troop);
    void upmoral();
    void balance_moral();
    void attack(Ordinary_Troop&);
    void take_damage(Ordinary_Troop&);
   void move_troop(const char ch,int,int);
};
}
#endif /* Ordinary_Troop_h */
