#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class state
{
public:	
	state* father;
	int costTotal;
	int moveCost;
	int spaceNb;
	vector <string> board;

	state()
	{
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
		spaceNb = 6;

	}
	//generating a new state
	state(state* father, int costTotal, int moveCost, int move) // move is gonna have int where space is going
	{
		this->father = father;
		this->costTotal = costTotal;
		this->moveCost = moveCost;

		int i = 0;
		state* temp = father;
		while (temp->board[i] != "space")
		{
			i++;
		}
		spaceNb = move;
		board = father->board;
		board[i] = board[move];
		board[move] = "space";
	}

};

class sortHelp
{
public:
	bool operator()(const state* a, const state* b)
	{
		return a->costTotal < b->costTotal;
	}

};

class puzzle
{
public:
	vector <state*> solution;
	vector <state*> openList;
	vector <state*> closedList;
	state* currentState;

	puzzle()
	{
		currentState = NULL;
		
		openList.push_back(new state());
		currentState = openList[0];
		while (!checkAnswer())
		{
			bool flag = false;
			if (currentState->spaceNb == 6)
			{
				state* temp = new state(currentState, currentState->costTotal + 1, 1, 5);
				temp->costTotal += euristique(temp);
				if (checkIfSeenAlready(temp) == false)
				{
					openList.push_back(temp);
					flag = true;
				}
				temp = new state(currentState, currentState->costTotal + 1, 1, 4);
				temp->costTotal += euristique(temp);
				if (checkIfSeenAlready(temp) == false)
				{
					openList.push_back(temp);
					flag = true;
				}
				temp = new state(currentState, currentState->costTotal + 2, 2, 3);
				temp->costTotal += euristique(temp);
				if (checkIfSeenAlready(temp) == false)
				{
					openList.push_back(temp);
					flag = true;
				}
			}
			else
			{
				if (currentState->spaceNb == 5)
				{
					state* temp = new state(currentState, currentState->costTotal + 1, 1, 4);
					temp->costTotal += euristique(temp);
					if (checkIfSeenAlready(temp) == false)
					{
						openList.push_back(temp);
						flag = true;
					}
					temp = new state(currentState, currentState->costTotal + 1, 1, 3);
					temp->costTotal += euristique(temp);
					if (checkIfSeenAlready(temp) == false)
					{
						openList.push_back(temp);
						flag = true;
					}
					temp = new state(currentState, currentState->costTotal + 2, 2, 2);
					temp->costTotal += euristique(temp);
					if (checkIfSeenAlready(temp) == false)
					{
						openList.push_back(temp);
						flag = true;
					}
					temp = new state(currentState, currentState->costTotal + 1, 1, 6);
					temp->costTotal += euristique(temp);
				if (checkIfSeenAlready(temp) == false)
					{
						openList.push_back(temp);
						flag = true;
					}
				}
				else
				{
					if (currentState->board[4] == "space")
					{
						state* temp = new state(currentState, currentState->costTotal + 1, 1, 3);
						temp->costTotal += euristique(temp);
						if (checkIfSeenAlready(temp) == false)
						{
							openList.push_back(temp);
							flag = true;
						}
						temp = new state(currentState, currentState->costTotal + 1, 1, 2);
						temp->costTotal += euristique(temp);
						if (checkIfSeenAlready(temp) == false)
						{
							openList.push_back(temp);
							flag = true;
						}
						temp = new state(currentState, currentState->costTotal + 2, 2, 1);
						temp->costTotal += euristique(temp);
						if (checkIfSeenAlready(temp) == false)
						{
							openList.push_back(temp);
							flag = true;
						}
						temp = new state(currentState, currentState->costTotal + 1, 1, 5);
						temp->costTotal += euristique(temp);
						if (checkIfSeenAlready(temp) == false)
						{
							openList.push_back(temp);
							flag = true;
						}
						temp = new state(currentState, currentState->costTotal + 1, 1, 6);
						temp->costTotal += euristique(temp);
						if (checkIfSeenAlready(temp) == false)
						{
							openList.push_back(temp);
							flag = true;
						}
					}
					else
					{
						if (currentState->board[3] == "space")
						{
							state* temp = new state(currentState, currentState->costTotal + 1, 1, 2);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
							temp = new state(currentState, currentState->costTotal + 1, 1, 1);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
							temp = new state(currentState, currentState->costTotal + 2, 2, 0);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
							temp = new state(currentState, currentState->costTotal + 1, 1, 4);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
							temp = new state(currentState, currentState->costTotal + 1, 1, 5);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
							temp = new state(currentState, currentState->costTotal + 2, 2, 6);
							temp->costTotal += euristique(temp);
							if (checkIfSeenAlready(temp) == false)
							{
								openList.push_back(temp);
								flag = true;
							}
						}
						else
						{
							if (currentState->spaceNb == 2)
							{
								state* temp = new state(currentState, currentState->costTotal + 1, 1, 1);
								temp->costTotal += euristique(temp);
								if (checkIfSeenAlready(temp) == false)
								{
									openList.push_back(temp);
									flag = true;
								}
								temp = new state(currentState, currentState->costTotal + 1, 1, 0);
								temp->costTotal += euristique(temp);
								if (checkIfSeenAlready(temp) == false)
								{
									openList.push_back(temp);
									flag = true;
								}
								temp = new state(currentState, currentState->costTotal + 1, 1, 3);
								temp->costTotal += euristique(temp);
								if (checkIfSeenAlready(temp) == false)
								{
									openList.push_back(temp);
									flag = true;
								}
								temp = new state(currentState, currentState->costTotal + 1, 1, 4);
								temp->costTotal += euristique(temp);
								if (checkIfSeenAlready(temp) == false)
								{
									openList.push_back(temp);
									flag = true;
								}
								temp = new state(currentState, currentState->costTotal + 2, 2, 5);
								temp->costTotal += euristique(temp);
								if (checkIfSeenAlready(temp) == false)
								{
									openList.push_back(temp);
									flag = true;
								}
							}
							else
							{
								if (currentState->spaceNb == 1)
								{
									state* temp = new state(currentState, currentState->costTotal + 1, 1, 0);
									temp->costTotal += euristique(temp);
									if (checkIfSeenAlready(temp) == false)
									{
										openList.push_back(temp);
										flag = true;
									}
									temp = new state(currentState, currentState->costTotal + 1, 1, 2);
									temp->costTotal += euristique(temp);
									if (checkIfSeenAlready(temp) == false)
									{
										openList.push_back(temp);
										flag = true;
									}
									temp = new state(currentState, currentState->costTotal + 1, 1, 3);
									temp->costTotal += euristique(temp);
									if (checkIfSeenAlready(temp) == false)
									{
										openList.push_back(temp);
										flag = true;
									}
									temp = new state(currentState, currentState->costTotal + 2, 2, 4);
									temp->costTotal += euristique(temp);
									if (checkIfSeenAlready(temp) == false)
									{
										openList.push_back(temp);
										flag = true;
									}
								}
								else
								{
									if (currentState->spaceNb == 0)
									{
										state* temp = new state(currentState, currentState->costTotal + 1, 1, 1);
										temp->costTotal += euristique(temp);
										if (checkIfSeenAlready(temp) == false)
										{
											openList.push_back(temp);
											flag = true;
										}
										temp = new state(currentState, currentState->costTotal + 1, 1, 2);
										temp->costTotal += euristique(temp);
										if (checkIfSeenAlready(temp) == false)
										{
											openList.push_back(temp);
											flag = true;
										}
										temp = new state(currentState, currentState->costTotal + 2, 2, 3);
										temp->costTotal += euristique(temp);
										if (checkIfSeenAlready(temp) == false)
										{
											openList.push_back(temp);
											flag = true;
										}
									}
								}
							}
						}
					}
				}
			}
			
			if (flag == true)
			{
				state* temp3 = openList[0];
				openList.erase(openList.begin());
				closedList.push_back(temp3);
				sort(openList.begin(), openList.end(), sortHelp());
			}	

			currentState = openList[0];
		}
		cout << "complete" << endl;
	}

	bool checkAnswer()
	{
		int black = 0;
		int white = 0;
		for (unsigned int i = 0; i < currentState->board.size(); i++)
		{
			if (currentState->board[i] =="black")
			{
				black++;
			}
			else 
				if (currentState->board[i] == "white")
				{
					white++;
				}
			if (white > 0 && black < 3)
				return false;
			if (white == 0 && black == 3)
				return true;
		}
		return false;
	}

	bool checkIfSeenAlready(state* ptr)
	{
		for (unsigned int i = 0; i < openList.size(); i++)
		{
			if (openList[i]->board == ptr->board)
			{
				delete ptr;
				return true;
			}
		}
		for (unsigned int i = 0; i < closedList.size(); i++)
		{
			if (closedList[i]->board == ptr->board)
			{
				delete ptr;
				return true;
			}
				
		}
		return false;
	}
	int euristique(state* nextState)
	{
		int compteur = 0;
		int i = 0;
		for (int i = 0; i < nextState->board.size(); i++)
		{
			if (nextState->board[i] == "black")
				compteur += (i - 3);
		}
		return compteur;
	}
};

int main()
{

	puzzle a;

	return 0;
}
