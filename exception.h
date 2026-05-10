//Throws an exception if the input is blank
string text(string t) {

    cout << "  " << t << ": ";

    string s;

    getline(cin, s);
    if (s.empty())
        throw string("Input cannot be empty.");

    return s;
}

//Clears the input buffer and throws if the value is non-numeric or negative
double number(string t) {		

    cout << "  " << t << ": ";

    double n;

	//Check for non-numeric input
    if (!(cin >> n)) {
        cin.clear();
		
		//Discard the input remaining in the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        throw string("Invalid numeric input.");
    }

	//Consume the trailing newline after the number
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	//Negative amounts are not valid
    if (n < 0)
        throw string("Negative values are not allowed.");

    return n;
}