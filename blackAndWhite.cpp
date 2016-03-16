#include <iostream>
#include <string>
#include <vector>

using namespace std;

class state
{
	vector <string> board;
	//int black;
	//int white;
	state* father;
	int costTotal;
	int moveCost;

public:
	state()
	{
		//this->black = black;
		//this->white = white;
		for (int i = 0; i < 3; i++)
		{
			board.push_back("white");
		}
		for (int i = 0; i < 3; i++)
		{
			board.push_back("black");
		}
		board.push_back("space");

		father = NULL;
		costTotal = 0;
		moveCost = 0;

	}
	//answers
	state(string a, string b, string c, string d, string e, string f, string g)
	{
		board.push_back(a);
		board.push_back(b);
		board.push_back(c);
		board.push_back(d);
		board.push_back(e);
		board.push_back(f);
		board.push_back(g);
	}
	//generating a new state
	state(state* father, int costTotal, int moveCost, int move) // move is gonna have int where space is going
	{
		this->father = father;
		this->costTotal = costTotal;
		this->moveCost = moveCost;

		int i =0;
		state* temp = father;
		while(temp->board[i] != "space")
		{
			i++;
		}
		board = father->board;
		board[i] = board[move];
		board[move] = "space";
	}

};

class puzzle
{
	vector <state*> answers;
	vector <state*> solution;
	vector <state*> openList;
	vector <state*> closedList;
	state* currentState;

	puzzle()
	{
		answers.push_back(new state("space","black","black","black","white","white","white"));
		answers.push_back(new state("black","space","black","black","white","white","white"));
		answers.push_back(new state("black","black","space","black","white","white","white"));
		answers.push_back(new state("black","black","black","space","white","white","white"));
		answers.push_back(new state("black","black","black","white","space","white","white"));
		answers.push_back(new state("black","black","black","white","white","space","white"));
		answers.push_back(new state("black","black","black","white","white","white","space"));
		currentState = NULL;

		state initial();
		while(checkAnswer())
		{

		}
	}
	
	bool checkAnswer()
	{
		for(int i =0 ; i< 7; i++)
		{
			if(currentState == answers[i])
				return true;
		}
		return false;
	}

};

int main()
{
	puzzle sup();
	
	return 0;
}
