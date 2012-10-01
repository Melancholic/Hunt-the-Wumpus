#ifndef ROOM_H
#define ROOM_H
//enum typeroom{none, deep, dust, bat, shelest, vampus, hrap,protag};
struct room{
  room *prew;
  room *next1;
  room *next2;
  //typeroom status;
  //bool  none;
  bool deep;
  bool wind;
  bool bat;
  bool shelest;
  bool Vampus;
  bool hrap;
  bool protag;
  int number;
  room();

  //room();
  //~room();
  
  
};
#endif
