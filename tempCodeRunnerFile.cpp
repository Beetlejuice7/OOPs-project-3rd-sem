#include <iostream>
#include <unistd.h>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
int score = 0;
int incor = 0;
int value1 = 0;
int played = 0;
int answer;
class quiz
{

    int diflev;

public:
    
    void welcome()
    {
        cout << "________________________________________________________________________________________________________________________________________________________________" << endl;
        cout << "\n                                                                        Welcome to 'DIMAG KO KHEL'\n";
        cout << "________________________________________________________________________________________________________________________________________________________________" << endl;
    }
    void enter()
    {
        cout << endl << endl;
        cout << "\n\n\n\n\n\n\n\n\n\n\n                                                                        Press enter to continue...";
        cin.ignore();
        // cin.get();
        // system("clear");
        loading();
    }
    void loading()
    {
        clear();
        MIL();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                                                        Loading";
        for (int i = 0; i < 2; i++)
        {
            cout << "..";
            cout.flush();
            sleep(1);
        }
        
    }
    void processing()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                                                       Processing";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            cout.flush();
            sleep(1);
        }
    }
    void MIL()
    {
        cout << "________________________________________________________________________________________________________________________________________________________________" << endl;
        cout << "\n                                                                         DIMAG KO KHEL\n";
        cout << "________________________________________________________________________________________________________________________________________________________________" << endl << endl;
    }
    void exiting()
    {
        cout << endl << endl << "                                                               Exiting 'DIMAG KO KHEL'";
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            cout.flush();
            sleep(1);
        }
        clear();
        exit(1);
    }
    
    void reward(int a)
    {
        ifstream file2("reward.txt");
        int value;
        file2 >> value;
        value = value + a;
        ofstream file("reward.txt");

        file << value;

        file.close();

        // statistics();
        
    }
    void correct()
    {
        ifstream file2("correct.txt");
        int value;
        file2 >> value;
        value = value + score;
        ofstream file("correct.txt");
        file << value;

        file.close();
    }
    void incorrect()
    {
        ifstream file2("incorrect.txt");
        int value;
        file2 >> value;
        value = value + incor;
        ofstream file("incorrect.txt");
        file << value;

        file.close();
    }
    
    void statistics()
    {
        ifstream file2("statistics.txt");
        int value;
        file2 >> value;
        value = value + played;
        ofstream file("statistics.txt");

        file << value;

        file.close();
        
    }
    void statisticshow()
    {
        clear();

        MIL();

        cout << "\n\n                                                                        Statistics" << endl;
        cout << "                                                                        ----------" << endl << endl;
        int import4, import5, add;
        ifstream file4("correct.txt");
        ifstream file5("incorrect.txt");                //1
        file4 >> import4;
        file5 >> import5;
        file4.close();
        file5.close();
        add = import4 + import5;
        cout << "\n\n                                                                   Total Answers : " << add;

                                                //2
        ifstream file2("correct.txt");

        int import2;

        file2 >> import2;

        file2.close();

        cout << "\n\n                                                                   Correct Answers : " << import2;
                                                //3
        ifstream file3("incorrect.txt");

        int import3;

        file3 >> import3;

        file3.close();

        cout << "\n\n                                                                   Wrong Answers : " << import3;
                                                //4
        
        double percent = static_cast<double>(import2) / add * 100;

        cout << "\n\n                                                                   Percentage of correct Answer : " << fixed << setprecision(2) << percent << "%";
        
                                                //5
        ifstream file("statistics.txt");

        int import;

        file >> import;

        file.close();
        
        cout << "\n\n                                                                   Game Played : " << import;
                                                //6
        ifstream file1("reward.txt");

        int import1;

        file1 >> import1;

        file1.close();

        cout << "\n\n                                                                   Total Reward : $" << import1;

        cout << endl << endl << endl;

        goback();

    }
    void confirm()
    {
        clear();
        MIL();
        string choice;
        cout << "\n\n\n\n\n\n                                                         Are you sure you want to reset your past statistics?" << endl << endl << endl << endl << endl;
        cout << "                                                                       YES                 NO" << endl << endl << endl;
        cout << "                                                                     --> ";
        cin >> choice;
        if (choice=="yes" || choice=="YES" || choice=="yES" || choice=="YeS" || choice=="YEs" || choice=="Yes" || choice=="yEs" || choice=="yeS" || choice=="y" || choice=="Y")
        {
            reset();
        }
        else if (choice=="no" || choice=="NO" || choice=="nO" || choice=="No" || choice=="n" || choice=="N")
        {
            menu();
        }
        else
        {
            cout << "\n\n                                                                        Wrong input." << endl;
            goback();
        }
        
        
    }
    void reset()
    {
        clear();
        MIL();
        int reset = 0;

        ofstream file("correct.txt", ios::trunc);
        ofstream file1("incorrect.txt", ios::trunc);
        ofstream file2("reward.txt", ios::trunc);
        ofstream file3("statistics.txt", ios::trunc);

        file << reset;
        file1 << reset;
        file2 << reset;
        file3 << reset;

        file.close();
        file1.close();
        file2.close();
        file3.close();

        cout << "\n\n\n\n\n\n                                                                        Reset Successfully";

        goback();

    }
    void help()
    {
        clear();
        MIL();
        cout << endl << endl;
        ifstream file("help.txt");
        string line;
        while (std::getline(file, line)) {
        cout << line << endl;
        }
        goback();
    }
    void about()
    {
        clear();
        MIL();
        cout << endl << endl;
        ifstream file("about.txt");
        string line;
        while (std::getline(file, line)) {
        cout << line << endl;
        }
        goback();
    }

    void clear(){
        system("clear");
    }
    void difilevelfoot()        //Football
    {
        clear();
        MIL();
        cout << "\n\n\n                                                                   Choose dificult level :-" << endl << endl << endl;
        cout << "                                                                   1. Easy            2. Hard" << endl << endl << endl;
        cout << "                                                                   --> ";
        cin >> diflev;
        if (diflev == 1)
        {
            footballEz();
        }
        else if (diflev == 2)
        {
            footballHard();
        }
        else
        {
            difilevelfoot();
        }
    }
    void difilevelGK()        //General knowledge
    {
        clear();
        MIL();
        cout << "\n\n\n                                                                   Choose dificult level :-" << endl << endl << endl;
        cout << "                                                                   1. Easy            2. Hard" << endl << endl << endl;
        cout << "                                                                   --> ";
        cin >> diflev;
        if (diflev == 1)
        {
            GKEz();
        }
        else if (diflev == 2)
        {
            GKHard();
        }
        else
        {
            difilevelGK();
        }
    }
    void difilevelHistory()        //History
    {
        clear();
        MIL();
        cout << endl << endl << endl << endl;
        cout << "\n\n\n                                                                   Not available right now." << endl;
        cout << endl << endl << endl << endl;
        gocategory();
    }
    
    //football easy function
    void footballEz()
    {
        clear();
        MIL();
                                    //1
        cout << endl << endl << endl;
        cout << "                                                           1. Who is the best football player in the world." << endl << endl;
        cout << "                                                               A. Cristiano Ronaldo       B. Kaka" << endl << endl;
        cout << "                                                               C. Zinedine Zidane         D. Lionel messi" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct Siuuuuuuuu";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        played++;
        nextq();
                                    //2
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           2. Who has most individual world cups." << endl << endl;
        cout << "                                                               A. Cafu                    B. Pele" << endl << endl;
        cout << "                                                               C. Ronaldo                 D. Mauro" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct, RIP GOAT";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //3
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           3. Which country hosted the 2018 FIFA WORLD CUP." << endl << endl;
        cout << "                                                               A. Brazil                  B. France" << endl << endl;
        cout << "                                                               C. Russia                  D. Germany" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //4
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           4. How many players are there on a standard football team?" << endl << endl;
        cout << "                                                               A. 8                       B. 10" << endl << endl;
        cout << "                                                               C. 9                       D. 11" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //5
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           5. In which country did the sport of football originate?" << endl << endl;
        cout << "                                                               A. England                       B. Brazil" << endl << endl;
        cout << "                                                               C. Italy                         D. Germany" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //6
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           6. Who is the all-time top scorer in the history of the UEFA Champions League?" << endl << endl;
        cout << "                                                               A. Lionel Messi                       B. Cristiano Ronaldo" << endl << endl;
        cout << "                                                               C. Raul Gonzalez                      D. Robert Lewandowski" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //7
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           7. Which English club is known as the \"Red Devils\"?" << endl << endl;
        cout << "                                                               A. Arsenal                       B. Liverpool" << endl << endl;
        cout << "                                                               C. Manchester United             D. Chelsea" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //8
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           8. Which player is often referred to as \"CR7\" in the football world?" << endl << endl;
        cout << "                                                               A. Neymar                       B. Kaka" << endl << endl;
        cout << "                                                               C. Cristiano Ronaldo            D. Lionel Messi" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //9
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           9. Which team has the most Champions League titles?" << endl << endl;
        cout << "                                                               A. AC Milan                       B. Real Madrid" << endl << endl;
        cout << "                                                               C. Barcelona                      D. Liverpool" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //10
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           10. Which is the home stadium of Real Madrid?" << endl << endl;
        cout << "                                                               A. Camp Nou                      B. Old Trafford" << endl << endl;
        cout << "                                                               C. Anfield                       D. Santiago Bernabéu" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }

        result();
    }

    //football hard difficult level 
    void footballHard()
    {
        clear();
        MIL();
                                    //1
        cout << endl << endl << endl;
        cout << "                                                           1. Which player won the Ballon d'Or in 2008, ending the Ronaldo-Messi" << endl << endl;
        cout << "                                                               streak that lasted from 2008 to 2017?" << endl << endl << endl;
        cout << "                                                               A. Kaka                   B. Xavi Hernandez" << endl << endl;
        cout << "                                                               C. Andrés Iniesta         D. Franck Ribéry" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        played++;
        nextq();
                                    //2
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           2. Who scored the winning goal in the 2014 FIFA World Cup final between" << endl << endl;
        cout << "                                                                Germany and Argentina?" << endl << endl << endl;
        cout << "                                                               A. Lionel Messi            B. Thomas Müller" << endl << endl;
        cout << "                                                               C. Mario Götze             D. Miroslav Klose" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //3
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           3. Which club won the UEFA Champions League in the 2011-2012 season?." << endl << endl << endl;
        cout << "                                                               A. Real Madrid             B. Chelsea" << endl << endl;
        cout << "                                                               C. Bayern Munich           D. Barcelona" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //4
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           4. Who was the top scorer of the 2010 FIFA World Cup held in South Africa?" << endl << endl << endl;
        cout << "                                                               A. David Villa             B. Thomas Müller" << endl << endl;
        cout << "                                                               C. Wesley Sneijder         D. Diego Forlán" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //5
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           5. Which team won the 2016 UEFA European Championship?" << endl << endl << endl;
        cout << "                                                               A. Germany                       B. Portugal" << endl << endl;
        cout << "                                                               C. France                        D. Spain" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //6
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           6. Who won the FIFA World Cup Golden Boot for being the top scorer in" << endl << endl;
        cout << "                                                                the 2018 tournament?" << endl << endl << endl;
        cout << "                                                               A. Kylian Mbappé                  B. Cristiano Ronaldo" << endl << endl;
        cout << "                                                               C. Lionel Messi                   D. Harry Kane" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //7
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           7. In the 2012-2013 season, which player broke the record for the most" << endl << endl;
        cout << "                                                                goals scored in a single UEFA Champions League campaign?" << endl << endl << endl;
        cout << "                                                               A. Cristiano Ronaldo             B. Lionel Messi" << endl << endl;
        cout << "                                                               C. Dider Drogba                  D. Robert Lewandowski" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //8
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           8. Who won the FIFA World Cup Best Young Player award in the 2014 tournament?" << endl << endl << endl;
        cout << "                                                               A. Paul Pogba                   B. James Rodríguez" << endl << endl;
        cout << "                                                               C. Kylian Mbappé                D. Thomas Müller" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //9
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           9. Which player won the Golden Foot award in 2020, given to active " << endl << endl;
        cout << "                                                               players aged 29 or older for outstanding achievements??" << endl << endl << endl;
        cout << "                                                               A. Cristiano Ronaldo              B. Lionel Messi" << endl << endl;
        cout << "                                                               C. Zlatan Ibrahimović             D. Andres Iniesta" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //10
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           10. Which Portuguese player won the UEFA European Championship Golden" << endl << endl;
        cout << "                                                                Boot as the top scorer in the 2016 tournament?" << endl << endl << endl;
        cout << "                                                               A. Cristiano Ronaldo             B. Eder" << endl << endl;
        cout << "                                                               C. Nani                          D. Renato Sanches" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }

        result();
    }

    //General knowledge easy function
    void GKEz()
    {
        clear();
        MIL();
                                    //1
        cout << endl << endl << endl;
        cout << "                                                           1. What is the capital of the United States?" << endl << endl << endl;
        cout << "                                                               A. Washington, D.C.       B. New York" << endl << endl;
        cout << "                                                               C. Los Angeles            D. Chicago" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        played++;
        nextq();
                                    //2
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           2. In which continent is the Sahara Desert located?" << endl << endl << endl;
        cout << "                                                               A. Africa                  B. Asia" << endl << endl;
        cout << "                                                               C. South America           D. North America" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //3
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           3. What is the largest planet in our solar system??." << endl << endl << endl;
        cout << "                                                               A. Earth                   B. Saturn" << endl << endl;
        cout << "                                                               C. Jupiter                 D. Mars" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //4
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           4. Who is known as the inventor of the telephone?" << endl << endl << endl;
        cout << "                                                               A. Thomas Edison           B. Alexander Graham Bell" << endl << endl;
        cout << "                                                               C. Nikola Tesla            D. Marie Curie" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //5
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           5. Which ocean is the largest on Earth??" << endl << endl << endl;
        cout << "                                                               A. Indian Ocean                  B. Southern Ocean" << endl << endl;
        cout << "                                                               C. Atlantic Ocean                D. Pacific Ocean" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //6
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           6. What is the currency of Japan?" << endl << endl << endl;
        cout << "                                                               A. Yen                 B. Won" << endl << endl;
        cout << "                                                               C. Yaun                D. Baht" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //7
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           7. Who painted the Mona Lisa?" << endl << endl << endl;
        cout << "                                                               A. Vincent van Gogh             B. Pablo Picasso" << endl << endl;
        cout << "                                                               C. Leonardo da Vinci            D. Michelangelo" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //8
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           8. Which river is the longest in the world??" << endl << endl << endl;
        cout << "                                                               A. Nile River                   B. Amazon River" << endl << endl;
        cout << "                                                               C. Mississippi River            D. Yangtze River" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //9
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           9. What is the official language of Brazil?" << endl << endl << endl;
        cout << "                                                               A. Brazilian               B. Portuguese" << endl << endl;
        cout << "                                                               C. French                  D. Italian" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //10
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           10. In which year did World War II end?" << endl << endl << endl;
        cout << "                                                               A. 1943                        B. 1950" << endl << endl;
        cout << "                                                               C. 1939                        D. 1945" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }

        result();
    }

    //General knowledge hard function
    void GKHard()
    {
        clear();
        MIL();
                                    //1
        cout << endl << endl << endl;
        cout << "                                                           1. Which chemical element has the symbol \"Au\" on the periodic table?" << endl << endl << endl;
        cout << "                                                               A. Silver                 B. Gold" << endl << endl;
        cout << "                                                               C. Platinum               D. Mercury" << endl << endl;
        cout << "                                                           --> ";
        try
        {
        if(scanf("%d", answer)!=1)
        {
            throw 1;
        }
        else if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        }
        played++;
        nextq();
                                    //2
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           2. Who was the first woman to win a Nobel Prize" << endl << endl << endl;
        cout << "                                                               A. Mother Teresa           B. Rosalind Franklin" << endl << endl;
        cout << "                                                               C. Jane Goodall            D. Marie Curie" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //3
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           3. In which year did the Chernobyl nuclear disaster occur?" << endl << endl << endl;
        cout << "                                                               A. 1986                    B. 1979" << endl << endl;
        cout << "                                                               C. 1991                    D. 2000" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct";
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //4
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           4. What is the largest desert in the world by area?" << endl << endl << endl;
        cout << "                                                               A. Sahara Desert           B. Gobi Desert" << endl << endl;
        cout << "                                                               C. Antarctic Desert        D. Arabian Desert" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //5
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           5. What is the largest moon in our solar system?" << endl << endl << endl;
        cout << "                                                               A. Titan                         B. Io" << endl << endl;
        cout << "                                                               C. Europa                        D. Ganymede" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //6
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           6. What is the largest island in the world?" << endl << endl << endl;
        cout << "                                                               A. Australia           B. Greenand" << endl << endl;
        cout << "                                                               C. Borneo              D. Madagascar" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }
        nextq();
                                    //7
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           7. In which year did the first manned moon landing take place?" << endl << endl << endl;
        cout << "                                                               A. 1961                         B. 1975" << endl << endl;
        cout << "                                                               C. 1982                         D. 1969" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'D' || answer == 'd')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : D" << endl;
            incor++;
        }
        nextq();
                                    //8
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           8. In particle physics, what is the smallest building block of matter?" << endl << endl << endl;
        cout << "                                                               A. Quark                        B. Neutrino" << endl << endl;
        cout << "                                                               C. Photon                       D. Electron" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : A" << endl;
            incor++;
        }
        nextq();
                                    //9
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           9. Who wrote Nepali National Anthem?" << endl << endl << endl;
        cout << "                                                               A. Motiram Bhatta          B. Lekhnath Paudyal" << endl << endl;
        cout << "                                                               C. Pradip Kumar Rai        D. Bhanubhakta Acharya" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : C" << endl;
            incor++;
        }
        nextq();
                                    //10
        clear();
        MIL();
        cout << endl << endl << endl;
        cout << "                                                           10. How many rings does the planet saturn have?" << endl << endl << endl;
        cout << "                                                               A. 8                         B. 7" << endl << endl;
        cout << "                                                               C. 6                         D. 9" << endl << endl;
        cout << "                                                           --> ";
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            cout << endl;
            cout << "                                                           ✓ Correct" << endl;
            score++;
            value1+=20;
        }
        else
        {
            cout << endl;
            cout << "                                                           ✕ Incorrect" << endl << endl;
            cout << "                                                           Answer : B" << endl;
            incor++;
        }

        result();
    }

    // Result and returning function
    void result()
    {
        int plus;
        plus = score;
        cout << endl << endl << endl << endl << endl << endl << endl << endl << "                                                           Enter for result...";
        cin.ignore();
        cin.get();
        system("clear");
        MIL();
        processing();
        clear();
        MIL();
        cout << "\n\n                                                                            Result" << endl;
        cout << "                                                                            ------" << endl << endl << endl;
        cout << "\n\n                                                                  Your score is " << plus << " out of 10." << endl;
        cout << "\n\n                                                                      You Receive = $" << value1 << endl;
        cout << endl << endl << endl << endl << endl;
        reward(value1);
        statistics();
        correct();
        incorrect();
        score = 0;
        played = 0;
        value1 = 0;
        incor = 0;
        // goback();
        cout << "\n\n\n                                                                Press enter to go back to menu...";
        cin.ignore();
        // cin.get();
        menu();
    }
    void goback()
    {
        cout << "\n\n\n                                                                Press enter to go back to menu...";
        cin.ignore();
        cin.get();
        // loading();
        menu();
    }
    void gocategory()
    {
        cout << "\n\n                                                                  Press enter to go back...";
        cin.ignore();
        cin.get();
        // loading();
        category();
    }
    void nextq()
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl << "                                                           Enter to next question...";
        cin.ignore();
        cin.get();
    }
    void category()
    {
        clear();
        MIL();
        int choose;
        cout << "\n\n\n                                                                   Select the category :-" << endl << endl << endl;
        cout << "                                                                   1. Football\n" << endl;
        cout << "                                                                   2. General Knowledge\n" << endl;
        cout << "                                                                   3. History\n" << endl;
        cout << "                                                                   4. Back to menu\n" << endl;
        again :
        cout << "                                                                    -> ";
        cin >> choose;
        switch (choose)
        {
            case 1:
                difilevelfoot();
                break;
            case 2:
                difilevelGK();
                break;
            case 3:
            difilevelHistory();
                break;
            case 4:
            menu();
                break;
            default :
                cout << "\n                                                                   Invalid Selection." << endl << endl;
                goto again;
                break;
        }
    }
    // Menu
    void menu(){
        
        int choice;
        clear();
        MIL();
        cout << "\n\n                                                                        Menu" << endl << endl << endl << endl;
        cout << "                                                                   1. New Game\n" << endl;
        cout << "                                                                   2. Statistics\n" << endl;
        cout << "                                                                   3. Reset\n" << endl;
        cout << "                                                                   4. Help\n" << endl;
        cout << "                                                                   5. About\n" << endl;
        cout << "                                                                   6. Exit\n" << endl << endl;
        cout << "                                                                    -> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            category();
            break;
        case 2:
            statisticshow();
            break;
        case 3:
            confirm();
            break;
        case 4:
            help();
            break;
        case 5:
            about();
            break;
        case 6:
            exiting();
        default:
            break;
        }
    }
    catch(int a)
    {
        cout << "Invalid";
    }
};
int main()
{
    system("clear");
    quiz q;
    q.welcome();
    // q.enter();
    q.menu();
}