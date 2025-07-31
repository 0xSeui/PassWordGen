/* 0xSeui */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;
const int max_length = 32;
const int min_length = 6;
// Function Print Info
void print_info() {
    cout << "\033[1;36m==============================\033[0m" << endl;
    cout << "\033[1;32m    🔐 Strong Password Gen    \033[0m" << endl;
    cout << "\033[1;33m        copyright \033[1;31m0xSeui   \033[0m" << endl;
    cout << "\033[1;36m==============================\033[0m" << endl;
}
// Function Copy The Password Automatically
void copyToClipboard(const string& text) {
    string safeText = "\"";

    for (char c : text) {
        if (c == '"') safeText += '\\';
        safeText += c;
    }

    safeText += "\"";

    string command = "echo " + safeText + " | clip";
    system(command.c_str());
}
// Function Save The Password
void savePassword(string PassWord)
     {     
         ofstream file("passwords.txt", ios::app); // 
          if (file.is_open()) {
        file << PassWord << endl;
        file.close();
        cout << "\033[1;36m📁 Saved to passwords.txt\033[0m" << endl;
    } else {
        cout << "\033[1;31m❌ Failed to write to file!\033[0m" << endl;
    }
          

     }

// Strong Password Generator
void PassGen(int sizePassword) 
     {  
         
         char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
         string PassWord = "";
         int size_char = sizeof(characters) - 1 ; // \0
         srand(time(0)); 
              for(int index = 0 ; index < sizePassword ; index++ )
             {
                
                int key_generated = rand() % size_char ;
                PassWord += characters[key_generated];
                 
           }

        

         cout << "\033[1;32mPassword : \033[0m" <<"\033[1;33m" << PassWord <<"\033[0m" << endl;
         copyToClipboard(PassWord);
         savePassword(PassWord);
     }

 
int main() {
    print_info();
        cout << "Choice (Y) or (N) : ";
        char option; 
         cin >> option;
                 while(option == 'Y' || option == 'y') 
                     { 
                         int input;
                         cout << "\033[1;32mPassword Length : \033[0m";
                         cin >> input ;
                         if(input >= min_length && input <= max_length   )
                           {
           
                            PassGen(input);
                            
                             cout << "\nGenerate another password? (Y/N): ";
                             cin >> option;

                        }else{

                                cout <<"\033[1;31mSorry Enter Number Between 6 Length 32 \033[0m"<< endl;
 
                             } 

}
         
          string out = (option == 'N' || option == 'n') ? "\033[1;36m👋 Thank You\033[0m" : "\033[1;31mInvalid Input\033[0m";
            cout << out;
                    
    return 0;
}
