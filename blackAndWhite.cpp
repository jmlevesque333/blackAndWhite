#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class state
{
public:
	state* father; // which state was before this one
	int costTotal; // cost to get to this node + the euristique of the node
	int moveCost; // move cost between this state and its father
	int spaceNb; // which square space is in
	vector <string> board;

	state() // default state, the one we start with
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
		this->moveCost = father->moveCost + moveCost;

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

class sortHelp // to use with std::sort to help understand my class
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
	vector <state*> openList; // list of nodes discovered but yet to be explored
	vector <state*> closedList; // list of nodes explored
	state* currentState; // what makes this program work in every single way

	puzzle() // my whole program
	{
		currentState = NULL;

		openList.push_back(new state());
		currentState = openList[0];
		while (checkAnswer() != true || openList.empty() == true)
		{
			bool flag = false;
			if (currentState->spaceNb == 6) // check where space is and does stuff accordingly
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
				if (currentState->spaceNb == 5) // check where space is and does stuff accordingly
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
					if (currentState->board[4] == "space") // check where space is and does stuff accordingly
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
						if (currentState->board[3] == "space") // check where space is and does stuff accordingly
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
							if (currentState->spaceNb == 2) // check where space is and does stuff accordingly
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
								if (currentState->spaceNb == 1) // check where space is and does stuff accordingly
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
									if (currentState->spaceNb == 0) // check where space is and does stuff accordingly
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

			state* temp3 = openList[0];
			openList.erase(openList.begin());
			closedList.push_back(temp3);
			sort(openList.begin(), openList.end(), sortHelp());
			currentState = openList[0];
		}
		print();
	}

	bool checkAnswer() // checks if we've found a winner 
	{
		int black = 0;
		int white = 0;
		for (unsigned int i = 0; i < currentState->board.size(); i++) // check if theres three black infront of the first white
		{
			if (currentState->board[i] == "black")
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

	bool checkIfSeenAlready(state* ptr) // check if we need to generate or not
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
	int euristique(state* nextState) // what my program sorts by
	{
		int compteur = 0;
		int i = 0;
		for (int i = 0; i < nextState->board.size(); i++) // checks where eac h one of my blacks are and gives score accordingly
		{
			if (nextState->board[i] == "black")
				compteur += (i - 3);
		}
		return compteur;
	}

	void print() // what cout my stuff
	{
		vector <state> temp;
		
		while (currentState != NULL)
		{
			temp.insert(temp.begin(),*currentState);
			currentState = currentState->father;
		}
		for (int j = 0; j < temp.size(); j++)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << temp[j].board[i] << "\t";
			}
			cout << "\t" <<temp[j].moveCost;
			cout << endl;
		}
	}
};

int main()
{

	puzzle a; // whole program fits on one line yo 100/100

	return 0;
}
