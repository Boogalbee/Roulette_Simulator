#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

int randomnum(){
	int num = rand() % 36;
	return num;
}

struct data{
	int location, frequency;
};

int main(){
	system("color 0a");

	srand(time(NULL));
	const int x = 1000;

	//Header Formatting
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "|Welcome to Caesar's Palace - Roulette|\n\n";
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "\t\tProgrammers:\n";
	cout << "\tAlec Bewsee && Zach Roy && Jason Byrd\n" << endl;

	int sum = 0;
	data total[x];

	for (int i = 0; i<36; i++){
		total[i].location = i;
		total[i].frequency = 0;
	}

	for (int i = 0; i<1000; i++){

		int bet[x];
		int winningnum[x];
		int wallet = 1000;
		data wheel[x];

		for (int k = 0; k<36; k++){
			wheel[k].location = k;
			wheel[k].frequency = 0;
		}

		for (int k = 0; k<x; k++){
			winningnum[k] = randomnum();
			bet[k] = randomnum();

			for (int i = 0; i<x; i++){
				if (winningnum[k] == wheel[i].location){
					++wheel[i].frequency;
					++total[i].frequency;
				}
			}
		
			if (bet[k] == winningnum[k])
				wallet += 34;
			else
				wallet -= 1;
		}
		if (i == 1){
			cout << "location\tfrequency\n";
			for (int k = 0; k<36; k++)
			{
				cout << wheel[k].location << "\t\t" << wheel[k].frequency << endl;

			}
			cout << endl << "After " << x << " bets, gambler has $" << wallet << endl;
		}
		sum += wallet;
	}

	cout << "1000 Times" << endl << endl;
	cout << "Location\tFrequency" << endl;
	
	for (int i = 0; i<36; i++){
		cout << total[i].location << "\t\t" << total[i].frequency << endl;
	}

	int average = sum / 1000;
	cout << "After 1000 bets, Average is $" << average << endl;

}
