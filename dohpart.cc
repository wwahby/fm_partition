#include "hgraph.hpp"
#include "system.hpp"
#include <stdlib.h>

int SEED =1;
double RATIO =0.5;

int main(int argc, char *argv[])
{
parthgraph hg;
char name[]="tresult";
//if(argc==3 || argc==2)
if(argc > 1)
  {
  if(argc >= 4) 
  {
     SEED = atoi(argv[3]);
     if(argc == 5) RATIO = atof(argv[4]);
  }
  hg.getgraph(argv[1]);
  double time=seconds();
  hg.initgains();
  hg.part();
  time=seconds()-time;
  char *fname;
  if (argc==2)
    fname=name; 
  else
    fname=argv[2];
  ofstream myresult(fname,ios::app);
  if (!myresult) 
    {
    cout<<"error opening file ";
    cin>>name;
    exit(0);
    }
  char string[100];
  hg.print(string);
  myresult<<argv[1]<<",";
  myresult<<"seed, "<<SEED<<",";
  myresult<<"final cutset, "<<hg.cutset()<<',';
  myresult<<"time, "<<time<< " ,";
  myresult<<string;
  myresult<<'\n';
  }
}

