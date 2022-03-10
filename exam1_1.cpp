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
    do{	
		srand(time(0));
        showScreen(screen);
        cout << "Please choose a card: ";
        cin >> pos >> img;
        randomCardNumber();
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
			numCard = (char)cc + "";
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
    string num[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    // char arr[13][4] = {}; // Club, Square, Heart, Pho
    // for(int i=0; i<13; i++){
    //     cc = rand()%13+1; //face of card prob = 1/4
    //     for(int j=0; j<4; j++){
    //         imgCard = rand()%4//rand number  prob 1/13
    //         // statement for arr prop = 1/4 * 1/13 -> each of card have prob. is 1/52. 
    //         arr[i]
    //     }
    // }

    // int low; // 2-10
    // int high; // J-A
    int lh = rand()%3; // lh = 0/1 => 2- 10 (prob = 2/3), lh = 2 => J-A (prob = 1/3)
    if(lh == 0 || lh == 1){
        // low = rand()%9+2; //2-10
        // numCard = (char) low;
        //-------------------------- arr
        // low = rand()%8;
        numCard = num[rand()%8];
    }else{
        // high = rand()%4;// 0-3
        // if(high == 0){
        //     numCard = 'J';
        // }else if(){
        //     ...
        // }

        //---------------------------arr
        numCard = num[(rand()%4)+9];
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
	    	cout << "Victory!!! You can get your reward" << endl;
		}else{
			cout << "Loose!!! You don't have any luck, So sad" << endl;
		}
		
        do{
            cout << "Are you want to play more?[Y/n]: ";
		    cin >> con;
            if(con == "n"){
                stop = false;
            }
        }while(!(con=="Y" || con=="n"));
	}
}
