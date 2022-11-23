#include <iostream>
#include "sculptor.h"
#include "leitor.h"
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"

using namespace std;

int main()
{
   Sculptor *ctr;

   Leitor parser;

   vector<FiguraGeometrica*> figura;

   figura = parser.parse("miniGalaxia.txt");

   ctr = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

   for(size_t i=0;i<figura.size();i++){

       cout << "draw\n";

       figura[i]->draw(*ctr);
   }

   ctr->writeOFF((char*) "miniGalaxia.off");
   for(size_t i=0; i<figura.size(); i++){

       delete figura[i];

   }
   delete ctr;
   return 0;
}
