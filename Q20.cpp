#include <iostream>
#include <stdlib.h>

using namespace std;

class MemoryMangagement
{
    public:
        int doMalloc()
        {
            /*
            malloc -> make allocation (specified number of bytes)
            malloc(numBytes : int) : void*
            */
            
            int size = 10;
            
            // Create pointer to array
            int *array;
            // Make allocation to array of correct size and cast to int* to assign to array
            array = (int*) malloc(size * sizeof(int));;
            
            // Test if null pointer was returned
            if (array == NULL)
            {
                fprintf(stderr, "malloc falied\n");
                return -1;
            }
            
            // Print array
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
            
            return 0;
        }
        
        int doRealloc()
        {
            /*
            realloc -> re-allocate
            realloc(array : void* , numBytes : int) : void*
            */
            
            // malloc array
            int size = 3;
            int *array = (int*) malloc(size * sizeof(int));
            array[0] = 1; // assign values to array
            array[1] = 2;
            array[2] = 3;
            
            // print
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
            
            // realloc
            size = 4;
            array = (int*) realloc(array, size * sizeof(int)); // reallocate & cast
            array[3] = 4; // assign value to new slot
            
            // print
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
            
            return 0;
        }
        
        int doCalloc()
        {
            /*
            calloc -> clear allocation (allocate and clear to 0)
            calloc(numUnits : int , sizeOfUnit : int) : void*
            */
            int size = 3;
            
            // calloc
            int *array = (int*) calloc(size, sizeof(int)); // allocate and cast
            
            // print
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
        }
        
        int doFree()
        {
            /*
            free -> return memory to free store
            free(array : void*)
            */
            
            // malloc
            int *array = (int*) malloc(10 * sizeof(int));
            
            // free
            free(array);
            
            return 0;
        }

};

