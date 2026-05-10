================================================================
        PERSONAL FINANCE TRACKER
        OOP CCP & CCA -- FSCT Section E -- Group 5
================================================================

----------------------------------------------------------------
PROBLEM DOMAIN
----------------------------------------------------------------
This program is a console-based personal finance management
system. It allows users to record and categorize financial
transactions (income, expenses, and savings transfers), set
monthly spending budgets per category with automatic alerts,
view summaries and reports, and export a final report to a
text file -- all through an interactive menu.

----------------------------------------------------------------
HOW TO COMPILE
----------------------------------------------------------------
Requirements:
  - A C++ compiler supporting C++11 or later (e.g. g++, MSVC)
  - All source files must be in the same folder:
      heading.h
      entry.h
      InExSa.h
      wallet.h
      exception.h
      menu.h
      Personal Finance Tracker.cpp

Compile on Linux / Mac:
  g++ "Personal Finance Tracker.cpp" -o finance

Compile on Windows (Command Prompt):
  g++ "Personal Finance Tracker.cpp" -o finance.exe

----------------------------------------------------------------
HOW TO RUN
----------------------------------------------------------------
Linux / Mac:
  ./finance

Windows:
  finance.exe

On launch, enter your name when prompted. The main menu will
appear. Use the numbered options to add transactions, set
budgets, view reports, and export your data.

----------------------------------------------------------------
IMPLEMENTED OOP FEATURES
----------------------------------------------------------------
1.  Encapsulation
    Private and protected data members (id, date, money, etc.)
    inside Entry and Wallet prevent direct external access.

2.  Abstraction
    Entry is an abstract base class with pure virtual functions
    label() and value(), hiding implementation details from the
    rest of the program.

3.  Inheritance
    Income, Expense, and Saving all inherit from Entry,
    reusing its shared attributes and interface.

4.  Polymorphism
    Virtual functions (label(), value(), show()) are overridden
    in each derived class and resolved at runtime through
    Entry* base-class pointers.

5.  Parameterized Constructors
    All classes use parameterized constructors to initialize
    objects with transaction details (date, amount, note, type)
    and budget information at the point of creation.

6.  Destructors
    Wallet's destructor (~Wallet) iterates over the items
    vector and calls delete on each Entry* pointer, releasing
    all dynamically allocated memory and preventing leaks.

7.  Static Member
    Entry::nextId is a static integer shared across all
    instances, automatically generating a unique ID for each
    new transaction.

8.  STL Containers
    vector<Entry*> stores all transactions in Wallet.
    map<string, Budget> stores per-category budget data,
    providing efficient lookup by category name.

9.  Dynamic Memory Allocation
    Transactions are created on the heap using new Income(),
    new Expense(), and new Saving(), stored as Entry* pointers
    for runtime polymorphism and flexible memory management.

10. File Handling
    The exportReport() method in Wallet uses fstream (ofstream)
    to write a formatted financial summary to report.txt.

11. Exception Handling
    Input helpers text() and number() throw string exceptions
    for empty input, non-numeric values, and negative amounts.
    The menu loop catches and displays these errors cleanly.

12. Composition
    Wallet contains a vector of Entry* objects and a map of
    Budget structs, demonstrating that a Wallet is composed of
    and fully owns its transaction and budget data.

================================================================
