#include"game.h"
#include<iostream>
#include<stdlib.h>
inline int randvalue(int max, int min);
inline int get(int *a);
inline void change(int a, int b);
const int size=20;
const int min=0;
const int max=19;
game::game(){
 structure=new room[size];
  //
  {
  structure[0].prew=&structure[15];
  structure[0].next1=&structure[5];
  structure[0].next2=&structure[1];
  
  structure[1].prew=&structure[0];
  structure[1].next1=&structure[6];
  structure[1].next2=&structure[2];
  
  structure[2].prew=&structure[1];
  structure[2].next1=&structure[7];
  structure[2].next2=&structure[3];
  
  structure[3].prew=&structure[2];
  structure[3].next1=&structure[8];
  structure[3].next2=&structure[4];
  
  structure[4].prew=&structure[3];
  structure[4].next1=&structure[9];
  structure[4].next2=&structure[14];
  
  structure[5].prew=&structure[0];
  structure[5].next1=&structure[10];
  structure[5].next2=&structure[6];
  
  structure[6].prew=&structure[5];
  structure[6].next1=&structure[1];
  structure[6].next2=&structure[7];
  
  structure[7].prew=&structure[6];
  structure[7].next1=&structure[2];
  structure[7].next2=&structure[8];
  
    structure[8].prew=&structure[7];
  structure[8].next1=&structure[3];
  structure[8].next2=&structure[9];
  
    structure[9].prew=&structure[8];
  structure[9].next1=&structure[4];
  structure[9].next2=&structure[19];
  
    structure[10].prew=&structure[5];
  structure[10].next1=&structure[11];
  structure[10].next2=&structure[15];
  
    structure[11].prew=&structure[10];
  structure[11].next1=&structure[12];
  structure[11].next2=&structure[16];
  
    structure[12].prew=&structure[11];
  structure[12].next1=&structure[13];
  structure[12].next2=&structure[17];
  
    structure[13].prew=&structure[12];
  structure[13].next1=&structure[18];
  structure[13].next2=&structure[14];
  
    structure[14].prew=&structure[13];
  structure[14].next1=&structure[19];
  structure[14].next2=&structure[4];
  
    structure[15].prew=&structure[0];
  structure[15].next1=&structure[10];
  structure[15].next2=&structure[16];
  
    structure[16].prew=&structure[15];
  structure[16].next1=&structure[11];
  structure[16].next2=&structure[17];
  
    structure[17].prew=&structure[16];
  structure[17].next1=&structure[12];
  structure[17].next2=&structure[18];
  
    structure[18].prew=&structure[17];
  structure[18].next1=&structure[13];
  structure[18].next2=&structure[19];
  
    structure[19].prew=&structure[18];
  structure[19].next1=&structure[9];
  structure[19].next2=&structure[14];
  }

  int *array=new int[size];
  for(int i=0;i<size;i++)array[i]=i+1;
  for(int i=0;i<size;i++){
    structure[i].number=get(array);
}
  delete[] array;
//   std::cout<<structure[8].number;
//   std::cout<<structure[7].next2->number;
  structure[getInd(player.pos)].protag=true;
  int tmp;
  for (int i =0; i<4;i++){
    do{
     tmp=randvalue(min,max);
    }while(structure[tmp].deep==true || structure[tmp].bat==true ||structure[tmp].protag==true); 
    structure[tmp].deep=true;
    structure[tmp].next1->wind=true;
    structure[tmp].next2->wind=true;
    structure[tmp].prew->wind=true;
    
    do{
     tmp=randvalue(min,max);
    }while(structure[tmp].deep==true || structure[tmp].bat==true);
        structure[tmp].bat=true;
	structure[tmp].next1->shelest=true;
	structure[tmp].next2->shelest=true;
	structure[tmp].prew->shelest=true;
  }
  
      do{
    tmp=randvalue(min,max);
    }while(structure[tmp].deep==true || structure[tmp].bat==true);
    addVantus(tmp);

//   for(int i=0;i<size;i++){
//   if(structure[i].deep==true)std::cout<<"\nВампус в"<<i+1<<"\n";
// }
    

}

void game::addVantus(int tmp){
    structure[tmp].Vampus=true;
    structure[tmp].next1->hrap=true;
    structure[tmp].next2->hrap=true;
    structure[tmp].prew->hrap=true;
    indVampus=tmp;
}

void change(int a, int b){
  int tmp;
  tmp=a;
  a=b;
  b=tmp;
}
game::~game(){
  delete[] structure;
}
int randvalue(int min, int max){
  return(rand()%(max+1-min)+min);
}
int get(int *a){
  int s,ind;
  do{
    ind=randvalue(0,19);
    s=a[ind];
    if(s!=0)a[ind]=0;
  }while(s==0);
  return s;
}

pl::pl(){
  strel=5;
  dead=false;
  //pos=randvalue(1,20);
   pred=0;
}


bool pl::vistrel(){
  strel--;
  if (strel>0) return true;
  return false;
}

void game::clearPlayer(){
  for(int i=0;i<size;i++){
    structure[i].protag=false;
  }
}

void game::clearHrap(){
  for(int i=0;i<size;i++){
    structure[i].hrap=false;
  }
}

int game::GetIndPred(){
  for(int i=0;i<size;i++){
    if(structure[i].protag==true)return i;else return 0;
  }
}

int game::getInd(int a){
  for(int i=0;i<size;i++){
    if(structure[i].number==a){return i;}
  }
}
int game::getindexPlayer(){
  for(int i=0;i<size;i++){
    if(structure[i].protag){return i;}
  }
}

void game::user(){
  int menu,room1,room2,room3,t,tmp;
  bool strelba;
  do{
  tmp=randvalue(1,20);
  //std::cout<<"\nerr";
  }while(structure[getInd(tmp)].bat || structure[getInd(tmp)].deep || structure[getInd(tmp)].Vampus);
  player.pos=tmp;
//   for(int i= 0;i<size;i++){
//     std::cout<<"  "<<structure[i].number<<" ";
//   }
  std::cout<<"\nОхота на Вампуса\n";
  do{
    if(player.pred!=0)std::cout<<"\nВы покинули комнату:"<<player.pred;
    std::cout<<"\nВы находитесь в комнате: "<<player.pos;
    //player.pred=GetIndPred();
    std::cout<<"\n";
    clearPlayer();
    //structure[getInd(player.pred)].protag=false;
    structure[getInd(player.pos)].protag=true;
    t=getindexPlayer();
    if(structure[/*getInd(player.pos)*/t].shelest==true)std::cout<<"\n Я слышу шелест летучих мышей";
    if(structure[t].hrap==true){
      std::cout<<"\n Я слышу храп Вампуса";
      strelba=true;}else strelba=false;
    if(structure[t].wind==true)std::cout<<"\n Я чувствую ветер из подземной пропасти";
    room1=structure[t].next1->number;
    room2=structure[t].next2->number;
    room3=structure[t].prew->number;
    std::cout<<"\n";
    std::cout<<"\n 1. Вы можете перейти в комнату: ";
    std::cout<< /*getInd(player.pos)*/ room3<<"\n 2. Вы можете перейти в комнату "<<room1;
    std::cout<<"\n 3. Вы можете перейти в комнату: " << room2<<" \n"/*<<vamp()<<"  "*/;
    if(strelba){std::cout<<" 4.  Сделать выстрел: \n";}
    std::cin>>menu;
    
        if(strelba){
      switch(menu){
       case 1:{
	player.pred=player.pos;
	player.pos=(room3);};break;
      case 2:{
	player.pred=player.pos;
	player.pos=(room1);};break;
      case 3:{
	player.pred=player.pos;
	player.pos=(room2);};break;
      case 4:{
	if(StrProc()){
	  std::cout<<"\n Вы убили Вампуса!\n";
	  return;
	}else{
	  std::cout<<"\nВыстрел неудался!";break;};};
	default:{std::cout<<"Err Input Data\n";return;}
    }
    }else{
   
    switch(menu){
      case 1:{
	player.pred=player.pos;
	player.pos=(room3);};break;
      case 2:{
	player.pred=player.pos;
	player.pos=(room1);};break;
      case 3:{
	player.pred=player.pos;
	player.pos=(room2);};break;
	
      default:{std::cout<<"Err Input Data\n";return;}
    }
     if (structure[getInd(player.pos)].deep==true){
       std::cout<<"\nВы разбились, упав с большой высоты";
       player.dead=true; break;}
     if (structure[getInd(player.pos)].Vampus==true){
       std::cout<<"\nВас постигла ужасная участь, разбудив Вампуса";
       player.dead=true; break;}
       if (structure[getInd(player.pos)].bat==true){
       std::cout<<"\nЛетучие мыши Вас телепартировали\n";
       player.pos=randvalue(1,20);
	 if (structure[getInd(player.pos)].Vampus==true){
	   player.dead=true;
        std::cout<<"\nЛетучие мыши уронили Вас прямо на Вампуса. Он был злой  и голодный.";
      }
       }
     }
  
  }while(!player.dead);
  std::cout<<"\nGame Over !!! }8@ \n";
}

bool game::StrProc(){
  int number,slv;
  std::cout<<"\nВведите номер комнаты ";
  std::cin>>number;
  if(player.vistrel()){
    if(structure[getInd(number)].Vampus==true){
      std::cout<<"\n Осталось "<<player.strel<<" стрел.";
      return true;} else{
	slv=randvalue(1,100);
	if (slv>0 && slv<=25)std::cout<<"\n Вампус проснулся, перевернулся и вновь захрапел";
	if (slv>25 && slv>=50){
	  std::cout<<"\n Вампус проснулся, и перешел в соседнюю комнату";
	  structure[indVampus].Vampus=false;
	  clearHrap();
	  indVampus=getInd(structure[indVampus].prew->number);
	  addVantus(indVampus);
	}
	
	if (slv>50 && slv>=75){
	  std::cout<<"\n Вампус проснулся, и перешел в соседнюю комнату";
	  structure[indVampus].Vampus=false;
	  clearHrap();
	  indVampus=getInd(structure[indVampus].next1->number);
	  addVantus(indVampus);
	}
	
	if (slv>75 && slv>=100){
	  std::cout<<"\n Вампус проснулся, и перешел в соседнюю комнату";
	  structure[indVampus].Vampus=false;
	  clearHrap();
	  indVampus=getInd(structure[indVampus].next2->number);
	  addVantus(indVampus);
	}
	
	std::cout<<"\n Осталось "<<player.strel<<" стрел.";
	return false;};
  }else return false;
}
int game::vamp(){
  int s=0,a;
  for(int i=0;i<size;i++){
    if(structure[i].Vampus==true){
      a=i;
      s++;}
  }
  if (s==1) return structure[a].number; else return 0;
}