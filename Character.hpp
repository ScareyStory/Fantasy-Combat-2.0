/**************************************************************************
** Program Name: Character.hpp
** Name:         Story Caplain
** Date:         02/20/19
** Description:  This is the implemntation file for the Character class.
**               It is the parent class in the Fantasy Combat Game
**************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

struct Queue;

class Character {

private:

protected:

  //Character's name
  std::string name;

  //Character attributes
  int attack;
  int defense;
  int armor;
  int strength;

  //Pointers to next and previous nodes in list
  //Character *next;
  //Character *prev;

public:

  //Pointers to next and previous nodes in list
  Character *next;
  Character *prev;
  
  Character(int, int, int, int);

  virtual int attacking() = 0;

  virtual int defending() = 0;

  std::string getName();
 
  int getAttack();

  int getDefense();

  int getArmor();

  int getStrength();
  
  void setAttack(int);

  void setDefense(int);

  int setArmor(int);

  virtual void setStrength(int) = 0;

  virtual void recover() = 0;

  void setName(int);

  virtual ~Character();

  friend Queue;

};

////////// QUEUE CLASS //////////
struct Queue {

  //points to the head of a queue
  Character *head;

  //Constructor 
  Queue();

  //Checks if the queue is empty, returns true if empty
  bool isEmpty();

  //Takes a user-inputted character choice 
  //Creates a Character with user-inputted choice
  //Then appends it to the back of the list.
  void addBack(int);

  //Returns the value of the node at the front of the queue.
  void getFront();

  //Removes the front Character of the queue and moves to loser queue.
  void removeLoser(Queue*);

  //Traverses through the queue from head using next pointers 
  //Then prints the values of each QueueNode in the queue.
  void printQueue();

  //Deconstructor
  ~Queue();

};

#endif
