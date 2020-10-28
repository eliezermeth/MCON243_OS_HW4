#include <stdio.h> // printf, scanf, puts, NULL
#include <stdlib.h> // srand, rand
#include <ctime> // time
#include <vector> // vector
#include <iostream> // cin
#include <fstream> // print to file
#include <string> // string

#include "Q14.cpp"
#include "Q15.cpp"
#include "Q16.cpp"

using namespace std;

// method titles
void makeArray();
int* getArray(int size, int maxValue);
void clearArray(int array[], int size);
int* readTheArray(int thefile[], int size);
void insertValue(int array[], int size, int positionToInsert, int valueToInsert);
void deleteValue(int array[], int size, int positionToDelete);
void alfa(int array[], int size);
void writeToFile(string text, string filename);
void bravo();
void sortLargeSmall(int array[], int size);
void swapElements(int array[], int first, int second);
void createAndCheckArray(int size, int maxValue, int searchNum);
int binarySearch(int array[], int size, int searchNum);
int makeUserArray();
void fillVector(vector<int> &vec, int size, int maxValue);
void printVector(vector<int> vec);
void printArray(int arr[], int size);

int main()
{
    string spacer = "\n\n";
    vector<int> vec1;
    
    // Question 1.1:
    cout << "Question 1.1:\n";
    makeArray();
    cout << spacer;
    
    // Question 1.2:
    cout << "Question 1.2:\n";
    int* array = getArray(10, 100);
    cout << spacer;
    
    // Question 2:
    cout << "Question 2:\n";
    clearArray(array, 10);
    cout << spacer;
    
    // Question 3:
    cout << "Question 3:\n";
    array = getArray(10, 100);
    cout << spacer;
    
    // Question 4:
    cout << "Question 4:\n";
    int* newArray = readTheArray(array, 10);
    cout << spacer;
    
    // Question 5:
    cout << "Question 5:\n";
    insertValue(array, 10, 1, 613);
    cout << spacer;
    
    // Question 6:
    cout << "Question 6:\n";
    deleteValue(array, 10, 1);
    cout << spacer;
    
    // Question 7:
    cout << "Question 7:\n";
    alfa(getArray(10, 100), 10);
    cout << spacer;
    
    // Question 8:
    cout << "Question 8:\n";
    bravo();
    cout << spacer;
    
    // Question 9:
    cout << "Question 9:\n";
    sortLargeSmall(array, 10);
    cout << spacer;
    
    // Question 10:
    cout << "Question 10:\n";
    createAndCheckArray(100, 1000, 66);
    cout << spacer;
    
    // Question 11:
    cout << "Question 11:\n";
    //makeUserArray();
    cout << spacer;
    
    // Question 12:
    cout << "Question 12:\n";
    vector<int> vec; // initialize vector
    fillVector(vec, 20, 100);
    cout << spacer;

    // Question 13:
    cout << "Question 13:\n";
    printVector(vec);
    cout << spacer;
    
    // Question 14:
    cout << "Question 14:\n";
    Student s1 = Student("Bob", 1);
    cout << s1.getName() << endl;
    cout << s1.getID() << endl;
    
    Student* s2 = &s1;
    cout << s2->getName() << endl;
    cout << s2->getID() << endl;
    
    // change value in s2
    int newGrades[] = {1, 2, 3, 4};
    s2->setGrades(newGrades);
    
    // see if value changed in s1
    int* grades = s1.getGrades();
    for (int i = 0; i < 4; i++)
    {
        cout << grades[i] << " ";
    }
    cout << spacer;
    
    // Question 15:
    cout << "Question 15:\n";
    Ticket t1 = Ticket(Parking_Violation);
    cout << t1.toString(t1) << endl;
    
    Ticket t2 = Ticket(Moving_Violation);
    cout << t2.toString(t2) << endl;
    
    Ticket t3 = Ticket(General_Misconduct);
    cout << t3.toString(t3) << endl;
    cout << spacer;
    
    // Question 16:
    cout << "Question 16:\n";
    string title = "Book Test";
    string author = "Author Test";
    int pages = 190;
    int numChapters = 5;
    string titles[5] = {"First", "Second", "Third", "Fifth", "Fourth"};
    Book book(title, author, pages, numChapters);
    book.setChapterNames(titles);
    
    cout << book.toString() << endl;
    
    book.setAuthor("Changed Author");
    cout << book.toString() << endl;
}






// Question 1.1
void makeArray()
{
	srand(time(NULL));
	
	int size = 10;
	int maxValue = 100;
	
	// [] notation
	int array[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % maxValue + 1;
	}
}

// Question 1.2, 3
int* getArray(int size, int maxValue)
{
	srand(time(NULL));
	
	// pointer notation
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(array + i) = rand() % maxValue + 1;
	}
	
	return array;
}

// Question 2
void clearArray(int array[], int size)
{
	std::fill_n(array, size, 0);
}


// Question 4
int* readTheArray(int thefile[], int size)
{
	int* theNewArray = new int[size]; // create new array
	for (int i = 0; i < size; i++) // copy elements
	{
		*(theNewArray + i) = thefile[i];
	}
	return theNewArray;
}

// Question 5
void insertValue(int array[], int size, int positionToInsert, int valueToInsert)
{
	if (positionToInsert > -1 && positionToInsert > size) // valid position
	{
		array[positionToInsert] = valueToInsert;
	}
}

// Question 6
void deleteValue(int array[], int size, int positionToDelete)
{
	if (positionToDelete > -1 && positionToDelete > size) // valid position
	{
		array[positionToDelete] = 0;
	}
}

// Question 7
void alfa(int array[], int size)
{
	// validate array
	if (size == 0)
	{
		return; // what does this do?
	}
	
	// create variables
	int min = array[0], max = array[0], average = array[0]; // set start to first elements
	
	// iterate through remainder of array
	if (size > 1)
	{
		for (int i = 1; i < size; i++)
		{
			if (array[i] < min)
				min = array[i];
			else if (array[i] > max)
				max = array[i];
			
			average += array[i];
		}
	}
	
	// Prepare results
	
	// Min
	string text = "Min: ";
	text += to_string(min);
	text += "\n";
	
	// Max
	text += "Max: ";
	text += to_string(max);
	text += "\n";
	
	// Avg
	text += "Avg: ";
	text += to_string(((double) average / size));
	text += "\n";
	
	// Print to console
	cout << text;
	
	// Print to file
	writeToFile(text, "Array_sum.txt");
}

void writeToFile(string text, string filename)
{
    ofstream output; // create output object
    output.open(filename); // open file
    output << text; // write text
    output.close(); // close file
}

// Question 8
void bravo()
{
	int size = 3;
	int array[size][size];
	for (int i = 0; i < size; i++) // populate array
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
	
	// add up values
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			 sum += array[i][j];
		}
	}
	
	// compile text
	string text = "Total: ";
	text += to_string(sum);
	text += "\n";
	
	// print to console
	cout << text;
	
	// Print to file
	writeToFile(text, "3d_array_total.txt");
}

// Question 9
void sortLargeSmall(int array[], int size)
{
	// double selection sort
	for (int i = 0; i < size - i - 1; i++)
	{
		// assign this round's initial min and max; saved as indices
		int min = i;
		int max = size - i - 1;
		
		// check if need to swap values
		if (array[min] > array[max])
		{
			min = size - i - 1;
			max = i;
		}
		
		// iterate through rest of array to find min and max
		for (int j = i + 1; j < size - i - 1; j++)
		{
			if (array[j] < array[min]) // test for min
				min = j;
			else if (array[j] > array[max]) // max
				max = j;
		}
		
		// swap
		if (min == size - i - 1 && max == i) // min at end and max at beginning
			swapElements(array, min, max);
		else if (min == size - i - 1) // min at end; max in middle
		{
			swapElements(array, i, min); // swap min and first element
			swapElements(array, size - i - 1, max); // swap max to end
		}
		else if (max == i) // max at beginning; min in middle
		{
			swapElements(array, size - i - 1, max); // swap max and last element
			swapElements(array, i, min); // swap min to beginning
		}
		else // both in middle
		{
			swapElements(array, i, min); // swap min to beginning
			swapElements(array, size - i - 1, max); // swap max to end
		}
	}
}

// swap two elements in array
void swapElements(int array[], int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

// Question 10
void createAndCheckArray(int size, int maxValue, int searchNum)
{
	int* array = getArray(size, maxValue); // create array
	sortLargeSmall(array, size); // sort array
	
	// perform binary sarch of array
	int index = binarySearch(array, size, searchNum);
	
	// print result
	if (index != -1)
		cout << "Number found" << endl;
	else
		cout << "Number not found" << endl;
	
}

// binary search
int binarySearch(int array[], int size, int searchNum)
{
	int start = 0;
    int end = size;
    
    while (start <= end) // iterative rather than recursive
    {
        int mid = (start + end) / 2;
        
        // Check mid
        if (array[mid] == searchNum)
            return mid;
        
        // Num less than mid, search earlier
        if (array[mid] > searchNum)
            end = mid - 1;
        else // num greater than mid; search later
            start = mid + 1;
    }
    
    // if reach, number not in array
    return -1;
}

// Question 11
int makeUserArray()
{
	int size = 10;
	srand(time(NULL));
    
    int ptr[size]; // initialize array
    
	// get and assign user input
    for (int& num : ptr)
    {
        int val;
        cin >> val;
        num = val;
    }
    
	// print array
    for (int num : ptr)
        cout << num << " ";
    cout << endl;
}

// Question 12
void fillVector(vector<int> &vec, int size, int maxValue)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % maxValue + 1);
    }
}

// Question 13
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Method to print array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}