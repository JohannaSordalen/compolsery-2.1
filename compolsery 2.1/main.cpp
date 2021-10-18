#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>


//used for terminating program
bool isCorrect{ false };

void password();
void blackjack();
int deal_card();

int main() {
	
	

	password();

	srand(time(0));

	
	if (isCorrect == true) {
		blackjack();
	}

	return 0;

}


void password() {
	std::string userinputname;
	std::string userinputpass;


	for (int i = 0; i < 3; i++) {
		std::cout << "username: ";
		std::cin >> userinputname;
		std::cout << "password: ";
		std::cin >> userinputpass;


		if (userinputname == "cutee" && userinputpass == "adminpass") {
			isCorrect = true;
			break;
		}
		else (std::cout << "invalade username or password" << std::endl);
	}
}



int deal_card() {

	
	int val = 0;
	
		
		val = rand() % 13 + 1;
		if (val > 10) val = 10;
	
		return val;

}


void blackjack() {
	std::cout << " " << std::endl;
	std::cout << "welcome to black jack!!!" << std::endl << std::endl;
	std::cout << "minimun bet is 10$!" << std::endl;
	std::cout << "to quit program press 0 in betting area" << std::endl << std::endl;

	// amount of cards and cards that get dealt
	int player_card=0;
	int player_total=0;
	int house_card = 0;
	int house_total = 0;

	int player_money = 100; // all the money the player has/starts with
	int house_money = 100; // all the money the house has/starts with
	// player comands
	int bet;
	char player_choice;
	char exit_game;
	
	

	

	while (player_money > 0 && house_money > 0 && player_money > 10)
	{
		player_total = 0;
		house_total = 0;
		

		std::cout << " " << std::endl <<std::endl;
		std::cout << "You have |" << player_money << "$| available" << std::endl;
		std::cout << "How much do you want to bet?" << std::endl;
		do
		{
			std::cin >> bet;
			

			if (bet == 0) {
				exit(0);
			}
			else if (bet > player_money) {
				std::cout << "You dont have enough money! " << std::endl;
				std::cout << "Place new bet" << std::endl;

			}
			else if (bet < 10) {
				std::cout << "too little money D:" << std::endl;
				std::cout << "Place new bet" << std::endl;
			}
			else if (bet > house_money) {
				std::cout << "house does not have that much money!!!" << std::endl;
				std::cout << "Place new bet" << std::endl;
			}


			



		} while (bet > player_money || bet < 10 || bet>house_money);


		
		
		do
		{
			std::cout << " " << std::endl;
			player_card = deal_card();

			if (player_card == 1) {
				std::cout << "Should ace be 1(n) or 11(m)? " << std::endl;
				std::cin >> player_choice;
				if (player_choice == 'm') {
					player_total = player_total + 11;
					
				}
				if (player_choice == 'n') {
					player_card = 1;
					
				}
				

			}
		

			player_total = player_total + player_card;
			std::cout << "Player's card  |" << player_card <<"| " << std::endl;

			std::cout << "Total value is |" << player_total << "| " << std::endl;
			

			if (player_total > 21) {
				std::cout << "You |lose|" << std::endl;
				player_money = player_money - bet;
				house_money = house_money + bet; 
				
				break;
			}

			std::cout << " " << std::endl;
			std::cout << "Do you want to hit(h) or stand(s)?" << std::endl;

			std::cin >> player_choice;

			
			 if (player_choice == 's') {
				break;
			}
			 if (player_choice == 'h') {
				continue;
			}

			

		}
		while (player_total < 22);

	

		if (player_choice == 's') {
				//dealers turn
			std::cout << " " << std::endl;
			std::cout << "dealers turn" << std::endl;
			 do
				 {
				 
				
				std::cout << " " << std::endl;
				
				house_card= deal_card();

				

				if (house_card == 1 && house_total > 1) {
					house_card = house_card + 11;
				}
				if (house_total == 1 && house_total > 12) {
					house_card = house_card+ 1;
				}
				
				
				house_total = house_total + house_card;
				std::cout << "House's card   |" << house_card << "| " << std::endl;
				std::cout << "Total value is |" << house_total << "| " << std::endl;
			 
				
				if (house_total > 21)
				{
					std::cout << "You |win|" << std::endl << std::endl;
					player_money = player_money + bet;
					house_money = house_money - bet;
					break;
				}

			

				if ( house_total > 21 || house_total > player_total)
				{
					std::cout << "You |lose|" << std::endl << std::endl;
					player_money = player_money - bet;
					house_money = house_money + bet;
					break;

				}
				if (house_total == player_total)
				{
					std::cout << "It's a |tie|";
					break;
				}
				
			} while (true);



			}
		;
	}


}


