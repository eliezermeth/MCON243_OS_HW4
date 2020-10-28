#include <iostream>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

class Book
{
    private:
        string bookName;
        string author;
        int numPages;
        int numChapters;
        string* chapterNames;
    
    public:
        Book(std::string bookName = nullptr, std::string author = nullptr, 
            int numPages = 0, int numChapters = 0)
        {
            this->bookName = bookName;
            this->author = author;
            this->numPages = numPages;
            this->numChapters = numChapters;
            
            
            cout << "Running the constructor\n";
            chapterNames = new string[numChapters];
            for (int i = 0; i < numChapters; i++)
            {
                //chapterNames[i] = nullptr; // threw segmentation fault
                chapterNames[i] = "";
            }
        }
        
        // destructor
        ~Book()
        {
            cout << "Running the destructor\n";
            delete[] chapterNames;
        }
        
        // copy constructor
        Book(const Book& obj) noexcept
        {
            cout << "In copy constructor\n";
            
            this->bookName = obj.bookName;
            this->author = obj.author;
            this->numPages = obj.numPages;
            this->numChapters = obj.numChapters;
            chapterNames = new string[numChapters];
            for (int i = 0; i < numChapters; i++)
            {
                chapterNames[i] = obj.chapterNames[i];
            }
        }
        
        // assignment operator
        Book& operator=(const Book& obj) noexcept
        {
            cout << "In operator equals\n";
            
            if (this != &obj)
            {
                if (numChapters > 0)
                {
                    delete[] chapterNames;
                }
                
                this->bookName = obj.bookName;
                this->author = obj.author;
                this->numPages = obj.numPages;
                this->numChapters = obj.numChapters;
                chapterNames = new string[this->numChapters];
                for (int i = 0; i < numChapters; i++)
                {
                    this->chapterNames[i] = obj.chapterNames[i];
                }
            }
            return *this;
        }
        
        // move assignment operator
        Book& operator=(Book&& obj) noexcept
        {
            cout << "In move assignment operator\n";
            
            if (this != &obj)
            {
                delete[] chapterNames;
                
                this->bookName = obj.bookName;
                this->author = obj.author;
                this->numPages = obj.numPages;
                this->numChapters = obj.numChapters;
                chapterNames = obj.chapterNames;
                
                obj.chapterNames = nullptr;
            }
            return *this;
        }
        
        // move constructor
        Book(Book&& obj) noexcept
        {
            cout << "In move constructor\n";
            
            //*this = move(obj);
            this->bookName = obj.bookName;
            this->author = obj.author;
            this->numPages = obj.numPages;
            this->numChapters = obj.numChapters;
            chapterNames = obj.chapterNames;
            
            obj.chapterNames = nullptr;
        }
        
        //-----------------------------------------------------
        // Getters and setters
        void setbookName(string bookName)
        {
            this->bookName = bookName;
        }
        string getBookName()
        {
            return bookName;
        }
        
        void setAuthor(string author)
        {
            this->author = author;
        }
        string getAuthor()
        {
            return author;
        }
        
        void setNumPages(int numPages)
        {
            this->numPages = numPages;
        }
        int getNumPages()
        {
            return numPages;
        }
        
        void setNumChapters(int numChapters)
        {
            this->numChapters = numChapters;
        }
        int getNumChapters()
        {
            return numChapters;
        }
        
        void setChapterNames(string* chapterNames)
        {
            this->chapterNames = chapterNames;
        }
        string* getChapterNames() // modify to deep copy?
        {
            return chapterNames;
        }
        
        // to string
        string toString()
        {
            string str;
            std::stringstream ss;
            
            // Make string
            str.append("Book: ").append(bookName).append("\n");
            str.append("Author: ").append(author).append("\n");
            // pages
            ss << numPages;
            str.append("Pages: ").append(ss.str()).append("\n");
            ss.str(""); // clear
            // chapters
            str.append("Chapters:\n");
            for (int i = 0; i < numChapters; i++)
            {
                ss << (i + 1);
                str.append(ss.str()).append(": ").append(chapterNames[i]).append("\n");
                ss.str(""); // clear
            }
            
            return str;
        }
};