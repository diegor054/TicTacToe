#include <vector>
#include <iostream>

using namespace std;

void drawBoard(const vector < char >&gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;
    
   return;
}

void initVector(vector <char> &vec) {
   vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m', 
   'n','o','p','q','r','s','t','u','v','w','x','y','z'};
   
    for(unsigned int i = 0; i < vec.size(); ++i){
       vec.at(i) = letters.at(i);
    }
   return;
}

int convertPosition(char boardPosition) {
   int vectorindex;
   if(boardPosition == 'a'){
      vectorindex = 0;
   }
   if(boardPosition == 'b'){
      vectorindex = 1;
   }
   if(boardPosition == 'c'){
      vectorindex = 2;
   }
   if(boardPosition == 'd'){
      vectorindex = 3;
   }
   if(boardPosition == 'e'){
      vectorindex = 4;
   }
   if(boardPosition == 'f'){
      vectorindex = 5;
   }
   if(boardPosition == 'g'){
      vectorindex = 6;
   }
   if(boardPosition == 'h'){
      vectorindex = 7;
   }
   if(boardPosition == 'i'){
      vectorindex = 8;
   }
   if( boardPosition == 'j' || boardPosition == 'k' || boardPosition == 'l' || boardPosition == 'm'
    || boardPosition == 'n' || boardPosition == 'o' || boardPosition == 'p'|| boardPosition == 'q' 
    || boardPosition == 'r' || boardPosition == 's' || boardPosition == 't' || boardPosition == 'u'
    || boardPosition == 'v' || boardPosition == 'w' || boardPosition == 'x' || boardPosition == 'y' 
    || boardPosition == 'z'){
      
   cout << "Please choose a position: " << endl;
   }
   return vectorindex;
}

bool validPlacement(const vector<char> &gameBoard, int positionIndex) {
   bool valid = true;
   if((gameBoard.at(positionIndex) == 'X') || (gameBoard.at(positionIndex) == 'O')
   || (positionIndex < 0 ) || (positionIndex > 8)){
      valid = false;
   }
   return valid;
}

int getPlay(const vector<char> &gBoard) {
   char bPosition = ' ';  
   cout << "Please choose a position: ";
   cout << endl;
   cin >> bPosition;
    while (validPlacement(gBoard, convertPosition(bPosition)) == false){
           cout << "Please choose a position: "; 
           cin >> bPosition;
         if(validPlacement(gBoard, convertPosition(bPosition)) == true){
         return convertPosition(bPosition);
        }
        }
        return convertPosition(bPosition);
}
 

const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
   vector<char> gameBoard(9);
   int curentPlay;
   int whosTurn = PLAYER1; 
   
   initVector(gameBoard);
   drawBoard(gameBoard);
  
   getPlay(gameBoard);
   return 0;
}