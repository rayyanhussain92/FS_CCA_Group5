//Header Files for different workings
#include"heading.h"
#include"entry.h"
#include"InExSa.h"
#include"wallet.h"
#include"exception.h"
#include"menu.h"

//Entry point for the program - It prompts the user
int main() {

    try {
        heading("Welcome to Personal Finance Tracker");
        string name;
        cout << "\n  Enter your name: ";
        getline(cin, name);
        
		//Default to "user" if the name field was left blank
		if (name.empty())
            name = "User";

		//Create the wallet object
        Wallet w(name);

		//Show the empty initial state
        w.showAll();
        w.summary();
        w.showBudget();
        
        //Interactive Menu Loop
		menu(w);
    }

	//Catch any unhandled exceptions
    catch (string errorMessage) {

        cout << "\nError: "
             << errorMessage
             << "\n";
    }

    return 0;
}