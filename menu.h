//Displays the main menu in a loop and dispatches user choices to the appropriate wallet method
//All input errors are caught and displayed in line
void menu(Wallet& w) {

    int ch = 0;

    while (true) {

        heading("Personal Finance Tracker -- Menu");

		//Print all available menu options
        cout << "  1.  Add Income\n"
             << "  2.  Add Expense\n"
             << "  3.  Add Savings Transfer\n"
             << "  4.  Set Budget\n"
             << "  5.  View All Transactions\n"
             << "  6.  View Financial Summary\n"
             << "  7.  View Budget Status\n"
             << "  8.  View Sorted by Amount\n"
             << "  9.  Filter by Category\n"
             << "  10. Remove Transaction by ID\n"
             << "  11. Export Final Report\n"
             << "  0.  Exit\n"
             << line('-', 40)
             << "\n"
             << "  Your choice: ";

        try {
			
			//Validate that the user entered a number
            if (!(cin >> ch)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw string("Invalid menu choice.");
            }

			//Consume newline so getline() calls work correctly
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

			//Declare reusable input variables for all cases
            string d, n, t, a;
            double m;
            int id, s;

            switch (ch) {

            case 1:

                d = text("Date (YYYY-MM-DD)");
                m = number("Amount");
                n = text("Description");
                t = text("Category");

                w.addIncome(d, m, n, t);
                break;

            case 2:

                d = text("Date (YYYY-MM-DD)");
                m = number("Amount");
                n = text("Description");
                t = text("Category");

                w.addExpense(d, m, n, t);
                break;

            case 3:

                d = text("Date (YYYY-MM-DD)");
                m = number("Amount");
                n = text("Description");
                a = text("Target Account");

                w.addSaving(d, m, n, a);
                break;

            case 4:

                t = text("Category name");
                m = number("Monthly spending limit ($)");

                w.setBudget(t, m);
                break;

            case 5:

                w.showAll();
                break;

            case 6:

                w.summary();
                break;

            case 7:

                w.showBudget();
                break;

            case 11:

                w.exportReport();
                break;

            case 0:

                cout << "\n  Goodbye!\n\n";
                return;

			//Unrecognized option entered
            default:

                cout << "  Invalid choice. Try again.\n";
            }
        }

		//Catch any string exceptions thrown by input helpers or wallet methods and display them as errors
        catch (string errorMessage) {

            cout << "\n  ERROR: "
                 << errorMessage
                 << "\n";
        }

        cout << "\n  Press Enter to continue...";

        cin.get();
    }
}