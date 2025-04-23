#include <iomanip>
#include <iostream>
#include "tester.h"

using namespace std;

// setters
void Tester::SetName(const string& a_name)
{
    _name = a_name;
}

void Tester::SetScore(int a_score)
{
    _score = a_score;
}

// getters
string Tester::get_name()
{
    return _name;
}

int Tester::get_score()
{
    return _score;
}

// default constructor
Tester::Tester()
{
    _name = " ";
    _score = 0;
}

// destructor
Tester::~Tester()
{
    _name = string(_name.length(), 0);
    _score = 0;
}

void Tester::display(ostream& out)
{
    out << left << setw(15) << _name << " " << _score << endl;
}

  

// demonstrates that it can look up data by name using a linear (sequential) search
int Tester::linSearch(Tester testers[], int size)
    {
    string search;
    int result = 0; // set index
    bool found = false;
    cout << "\nEnter a Student to search for: ";
    cin >> search;   
        for (int i = 0; i < sizeof(Tester); ++i)
        {
            if(search == testers[i].get_name())
            {
               result = i; 
               testers[i].display(cout);
               found = true;
               break;
            }
        }
        
        if(!found)
            cout << "Not found";

        return result;
    }


    // goes on to sort the array according to the int data member using selection sort, thereby ordering the data in ascending numeric order by score (see Chapter 8)
    int Tester::scoreSort(Tester testers[], int size)
    {
        int minIndex; 
        int minValue;

        for(int i = 0; i < (size - 1); i++)
        {
            minIndex = i;
            minValue = testers[i].get_score();
            for(int j = i + 1; j < size; j++)
            {
                if(testers[j].get_score() < minValue)
                {
                    minValue = testers[j].get_score();
                    minIndex = j;
                }
            }
            
            // swap function?
            Tester temp = testers[i];
            testers[i] = testers[minIndex];
            testers[minIndex] = temp;
        }

        cout << "\nSorted" << endl;
        for(int idx = 0; idx < size; ++idx)
            testers[idx].display(cout);
        
        return minValue;
    }

    // demonstrates that it can look up data by score using a binary search (see Chapter 8)
    int Tester::scoreSearch(Tester testers[], int size)
    {
        int value = 0;  // user input score value
        int first = 0, 
            last = size - 1,
            middle,
            position = -1;
        bool flag = false;
        cout << "\nEnter a score to search for: ";
        cin >> value;

        while(!flag && first <= last)
        {
            middle = (first + last) / 2;
            if (testers[middle].get_score() == value)
            {
                flag = true;
                position = middle;
            }
            else if (testers[middle].get_score() > value)
                last = middle - 1;
            else
                first = middle + 1;
        }    
        
         if (position != -1)
        {
        testers[position].display(cout);    
        } else{
            cout << "Not found. " << endl;
        }

        // testers[position].display(cout);    
        
        return position;

    }

    // goes on to sort array according to the string data member using bubble sort, thereby ordering the data alphabetical
    bool Tester::testerSort(Tester testers[], int size)
    {
        bool flag = false;

        for(int i = size - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (testers[j].get_name() > testers[j+1].get_name())
                {
                    flag = true;
                    swap(testers[j], testers[j+1]);
                
                }
            }
        }
    cout << "\nAlpha-bubbled" << endl;
        for(int idx = 0; idx < size; ++idx)
            testers[idx].display(cout);

    return flag;
    }


    // demonstrates that it can look up data by name using a binary search
    int Tester::nameSearch(Tester testers[], int size)
    {
        string value;  // user input score value
        int first = 0, 
            last = size - 1,
            middle,
            position = -1;
        bool flag = false;
        
        cout << "\nEnter a name to search for: ";
        cin >> value;

        while(!flag && first <= last)
        {
            middle = (first + last) / 2;
            if (testers[middle].get_name() == value)
            {
                flag = true;
                position = middle;
            }
            else if (testers[middle].get_name() > value)
                last = middle - 1;
            else
                first = middle + 1;
        }    
        if (position != -1)
        {
        testers[position].display(cout);    
        } else{
            cout << "Not found. " << endl;
        }

        
        return position;
    }
// lists the names of the person(s) with the highest score - binary search
   int Tester::highScore(Tester testers[], int size)
    {
        int first = 0;

        for (int i = 0; i < size - 1; ++i)
        {
            first = i;

            for (int j = i + 1; j < size; ++j)
            {
                if(testers[j].get_score() > testers[first].get_score())
                {
                    first = j;
                }
                swap(testers[first], testers[j]);
            }
        }
        cout << "\nthe highest score\n";
        testers[first].display(cout);

        return first;
    }


// lists the names of the person(s) with the lowest score
    int Tester::lowScore(Tester testers[], int size)
    {
        int first = 0;

        for (int i = 0; i < size - 1; ++i)
        {
            first = i;

            for (int j = i + 1; j < size; ++j)
            {
                if(testers[j].get_score() < testers[first].get_score())
                {
                    first = j;
                }
                swap(testers[first], testers[j]);
            }
        }
        cout << "\nThe lowest score\n";
        testers[first].display(cout);

        return first;
    }

    