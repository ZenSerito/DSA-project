#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class codelog {
private: 
public: 
void create_an_account ();
};
void codelog :: create_an_account() {
    string name, address, email, username, password;
    char ch_for_pass;
    int age;
    ofstream out;
    out.open("test.txt");
    cout << "Name: " <<endl;
    getline(cin, name);
    cout << "Address: " <<endl;
    getline(cin, address);
    cout << "E-mail: "<<endl;
    getline(cin, email);
    cout << "Enter username (without space): "<<endl;
    getline(cin,username);
    cout << "Create password: "<<endl;
    while (ch_for_pass != 13)
    {
        ch_for_pass = getch();
        cout << "*";
        password += ch_for_pass;
    }
    out << "Name: " <<endl;
    out << name <<endl;
    out << "Address: "<<endl <<address <<endl;
    out << "E-mail: " <<endl <<email <<endl;
    out << "Password: " <<endl <<password <<endl;
    out.close();
    

}
int main(){
    codelog c1;
    c1.create_an_account();

    getch();
    return 0;
}