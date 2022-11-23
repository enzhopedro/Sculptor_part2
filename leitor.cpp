#include "leitor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"


using namespace std;

Leitor::Leitor()
{
    //ctor
}
    vector<FiguraGeometrica *> Leitor::parse(string filename){
    vector<FiguraGeometrica*> figura;
    stringstream ss;
    string token, s;
    ifstream fin;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        cout<< "Ocorreu um erro ao abrir: " << filename << std::endl;
        exit(0);

    }


  while(fin.good()){
        getline(fin, s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;
            if(ss.good()){
                if(token.compare("dim") == 0) {
                    ss >> dimx >> dimy >> dimz;
                }
                else if(token.compare("putVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> g >> b >> a;
                    figura.push_back(new PutVoxel(x, y ,z, r, g, b, a));
                }
                else if(token.compare("cutVoxel") == 0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    figura.push_back(new CutVoxel(x, y ,z));
                }
                else if(token.compare("putBox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figura.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }
                 else if(token.compare("cutBox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0;
                    figura.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }
                 else if(token.compare("putSphere") == 0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius >> r >> g >> b >> a;
                    figura.push_back(new PutSphere(xc, yc, zc, radius, r, g, b, a));
                }
                  else if(token.compare("cutSphere") == 0){
                    int xc, yc, zc, radius;
                    ss >> xc >> yc >> zc >> radius;
                    figura.push_back(new CutSphere(xc, yc, zc, radius));
                }
                else if(token.compare("putEllipsoid") == 0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
                    figura.push_back(new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));
                }
                 else if(token.compare("cutEllipsoid") == 0){
                    int xc, yc, zc, rx, ry, rz;
                    ss >> xc >> yc >> zc >> rx >> ry >> rz;
                    figura.push_back(new CutEllipsoid(xc, yc, zc, rx, ry, rz));
                }

            }
        }
     }
    return(figura);
 }

 int Leitor::getDimx(){
    return dimx;
 }
 int Leitor::getDimy(){
    return dimy;
 }
 int Leitor::getDimz(){
    return dimz;
 }
