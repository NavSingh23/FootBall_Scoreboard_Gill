class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int shotsOnGoal; 
    string coachName;
    string homeCity;
    
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        shotsOnGoal = 0; 
        coachName = "DefaultCoachName";
        homeCity = "DefaultCityName";
        
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) {coachName = sCN;}
      void setHomeCity(string sHC) {homeCity = sHC;}
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getcoachName() const {return coachName;}
      string gethomeCity() const { return homeCity;}
      
};

class Scoreboard
{
  private:
    int quarter; 
    int down;
    int yardToGo;
    Team home; //object that is a member of another object
    Team visitor; 
    double timeoutCount;
    int possession;
  public: 
    Scoreboard()
    {
      quarter = 0; 
      down = 0;
      yardToGo = 0;
      timeoutCount = 0.0;
      possession = 1;
    }  
    void setQuarter(int q) { quarter = q; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    void setDown(int d) { down = d;}
    void setyardToGo(int y)  { yardToGo = y; }
    void setTimeoutCount(double sTOC) { timeoutCount = sTOC;}
    void setPossession(int sp) {possession = sp;}
    int getQuarter() const { return quarter; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    int getDown() const { return down; }
    int getyardToGo() const { return yardToGo; }
    double gettimeoutCount() const {return timeoutCount;}
    int getPossession() const {return possession;}

    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      string timeC = "\x1b[" + to_string(33) + ";1m"; //time color
      string CoachNameC = "\x1b[" + to_string(32) + ";"+to_string(93)+"m";
      string CityNameC = "\x1b[" + to_string(32) + ";"+to_string(94)+"m";
      string TeamNameC = "\x1b[" + to_string(32) + ";"+to_string(91)+"m";

      for(int i=0; i < 40; i++) {cout << "*";}
      cout << endl;
      cout << color << "Football Scoreboard Nav Sytle" << reset << endl; 
      cout << TeamNameC << home.getName() << "\t\t" << visitor.getName() << reset << endl; 
      cout << score << home.getScore() << "\t\t\t\t\t\t  " << visitor.getScore() << reset << endl; 
      cout << timeC << "\t\t\tTime: "  << timeoutCount << reset <<endl;
      cout << "\t\t\tQTR: " << quarter << endl;
    
      cout << "Down: " << down << "\t\t\t\t  To Go: " << yardToGo << endl;
      cout << CoachNameC << home.getcoachName() << "\t " << visitor.getcoachName() << reset << endl;
      cout << CityNameC << home.gethomeCity()  << "\t\t " << visitor.gethomeCity()<< reset << endl;
      //for(int i=0; i < 35; i++) {cout << "*";}
      cout << endl;
      cout << "Possession: \t";
       if(possession == 1)
       {
         cout << "Team 1: " << home.getName()<< "*"<< endl;
         
       }
       else if (possession == 2)
       {
         cout << "Team 2: " << visitor.getName() << "*" << endl;
         
       }
       else{
         cout << "Error!!!";
       }
      cout << "Home: \t";
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName()<< "*"<< endl;
         for(int i=0; i < 40; i++) {cout << "*";}
       }
       else if (visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*" << endl;
         for(int i=0; i < 40; i++) {cout << "*";}
       }
       else{
         cout << "Error!!!";
       }
       cout << endl;
      
    }
};