# Animated-Bars
Animated Bars is an application that animates bars moving throughout a span of years given the data that is parsed from a file. For example, if the file of football.txt is entered in the Animated Bars application. The application will take that file parse all the data into sprate parts and use that data to built an animation of bars that displays the best football clubs in Europe from 1960 to 2019.



Files that consist of .h : 
  
  the .h files are the classes that where used to implement this application. barchartanimate.h extends from barchart.h and barchart.h extends from bar.h. 
  
    what each file does:
        1. bar.h file creates a single bar containing data from each line.
        2. barchart.h takes all the bars that were create in the bar.h code and stores those bars in a vector.        
        3. lastly, barchartanimate.h uses the barchart.h code that contains the group of bars and animates them based on the dates of bars.


Files that consist of .txt :
  
  these .txt files are text files that contain the data that will be used to parse and create bars from. Each lines contains data that needs to be parse. The data on each line is parsed by the commas that seprates them and each line contains different types of data that needs to be parsed.
