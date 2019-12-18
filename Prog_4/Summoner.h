

#ifndef Summoner_h
#define Summoner_h
#include "Immoral_Troop.h"
#include <vector>
#include <iostream>
using namespace std;
namespace laba4{
    class Summoner  {
    private:
        string name;
        bool initiative;
        int health;
        const int max_health=1000;
		int energy;
        const int max_energy=100;
		int experience;
		int accumulation_coeficient;
        vector<Immoral_Troop*> troops;
        vector<pair<string,unsigned>> knowledge;
        Coordinates p;
    public:
        //getters
       string get_name()  const  {return name;}
       bool get_initiative()  const { return initiative;}
	   int get_max_health()  const {return max_health;}
	   int get_health() const {return health; }
	   int get_max_energy()  const  {return max_energy;}
	   int get_energy()  const  {return energy;}
	   int get_accumulation_coeficient()  const  {return accumulation_coeficient;}
	   int get_experience()  const  {return experience;}
        Immoral_Troop* get_troops   (unsigned k) const {return troops[k];}
        pair<string,unsigned> get_knowledge (int k) const {return knowledge[k];}
		int get_size_of_knowledge() const {return knowledge.size();}
		int get_size_of_troops() const { return troops.size();}
        Coordinates get_coordinates() const { return p;}
        //setters
        Summoner& set_name(string nm){ name=nm; return *this;}
        Summoner& set_initiative(bool init){initiative=init; return *this; }
        Summoner& set_health(int heal){health=heal; return *this;}
        Summoner& set_energy(int energ){energy=energ;return *this;}
        Summoner& set_accumulation_coeficient(int accum){accumulation_coeficient=accum; return *this; }
        Summoner& set_experience(int exper){experience=exper; return *this;}
        Summoner& set_troops(Immoral_Troop *tp){
            troops.push_back(tp);
            return *this; }
        Summoner& set_knowledge(const pair<string,unsigned> &aPair){knowledge.push_back(aPair); return *this; }
		Summoner& set_coordinates(Coordinates p0) { p.x = p0.x; p.y = p0.y;  return *this; }

        //constructors
        Summoner():initiative(0), health(0),energy(0), experience(0), accumulation_coeficient(0),name(""),p(0,0){};
		Summoner(string name0, bool initiative0, int health0, int energy0, int experience0, int accumulation_coeficient0, vector<Immoral_Troop*> troops0, vector < pair < string, unsigned>> knowledge0, Coordinates p0);
        Summoner(const Summoner &sm);//copying constructor
        Summoner( Summoner &&sm);//moving constructor
        ~Summoner(){
            troops.clear();
            initiative=0;
            health=0;
            energy=0;
            experience=0;
            accumulation_coeficient=0;
            knowledge.clear();
            name="";
            cout<<"***Destructor_Summoner used***"<<endl;
        }
        
        //methods
        friend ostream& operator <<(ostream&,const Summoner&);
        Summoner & operator =(const Summoner&s1);
        void accumulate_energy();
        void upschool(string str, int exp);
        void take_damage( Immoral_Troop& enemy);
        void summon(Immoral_Troop *);
        void change_initiative();
    };
}


#endif /* Summoner_h */
