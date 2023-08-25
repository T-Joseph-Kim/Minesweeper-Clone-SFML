#pragma once
#include <random>
#include <vector>
#include<cstdlib>
using namespace std;


struct Tile{
    bool mine;
    int number = 0;
    int hasnumber;
    bool empty;
    Tile(){
        mine = false;
        number = 0;
        empty = true;
        hasnumber = false;
    };
    Tile (bool mine_){
        mine = mine_;
        number = 0;
        empty = false;
        hasnumber = false;
    }
    Tile(int number_){
        mine = false;
        number = number_;
        empty = false;
        hasnumber = true;
    }
};


struct Board{
    int num_mines;
    int rows;
    int cols;
    int tiles;
    vector<Tile> NumbersMines;
    vector<Tile> Mines;
    Board(int mines, int row, int col){
        srand((unsigned) time(NULL));
        num_mines = mines;
        tiles = row * col;
        rows = row;
        cols = col;
        Tile tile;
        vector<Tile> tempTiles(tiles, tile);
        for (int i = 0; i < num_mines; ++i){
            int mine_index = rand() % tiles;
            if(!tempTiles.at(mine_index).mine) {
                Tile mine_tile(true);
                tempTiles.at(mine_index) = mine_tile;
            }
            else{
                --i;
            }
        }
        Mines = tempTiles;
        for (int i = 0; i < tiles; ++i){
            if (!tempTiles.at(i).mine){
                if (i ==0){
                    int mine_count = 0;
                    if (tempTiles.at(i+1).mine){mine_count +=1;}
                    if (tempTiles.at(cols).mine){mine_count +=1;}
                    if (tempTiles.at(cols+1).mine){mine_count +=1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i == cols-1){
                    int mine_count = 0;
                    if (tempTiles.at(i-1).mine){mine_count +=1;}
                    if (tempTiles.at((i-1)+cols).mine){mine_count += 1;}
                    if (tempTiles.at((i)+cols).mine){mine_count += 1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i > 0 && i < cols -1){
                    int mine_count = 0;
                    if (tempTiles.at(i - 1).mine){mine_count +=1;}
                    if (tempTiles.at(i+1).mine){mine_count +=1;}
                    if (tempTiles.at(i + cols).mine){mine_count +=1;}
                    if (tempTiles.at((i+cols)-1).mine){mine_count +=1;}
                    if (tempTiles.at((i+cols)+1).mine){mine_count +=1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i == tiles - 1){
                    int mine_count = 0;
                    if (tempTiles.at(i - 1).mine){mine_count +=1;}
                    if (tempTiles.at(i-cols).mine){mine_count +=1;}
                    if (tempTiles.at((i-cols)-1).mine){mine_count +=1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i == ((tiles-1) - (cols-1))){
                    int mine_count = 0;
                    if (tempTiles.at(i+1).mine){mine_count += 1;}
                    if (tempTiles.at(i-cols).mine){mine_count+=1;}
                    if (tempTiles.at((i-cols)+1).mine){mine_count += 1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i > ((tiles-1) - (cols-1)) && i < tiles - 1){
                    int mine_count = 0;
                    if (tempTiles.at(i + 1).mine){mine_count +=1;}
                    if (tempTiles.at(i - 1).mine){mine_count += 1;}
                    if (tempTiles.at(i-cols).mine){mine_count +=1;}
                    if (tempTiles.at((i-cols)+1).mine){mine_count +=1;}
                    if (tempTiles.at((i-cols)-1).mine){mine_count +=1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if (i % cols == 0){
                    int mine_count = 0;
                    if (tempTiles.at(i + 1).mine){mine_count += 1;}
                    if (tempTiles.at(i-cols).mine){mine_count += 1;}
                    if (tempTiles.at(i+cols).mine){mine_count += 1;}
                    if (tempTiles.at((i-cols)+1).mine){mine_count += 1;}
                    if (tempTiles.at((i+cols)+1).mine){mine_count += 1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else if ((i+1) % cols == 0){
                    int mine_count = 0;
                    if (tempTiles.at(i-1).mine){mine_count += 1;}
                    if (tempTiles.at(i-cols).mine){mine_count += 1;}
                    if (tempTiles.at((i-cols)-1).mine){mine_count +=1;}
                    if (tempTiles.at(i+cols).mine){mine_count +=1;}
                    if (tempTiles.at((i+cols)-1).mine){mine_count +=1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
                else{
                    int mine_count = 0;
                    if (tempTiles.at(i+1).mine){mine_count +=1;}
                    if (tempTiles.at(i-1).mine){mine_count += 1;}
                    if (tempTiles.at(i-cols).mine){mine_count += 1;}
                    if (tempTiles.at(i+cols).mine){mine_count +=1;}
                    if (tempTiles.at((i-cols)-1).mine){mine_count +=1;}
                    if (tempTiles.at((i-cols)+1).mine){mine_count +=1;}
                    if (tempTiles.at((i+cols)-1).mine){mine_count +=1;}
                    if (tempTiles.at((i+cols)+1).mine){mine_count += 1;}
                    if (mine_count != 0){Tile number_tile(mine_count);
                        tempTiles.at(i) = number_tile;}
                }
            }
        }
        NumbersMines = tempTiles;
    }

};
