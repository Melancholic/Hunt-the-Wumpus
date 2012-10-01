#ifndef GAME_H
#define GAME_H
#include"room.h"
extern const int size;

struct pl{
  int strel;
  bool dead;
  int pos;
  int pred;

  pl();
  bool vistrel();
  
};

class game{
  room *structure;
  pl player;
  int pred;
  int indVampus;
  
public:
  game();
  void user();
  ~game();
  void clearPlayer();
  int GetIndPred();
  int getInd(int a);
  int getindexPlayer();
  bool StrProc();
  void addVantus(int i);
  void clearHrap();
  int vamp();
};

  
#endif