
#include <stdio.h>
#include "Immoral_Troop.h"
namespace laba4 {
    Immoral_Troop::Immoral_Troop(int speed0, int experience0, int count0, Creature cr, School* sch, Coordinates p0):
    speed(speed0), initiative(false),
    experience(experience0),count(count0),creature(cr),ptr_school(sch),p(p0)
    {
        damage=cr.get_damage()*count;
        protection=cr.get_protection()*count;
        health=cr.get_health()*count;
        
    }
    
    Immoral_Troop::Immoral_Troop(const Immoral_Troop& tr):
    speed(tr.get_speed()), initiative(tr.get_initiative()),damage(tr.get_damage()),protection(tr.get_protection()),p(tr.get_p()),
    experience(tr.get_experience()),count(tr.get_count()),health(tr.get_health()),creature(tr.get_creature()),ptr_school(tr.get_ptr_school())
    {
    }
    
    Immoral_Troop:: Immoral_Troop(Immoral_Troop&& tr):speed(tr.get_speed()), initiative(tr.get_initiative()),damage(tr.get_damage()),protection(tr.get_protection()),p(tr.get_p()),
    experience(tr.get_experience()),count(tr.get_count()),health(tr.get_health()),creature(tr.get_creature()),ptr_school(tr.get_ptr_school()){
        Creature a;
        Coordinates p0(0,0);
        tr.set_count(0);
        tr.set_speed(0);
        tr.set_damage(0);
        tr.set_health(0);
        tr.set_creature(a);
        tr.set_ptr_school(nullptr);
        tr.set_p(p0);
    }
   Immoral_Troop& Immoral_Troop:: operator=(const Immoral_Troop& tr){
        speed=tr.get_speed();
        initiative=tr.get_initiative();
        damage=tr.get_damage();
        protection=tr.get_protection();
        experience=tr.get_experience();
        count=tr.get_count();
        health=tr.get_health();
        creature=tr.get_creature();
        p=tr.get_p();
        ptr_school=tr.get_ptr_school();
        return *this;
    }
    void Immoral_Troop::attack(Immoral_Troop& tr){//tr enemy troop??
        /*int attack=0;
        if (ptr_school->get_name()==tr.get_ptr_school()->get_school_dominant()) attack+=5;
        if (ptr_school->get_school_dominant()==tr.get_ptr_school()->get_name()) attack-=5;
        attack+=tr.get_health()+tr.get_protection()-damage;
        if (attack<0) attack=0;
        tr.set_health(attack);*/
        tr.take_damage(*this);
    }
    void Immoral_Troop:: take_damage(Immoral_Troop& tr){
        int taking_damage=0;
        if (ptr_school->get_name()==tr.get_ptr_school()->get_school_dominant()) taking_damage+=5;
        if (ptr_school->get_school_dominant()==tr.get_ptr_school()->get_name()) taking_damage-=5;
        taking_damage=health+protection-tr.get_damage()+taking_damage;
        if (health>=taking_damage){
            health=taking_damage;
            if (creature.get_health()!=1)
            ((health%2==0))? count=health/creature.get_health(): count=health/creature.get_health()+1;//уменьшение кол-во
            else count=health/creature.get_health();
        }
    }
    void Immoral_Troop:: move_troop(const char ch,int m,int n){
        if (ch=='W') ((p.y+1)<m-1) ? p.y++: p.y=m-1;
        if (ch=='D') ((p.x+1)<n-1) ? p.x++: p.x=n-1;
        if (ch=='S') ((p.y-1)>0) ? p.y--: p.y=0;
        if (ch=='A') ((p.x-1)>0) ? p.x--:p.x=0;
    }
}
