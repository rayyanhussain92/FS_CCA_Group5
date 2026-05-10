//Child Class
class Income : public Entry {

public:

    Income(string d, double m, string n, string t)
        : Entry(d, m, n, t) {
    }

	//Returns entry type
    string label() const {
        return "Income";
    }

    double value() const {
        return money;
    }

	//Displays Income with a + sign
    void show() const {
        cout << "[+] ";
        Entry::show();
    }
};

//Child Class
class Expense : public Entry {
public:

    Expense(string d, double m, string n, string t)
        : Entry(d, m, n, t) {
    }
	
    string label() const {
        return "Expense";
    }

    double value() const {
        return -money;
    }

	//Displays expense with a - sign
    void show() const {
        cout << "[-] ";
        Entry::show();
    }
};

//Child Class
class Saving : public Entry {

public:

    Saving(string d, double m, string n, string acc)
        : Entry(d, m, n, "Savings") {
    }

    string label() const {
        return "Savings";
    }

    double value() const {
        return -money;
    }

	//Displays savings with s sign
    void show() const {
        cout << "[S] ";
        Entry::show();
    }
};

//Stores budget details for each category
struct Budget {
    double limit;
    double spent;

    Budget() {
        limit = 0;
        spent = 0;
    }
};