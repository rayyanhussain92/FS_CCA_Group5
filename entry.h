//Abstract Base Class for All Financial Entries
class Entry {
protected:

    int id;
    string date;
    string note;
    string type;
    double money;
    static int nextId; //Used to generate automatic IDs

public:

    Entry(string d, double m, string n, string t) {
    	//Prevents negative values
        if (m < 0)
            throw string("Amount cannot be negative.");

		//Prevents empty fields
        if (d.empty() || n.empty() || t.empty())
            throw string("Input fields cannot be empty.");

        id = nextId++;
        date = d;
        money = m;
        note = n;
        type = t;
    }

    virtual ~Entry() {}

	//Pure Virtual Functions for Polymorphism   
	virtual string label() const = 0;
    virtual double value() const = 0;
	
	//Displays transaction details
    virtual void show() const {
        cout << left << setw(4) << id << setw(12) << date << setw(11) << label() << setw(22) << note
             << setw(16) << type << right << fixed << setprecision(2) << setw(9) << money << "\n";
    }

	//Getters
    int getId() const {
        return id;
    }

    double getMoney() const {
        return money;
    }

    string getType() const {
        return type;
    }

    string getDate() const {
        return date;
    }

    string getNote() const {
        return note;
    }
};

//Starting ID Number
int Entry::nextId = 1;