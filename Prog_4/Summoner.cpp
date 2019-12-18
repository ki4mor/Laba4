
#include <iostream>
using namespace std;
#include <stdio.h>
#include "Summoner.h"
namespace laba4{

	Summoner::Summoner(string name0, bool initiative0, int health0, int energy0, int experience0, int accumulation_coeficient0, vector<Immoral_Troop*> troops0, vector < pair < string, unsigned>> knowledge0, Coordinates p0) {
		name = name0;
		initiative = initiative0;
		energy = energy0;
		health = health0;
		experience = experience0;
		accumulation_coeficient = accumulation_coeficient0;
		for (int i = 0; i < troops0.size(); i++) {
			troops.push_back(troops0[i]);
		}
		for (int i = 0; i < knowledge0.size(); i++) {
			knowledge.push_back(knowledge0[i]);
		}
		p = p0;
	}


    Summoner:: Summoner(const Summoner& sm):
    name(sm.get_name()),p(sm.get_coordinates()), initiative(sm.get_initiative()), health(sm.get_health()),energy(sm.get_energy()), experience(sm.get_experience()), accumulation_coeficient(sm.get_accumulation_coeficient()),max_health(sm.get_max_health()),
      max_energy(sm.get_max_energy()){
          for (int i=0;i<sm.get_size_of_knowledge();i++){
              knowledge.push_back(sm.get_knowledge(i));
          }
          for (int i=0;i<sm.get_size_of_troops();i++){
              troops.push_back(sm.get_troops(i));
          }
                cout << "*****Copying constructor used*****" << endl;
    }
    Summoner:: Summoner(Summoner&& sm): p(sm.get_coordinates()),name(sm.get_name()), initiative(sm.get_initiative()), health(sm.get_health()),energy(sm.get_energy()), experience(sm.get_experience()), accumulation_coeficient(sm.get_accumulation_coeficient()),max_health(sm.get_max_health()),
    max_energy(sm.get_max_energy()),troops(sm.troops),knowledge(sm.knowledge){
        sm.knowledge.clear();
        sm.troops.clear();
        sm.set_name("");
        sm.set_energy(0);
        sm.set_health(0);
        sm.set_experience(0);
        sm.set_initiative(0);
        sm.set_accumulation_coeficient(0);
        cout << "*****Moving constructor used*****" << endl;
    }
    ostream& operator <<(ostream& s,const Summoner& a){
        cout<<"Name: "<<a.name<<endl;;
        cout<<"Initiative: "<<a.initiative<<endl;
        cout<<"Max health: "<<a.max_health<<endl;
        cout<<"Health: "<<a.health<<endl;
        cout<<"Max energy: "<<a.max_energy<<endl;
        cout<<"Energy: "<<a.energy<<endl;
        cout<<"Experience: "<<a.experience<<endl;
        cout<<"Accumulation coefficient: "<<a.accumulation_coeficient<<endl;
        cout<<"School  knowledge"<<endl;
        for(int i=0;i<a.knowledge.size();i++){
            cout<<a.knowledge[i].first<<" "<<a.knowledge[i].second<<endl;
        }
       for(int i=0;i<a.troops.size();i++){
            cout<<a.troops[i]<<endl;
        }
        return s;
    }
    Summoner& Summoner:: operator=(const Summoner& s){
        name=s.get_name();
        initiative=s.get_initiative();
        health=s.get_health();
        energy=s.get_energy();
        experience=s.get_experience();
        accumulation_coeficient=s.get_accumulation_coeficient();
		p = s.get_coordinates();
        for (int i=0;i<s.get_size_of_knowledge();i++){
			knowledge.push_back(s.get_knowledge(i));
        }
        for (int i=0;i<s.get_size_of_troops();i++){
			troops.push_back(s.get_troops(i));
        }
        return *this;
    }
    void Summoner::accumulate_energy() {
        energy +=accumulation_coeficient * 20;
    }
    
    void Summoner::upschool(string str, int exp) {
        int i = 0;
        while (str != knowledge[i].first) {
            ++i;
        }
        knowledge[i].second += exp;
    }
    
    
    void Summoner::take_damage(Immoral_Troop& enemy) {
        int taking_damage;
        taking_damage=health-enemy.get_damage();
        if (taking_damage<0) taking_damage=0;
        health=taking_damage;
    }
    
   void Summoner::summon(Immoral_Troop *tr) {//передается собранный отряд со значения школ криче и тд
       troops.push_back(tr);
   }
    void Summoner::change_initiative(){
        for (int i=0;i<troops.size();i++){
                troops[i]->set_initiative(!troops[i]->get_initiative());
        }
        
    }
}
