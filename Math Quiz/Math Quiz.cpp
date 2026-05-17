
#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
using namespace std;

int randnum(int from , int to)
{
    return rand() % (to - from + 1) + from;
}
int readnum(string massege)
{
    int num;
    do
    {
        cout << massege;
        cin >> num;
    } while (num <= 0);
    return num;
}
enum enlevel{easy=1,med=2,hard=3,mixl=4};
enum enop{add=1,sub=2,mul=3,Div=4,mixo=5};
struct stall
{
    short numofq=0;
	short numofright = 0;
	short numofwrong = 0;
	enlevel level;
	enop operation;
};
enlevel choicelevel(short num)
{
    return (enlevel)num;
}
enop choiceoperation(short num)
{
    return (enop)num;
}
string printchoicelevel(enlevel level)
{
    switch (level)
    {
    case easy:
        return "Easy";
    case med:
        return "Medium";
    case hard:
        return "Hard";
    case mixl:
        return "Mix";
    }
}
string printchoiceoperation(enop operation)
{
    switch (operation)
    {
    case add:
        return "Addition";
    case sub:
        return "Subtraction";
    case mul:
        return "Multiplication";
    case Div:
        return "Division";
    case mixo:
        return "Mix";
    }
}
int levelnum(enlevel level)
{
    switch (level)
    {
    case easy:
        return randnum(1, 10);
    case med:
        return randnum(1, 50);
    case hard:
        return randnum(10, 100);
    case mixl:

        switch (randnum(1, 4))
        {
        case 1:
            return randnum(1, 10);
        case 2:
            return randnum(1, 50);
        case 3:
            return randnum(10, 100);
        }
    }
}
void operationchar(stall game,int num1,int num2,float& ans)
{
    switch (game.operation)
    {
    case add:
        cout << num1 << "\n" << num2 << " +\n" << "_________\n";
        ans = num1 + num2;
        break;
    case sub:
        cout << num1 << "\n" << num2 << " -\n" << "_________\n";
        ans = num1 - num2;
        break;
    case mul:
        cout << num1 << "\n" << num2 << " *\n" << "_________\n";
        ans = num1 * num2;
        break;
    case Div:
        cout << num1 << "\n" << num2 << " /\n" << "_________\n";
        ans = round((float)num1 / (float)num2);
        break;
    case mixo:

        switch (randnum(1, 4))
        {
        case 1:
            cout << num1 << "\n" << num2 << "  +\n" << "_________\n";
            ans = num1 + num2;
            break;
        case 2:
            cout << num1 << "\n" << num2 << "  -\n" << "_________\n";
            ans = num1 - num2;
            break;
        case 3:
            cout << num1 << "\n" << num2 << " *\n" << "_________\n";
            ans = num1 * num2;
            break;
        case 4:
            cout << num1 << "\n" << num2 << " /\n" << "_________\n";
            ans = round((float)num1 / (float)num2);
            break;
        }
    }
}

string passorfail(stall game)
{
    if(game.numofright >= game.numofwrong)
    {
        system("color 2f");
		return "Pass";
    }
    else
    {
		system("color 4f");
		return "Fail";
	}
}
bool endscreen(stall game)
{
    cout <<string(20, ' ');
    for (int i = 0; i < 45; i++)
    {
        cout << "_";
    }
    cout <<"\n\n"
    <<string(32, ' ')
    << " Final Results Is "<<passorfail(game)<<"\n"
    <<string(20, ' ');
    for (int i = 0; i < 45; i++)
    {
        cout << "_";
    }
    cout << "\n\n"
    << string(20, ' ')
    << "Number Of Qustions      : "<<game.numofq << "\n"
    << string(20, ' ')
    << "Qustions Level          : " << printchoicelevel(choicelevel(game.level)) << "\n"
    << string(20, ' ')
    << "Operations Type         : " << printchoiceoperation(choiceoperation(game.operation) )<< "\n"
    << string(20, ' ')
    << "Number Of Right Answers : " << game.numofright << "\n"
    << string(20, ' ')
    << "Number Of Wrong Answers : " << game.numofwrong << "\n"
    << string(20, ' ');
    for (int i = 0; i < 45; i++)
    {
        cout << "_";
    }
	cout << "\n"
    << string(20, ' ')
	<< "Do You Want To Play Again ? (Y/N) : ";
    char playagain;
    cin >> playagain;
    if (playagain == 'Y' || playagain == 'y')
    {
        system("cls");
		system("color 07");
        return true;
    }
    else
    {
        cout << "\nGood Bye !";
        return false;
	}
}

void thegame(stall& game)
{
    bool bendscreen = true;
    do
    {
		int num1 = 0, num2 = 0;
		float ans = 0;
		game.numofright = 0;
		game.numofwrong = 0;
		game.numofq = readnum("Enter Number Of Questions ? ");
		game.level = choicelevel(readnum("Enter Questions Level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? "));
		game.operation = choiceoperation(readnum("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? "));
        for (int i = 1; i <= game.numofq; i++)
        {
            cout << "\n\n"
            << "question [" << i << "/" << game.numofq << "]\n\n";
			num1 = levelnum(choicelevel(game.level));
			num2 = levelnum(choicelevel(game.level));
			operationchar(game, num1, num2, ans);
            float userans;
            cin >> userans;
            if (userans == ans)
            {
				cout << "Right Answer !\n";
				system("color 2f");
                game.numofright++;
            }
            else
            {
				cout << "Wrong Answer ! \nThe Right Answer Is : " << ans << "\n\a";
                system("color 4f");
                game.numofwrong++;
            }
        }
        bendscreen = endscreen(game);
    } while (bendscreen);
}

int main()
{
	srand((unsigned)time(NULL));
    stall game;
    thegame(game);
}


