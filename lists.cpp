// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: December 27, 2022
// This program asks the user to enters marks
// to then calculate and display the averages of the marks
// to the user


#include <iostream>
#include <list>


// This function calculates the average of a list of marks
float Calc_Average(std::list<float> listOfMarks) {
    // Declared Variables
    float sum, average;

    // Iterates through each index in the list of marks
    for (float index : listOfMarks) {
        // Adds each individual mark to the sum variable
        sum += index;
    }

    // Calculates the average if the marks
    average = sum / listOfMarks.size();

    // Returns the average to function call
    return average;
}


int main() {
    // Declared list
    std::list<float> userMarks;

    // Declared Variables
    std::string userMarkString;
    float userMark, marksAverage;

    // Checks for exceptions
    try {
        // Gets input from user until they input -1
        while (userMark != -1) {
            // Asks user to input a mark
            std::cout << "Enter a mark (input -1 to stop): ";
            std::getline(std::cin, userMarkString);

            // Casts user's mark to float
            userMark = stof(userMarkString);

            // Checks if user wants to stop inputting marks
            if (userMark == -1) {
                // Exits loop
                break;
            // Checks if user entered a mark outside the mark range
            } else if (userMark < -1 || userMark > 100) {
                std::cout << "Invalid Mark! Try again." << std::endl;
            // Adds the user's mark to a list
            } else {
                userMarks.push_back(userMark);
            }
        }

        // Checks if user did not enter any marks
        if (userMarks.size() == 0) {
            std::cout << "You did not enter any marks! Run the program again."
            << std::endl;
        } else {
            // Calls function to find the average of all the marks
            marksAverage = Calc_Average(userMarks);

            // Displays the list of marks
            std::cout << "\nList of Marks: ";

            // Iterates through the list of marks to display all the marks
            for (float mark : userMarks) {
                std::cout << mark << " ";
            }

            // Displays the average of all the marks
            std::cout << "\nThe average is " << marksAverage << "%"
            << std::endl;
        }
    // In the event of an exception
    } catch (std::invalid_argument) {
        std::cout << "You must enter a valid mark!" << std::endl;
    }
}
