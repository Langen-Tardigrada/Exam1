#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

const int row = 11; 
const int col = 92; 
string numCard = "";
string cardChar = "";
bool stop =true;
const int heart[][15] = { {0,0,1,1,1,0,0,0,0,0,1,1,1,0,0},
                          {0,1,1,1,1,1,1,0,0,1,1,1,1,1,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                          {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
                          {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
                          {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0}}; 

const int pho[][15] = {   {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
                          {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
                          {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
                          {0,0,1,1,1,1,1,1,1,1,1,1,1,0,0},
                          {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,0,1,0,1,1,1,1,1,1},
                          {0,1,1,1,1,0,1,1,1,0,1,1,1,1,0}}; 

const int square[][15] = {{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
                          {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
                          {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
                          {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}}; 

const int club[][15] = {  {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
                          {0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
                          {0,1,1,1,1,0,1,1,1,0,1,1,1,1,0},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,0,1,0,1,1,1,1,1,1},
                          {0,1,1,1,1,0,1,1,1,0,1,1,1,1,0}}; 

void showScreen(bool [][col]);
void updateScreen(bool [][col],string);
void randomCardNumber();
void result(string, string);
int main(){

    bool screen[row][col] = {};
    string pos;
	string img;
    string line;
    do{	
		srand(time(0));
        showScreen(screen);
        cout << "Please choose a card: ";
        cin >> pos >> img;
        randomCardNumber();
        do{
            for(int j=0; j<col; j++) cout << "-";
            cout << "\nYou inputs are invalid! Please give a new another.\n";
            cout << "Please choose a card: ";
            cin >> pos >> img;
            randomCardNumber();
        }while(numCard=="" && cardChar=="");
        updateScreen(screen, img);
        showScreen(screen);
//        cout << numCard<< cardChar<<  endl;
        result(pos,img);
    }while(stop);
    return 0; 
}

void showScreen(bool screen[row][col]){

    cout << "-";
    for(int j=0; j<col; j++){
        cout << "-";
    }
    cout << "-" << endl;
    for(int i=0; i<row; i++){
        cout << "|";
        for(int j=0; j<col; j++){
        	if(screen[i][j]){
        		cout << "*";
			}else{
				cout << " ";
			}
			screen[i][j] = false;
        }
        cout << "|";
        cout << endl;
    }
    cout << "-";
    for(int j=0; j<col; j++){
        cout << "-";
    }
    cout << "-" << endl;

} 

void randomCardNumber(){
	int cc = (rand()%13)+1;
	switch (cc){
		case 1: 
			numCard = "A";
			break;
		case 11:
			numCard = "J";
			break;
		case 12:
			numCard = "Q";
			break;
		case 13:
			numCard = "K";
			break;
		default:
			numCard = SSTR(numCard);
	}

	
	int imgCard = rand()%3;
	switch (imgCard){
		case 0: 
			cardChar = "C";
			break;
		case 1:
			cardChar = "S";
			break;
		case 2:
			cardChar = "H";
			break;
		case 3:
			cardChar = "P";
	}
	
}
void updateScreen(bool screen[row][col],string img){
	
	int i=0;
	int k=-1,o=-1;
    while(i<row){
    	int j=0;
    	int l=0, p=0;
        while(j<col){
            if(j>19 && j<35 && i>0 && i<row-1){
                if(img == "H" && heart[k][l]){
                        screen[i][j] = 1;
                    }else if(img == "C" && club[k][l]){
                        screen[i][j] = 1;
                    }else if(img == "S" && square[k][l]){
                        screen[i][j] = 1;
                    }else if(img == "P" && pho[k][l]){
                        screen[i][j] = 1;
                    }
                    l++;
            	}else if(j>55 && j<71 && i>0 && i<row-1){
            		if(cardChar == "H" && heart[o][p]){
                        screen[i][j] = 1;
                    }else if(cardChar == "C" && club[o][p]){
                        screen[i][j] = 1;
                    }else if(cardChar == "S" && square[o][p]){
                        screen[i][j] = 1;
                    }else if(cardChar == "P" && pho[o][p]){
                        screen[i][j] = 1;
               		}
               		p++;
				}      
        	j++;
		}
    	i++;
    	k++;
    	o++;
	}
}

void result(string pos, string img){
	string con;
	if(stop){
        for(int i=0; i<15; i++) cout<<" ";
        cout<< "Your card that you choose: "<< pos ;
        for(int i=0; i<10; i++) cout<<" ";
        cout<< "Computer random is " << numCard << endl; 
		
	    if(pos == numCard && img == cardChar){
            for(int j=0; j<col; j++) cout << "-";
	    	cout << "\nVictory!!! You can get your reward" << endl;
		}else{
            for(int j=0; j<col; j++) cout << "-";
			cout << "\nLoose!!! You don't have any luck, So sad" << endl;
		}

        for(int j=0; j<col; j++) cout << "-";
        do{ 
            cout << "\nAre you want to play more?[Y/n]: "; //add text
		    cin >> con;
            if(con == "n"){
                stop = false;
                cout << ".\n" << ".\n" << ".\nEndGame";
            }
        }while(!(con=="Y" || con=="n"));
	}
}
