/**************************************************************************
** Program Name: Vampire.hpp
** Name:         Story Caplain
** Date:         02/06/19
** Description:  This is the .cpp file for the Vampire class.
**               It handles its specific attack and defend functions.
**************************************************************************/
#include <iostream>
#include <random>
#include "Vampire.hpp"

Vampire::Vampire(int atk, int def, int arm, int str) : 
  Character(atk,def,arm,str) {}

//returns a value 1 to 12
int Vampire::attacking() {

  int die = rand();

  die = (die % 12) + 1;

  std::cout << "\n"<<name<<" attacks with a roll of " << die << std::endl;

  return die;

}

//50% chance of returning a value 1 to 6
//50% chance of charm occurring, which bumps defense to an unbeatable number
int Vampire::defending() {

  int charm = rand();

  //if charm is 1, no charm
  //if charm is 2, charm
  charm = (charm % 2) + 1;

  if(charm==1) {

    int die = rand();

    die = (die % 6) + 1;

    std::cout <<"\n"<<name<<" defends with a roll of " << die << std::endl;

    return die;

  }
  
  else {

    std::cout << "\n"<<name<<" has charmed its opponent!\n";
    std::cout <<name<<" takes no damage this round...\n";

    return 1000;

  }
}

//Updates strength value
void Vampire::setStrength(int s) {

  strength -= s;

  if(strength <= 0 && strength > -100) {
    strength = 0;
    std::cout << "\n"<<name<<" stumbles backwards and falls to its knees";
    std::cout << "\n5000 years of life looks to have reached its end...\n";
    std::cout << name<< " screams out and melts into black smoke!\n";
  }
  else if(strength <= -100) {
    strength = 0;
    std::cout << "\n"<<name<<" feels his body start to harden to stone...";
    std::cout << "\n"<<name<<"  leaps into the air and turns into a bat!\n";
    std::cout << "...But it is too late. The bat turns to stone!\n";
    std::cout << "The bat of stone falls to the ground and shatters...\n";
  }
}

//Lets a winning vampire recover some health
void Vampire::recover() {
  
  std::cout << std::endl;
  std::cout<<name<<" drains its victim of blood, recovering strength!";

  int recovery = rand();

  int diff = 18 - getStrength();

  //if the vamp actually took damage
  if(diff > 0) {

    recovery = (recovery % diff) + 1;

    strength += recovery;

    std::cout << std::endl;
    std::cout <<name<<" recovered "<<recovery<<" strength points!\n";
  }
  
  //vamp took no damage
  else {
    std::cout << std::endl;
    std::cout<<name<<" is at full strength!\n";
  }
}
