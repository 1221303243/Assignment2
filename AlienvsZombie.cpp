// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TxxL
// Names: Arif Faisal Bin Zakaria | Aizam Nazmien Bin Alinoordin | KOK YEW YAN
// IDs: 1221303243 | 1221303556 | 1211103790
// Emails: 1221303243@student.mmu.edu.my | 1221303556@student.mmu.edu.my | 1211103790@student.mmu.edu.my
// Phones: 01172428763 | 0146566541 | 0196696608
// *********************************************************

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Board
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
    Board(int dimX = 19, int dimY = 3, int numZ = 2);
    void init(int dimX, int dimY, int numZ);
    void display() const;
};

Board::Board(int dimX, int dimY, int numZ)
{
    init(dimX, dimY, numZ);
}

void Board::init(int dimX, int dimY, int numZ)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', 'h', 'r', 'p', '^', 'v', '<', '>'};
    int noOfObjects = 10; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array, except for center
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            if (i == dimY_ / 2 && j == dimX_ / 2)
            {
                map_[i][j] = 'A';
            }
            else
            {
                int objNo = rand() % noOfObjects;
                map_[i][j] = objects[objNo];
            }
        }
    }
    // Add Z's to the board
    for (int i = 0; i < numZ; ++i)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        map_[y][x] = 'Z';
    }
}

void Board::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << "      = Alien vs Zombie =       " << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}
void test1_1()
{
    Board board;
    board.display();
}
int main()
{
    // srand(1); // use this for fixed map during testing
    srand(time(NULL)); // try this for random map

    int dimX, dimY;
    string input;
    cout << "Game Dashboard" << endl;

    cout << "Columns = 19" << endl;
    cout << "Rows = 3" << endl;
    cout << "Do you want to change the columns and rows? (y/n)" << endl;
    cin >> input;
    if (input == "y")
    {
        cout << "Enter Columns:";
        cin >> dimX;
        cout << "Enter number of rows:";
        cin >> dimY;
        cout << "Do you want to start the game? (y/n)" << endl;
        cin >> input;
        if (input == "y")
        {
            Board board(dimX, dimY);
            board.display();
        }
        if (input == "n")
        {
            cout << "Ok, the map will not be displayed." << endl;
        }
    }
    if (input == "n")
    {
        cout << "Do you want to start the game? (y/n)" << endl;
        cin >> input;
        if (input == "y")
        {
            test1_1();
        }
        if (input == "n")
        {
            cout << "Ok, the map will not be displayed." << endl;
        }
    }
}