//
// Created by Layer on 07/03/2018.
//

#include "Map.h"
#include "Nexus.h"
#include "Water.h"
#include "Food.h"
#include <string>
#include <iostream>
#include <ctime>
//#include <ntsecpkg.h>


using namespace std;

Map* Map::_instance = NULL;

Map* Map::getInstance() {
    if(_instance == 0){
        _instance = new Map();
    }
    return (_instance);
}

void Map::startup() {
    size = 64;
    frame = 5000;
    entity.push_back(new Nexus());
    entity.push_back(new Water(1.0, 2.0));
    entity.push_back(new Food(1.0, 2.0));
}

bool Map::draw(){
    string base = "";
    //string *dArray;
    //dArray = new string[size][size];
    for (int i = 0; i < size; i++){
        for (int k = 0; k < size; k++){
            base += ".";
        }
        base += '\n';
    }

    for(auto &i : entity){
        if(typeid(*i) == typeid(Nexus)){

            srand(time(0));
            int x = rand()%63;
            int y = rand()%63;
            cout << x << " " << y << endl;


            int coord = (64 * y) + (x + y);
            if(coord == 64 * y && y != 0){
                coord++;
            }

            base.replace(coord , 1, "n");
        }
        if(typeid(*i) == typeid(Water)){

            int x = rand()%63;
            int y = rand()%63;
            cout << x << " " << y << endl;


            int coord = (64 * y) + (x + y);
            if(coord == 64 * y && y != 0){
                coord++;
            }

            base.replace(coord , 1, "w");
        }
        if(typeid(*i) == typeid(Food)){

            int x = rand()%63;
            int y = rand()%63;
            cout << x << " " << y << endl;


            int coord = (64 * y) + (x + y);
            if(coord == 64 * y && y != 0){
                coord++;
            }

            base.replace(coord , 1, "f");
        }
    }

    /*string **p = new string*[64];

    for (int i = 0; i < 64; i++){
        p[i] = new string[64];
    }

    for (int i = 0; i < 64; i++){
        for (int j = 0; j < 64; j++){
            p[i][j] = "*";
        }
    }

    /*for (int i = 0; i < size; i++){
        for (int k = 0; k < size; k++){
            dArray[i] = ".";
        }
        base += '\n';
    }*/

    /*int count[] = {0, 0, 0};

    int s = size + 1, side = -1;*/
    /*for (int i = 0; i < 64; i++){
        for (int j = 0; j < 64; j++){
            cout << p[i][j];
        }
        //cout << " " << endl;
    }*/

    cout << base << endl;
}

