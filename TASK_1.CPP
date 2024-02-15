#include<iostream>
using namespace std ;
int main(){
    int upper , lower ;
    cout<<"ENTER A LOWER AND UPPER LIMIT OF GUESS : ";
    cin>>lower>>upper;
    int GUESS_NUM = rand() % ((upper - lower) + 1);
    
   
     for(int i = lower ; i<upper ; i++){
        int guess ; 
        cout<<"GUESS A NUMBER  BETWEEN " <<lower<<" AND "<<upper<<" :" ; 
        cin>>guess;
        if(guess == GUESS_NUM){
            cout<<"THE GUESS NUMBER IS CORRECT : "<<GUESS_NUM;
            break ;
        }
       
        if(guess < GUESS_NUM){
           cout<<"THE GUESS NUMBER IS TOO LOW : "<<guess<<endl;
        }
        else if(guess > GUESS_NUM){
          cout<<"THE GUESS NUMBER IS TOO HIGH : "<<guess<<endl;
         }
        cout<<"GUESS A NUMBER AGAIN ."<<endl;
     }
     return 0 ;
}