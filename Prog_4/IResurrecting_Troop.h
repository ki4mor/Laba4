

#ifndef IResurrecting_Troop_h
#define IResurrecting_Troop_h
#include "Immoral_Troop.h"
namespace laba4 {
    class IResurrecting_Troop:public Immoral_Troop{
    private:
		int dead_creatures;
    public:
        //getters
        unsigned get_dead_creatures() const {return dead_creatures;}
        //setters
        IResurrecting_Troop& set_dead_creatures(int d_cr){
            dead_creatures=d_cr;
            return *this;
        }
        //constructors
     IResurrecting_Troop():Immoral_Troop(){dead_creatures=0;}//default construction
        IResurrecting_Troop(int dead_creatures0, int speed0, int experience0, int count0, Creature cr, School* sch,Coordinates p0):
        Immoral_Troop(speed0,experience0, count0,cr, sch, p0){
            dead_creatures=dead_creatures0;
        }
        IResurrecting_Troop(const IResurrecting_Troop&);//copying
        IResurrecting_Troop& operator=(const IResurrecting_Troop&);
       void resurrect_creatures();
    };
}

#endif /* Resurrecting_Troop_h */
