#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print(vector<vector<int>>&, int sizex, int sizey);
void update(vector<vector<int>>&, int weight, int sizex, int sizey);
void randomizemap(vector<vector<int>>&, int sizex, int sizey);


//prints out the grid.


int main() {
    int sizex, sizey, weight=1;
    cout << "Enter dimensions -  sizex, sizey: ";
    cin >> sizex >> sizey;

    vector<vector<int>> cellautomata(sizex, vector<int>(sizey, 0));
    // int testarray[sizex][sizey] = {};
    // int cellautomata[sizex][sizey] = {};
    int count = 0;
    srand(time(0));
    //while weight input is valud
    while (weight > 0 && weight <= 8) {
        
        randomizemap(cellautomata, sizex, sizey);
        // while (weight < 0 || weight >8) {
            cout << "How many neighbors does a tile need to survive(input > 0)? ";
            cin >> weight;
        // }
        count =0;
        for (int generation = 0; generation <= 10; generation++) {
            
            cin.ignore(256, '\n');
            // cout << "\n--begin if: " << generation << "\n";
            // cout << "\n---\n" << endl;
            // print(cellautomata, sizex, sizey);
            // randomizemap(cellautomata, sizex, sizey);
            // cout << "-would be a print usually-";
            // cout << "\n------next generation: " << count << "------\n" << endl;
            count++;

            update(cellautomata, weight, sizex, sizey);
            // cout << "\n--before if: " << generation << "\n";
            if (generation %2 == 0 || generation == 0) {
                cout << "\n------next generation: " << count << "------\n" << endl;
                print(cellautomata, sizex, sizey);
            }
        }
        weight = 0;
    }
    cout << "\n\nThe end\n" << endl;
    return 0;
}

void print(vector<vector<int>> &cellautomata, int sizex, int sizey){
    for (int i = 0; i <sizex; i++) {
        for (int j = 0; j <sizey; j++) {
            // cout << " " << j << " "
            if ( cellautomata[i][j] == -1 )
                cout << '#';
            else 
                cout << (cellautomata[i][j] == 1 ? '*' : ' ');
        }
    cout << endl;
    }

}

void update(vector<vector<int>> &cellautomata,int weight, int sizex, int sizey) {
    vector<vector<int>> nextgen = cellautomata;
    int sumneighbors = 0;
    for (int i = 1; i < sizex-1; i++) {
        for (int j = 1; j < sizey-1; j++) {
            sumneighbors = 0;
            if (cellautomata[i][j] == 1)    
                sumneighbors -= cellautomata[i][j];
            //count live neighbors for all tiles around current tile, including current tile -- then subtract crr tile from neighbor sum.
            for (int ni = i - 1; ni <= i + 1; ni++) {
                // if (cellautomata[ni][j] == 0 || ni ==1) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if ((cellautomata[ni][nj] == 1 || cellautomata[ni][nj] == 0)) {
                        sumneighbors += cellautomata[ni][nj];
                    }
                }   
            } 
            //check to see if num of neighbors meets weighted criteria for staying alive
            if (sumneighbors == 2 && nextgen[i][j] == 1)
                nextgen[i][j] = 1;
            else if (sumneighbors == 3 && nextgen[i][j] == 0)
                nextgen[i][j] = 1;
            else
                nextgen[i][j] = 0;
            // int sumneighbors = cellautomata[i+1][j-1] + cellautomata[i][j-1] + cellautomata[i-1][j-1] + 
            //    cellautomata[i-1][j] + cellautomata[i+1][j] + cellautomata[i-1][j+1] + cellautomata[i+1][j+1] + cellautomata[i][j+1];
            // if (sumneighbors < 3) {
            //     nextgen[i][j] = 1;
            // }
            // else {
            //     nextgen[i][j] = 0;
            // }
            // cout << "\n\n----\n\n";
            // for (int i = 0; i < cellautomata.size(); i++) {
            //     for (int j = 0; j < cellautomata[0].size(); j++) 
            //         cout << (cellautomata[i][j] == 1 ? '*' : ' ');
            // cout << endl;
            // }
        }
    }

    cellautomata = nextgen;
}

void generatetest(vector<vector<int>> &cellautomata, int sizex, int sizey) {
    for ()


}

void randomizemap(vector<vector<int>> &cellautomata, int sizex, int sizey) {
    //randomize the base grid original-
    //int temp;
    // for (int i = 0; i < cellautomata.size(); i++) {
    //     for (int j= 0; j < cellautomata[0].size(); j++) {         
    //         temp = rand()%2;
    //         cellautomata[i][j] = temp;
    //     }
    // }

    //randomization, but sets the border of the grid to -1 for future calculations, and prints it as '#' for clarity.
    cout << "\n\nRandomization:\n\n";
    //for each element( rows first, then columns ) randomize their value to be 0 or 1. 0 is dead, 1 is alive.
    for (int i = 0; i < sizex; i++) {
        for (int j=0; j < sizey; j++) {
            // temp = rand()%2;
            cellautomata[i][j] = rand()%2;
            if ((j == 0 || j == cellautomata[0].size()-1) ) {
                cellautomata[i][j] = -1;
            }
            else if (i == 0 || i == cellautomata.size()-1) {
                cellautomata[i][j] = -1;
            }

            if ( cellautomata[i][j] == -1)
                cout << '#';
            else 
                cout << (cellautomata[i][j] == 1 ? "*" : " ");
        }
    cout << endl;
    }
    cout <<"here" << endl;
}



