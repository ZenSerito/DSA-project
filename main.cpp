#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class codelog
{
private:
public:
    void intro();
    void homescreen();
};

void codelog ::intro()
{

    //                                  COORD is a inbuilt structure located in windows.h
    // The object c from COORD is used as C.X nad C.Y which are respectively the row and the column from where the message is to be printed
    //                                  Normally, there are 20 rows and 80 columns in a console window
    /*COORD c;
    c.X = 20;
    c.Y = 10;
    Updated to new method

    As the name suggests. It puts the consolecursor position to the output handle of COORD c
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); */

    /***********************************Background and Foreground*********************************/
    /*
        Background and Foreground Colors can be changed simply by:
        system ("COLOR attr");
        Example: system ("COLOR 1F");
        Here, 1st Hex in COLOR '1' gives background color
        And, 2nd Hex 'F' gives foreground color
        16 different colors are available
        Include stdlib.h for system() function
        Use system("COLOR FFF"); for details on availabe colors
        Use system("PAUSE"); to ask the user before proceeding i.e. Press any key to Continue
        Use system("CLS"); to clear screen
        Use cout << char(x); to print symbols where x is any number from 0 to 255;

    */

    /*  system("COLOR FFF"); */

    system("CLS");

    system("COLOR 3F");

    // This class is used to get height and width of the console window
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    int height = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    // Used to vertically center align the box

    for (int i = 0; i < (height - 5) / 2; i++)
    {
        cout << endl;
    }

    // Used to make box

    // First row
    for (int i = 0; i < (width - 80) / 2; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 80; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Second Row

    for (int i = 0; i < (((width - 8) / 2)); i++)
    {
        cout << " ";
    }
    cout << "CODELOG:" << endl;

    // Third Row

    for (int i = 0; i < (width - 76) / 2; i++)
    {
        cout << " ";
    }
    cout << "A mini project implementing a Social Media using the concepts of DSA and C++" << endl;

    for (int i = 0; i < (width - 80) / 2; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < 80; i++)
    {
        cout << "=";
    }
    cout << endl;

    /************************For press any key message*************************************/
    for (int i = 0; i < (width - 16) / 2; i++)
    {
        cout << " ";
    }
    cout << "Press any key...";
    getch();

    system("CLS");

    /*****************************For new Screen*******************************************/

    system("COLOR 2F");

    // This loop is for vertical center alignment of the content
    for (int i = 0; i < (height - 15) / 2; i++)
    {
        cout << endl;
    }

    // For center alignment of the horizontal lines
    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < 60; i++)
    {
        cout << "=";
    }
    // Two new lines for the line 'Project By'
    cout << endl
         << endl;

    for (int i = 0; i < (width - 13) / 2; i++)
    {
        cout << " ";
    }
    cout << "PROJECT BY: " << endl
         << endl;
    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < 60; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Name And Roll Number

    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Name";
    cout << setw(1) << left << " ";
    cout << setw(20) << right << "Roll Number" << endl;

    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < 60; i++)
    {
        cout << "=";
    }

    cout << endl
         << endl;

    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Tangsang Chongbang" << setw(1) << left << " " << setw(20) << right << "PUL077BEI047" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Template Thapa" << setw(1) << left << " " << setw(20) << right << "PUL077BEI046" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Sangam Rai" << setw(1) << left << " " << setw(20) << right << "PUL077BEI040" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Manish Shah" << setw(1) << left << " " << setw(20) << right << "PUL077BEI050" << endl;
    cout << endl;
    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 60; i++)
    {
        cout << "=";
    }

    cout << endl;
    for (int i = 0; i < (width - 16) / 2; i++)
    {
        cout << " ";
    }
    cout << "Press any key...";
    getch();
    system("CLS");
}

/************************************Home Screen***********************************/
void codelog :: homescreen()
{
    //To get height and width of the current console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    int height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
    system("COLOR 1F");

    int ch; // Stores user's choice

    //For vertical center alignment
    for (int i = 0; i < (height - 15) / 2; i++)
    {
        cout << endl;
    }

    //first row

    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 60; i++)
    {
        cout << char(205);
    }
    cout << endl << endl;

    //second row

    for (int i = 0; i < (width - 8) / 2; i ++)
    {
        cout << " ";
    }
    cout << "CODELOGS:" << endl;

    //third row

    for (int i = 0; i < (width - 46) / 2; i++)
    {
        cout << " ";
    }

    cout << "Connect and Work with your Fellow Programmers." << endl << endl;

    //fourth row

    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }

    for (int i = 0; i < 60; i++)
    {
        cout << char (205);
    }
    cout << endl << endl;

    //User options
    
    for(int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    cout << "(1) Create an Account" << endl;
    
    for(int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    cout << "(2) Login" <<endl;
    
    for(int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    cout << "(3) Exit" << endl << endl;
    
    for(int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    cout << "Enter your choice: " <<endl;
    do {
        
        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cin >> ch;
        switch (ch)
        {
            case 1: 
            break;
            case 2: 
            break;
            case 3:
            cout << endl;
            for (int i = 0; i < (width - 60) / 2; i++)
            {
                cout << " ";
            } 
            cout << "Exiting...";
            break;
            default: 
            for (int i = 0; i < (width - 60) / 2; i++)
            {
                cout << " ";
            }
            cout << "Invalid Choice, Input again..." <<endl;
        } 

    } while(ch != 3 && ch != 1 && ch != 2);
}
int main()
{

    codelog app;
    app.intro();
    app.homescreen();
    getch();
    return 0;
}
