#include <iostream>
#include <string>
#include <vector>

using namespace std;

class game
{
	vector <string> board;
	int black;
	int white;
public:
	game(int black, int white)
	{
		this->black = black;
		this->white = white;
		
		for (int i = 0; i < black; i++)
		{
			board.push_back("black");
		}

		for (int i = 0; i < white; i++)
		{
			board.push_back("white");
		}
		
		board.push_back("space");
	}
};

int main()
{
	game a(3,3);
	
	return 0;
}
