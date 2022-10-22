/*
----------------------------------------------
NAME: LUQMAN HANIS DANIEL BIN KHAILMI
TITLE: CASHIER SYSTEM
COPYRIGHT(C) 2022
----------------------------------------------
*/

#include <iostream>
using namespace std;

// login system
bool login() {
	// declare staff name and id;
	string staff1_id = "luqman";
	string staff1_password = "luq123";
	
	string staff2_id = "daniel";
	string staff2_password = "dan123";
	
	// Login interface (id)
	string user_id;
	string user_password;
	
	// ID check
	bool id_check = false;
	while (id_check == false) {
		cout << "-----------------------------------------" << endl;
		cout << "Please enter staff ID : ";
		cin >> user_id;
		
		// if the user enters the correct ID
		if (user_id == staff1_id || user_id == staff2_id) {
			id_check = true;
		}
		// if the user enters the wrong ID
		else {
			cout << "Invalid staff ID!" << endl;
		}
	}
	
	// Password check
	bool password_check = false;
	while (password_check == false) {
		cout << "-----------------------------------------" << endl;
		cout << "Please enter staff password : ";
		cin >> user_password;
		
		// if teh user enters the correct ID
		if (user_password == staff1_password || user_password == staff2_password) {
			if (user_id == staff1_id && user_password == staff1_password) {
				password_check = true;
			} else if (user_id == staff2_id && user_password == staff2_password) {
				password_check = true;
			} else {
				cout << "Invalid staff password!" << endl;
			}
		}
		// if the user enters the wrong password
		else {
			cout << "Invalid staff password!" << endl;
		}
	}
	
	// cashier access (yes/no)
	bool cashier_check = false;
	
	if (id_check == true && password_check == true) {
		cashier_check = true;
	}
	
	// return yes value
	return cashier_check;
}

//------------------------------------------------------------------------------------------------------------------------

// cashier menu
void cashier_menu() {
	cout << "-------------------------------------------" << endl;
	cout << "|--------------Cashier Menu---------------|" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "| 1) Cash Calculator ------------------ 1 |" << endl;
	cout << "| 2) Total Profit --------------------- 2 |" << endl;
	cout << "| 3) Software Information ------------- 3 |" << endl;
	cout << "| 4) Log Out -------------------------- 4 |" << endl; 
	cout << "-------------------------------------------" << endl;
}

//-------------------------------------------------------------------------------------------------------------------------

void menu() {
	cout << "-------------------------------------------" << endl;
	cout << "|-------------------Menu------------------|" << endl;
	cout << "|-----------------------------------------|" << endl;
	cout << "| 1) Maggi Goreng ------------------ RM 5 |" << endl;
	cout << "| 2) Maggi Kari -------------------- RM 5 |" << endl;
	cout << "| 3) Extrajoss --------------------- RM 3 |" << endl;
	cout << "| 4) Done ------------------------------- |" << endl; 
	cout << "-------------------------------------------" << endl;
}

// ------------------------------------------------------------------------------------------------------------------------

float cash_calculator() {
	cout << "You had been redirected to the Cash Calculator system." << endl;
	float totalItem = 0;
	float definitelyTotalPrice = 0;
	float totalPrice = 0;
	bool continue_transactions = true;
	while (continue_transactions == true) {
	
		// display menu
		menu();
		
		// get user item
		
		int order;
		cout << "Choose item : ";
		cin >> order;
		
		// key condition
		if (order == 1) {
			// maggi goreng
			totalItem = totalItem + 1;
			totalPrice = totalPrice + 5;
			cout << "----------------" << endl;
			cout << "Maggi Goreng added to the list." << endl;
			cout << "Total items : " << totalItem << endl;
			cout << "TotalPrice : RM " << totalPrice << endl;
		} else if (order == 2) {
			// maggi kari
			totalItem = totalItem + 1;
			totalPrice = totalPrice + 5;
			cout << "----------------" << endl;
			cout << "Maggi Kari added to the list." << endl;
			cout << "Total items : " << totalItem << endl;
			cout << "TotalPrice : RM " << totalPrice << endl;
		} else if (order == 3) {
			// extrajoss
			totalItem = totalItem + 1;                       
			totalPrice = totalPrice + 3;
			cout << "----------------" << endl;
			cout << "Extrajoss added to the list." << endl;
			cout << "Total items : " << totalItem << endl;
			cout << "TotalPrice : RM " << totalPrice << endl;
		} else if (order == 4) {
			// quit
			cout << "Done..." << endl;
			
			// make sure the customers have enough money to purchase
			bool enough = false;
			while (enough == false) {
				if (totalPrice == 0) {
					enough = true;
				} else {
					cout << "-------------------------------------" << endl;
					cout << "Total items : " << totalItem << endl;
					cout << "Total amount : RM " << totalPrice << endl;
					cout << "-------------------------------------" << endl;
					
					// get total cash from customer
					cout << "Input money : RM ";
					float custMoney;
					cin >> custMoney;
					
					if (custMoney - totalPrice >= 0) {
						cout << "Total change is : RM " << custMoney - totalPrice << endl;
						cout << "Thank you!" << endl;
						definitelyTotalPrice = definitelyTotalPrice + totalPrice;
						enough = true;
						
						// reset for new customer
						totalPrice = 0;
					} else {
						cout << "Not enough money!" << endl;
					}
				}
				
			}
			
			}
		
		cout << "Continue transactions? (y/n) : ";
		string answer;
		cin >> answer;
		if (answer == "n") {
			continue_transactions = false;
			return definitelyTotalPrice;
		}
		
	}
	return definitelyTotalPrice;
}

//-----------------------------------------------------------------------------------------------------

void software_informations() {
	cout << "------------------------" << endl;
	cout << "SOFTWARE INFORMATIONS" << endl;
	cout << "Maintainer : Luqman Hanis Daniel bin Khailmi" << endl;
	cout << "Current version : 1.2" << endl;
	cout << "Publish date : 21/10/2022" << endl;
	cout << "Last update : 23/10/2022" << endl;
	cout << "------------------------" << endl;
}

int main() {
	// // continuous commmand until the user decide to shut down the program
	bool shutdown = false;
	while (shutdown == false) {
	
		bool cashier_access = login();
		
		if (cashier_access == true) {
			
			// continuous commmand until the user decide to log out the program
			bool login_required = false;
			
			while (login_required == false) {
				int menu_key;
				
				// variable
				
				float totalCash;
				float totalProfit;
			
				// display cashier menu
				cashier_menu();
				cout << "Menu key (1-4) : ";
				cin >> menu_key;
				
				if (menu_key == 1) {
					bool continue_cash = true;
					while (continue_cash == true) {
						totalCash = cash_calculator();
						totalProfit = totalProfit + totalCash;
						cout << "Continue transactions? (y/n) : ";
						string continue_yn;
						cin >> continue_yn;
						
						if (continue_yn == "n") {
							continue_cash = false;
						}
					}
				} else if (menu_key == 3) {
					bool continue_info = true;
					
					while (continue_info == true) {
						software_informations();
						string exit;
						cout << "Exit? Press 'q' : ";
						cin >> exit;
						if (exit == "q") {
							continue_info = false;
						}
					}
				} else if (menu_key == 2) {
					bool continue_total = true;
					while (continue_total == true) {
						cout << "\nTotal profit is RM " << totalProfit << endl;
						cout << "\nExit? Press 'q': ";
						string exit;
						cin >> exit;
						if (exit == "q") {
							continue_total = false;
						}
					}
				} else if (menu_key == 4) {
					bool logout_prompt = false;
					while (logout_prompt == false) {
						cout << "Are you sure? (y/n): ";
						string logout;
						cin >> logout;
						if (logout == "y") {
							login_required = true;
							logout_prompt = true;
						}
					}
				} else {
					cout << "Invalid key!" << endl;
				}
			}
			
		}
	}
	return 0;
}
