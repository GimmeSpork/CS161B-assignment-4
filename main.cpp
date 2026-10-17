/******************************************************************************
# Author:           Lucy P
# Lab:              Assignment 8
# Date:             May 31, 2021
# Description:      calculates your numeric and letter grade from given 
#                   assignment scores, midterm exam score, and final exam score.
# Input:            numAssigns as int, numScore as double, 
# Output:           decimalGrade as double, letterGrade as char, prompt as string.
# Sources:          zybooks, assignment 7 and 8 resources.
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// display constant variables
const int MAXCHAR = 51;
const int CAP = 20;
const int MAXSTUDENTS = 25;

// display function prototypes
void welcome();
void readInput(char courseNums[][MAXCHAR], int students[], int &count);
void readInt(string prompt, int &num);
void printList(char courseNums[][MAXCHAR], int students[], int count);
void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count);
int main();

//start of bulk functions
void welcome(){
    cout << "Welcome to my Course Rosters program!!" << endl;
    cout << "\nEnter course number and students enrolled when prompted. Enter Quit"
    "or quit for course number when you are done." << endl;
    cout << endl;
}

void readInput(char courseNums[][MAXCHAR], int students[], int &count){
    char tempName[MAXCHAR] = {0};
    int i = 0;
    
    count = 0;
    cout << "Enter course number: ";
    cin.getline(tempName, MAXCHAR);
    while(strcmp(tempName, "quit") != 0 && strcmp(tempName, "Quit") != 0){
        if (count < CAP){
            strcpy(courseNums[count], tempName);
            readInt("Number of students enrolled: ", students[count]);
            while(students[count] > 25){
                cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
                readInt("Number of students enrolled: ", students[count]);
            }
        }else{
            cout << "List full!" << endl;
            break;
        }
        cout << "Enter course number: ";
        cin.getline(tempName, MAXCHAR);
        while(i < count && strcmp(courseNums[i], tempName) < 0){
            i++;
        }
        for(int j = count; j > i; j--){
            strcpy(courseNums[j], courseNums[j-1]);
        }
        strcpy(courseNums[i], tempName);
        count++;
        cin.getline(tempName, MAXCHAR);
    }
}

void readInt(string prompt, int &num){
    int tempVar = 0;

    cout << prompt;
    cin >> tempVar;
    while(!cin){
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> tempVar;
    }
    cin.ignore(10, '\n');
}

void printList(char courseNums[][MAXCHAR], int students[], int count){
    for (int i = 0; i < count; i++){
        cout << courseNums[i] << ": " << students[i] << endl;
    }
}

void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count){
    for(int i = 0; i < count - 1; i++){
        if (students[i] < 10){
            students[i] = students[i + 1];
            courseNums[i][MAXCHAR] = courseNums[i + 1][MAXCHAR];
            --count;
        }
    }
}

int main(){
    char courseNums[CAP][MAXCHAR];
    int students[MAXSTUDENTS];
    int count;

    welcome();
    readInput(courseNums, students, count);
    printList(courseNums, students, count);
    cancelCourses(courseNums, students, count);
    printList(courseNums, students, count);

    cout << "\nThank you for checking our my Course Rosters Program!" << endl;

}
