#ifndef TESTER_H
#define TESTER_H
#include <string>

class Tester {
    protected:
        std::string _name;
        int _score {};
    public:
    Tester();
    virtual ~Tester();

    // Setters
    void SetName(const std::string& a_name);
    void SetScore(int a_score);

    // Getters
    std::string get_name();
    int get_score();

    // methods
    void display(std::ostream& out);  // display function

    static int linSearch(Tester testers[], int size); // linear search by name function
    static int scoreSort(Tester testers[], int size); // selection sort function
    static int scoreSearch(Tester testers[], int size); // binary search by score function
    static bool testerSort(Tester testers[], int size); // bubble sort function
    static int nameSearch(Tester testers[], int size);  // binary search by name function
    static int highScore(Tester testers[], int size); // use the binary algorithm to display highest score
    static int lowScore(Tester testers[], int size); // use the binary algorithm to display lowwst score



    private:

};
#endif // TESTER_H