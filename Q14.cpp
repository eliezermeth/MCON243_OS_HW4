#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Student
{
    private:
        string name;
        int ID;
        int* grades;
    
    public:
        // Constructor
        Student(string name, int ID)
        {
            this->name = name;
            this->ID = ID;
            
            // Initialize grades array
            grades = new int[4];
            for (int i = 0; i < 4; i++)
            {
                grades[i] = 0;
            }
        }
        
        // Name
        string getName()
        {
            return name;
        }
        void setName(string name)
        {
            this->name = name;
        }
        
        // ID
        int getID()
        {
            return ID;
        }
        void setID(int ID)
        {
            this->ID = ID;
        }
        
        // Grades
        int* getGrades()
        {
            return grades;
        }
        void setGrades(int grades[])
        {
            this->grades = grades;
        }
};