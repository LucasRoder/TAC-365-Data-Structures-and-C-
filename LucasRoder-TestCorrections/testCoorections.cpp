#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>


// Question 1

template <typename T>
class vector
{
public:
    T pop_front();
private:
    unsigned int mSize;
    unsigned int mCapacity;
    T* mData;
};

template <typename T>
T vector<T>::pop_front(){
    T first = mData[0];

    for (int i = 0; i < mSize - 1; i++){
        mData[i] = mData[i + 1];
    }

    mSize -=1;

    return first;

}


// Question 2


class Team;

class Player
{
public:
    std::string name;
    long salary;
    Team* team;
};

class Team
{
public:
    std::string name;
    std::vector<Player*> players;
};

int main()
{
    std::ifstream file("teams.txt");

    std::map<std::string, Team*> teams;  
    std::vector<Team*> teamOrder;   
    std::string line;

    while (getline(file, line))
    {
        if (line.substr(0, 4) == "team")
        {
            Team* t = new Team;           
            t->name = line.substr(5);    

            teams[t->name] = t;          
            teamOrder.push_back(t);   
        }
    
        else if (line.substr(0, 6) == "player")
        {
            std::string rest = line.substr(7);

            int comma1 = rest.find(",");
            int comma2 = rest.find(",", comma1 + 1);

            std::string playerName = rest.substr(0, comma1);
            std::string teamName   = rest.substr(comma1 + 2, comma2 - (comma1 + 2));
            std::string salaryText = rest.substr(comma2 + 2);

            Player* p = new Player;
            p->name   = playerName;
            p->salary = stoi(salaryText);

            Team* t = teams[teamName];
            p->team = t;                   
            t->players.push_back(p);
        }
    }

    for (int i = 0; i < teamOrder.size(); i++)
    {
        Team* t = teamOrder[i];

    
        long total = 0;
        for (int j = 0; j < t->players.size(); j++)
        {
            total = total + t->players[j]->salary;
        }

        std::cout << std::left << std::setw(11) << t->name << total << std::endl;

        for (int j = 0; j < t->players.size(); j++)
        {
            std::cout << "    " << t->players[j]->name << std::endl;
        }
    }

    for (int i = 0; i < teamOrder.size(); i++)
    {
        for (int j = 0; j < teamOrder[i]->players.size(); j++)
        {
            delete teamOrder[i]->players[j];
        }
        delete teamOrder[i];
    }

    return 0;
}

// What I did wrong: for these questions I honestly think I just got stressed and wasnt thinking clearly 
// because it was very simple and we did this all in class
