//Navjot Gill
//Dr. T
//4-22-21
//1437 Progamming Fundamentals II


#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
#include "functions.h"
using namespace std; 


int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string newCity = "";
  string userChoice = ""; 
  int newScore = 0; 
  string newCoachName;
  int homeTeamQuestion;
  double time;
  int quarter;
  int down;
  int ToGo;
  int possession;

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl;
      cout << "C = Update Home City Name" << endl;
      cout << "D = Update Home Coach Name" << endl;
      cout << "E = Exit" << endl;
      cout << "F = Update Visitor Team Name" << endl;
      cout << "G = Update Visitor Team Score" << endl;
      cout << "H = Update Visitor Coach Name" << endl;
      cout << "I = Update Visitor City Names" << endl;
      cout << "J = Update Home Status" << endl;
      cout << "K = Update Time" << endl;
      cout << "L = Update Quarter" << endl;
      cout << "M = Update Down" << endl;
      cout << "N = Update Yards To Go" << endl;
      cout << "O = Update Possesseion Status" << endl;
      cout << "Enter choice: " << endl; 
      userChoice = validateString(userChoice);

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Name module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        newName = validateString(newName); 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        newScore = validateInt(newScore);
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home City Module****" << endl; 
        cout << "\nPlease enter a city for the home team: "; 
        newCity = validateString(newCity);
        tOne.setHomeCity(newCity);

      }
      else if(userChoice == "D" || userChoice == "d")
      {
        cout << "\nUpdate Home Coach Module****" << endl; 
        cout << "\nPlease enter the Home coach name: ";
        newCoachName = validateString(newCoachName);
        tOne.setCoachName(newCoachName);
        
                
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "Exit chosen." << endl; 
      }
      else if(userChoice == "F" || userChoice == "f")
      {
        cout << "\nUpdate Visitor Name Module****" << endl; 
        cout << "\nPlease enter a new name for the visitor team: ";
        newName = validateString(newName); 
        //change that home team's default name
        tTwo.setName(newName);
                
      }
      else if(userChoice == "G" || userChoice == "g")
      {
        cout << "\nUpdate Visitor Score Module****" << endl; 
        cout << "\nPlease enter a new score for the visitor team: "; 
        newScore = validateInt(newScore);
        tTwo.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "H" || userChoice == "h")
      {
        cout << "\nUpdate Visitor Coach Module****" << endl; 
        cout << "\nPlease enter the Visitor coach name: ";
        newCoachName = validateString(newCoachName);
        tTwo.setCoachName(newCoachName);
                 
      }
      else if(userChoice == "I" || userChoice == "i")
      {
        cout << "\nUpdate Visitor City Module****" << endl; 
        cout << "\nPlease enter a city for the visitor team: "; 
        newCity = validateString(newCity);
        tTwo.setHomeCity(newCity);
        
                 
      }
      else if(userChoice == "J" || userChoice == "j")
      {
        cout << "\n Update Home Staus Module" << endl;
        cout << "\n Who is home team" << endl;
        homeTeamQuestion = validateInt(homeTeamQuestion);
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true);
          tTwo.setHomeStatus(false);
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false);
          tTwo.setHomeStatus(true);
        }
                
      }
      else if(userChoice == "K" || userChoice == "k")
      {
        cout << "\nUpdate Timeout Count Module****" << endl; 
        cout << "\nPlease enter the Time: "; 
        time = validateDouble(time);
        s.setTimeoutCount(time);         
      }
      else if(userChoice == "L" || userChoice == "l")
      {
        cout << "\nUpdate Quarter Module****" << endl; 
        cout << "\nPlease enter Quarter: "; 
        quarter = validateInt(quarter);
        s.setQuarter(quarter);         
      }
      else if(userChoice == "M" || userChoice == "m")
      {
        cout << "\nUpdate Down Module****" << endl; 
        cout << "\nPlease enter Down: "; 
        down = validateInt(down);
        s.setDown(down);        
      }
      else if(userChoice == "N" || userChoice == "n")
      {
        cout << "\nUpdate To Go Module****" << endl; 
        cout << "\nPlease enter To go: "; 
        ToGo = validateInt(ToGo);
        s.setyardToGo(ToGo);        
      }
      else if(userChoice == "O" || userChoice == "o")
      {
        do
        {
        cout << "\nUpdate Possession Module****" << endl; 
        cout << "\nPlease enter [1 for Home Team or 2 for Visitor Team]: "; 
        possession = validateInt(possession);
        s.setPossession(possession); 
        }while(possession != 1 && possession != 2);    
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo);
  
  }while(userChoice != "E" && userChoice != "e");


  return 0; 
}