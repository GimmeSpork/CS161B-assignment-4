/******************************************************************************
# Author:           Lucy P
# Lab:              Assignment 4
# Date:             October 17, 2026
# Description:      This program uses two parallel arrays to read the course
#                   numbers, and student count of different classes. It will output
#                   the course numbers and student amounts in each class both before
#                   and after the classes with less than 10 students are taken out.
# Input:            tempName as char, num as int
# Output:           courseNums[] as char, students[] as int.
# Sources:          zybooks, assignment 4 resources
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

//start of bulk code
void welcome(){
    cout << "Welcome to my Course Rosters program!!" << endl;
    cout << "\nEnter course number and students enrolled when prompted. Enter Quit"
    " or quit for course number when you are done." << endl;
    cout << endl;
}

void readInput(char courseNums[][MAXCHAR], int students[], int &count){
    char tempName[MAXCHAR] = {0};
    int tempStudents {};
    int tempStudentCount = 0;
    
    count = 0;
    cout << "Enter course number: ";
    cin.getline(tempName, MAXCHAR);
    while(strcmp(tempName, "quit") != 0 && strcmp(tempName, "Quit") != 0){
        if (count < CAP){
            readInt("Number of students enrolled: ", tempStudentCount);
            while(tempStudentCount > MAXSTUDENTS || tempStudentCount < 0){
                cout << "Invalid number!! Please enter a number between 0 and 25" << endl;
                readInt("Number of students enrolled: ", tempStudentCount);
            }

        int indexToInsertAt = 0;
        while(indexToInsertAt < count && strcmp(courseNums[indexToInsertAt], tempName) < 0){
            indexToInsertAt++;
        }
        for(int j = count; j > indexToInsertAt; j--){
            strcpy(courseNums[j], courseNums[j-1]);
            students[j] = students[j - 1];
        }
        strcpy(courseNums[indexToInsertAt], tempName);
        students[indexToInsertAt] = tempStudentCount;
        ++count;
        }else{
            cout << "List full!" << endl;
            break;
        }
        cout << "Enter course number: ";
        cin.getline(tempName, MAXCHAR);
    }
}

void readInt(string prompt, int &num){
    cout << prompt;
    cin >> num;
    while(!cin){
        cout << "Invalid input! Please try again!!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> num;
    }
    cin.ignore(10, '\n');
}

void printList(char courseNums[][MAXCHAR], int students[], int count){
    for (int i = 0; i < count; i++){
        cout << courseNums[i] << ": " << students[i] << endl;
    }
}

void cancelCourses(char courseNums[][MAXCHAR], int students[], int &count){
    int courseCount = 0;

    for(int i = 0; i < count; i++){
        if(students[i] >= 10){
            strcpy(courseNums[courseCount], courseNums[i]);
            students[courseCount] = students[i];
            courseCount++;
        }
    }
    count = courseCount;
}

int main(){
    char courseNums[CAP][MAXCHAR];
    int students[MAXSTUDENTS];
    int count;

    welcome();
    readInput(courseNums, students, count);

    cout << "\nList of courses and students:" << endl;
    printList(courseNums, students, count);
    cancelCourses(courseNums, students, count);

    cout << "\nList after cancellations:" << endl;
    printList(courseNums, students, count);

    cout << "\nThank you for checking out my Course Rosters Program!" << endl;

}
