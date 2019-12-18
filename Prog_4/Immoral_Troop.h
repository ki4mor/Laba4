
#ifndef Immoral_Troop_h
#define Immoral_Troop_h
#include "School.h"
using namespace std;
namespace laba4{
    struct Coordinates{
        int x;
        int y;
        Coordinates(int x0,int y0): x(x0),y(y0){}
		Coordinates() : x(0), y(0) {}
    };
  class Immoral_Troop{
    protected:
		int speed;
        bool initiative;
		int damage;
		int protection;
		int experience;
		int count;
		int health;
        Creature creature;
        School *ptr_school;
        Coordinates p;
      
    public:
        //getters
		int get_speed() const {    return speed;}
        bool get_initiative()const {    return initiative;}
		int get_damage() const{ return damage; }
		int get_protection() const{ return protection; }
		int get_experience() const{ return experience; }
		int get_count() const { return count; }
		int get_health() const {return health;}
       Coordinates get_p() const {return p;}
        Creature get_creature()const { return creature; }
        School* get_ptr_school()const { return ptr_school; }

        //setters
        Immoral_Troop& set_speed(int a) {  speed=a; return *this; }
        Immoral_Troop& set_initiative(bool a) {  initiative = a; return *this; }
        Immoral_Troop& set_damage(int a) {  damage = a; return *this; }
        Immoral_Troop& set_protection(int a) {  protection = a; return *this; }
        Immoral_Troop& set_experience(int a) {  experience = a; return *this; }
        Immoral_Troop& set_count(int a) {  count = a; return *this; }
        Immoral_Troop& set_health(int a){health=a; return *this; }
       Immoral_Troop& set_p(Coordinates p0){p=p0; return *this;}
        Immoral_Troop& set_creature(Creature a) {creature=a; return *this;}
        Immoral_Troop& set_ptr_school(School* a){ptr_school=a; return *this;}
        //constructors
      Immoral_Troop():speed(0),initiative(false),damage(0),protection(0),experience(0),count(0),health(0), ptr_school(nullptr),p(0,0){
      }
      Immoral_Troop(int speed0, int experience0, int count0, Creature cr, School* sch,Coordinates p0);
      Immoral_Troop(const Immoral_Troop&);//copying
      Immoral_Troop(Immoral_Troop&&);//moving
      virtual ~Immoral_Troop(){}
        //methods
       virtual Immoral_Troop& operator =(const Immoral_Troop&);
        virtual void attack(Immoral_Troop&);
        virtual void take_damage(Immoral_Troop&);
      virtual void move_troop(const char ch,int,int);

    };
}


#endif /* Troop_h */
