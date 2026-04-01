#include <iostream>
#include<string>
#include<fstream>
using namespace std;

bool userExists(string username){
    ifstream file("users.txt");
    string u,p;
   while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

void registrationUser(){
    string username ,password;

    cout<<"\n--- Registration ---\n";
    cout<<"Enter username: ";
    cin>>username;

    if(userExists(username)){
        cout<<"Username already exists. Please choose a different username.\n";
        return;
    }

    cout<<"Enter password: ";
    cin>>password;

    ofstream file("users.txt", ios::app);
    file<<username<<endl;
    file<<password<<endl;
    file.close();
    cout<<"Registration successful! You can now log in.\n";
}

void loginUser(){
    string username, passord;
    string u,p;
    bool found = false;

    cout<<"\n--- Login ---\n";
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>passord;

    ifstream infile("users.txt");
    while (infile >> u >> p) {
        if(u== username && p == passord){
            found = true;
            break;
        
        }
    }
    if(found){
        cout<<"Login successful! Welcome, "<<username<<"!\n";
    }else{
        cout<<"Invalid username or password. Please try again.\n";
    }

}
int main(){
    int choice;
do{
    cout<<"\n===MENU===\n";
    cout<<"1. Registration\n";
    cout<<"2. Login\n";
    cout<<"3. Exit\n";
    cin>>choice;
    switch(choice){
        case 1:
          registrationUser();
          break;
        case 2:
          loginUser();
          break;
        case 3:
            cout<<"Exiting the program. Goodbye!\n";
            break;
        default:
            cout<<"Invalid choice. Please try again.\n";
    }
} while(choice != 3);

    return 0;
}