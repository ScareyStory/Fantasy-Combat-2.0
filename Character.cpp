/**************************************************************************
** Program Name: Character.cpp
** Name:         Story Caplain
** Date:         02/06/19
** Description:  This is the .cpp file for the Character class.
**               It is the parent class in the Fantasy Combat Game
**************************************************************************/
#include <iostream>
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

Character::Character(int atk, int def, int arm, int str) : 
  attack(atk), defense(def),  armor(arm), strength(str) {}

std::string Character::getName() { return name; }

void Character::setName(int type) { 
 
  if(type==1) {
    std::cout << "\nWhat would you like to name this Vampire?: ";
  }
  else if(type==2) {
    std::cout << "\nWhat would you like to name this Barbarian?: ";
  }
  else if(type==3) {
    std::cout << "\nWhat would you like to name these Blue Men?: ";
  }
  else if(type==4) {
    std::cout << "\nWhat would you like to name this Medusa?: ";
  }
  else if(type==5) {
    std::cout << "\nWhat would you like to name this Harry Potter?: ";
  }
  else {
    std::cout << "\nINVALID TYPE\n";
  }

  int val = 1;
  std::getline(std::cin,name);
  while(val==1) {
    if(std::cin.fail() || name.length() > 15) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cout << "\nOops! Invalid input." << std::endl;
      std::cout << "Enter a name 15 characters or less: ";
      std::cin  >> name;
    }   
    else if(!std::cin.fail()) {
      val = 0;
    }   
  }
}

int Character::getAttack() { return attack; }

void Character::setAttack(int a) { attack = a; }


int Character::getDefense() { return defense; }

void Character::setDefense(int d) {defense = d;}


int Character::getArmor() { return armor; }

int Character::setArmor(int damage) { 
 
  //If attack doesn't destroy armor, reduce armor 
  if(armor >= damage) {
    armor -= damage;
    return 0;
  }
  //Else if attack destroys armor, or no armor, return damage
  //to be deducted from strength
  else {
    int excess = damage - armor;
    armor = 0;
    return excess;
  }
}


int Character::getStrength() { return strength; }

Character::~Character() {}

////////// QUEUE FUNCTIONS //////////

Queue::Queue() {head =  NULL;}

//Checks if queue is empty returns true if empty
bool Queue::isEmpty() {

  //if head points to null, list is empty, return true
  
  if(head==NULL) {return true;}

  else {return false;}
}

//Creates a new Character node at the back of the character Queue
void Queue::addBack(int choice) {

  //check if list is empty
  bool check = isEmpty();

  //if it is empty
  if(check==true) {

    switch(choice) {

      case 1:
        head = new Vampire(0,0,1,18);
        head->setName(1);
        break;
      case 2:
        head = new Barbarian(0,0,0,12);
        head->setName(2);
        break;
      case 3:
        head = new BlueMen(0,0,3,12);
        head->setName(3);
        break;
      case 4:
        head = new Medusa(0,0,3,8);
        head->setName(4);
        break;
      case 5:
        head = new HarryPotter(0,0,0,10);
        head->setName(5);
        break;
      default: std::cout <<"\n\n 1: Error, default case reached\n\n";
    }

    //set next and prev
    head->next = head;
    head->prev = head;
  }
  
  //if not empty list
  else {
    //Point head to new tail
    Character *tail = head->prev;

    //Assign pointer to parent object to a new child object
    Character *c; 
    switch(choice) {

      case 1:
        c = new Vampire(0,0,1,18);
        c->setName(1);
        break;
      case 2:
        c = new Barbarian(0,0,0,12);
        c->setName(2);
        break;
      case 3:
        c = new BlueMen(0,0,3,12);
        c->setName(3);
        break;
      case 4:
        c = new Medusa(0,0,3,8);
        c->setName(4);
        break;
      case 5:
        c = new HarryPotter(0,0,0,10);
        c->setName(5);
        break;
      default: std::cout <<"\n\n 2: Error, default case reached\n\n";
        c = new Vampire(0,0,1,18);
    }

    //place c at tail
    c->next = head;

    c->prev = tail;

    head->prev = c;

    tail->next = c;
  }
}

void Queue::getFront() {

  bool check = isEmpty();

  if(check==false) {
    std::cout << "\n\nTop of line up is: " << head->name << "\n\n";
  }
  else { std::cout << "\n\nNo one on team!\n\n"; }
}

//remove front will instead put the loser in a new loser queue
void Queue::removeLoser(Queue *losers) {

  //if one element
  if(head==(head->prev) && head==(head->next)) {

    bool loserCheck = losers->isEmpty();

    //if losing queue is empty
    if(loserCheck==true) {

      //make loser queue the first losing character
      losers->head = head;

      losers->head->next = head;
      losers->head->prev = head;
    }
    
    //if loser queue isn't empty
    else {

      //Create a pointer to the loser queue's tail
      Character *tail = losers->head->prev;

      //Point head's next to the head of loser queue
      head->next = losers->head;

      //Point head's prev to the tail of loser queue
      head->prev = losers->head->prev;

      //link back
      losers->head->prev = head;

      //link back
      tail->next = head;
    }

    //set head of now empty team list to null
    head = NULL;
    delete head;
  }

  //else at least two elements
  else {

    //store result of isEmpty in loserCheck
    bool loserCheck = losers->isEmpty();
    
    //if losing queue is empty
    if(loserCheck==true) {

      losers->head = head;
    
      //New pointer to Character temp points to head
      Character *temp = head;

      //Set head to point to point to next node
      head = head->next;

      //Set old head's prev pointer to temp's prev pointer
      head->prev = temp->prev;

      //Temp's prev's next points to the old head
      //Make it point to the new head
      temp->prev->next = head;

      //Reset losing character's next and prev pointers
      losers->head->next = losers->head;
      losers->head->prev = losers->head;

    }
    
    //if loser queue isn't empty
    else {

      //Create a pointer to the losers queue's tail
      Character *Ltail = losers->head->prev;
      Character *oldHead = head;

      //rotate head
      head = head->next;

      //point tail to new head
      head->prev->prev->next = head;

      //make new head's prev the tail
      head->prev = head->prev->prev;

      //losing queue's tail' next points to old head
      Ltail->next = oldHead;

      //Point old head back to losing tail
      oldHead->prev = Ltail;

      //Point old head's next to head of losing queue
      oldHead->next = losers->head;

      //Point losing queue's head's prev to oldHead
      losers->head->prev = oldHead;

    }
    //Deallocate the memory used by temp
    //delete temp;
  }
}

//Prints out names of characters
void Queue::printQueue() {

  //check if list is empty
  bool check = isEmpty();

  //if not empty
  if(check==false) {

    //create temporary node
    Character* temp = head->next;

    //While the temp node's next pointer is not pointing to the head of the
    //list (aka while the list has not reached the beginning again)
    std::cout << head->name << "\n";

    while(temp != head) {

      //output that character's name 
      std::cout << temp->name << "\n";

      //set temp to point to the next character
      temp = temp->next;
    }
  }
  //Else if list is empty, tell user
  else {
    std::cout << "\nNo players remain on this team...\n";
  }
}

//Deconstructor
Queue::~Queue() {

  bool check = isEmpty();

  while(check==false) {

    //if one element in the list
    //we check this by seeing if head prev and next pointer point to itself
    if(head==head->prev && head==head->next) {
      delete head;
      head = NULL;
    }

    //else if at least two elements
    else {
      //New pointer to Character temp points to head
      Character *temp = head;

      //Set old head's next pointer to point to itself
      head = head->next;

      //Set old head's prev pointer to temp's prev pointer
      head->prev = temp->prev;

      //Temp's prev's next points to the old head
      //Make it point to the new head
      temp->prev->next = temp->next;

      //Deallocate the memory used by temp
      delete temp;
    }
    //check again if list is empty
    //if it isn't check stays false and loop goes again
    //if list is empty than deconstructor ends
    check = isEmpty();
  }
}
