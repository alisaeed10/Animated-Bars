
#include <iostream>
#include <algorithm>
#include <map>
#include "bar.h"

using namespace std;


const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for darker mode terminals

const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};


class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity; //number of spaces we have in the array
    int size; // the number of elements in the array
    string frame; //basically like a picture of what the bars look like at that frame.
    
 public:
    
    // default constructor:
    //contains all default values.
    //returns nothing since its a constructor.
    BarChart() {       
        // every varible is set to default.
         frame = "";
         size = 0;
         capacity = 0;
         bars = new Bar[capacity];
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    //returns nothing since its a constructor.
    BarChart(int n) {
        if(n < 0 || n == 0){
            cout << "Enter a positive non-zero number" << endl;
        }
        else {
            this->capacity = n; // n being the number of rooms to allocate, should be assign to capacity because that lets us st
            this->bars = new Bar[capacity]; // now we allocate the capacity amount of memory into bars pointer.
            this->size = 0; // set to defualt because there is nothing in that new space that was allocated.
            this->frame = "";
        }
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value. 
    // the parameter is an object of type BarChart because we want to copy the barChart to the other BarChart object
    //returns nothing since its still a constructor.
    BarChart(const BarChart& other) {

        this->frame = other.frame;
        this->capacity = other.capacity; // this copys the elements of the objects that is being passed to the existing varibles.
        this->size = other.size; // copies the size of the object being passed to the objected being used in the function.
        this->bars = new Bar[other.capacity]; // this copies the objects memeory into the object thats being used in the function.

        for(size_t i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
    }
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    // It assign all the values in the right object to the left object. However we first have to the delete everything in the left object.
    // returnds the new values of the object on the left.
    BarChart& operator=(const BarChart& other) {
        
        if(this == &other) {
            return *this;
        }
    
        delete[] this->bars; // deletes the memory of the varible thats being assinged to.
        
        this->capacity = other.capacity; // assigns the number of capacity in the array to the object being assigned
        this->size = other.size; // the assigned object now has the same size as the object on the left of the = operator
       
        this->bars = new Bar[other.capacity]; // the memory or address of the pointer on the right of the = oprator to the object on the left.
        this->frame = other.frame;
        //copies all the elements from object on the right to the object on the left.
        for(size_t i = 0; i < other.size; i++) {
            this->bars[i] = other.bars[i];
        }
        return *this;   // returns the new values
    }

    // clear
    // frees memory and resets all private member variables to default values.
    // if the array is null then theres nothing to delete so it just prints a message.
    // returns void.
    void clear() {
        if(bars == nullptr){
            cout << "There is no memeory to clear." << endl;
        }
        else{
            delete[] bars; // this frees all the memory that was allocated.
            bars = nullptr; // sets the pointer to point to null.
            size = 0; // we're deleting all the elements in the array/pointer
            capacity = 0; // setting the capacity to zero since we're deleting the memory
        }       
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart. Also is called when tring to add elements when we are out of scope.
    //
    virtual ~BarChart() {

        if(size > capacity) {
            delete [] bars;
        }
        else{
            delete [] bars;
            bars = nullptr;
        }
    }
    
    // setFrame: it assigns the value that was passed in to the private data variable frame.
    //takes in a string which is the frame
    //return void since we're only changing the private data variable
    void setFrame(string frame) {
        this->frame = frame;        
    }
    
    // getFrame(): 
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        if(frame == "") {
            cout << "frame has not been assign." << endl;
        }

        return frame; 
    }

    // addBar
    // adds a Bar to the BarChart.
    // takes in name, value, category which are the information needed to make a bar
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        Bar oneBar(name, value, category); // we use the bar class to create a bar.
        
        if(size < capacity) {
            this->bars[size] = oneBar;
            //this->bars = frame;
            size++; // increments size to track how many elements we have.
            return true;
        }
        else {
            cout << "ERROR: not enough memory to store the bar\n"; // this is when the person is trying to add values to the array when the array is already full.
        }

        
        return false; // TO DO:  update this, it is only here so code compiles.
    }
    
    // getSize(): gets the size of the array.
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
    
        return size; 
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        if(i < 0 || i > this->size) {
            throw out_of_range("BarChart: i out of bounds");
        }
        
        return this->bars[i];  //returns a bar element.
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        Bar printBar;
        
        output << "frame: " << getFrame() << endl;
        sort(bars, bars+size, greater<Bar>());
        for(int i = 0; i < size; ++i) {           
            printBar = bars[i];
            output << printBar.getName() << " " << printBar.getValue() << " " << printBar.getCategory() << endl;
        }
        
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    //returns void since we are only printing values.
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax;  // this is number of BOXs that should be printed
        double maxValue = 0;
        string barstr;
        string color = "";
        double value;

        sort(bars, bars+size, greater<Bar>());
        maxValue = bars[0].getValue();

        for(int i = 0; i < top; i++) {
            barstr = "";
            value = bars[i].getValue();
            value = (value / maxValue) * 60;
            lenMax = value;
            //if the category is not in the map or if the map size is zero get it resets the color. else color is assign with the color that cooralates with the category.
            if(!colorMap.count(bars[i].getCategory()) || colorMap.size() == 0){
               color = RESET; 
            }
            else {
                color = colorMap[bars[i].getCategory()];
            }
            //loops through lenMax to get the number of boxs
            for(int j = 0; j < lenMax; j++) {
                barstr += BOX;
            }
            // when there are no bars being made then it doesn't print them
            if(barstr != ""){
                output << color << barstr << " " << bars[i].getName() <<  " " << bars[i].getValue() << endl;
            }
        }
    }
    
};

