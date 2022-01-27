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
   vector<char> letters = {'a','b','c','d','e','f','g','h','i'};
   //,'j','k','l','m', 
   //'n','o','p','q','r','s','t','u','v','w','x','y','z'};
   
    for(unsigned int i = 0; i < vec.size(); ++i){
       vec.at(i) = letters.at(i);
    }
   return;
}

int convertPosition(char &boardPosition) {
   int vectorindex;
   while(boardPosition == 'j' || boardPosition == 'k' || boardPosition == 'l' || boardPosition == 'm'
    || boardPosition == 'n' || boardPosition == 'o' || boardPosition == 'p'|| boardPosition == 'q' 
    || boardPosition == 'r' || boardPosition == 's' || boardPosition == 't' || boardPosition == 'u'
    || boardPosition == 'v' || boardPosition == 'w' || boardPosition == 'x' || boardPosition == 'y' 
    || boardPosition == 'z'){
   cout << "Please choose a position: " << endl;
   cin >> boardPosition;
   }

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


bool gameWon(const vector<char> &gameBoard, int &winner) {
   if((gameBoard.at(0) == 'X') && (gameBoard.at(1) == 'X') && (gameBoard.at(2) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(0) == 'O') && (gameBoard.at(1) == 'O') && (gameBoard.at(2) == 'O')){
    winner = 1;
      return true;
   }
   if((gameBoard.at(0) == 'X') && (gameBoard.at(3) == 'X') && (gameBoard.at(6) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(0) == 'O') && (gameBoard.at(3) == 'O') && (gameBoard.at(6) == 'O')){
      winner = 1;
      return true;
   }
   if((gameBoard.at(0) == 'X') && (gameBoard.at(4) == 'X') && (gameBoard.at(8) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(0) == 'O') && (gameBoard.at(4) == 'O') && (gameBoard.at(8) == 'O')){
       winner = 1;
      return true;
   }
    if((gameBoard.at(1) == 'X') && (gameBoard.at(4) == 'X') && (gameBoard.at(7) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(1) == 'O') && (gameBoard.at(4) == 'O') && (gameBoard.at(7) == 'O')){
       winner = 1;
      return true;
   }
   if((gameBoard.at(2) == 'X') && (gameBoard.at(5) == 'X') && (gameBoard.at(8) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(2) == 'O') && (gameBoard.at(5) == 'O') && (gameBoard.at(8) == 'O')){
       winner = 1;
      return true;
   }
   if((gameBoard.at(2) == 'X') && (gameBoard.at(4) == 'X') && (gameBoard.at(6) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(2) == 'O') && (gameBoard.at(4) == 'O') && (gameBoard.at(6) == 'O')){
       winner = 1;
      return true;
   }
   if((gameBoard.at(3) == 'X') && (gameBoard.at(4) == 'X') && (gameBoard.at(5) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(3) == 'O') && (gameBoard.at(4) == 'O') && (gameBoard.at(5) == 'O')){
       winner = 1;
      return true;
   }
   if((gameBoard.at(6) == 'X') && (gameBoard.at(7) == 'X') && (gameBoard.at(8) == 'X')){
       winner = 0;
      return true;
   }
   if((gameBoard.at(6) == 'O') && (gameBoard.at(7) == 'O') && (gameBoard.at(8) == 'O')){
       winner = 1;
      return true;
   }

   return false;
}

const int PLAYER1 = 0;
const int PLAYER2 = 1;


int main() {
   vector<char> gameBoard(9);
   int winner = 2;
   int whosTurn = PLAYER1; 
   int plays = 0;
   initVector(gameBoard); 

   while(!gameWon(gameBoard, winner) && plays <= 8){
   drawBoard(gameBoard);

   if(whosTurn == PLAYER1){
        gameBoard.at(getPlay(gameBoard)) = 'X';
        plays++;
       whosTurn = PLAYER2;
   }
   else{
        gameBoard.at(getPlay(gameBoard)) = 'O';
        plays++;
       whosTurn = PLAYER1;
   }
   }
   drawBoard(gameBoard);
   if(winner == 0){
     cout << "Player 1 Won!" << endl;
   }
   if(winner == 1){
     cout << "Player 2 Won!" << endl;
   }
   if(winner == 2){
     cout << "Nobody Won. It's a tie!" << endl;
   }

   return 0;
}