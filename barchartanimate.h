

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "barchart.h"

using namespace std;

class BarChartAnimate
{
private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart *barcharts; // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int colorIndex = 0;

public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source)
    {
        // all variables set to default
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        this->capacity = 4;
        this->barcharts = new BarChart[capacity];
        this->size = 0;
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate()
    {

        if (this->size > this->capacity)
        {
            delete[] barcharts;
            this->barcharts = nullptr;
        }
        else
        {
            delete[] barcharts;
            this->barcharts = nullptr;
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    // while the file is open we parse the file and store each values into there respective place and create a group of bars. then store those group of bars into the barcharts array with the frame.
    //returns viod since we're only storing values.
    void addFrame(ifstream &file)
    {
        string country, name, category, valueReadFromFile, date;
        int value = 0, numOfData;
        
        file >> numOfData; // gets the number of number of data in that group.
        BarChart groupOfBars(numOfData); // creates an object of BarChart to store the group of bars and the numofData is the capacity of how bars to store.
        if (!file.fail())
        {
            for (int i = 0; i < numOfData; i++)
            {
                // parses the file by the string
                getline(file, date, ',');
                groupOfBars.setFrame(date); //assigns the frame with a value
                getline(file, name, ',');
                getline(file, country, ',');
                getline(file, valueReadFromFile, ',');
                getline(file, category);
                value = stoi(valueReadFromFile); // converts the file string value into an int value to store in the bar object.
                // this will check if catorgey is in the map and if not then it will add it to the map with a specific color.
                if (!colorMap.count(category))
                {
                    // if all the colors were used then it loops back to the first index.
                    if (colorIndex >= 7)
                    {
                        colorIndex = 0;
                    }
                    else
                    {
                        colorMap[category] = COLORS[colorIndex];
                        colorIndex++;
                    }
                }
                groupOfBars.addBar(name, value, category); // this will store each bar that we created into the the barchart which has allocated memeory to hold each bar in the specific group.
            }
            // checking if capacity is equal to size, which then we would need to allocate more memory.
            if (capacity == size)
            {
                int newCapacity = capacity * 2; // doubling the size of old capacity
                BarChart *newBarcharts = new BarChart[newCapacity]; // creating a new barcharts array object
                // storing all the old data into the new array object
                for (int i = 0; i < size; i++)
                {
                    newBarcharts[i] = barcharts[i];
                }
                delete[] barcharts;
                capacity = newCapacity;   // assign the old capacity with the new capacity
                barcharts = newBarcharts; // assign the old array with the new array
            }
            barcharts[size] = groupOfBars; //stores the group of bars into the index of barcharts at index size.
            size++; // increase the size since we added to the list.
        }
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
    // this prints all the bars in that were stroe in barcharts array and it animates it using the functions given.
    void animate(ostream &output, int top, int endIter)
    {
        unsigned int playback = 50000;
        double speed = 3;
        string colorBlack = ("\033[1;37m");
        
        /*
        // CREATIVE COMPONENT:
        cout << "For faster speed enter small numbers." << endl;
        cout << "Enter the speed for the bars (recommended 1 to 5): ";
        cin >> speed;
        cout << "Enter the playback speed of the graph (recommended 5000 to 90000): ";
        cin >> playback;
        */

        if (endIter == -1)
        {
            endIter = size;
        }
        for (int i = 0; i < endIter; i++)
        {
            top = barcharts[i].getSize();
            BarChart groupOfBars(top);
            groupOfBars = barcharts[i];
            usleep(speed * playback);
            output << CLEARCONSOLE;
            output << colorBlack;
            output << title << endl;
            output << source << endl;
            output << endl;
            groupOfBars.graph(cout, colorMap, top);
            output << colorBlack;
            output << endl;
            output << xlabel << endl;
            output << "Frame: " << barcharts[i].getFrame() << endl;
        }
    }

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize()
    {

        return this->size; 
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    // the i that is passed in is the index we want to access
    BarChart &operator[](int i)
    {

        if (i < 0 || i > this->size)
        {
            throw out_of_range("BarChartAnimate: i out of bounds");
        }
    
        return this->barcharts[i]; 
    }
};
