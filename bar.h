 
#include <iostream>
#include <string>
using namespace std;


class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    string name; // will store the name of the bar.
    int value; // will store the value of each bar.
    string category; // will store the category of each bar.

 public:

    // default constructor:
    Bar() {
        
        // all the variables are set to their default values.
        name = "";
        value = -1;
        category = ""; 
        
    }

    //
    // a second constructor with parameters:
    // once we create an object of type bar we can pass values into the parameters to assign the private variables with the values passed in.
    // takes name, value, and category as parameters which are the characteristics of a bar.
    // returns nothing since is a constructor
    Bar(string name, int value, string category) {
        
        // TO DO:  Write this constructor.
        this->name = name;
        this->value = value;
        this->category = category;
        
    }

    // destructor:
    virtual ~Bar() {
        
        // TO DO:  Write this destructor or leave empty if not needed.
        
    }

    // getName: returns the name private varible.
	string getName() {
        return name;
	}

    // getValue: returns the value private varible.
	int getValue() {

        return value;
	}

    // getCategory: returns a category value 
	string getCategory() {
        
        return category;
    }

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.
    // these functions compare the left object with the right object.
    // returns a bool value where the comparison is right/true or wrong/false.
	bool operator<(const Bar &other) const {
        if(this->value < other.value) {
            return true;
        }
        return false;
	}

	bool operator<=(const Bar &other) const {
        if(this->value <= other.value) {
            return true;
        }
        return false;
	}

	bool operator>(const Bar &other) const {
        if(this->value > other.value) {
            return true;
        }
        return false;
	}

	bool operator>=(const Bar &other) const {
        if(this->value >= other.value) {
            return true;
        }
        return false;
	}
};

