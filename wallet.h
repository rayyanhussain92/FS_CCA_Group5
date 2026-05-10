//Main wallet class - Handles all financial operations
class Wallet {

	//Stores all transactions
    vector<Entry*> items;
    
    //Stores budget by category
    map<string, Budget> budget;

    string owner;
    double saved;

public:

    Wallet(string n) {

        owner = n;
        saved = 0;
    }

	//Destructor frees allocated memory
    ~Wallet() {

        for (int i = 0; i < items.size(); i++)
            delete items[i];
    }

    void addIncome(string d, double m, string n, string t) {
        items.push_back(new Income(d, m, n, t));
        cout << "  >> Income added (ID "<< items.back()->getId()<< ")\n";
    }

    void addExpense(string d, double m, string n, string t) {
        items.push_back(new Expense(d, m, n, t));
        
		if (budget.count(t))
            budget[t].spent += m;
        cout << "  >> Expense added (ID "<< items.back()->getId()<< ")\n";

		//Checks warning or exceeded limit
        if (budget.count(t)) {
            double used =
                (budget[t].spent / budget[t].limit) * 100;

            if (budget[t].spent > budget[t].limit) {

                cout << "\n" << line('!', 54)<< "\n Budget exceeded for category: [" << t << "]\n"
                     << line('!', 54) << "\n";
            }

            else if (used >= 80) {

                cout << "\n" << line('*', 54) << "\n Budget warning for category: "<< t << "\n"
                     << line('*', 54) << "\n";
            }
        }
    }

    void addSaving(string d, double m, string n, string a) {
        items.push_back(new Saving(d, m, n, a));
        saved += m;
        cout << "  >> Savings transfer added (ID " << items.back()->getId()<< ")\n";
    }

    void setBudget(string t, double l) {

		//Prevents invalid budget values
        if (l <= 0)
            throw string("Budget must be greater than 0.");

        budget[t].limit = l;

        cout << "  >> Budget set: [" << t << "] = $" << fixed << setprecision(2) << l << "\n";
    }

	//Remove transactions using ID
    bool remove(int id) {

        for (int i = 0; i < items.size(); i++) {

            if (items[i]->getId() == id) {
                delete items[i];
                items.erase(items.begin() + i);
                return true;
            }
        }

        return false;
    }

    double totalIncome() const {

        double total = 0;
        for (int i = 0; i < items.size(); i++) {
            if (items[i]->value() > 0)
                total += items[i]->value();
        }

        return total;
    }

    double totalExpense() const {
        double total = 0;
        for (int i = 0; i < items.size(); i++) {
            if (items[i]->value() < 0)
                total += items[i]->getMoney();
        }

        return total;
    }

	//Displays all transactions
    void showAll() const {

        heading("All Transactions  --  " + owner);

        cout << "     "
             << left << setw(4) << "ID" << setw(12) << "Date" << setw(11) << "Type"<< setw(22) << "Description"
             << setw(16) << "Category"<< right << setw(9) << "Amount"<< "\n" << line('-', 78)<< "\n";

        for (int i = 0; i < items.size(); i++)
            items[i]->show();

        cout << line('-', 78) << "\n";
    }

    void summary() const {

        heading("Financial Summary");

        double income = totalIncome();
        double expense = totalExpense();
        double net = income - expense;

        cout << fixed << setprecision(2);

        cout << "  Total Income    : $" << income << "\n";
        cout << "  Total Expenses  : $" << expense << "\n";
        cout << "  Savings Balance : $" << saved << "\n";
        cout << "  Net Balance     : $" << net << "\n";

		//Warning if expenses exceed income
        if (net < 0)
            cout << "\n  WARNING: Spending exceeds income! ***\n";
    }

    void showBudget() const {

        heading("Budget Status");

        if (budget.empty()) {

            cout << "  No budgets set.\n";
            return;
        }

        cout << left << setw(16) << "Category" << setw(10) << "Limit" << setw(10) << "Spent"
             << setw(12) << "Remaining"<< setw(8) << "Used%"<< "Status\n"<< line('-', 70)<< "\n";

        map<string, Budget>::const_iterator it;

        for (it = budget.begin(); it != budget.end(); ++it) {

            double remain =
                it->second.limit - it->second.spent;

            double used = 0;

            if (it->second.limit > 0)
                used =
                    (it->second.spent /
                     it->second.limit) * 100;

            string state = "OK";

            if (it->second.spent > it->second.limit)
                state = "OVER BUDGET";

            else if (used >= 80)
                state = "WARNING";

            cout << left << setw(16) << it->first<< "$"<< right << setw(8)<< fixed << setprecision(2)
                 << it->second.limit<< "  $" << setw(8) << it->second.spent << "  $"
                 << setw(10)<< left << remain << right << setw(6)<< setprecision(1) << used
                 << "%  " << state << "\n";
        }
    }

	//Exports report to a text file
    void exportReport() const {

        ofstream file("report.txt");

		//Checks if file was created successfully
        if (!file)
            throw string("Could not create report file.");

        file << "PERSONAL FINANCE REPORT\n";
        file << "========================\n\n";

        file << "Owner: " << owner << "\n\n";

        file << "Total Income: $" << totalIncome() << "\n";
        file << "Total Expense: $" << totalExpense() << "\n";
        file << "Savings: $" << saved << "\n";

        file.close();

        cout << "\n  >> Final report exported to report.txt\n";
    }
};