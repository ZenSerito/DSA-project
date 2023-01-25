#include<iostream>
#include<iomanip>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

class codelog {
    private:

    public:
    void homescreen();
};

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
            cout << endl << endl;
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
    codelog c;
    c.homescreen();
    getch();
}