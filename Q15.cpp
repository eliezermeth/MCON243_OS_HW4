#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum violation {Parking_Violation, Moving_Violation, General_Misconduct};

class Ticket
{
    private:
        static int count()
        {
            static int count = 0;
            return ++count;
        }
        int ID;
        violation type;
        
    public:
        // Constructor
        Ticket(violation type)
        {
            this->ID = count();
            this->type = type;
        }
        
        // ID; initially starts at count
        int getID()
        {
            return ID;
        }
        void setID(int num)
        {
            this->ID = num;
        }
        
        // Violation type
        violation getType()
        {
            return type;
        }
        void setType(violation type)
        {
            this->type = type;
        }
        
        // to String
        static string toString(Ticket t)
        {
            string str;
            
            // header
            std::stringstream ss;
            ss<<t.ID;
            str.append("Ticket ");
            str.append(ss.str());
            str.append(": ");
            
            // type & fine
            str.append(enumToString(t.type));
            str.append(", fine $");
            ss.str(""); // clear ss
            ss<<typeFine(t.type);
            str.append(ss.str());
            
            return str;
        }
        
        // enum to string
        static string enumToString(violation type)
        {
            switch (type)
            {
            case violation::Parking_Violation:
                return "Parking Violation";
            case violation::Moving_Violation:
                return "Moving Violation";
            case violation::General_Misconduct:
                return "General Misconduct";
            }
        }
        
        // fine value
        static int typeFine(violation type)
        {
            switch (type)
            {
            case violation::Parking_Violation:
                return 50;
            case violation::Moving_Violation:
                return 25;
            case violation::General_Misconduct:
                return 20;
            }
        }
};
