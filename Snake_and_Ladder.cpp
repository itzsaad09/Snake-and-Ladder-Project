#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <thread>
using namespace std;

int player1 = 0, player2 = 0, lastpositionP1 = 0, lastpositionP2 = 0; // Declare for Player's Position

int LongerStreakP1 = 0, CurrentStreakP1 = 0, LongerStreakP2 = 0, CurrentStreakP2 = 0; // Declare for Win Count

// Welcome Mesaage
void welcome(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout <<"\n\t\tWelcome to the Snake and Ladder Game";
    SetConsoleTextAttribute(hConsole, 7);
}

// Input Player 1 Name
string player1name;
bool valid_input1 = false;
void player1n(){
    do {
        cout<< endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 13);
        cout <<"\n\t\tEnter Player 1 Name: ";
        SetConsoleTextAttribute(hConsole, 7);
        getline(cin, player1name);
        // Check if user input carriage return
        if (player1name == "") {
            valid_input1 = false;
        }
        // Check if the input contains only characters and spaces
        else if (player1name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            valid_input1 = true;
        } 
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\tInvalid input. Please enter only letters.";
            SetConsoleTextAttribute(hConsole, 7);
        }
    } while (!valid_input1);
}

// Input Player 2 Name
string player2name;
bool valid_input2 = false;
void player2n(){
    do {
        cout<< endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 14);
        cout <<"\n\t\tEnter Player 2 Name: ";
        SetConsoleTextAttribute(hConsole, 7);
        getline(cin, player2name);
        // Check if user input carriage return
        if (player2name == "") {
            valid_input2 = false;
        }
        // Check if the input contains only characters and spaces
        else if (player2name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            valid_input2 = true;
        }  
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "\n\t\tInvalid input. Please enter only letters.";
            SetConsoleTextAttribute(hConsole, 7);
        }
    } while (!valid_input2);
}

// Function for Display Board
int board[10][10] = {{100,99,98,97,96,95,94,93,92,91},{81,82,83,84,85,86,87,88,89,90},{80,79,78,77,76,75,74,73,72,71},{61,62,63,64,65,66,67,68,69,70},{60,59,58,57,56,55,54,53,52,51},
{41,42,43,44,45,46,47,48,49,50},{40,39,38,37,36,35,34,33,32,31},{21,22,23,24,25,26,27,28,29,30},{20,19,18,17,16,15,14,13,12,11},{1,2,3,4,5,6,7,8,9,10}};
void display_board() {
    system("cls");
    //100-91
    cout <<"\n\t\t _________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________"<<"_________";
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[0][0]<<setw(5)<<"|"<<setw(5)<<board[0][1]<<setw(5)<<"|"<<setw(5)<<board[0][2]<<setw(5)<<"|"<<setw(5)<<board[0][3]<<setw(5)<<"|"<<setw(5)<<board[0][4]<<setw(5)<<"|"<<setw(5)<<board[0][5]<<setw(5)<<"|"<<setw(5)<<board[0][6]<<setw(5)<<"|"<<setw(5)<<board[0][7]<<setw(5)<<"|"<<setw(5)<<board[0][8]<<setw(5)<<"|"<<setw(5)<<board[0][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S8\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S7\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S6\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L8\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //81-90
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[1][0]<<setw(5)<<"|"<<setw(5)<<board[1][1]<<setw(5)<<"|"<<setw(5)<<board[1][2]<<setw(5)<<"|"<<setw(5)<<board[1][3]<<setw(5)<<"|"<<setw(5)<<board[1][4]<<setw(5)<<"|"<<setw(5)<<board[1][5]<<setw(5)<<"|"<<setw(5)<<board[1][6]<<setw(5)<<"|"<<setw(5)<<board[1][7]<<setw(5)<<"|"<<setw(5)<<board[1][8]<<setw(5)<<"|"<<setw(5)<<board[1][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(5)<<"\u001b[32m   L7\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L4\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S5\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //80-71
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[2][0]<<setw(5)<<"|"<<setw(5)<<board[2][1]<<setw(5)<<"|"<<setw(5)<<board[2][2]<<setw(5)<<"|"<<setw(5)<<board[2][3]<<setw(5)<<"|"<<setw(5)<<board[2][4]<<setw(5)<<"|"<<setw(5)<<board[2][5]<<setw(5)<<"|"<<setw(5)<<board[2][6]<<setw(5)<<"|"<<setw(5)<<board[2][7]<<setw(5)<<"|"<<setw(5)<<board[2][8]<<setw(5)<<"|"<<setw(5)<<board[2][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S8\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S7\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S6\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L6\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L8\u001b[0m"<<setw(5)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //61-70
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[3][0]<<setw(5)<<"|"<<setw(5)<<board[3][1]<<setw(5)<<"|"<<setw(5)<<board[3][2]<<setw(5)<<"|"<<setw(5)<<board[3][3]<<setw(5)<<"|"<<setw(5)<<board[3][4]<<setw(5)<<"|"<<setw(5)<<board[3][5]<<setw(5)<<"|"<<setw(5)<<board[3][6]<<setw(5)<<"|"<<setw(5)<<board[3][7]<<setw(5)<<"|"<<setw(5)<<board[3][8]<<setw(5)<<"|"<<setw(5)<<board[3][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(5)<<"\u001b[31m   S3\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L7\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S4\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //60-51
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[4][0]<<setw(5)<<"|"<<setw(5)<<board[4][1]<<setw(5)<<"|"<<setw(5)<<board[4][2]<<setw(5)<<"|"<<setw(5)<<board[4][3]<<setw(5)<<"|"<<setw(5)<<board[4][4]<<setw(5)<<"|"<<setw(5)<<board[4][5]<<setw(5)<<"|"<<setw(5)<<board[4][6]<<setw(5)<<"|"<<setw(5)<<board[4][7]<<setw(5)<<"|"<<setw(5)<<board[4][8]<<setw(5)<<"|"<<setw(5)<<board[4][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(5)<<"\u001b[31m   S4\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L5\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S2\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L6\u001b[0m"<<setw(5)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //41-50
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[5][0]<<setw(5)<<"|"<<setw(5)<<board[5][1]<<setw(5)<<"|"<<setw(5)<<board[5][2]<<setw(5)<<"|"<<setw(5)<<board[5][3]<<setw(5)<<"|"<<setw(5)<<board[5][4]<<setw(5)<<"|"<<setw(5)<<board[5][5]<<setw(5)<<"|"<<setw(5)<<board[5][6]<<setw(5)<<"|"<<setw(5)<<board[5][7]<<setw(5)<<"|"<<setw(5)<<board[5][8]<<setw(5)<<"|"<<setw(5)<<board[5][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //40-31
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[6][0]<<setw(5)<<"|"<<setw(5)<<board[6][1]<<setw(5)<<"|"<<setw(5)<<board[6][2]<<setw(5)<<"|"<<setw(5)<<board[6][3]<<setw(5)<<"|"<<setw(5)<<board[6][4]<<setw(5)<<"|"<<setw(5)<<board[6][5]<<setw(5)<<"|"<<setw(5)<<board[6][6]<<setw(5)<<"|"<<setw(5)<<board[6][7]<<setw(5)<<"|"<<setw(5)<<board[6][8]<<setw(5)<<"|"<<setw(5)<<board[6][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(5)<<"\u001b[31m   S3\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L5\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[32m   L3\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L2\u001b[0m"<<setw(5)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //21-30
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[7][0]<<setw(5)<<"|"<<setw(5)<<board[7][1]<<setw(5)<<"|"<<setw(5)<<board[7][2]<<setw(5)<<"|"<<setw(5)<<board[7][3]<<setw(5)<<"|"<<setw(5)<<board[7][4]<<setw(5)<<"|"<<setw(5)<<board[7][5]<<setw(5)<<"|"<<setw(5)<<board[7][6]<<setw(5)<<"|"<<setw(5)<<board[7][7]<<setw(5)<<"|"<<setw(5)<<board[7][8]<<setw(5)<<"|"<<setw(5)<<board[7][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S5\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L4\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[31m   S2\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //20-11
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[8][0]<<setw(5)<<"|"<<setw(5)<<board[8][1]<<setw(5)<<"|"<<setw(5)<<board[8][2]<<setw(5)<<"|"<<setw(5)<<board[8][3]<<setw(5)<<"|"<<setw(5)<<board[8][4]<<setw(5)<<"|"<<setw(5)<<board[8][5]<<setw(5)<<"|"<<setw(5)<<board[8][6]<<setw(5)<<"|"<<setw(5)<<board[8][7]<<setw(5)<<"|"<<setw(5)<<board[8][8]<<setw(5)<<"|"<<setw(5)<<board[8][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L3\u001b[0m"<<setw(5)<<"|"<<setw(5)<<"\u001b[31m   S1\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L1\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
    //1-10
    cout <<"\n\t\t"<<"|"<<setw(5)<<board[9][0]<<setw(5)<<"|"<<setw(5)<<board[9][1]<<setw(5)<<"|"<<setw(5)<<board[9][2]<<setw(5)<<"|"<<setw(5)<<board[9][3]<<setw(5)<<"|"<<setw(5)<<board[9][4]<<setw(5)<<"|"<<setw(5)<<board[9][5]<<setw(5)<<"|"<<setw(5)<<board[9][6]<<setw(5)<<"|"<<setw(5)<<board[9][7]<<setw(5)<<"|"<<setw(5)<<board[9][8]<<setw(5)<<"|"<<setw(5)<<board[9][9]<<setw(5)<<"|";
    cout <<"\n\t\t"<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L1\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[31m   S1\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|"<<setw(5)<<"\u001b[32m   L2\u001b[0m"<<setw(5)<<"|"<<setw(10)<<"|";
    cout <<"\n\t\t|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|_________"<<"|";
}

// Game Score
void gamescore(string player1name, string player2name, int P1, int P2) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << endl;
    cout << "\n\t\tGAME STATUS";
    SetConsoleTextAttribute(hConsole, 7);
    cout<< endl;

    SetConsoleTextAttribute(hConsole, 13);
    cout << "\n\t\t" << player1name << " is at position " << P1 << endl;
    
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\n\t\t" << player2name << " is at position " << P2 << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

// Play Dice
int score, dice1 = 0, dice2 = 0, dice3 = 0;
void play_dice(int & score) {
    srand(time(NULL));
    dice1 = 0, dice2 = 0, dice3 = 0;
    // Generate Random Number from 1 to 6
    dice1 = rand()%6+1;

    // If Random Number is 6
    if (dice1 == 6) {
        cout << endl;
        cout << "\n\t\tYou got 6 >> Press any key to roll a dice again ";
        getch();
        dice2 = rand()%6+1;
    }

    // If Random Number is 6
    if (dice2 == 6) {
        cout << endl;
        cout << "\n\t\tYou got 6 >> Press any key to roll a dice again ";
        getch();
        dice3 = rand()%6+1;
    }

    // If Random Number is 6
    if (dice3 == 6) {
        dice1=0,dice2=0,dice3=0;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 4);
        cout << endl;
        cout << "\n\t\tOops!! You got 6 three times in sequence " ;
        SetConsoleTextAttribute(hConsole, 7);
    }

    cout << endl;
    cout << "\n\t\tYou got " << dice1 << " Point !! "<< endl;

    if (dice2 > 0) {
    cout << "\n\t\tYou got " << dice2 << " Point !! "<< endl;
    }

    if (dice3 > 0) {
    cout << "\n\t\tYou got " << dice3 << " Point !! "<< endl;
    }

    // Calculate Score at position 0
    if (lastpositionP1 == 0 && lastpositionP2 == 0) {
        score = score + dice1 + dice2 + dice3 - 5;
        if (dice1 == 1) {
            score = 1;
        }
    }
    // Calculate Score at position which is greater then zero
    else 
        score = score + dice1 + dice2 + dice3;
    
    if (player1 >= 1 && player2 >= 1) {
        if (score <= 100) {
            cout << "\n\t\tNow you are at position " << score << endl;
        }
    }
    switch (score) {
        case 99:
            score = 78;
            break;
        case 95:
            score = 75;
            break;
        case 93:
            score = 73;
            break;
        case 87:
            score = 24;
            break;
        case 64:
            score = 60;
            break;
        case 61:
            score = 40;
            break;
        case 52:
            score = 29;
            break;
        case 17:
            score = 7;
            break;
        case 5:
            score = 13;
            break;
        case 9:
            score = 31;
            break;
        case 18:
            score = 37;
            break;
        case 28:
            score = 84;
            break;
        case 38:
            score = 57;
            break;
        case 51:
            score = 72;
            break;
        case 62:
            score = 81;
            break;
        case 71:
            score = 92;
            break;
    }
}

// Player Turn
int player_turn() {
    system("cls");
    while (player1 < 100 && player2 < 100) {
        system("cls");
        // Call Display Board Function
        display_board();
        // Call Gamescore Function
        gamescore(player1name, player2name, player1, player2);

        if (player1 == 0) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 13);
            cout << "\n\t\t" << player1name;
            SetConsoleTextAttribute(hConsole, 7);
            cout << " : Now your Turn >> Press any key to roll a dice ";
            getch();
            lastpositionP1 = player1;
            play_dice(player1);
            this_thread::sleep_for(0.5s);
            if (dice1 == 1) {
                
            }
            else if (dice1 == 6) {
                switch (player1) {
                    case 5:
                        player1 = 13;
                        break;
                    case 9:
                        player1 = 31;
                        break;
                }
                if (player1 < lastpositionP1 - dice1 - dice2 - dice3) {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\t\tOops!! Snake found !! Now You are at postion " << player1 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player1 > lastpositionP1 + dice1 + dice2 + dice3) {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\n\t\tGreat!! you got a ladder !! Now You are at position " << player1 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            else 
                player1 = 0;
        }
        else if (player1 > 0) {
            // Player 1 Turn Runs only if Player 2 value is less than 100
            if (player2 < 100) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 13);
                cout << "\n\t\t" << player1name;
                SetConsoleTextAttribute(hConsole, 7);
                cout << " : Now your Turn >> Press any key to roll a dice ";
                getch();
                lastpositionP1 = player1;
                play_dice(player1);
                if (player1 < lastpositionP1 - dice1 - dice2 - dice3) {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\t\tOops!! Snake found !! Now You are at postion " << player1 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player1 > lastpositionP1 + dice1 + dice2 + dice3) {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\n\t\tGreat!! you got a ladder !! Now You are at position " << player1 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player1 > 100) {
                    player1 = lastpositionP1;
                }
            }
        }

        if (player2 == 0) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 13);
            cout << "\n\t\t" << player2name;
            SetConsoleTextAttribute(hConsole, 7);
            cout << " : Now your Turn >> Press any key to roll a dice ";
            getch();
            lastpositionP2 = player2;
            play_dice(player2);
            this_thread::sleep_for(0.5s);
            if (dice1 == 1) {

            }
            else if (dice1 == 6) {
                switch (player2) {
                    case 5:
                        player2 = 13;
                        break;
                    case 9:
                        player2 = 31;
                        break;
                }
                if (player1 < lastpositionP2 - dice1 - dice2 - dice3) {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\t\tOops!! Snake found !! Now You are at postion " << player2 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player2 > lastpositionP2 + dice1 + dice2 + dice3) {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\n\t\tGreat!! you got a ladder !! Now You are at position " << player2 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
            }
            else 
                player2 = 0;
        }

        else if (player2 > 0) {
            // Player 2 Turn Runs only if Player 1 value is less than 100
            if (player1 < 100) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 14);
                cout << "\n\t\t" << player2name;
                SetConsoleTextAttribute(hConsole, 7);
                cout << " : Now your Turn >> Press any key to roll a dice ";
                getch();
                lastpositionP2 = player2;
                play_dice(player2);
                if (player2 < lastpositionP2 - dice1 - dice2 - dice3) {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << "\n\t\tOops!! Snake found !! Now You are at postion " << player2 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player2 > lastpositionP2 + dice1 + dice2 + dice3) {
                    SetConsoleTextAttribute(hConsole, 2);
                    cout << "\n\t\tGreat!! you got a ladder !! Now You are at position " << player2 << endl;
                    SetConsoleTextAttribute(hConsole, 7);
                }
                else if (player2 > 100) {
                    player2 = lastpositionP2;
                }
            }
            getch();
        }
    }
    return 0;
}

// Result
void result() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\n\t\t\tRESULT\n\n";
    cout << endl;
    if (player1 == 100){
        SetConsoleTextAttribute(hConsole, 13);
        cout <<"\n\t"<< player1name << " !! You are the winner of the game\n\n";
    }
    else if (player2 == 100){
        SetConsoleTextAttribute(hConsole, 14);
        cout <<"\n\t"<< player2name << " !! You are the winner of the game\n\n";
    }
    SetConsoleTextAttribute(hConsole, 7);
}

// Win Count Player1
void win_count_p1() {
    if (player1 == 100)
      CurrentStreakP1++;
    else
      CurrentStreakP1 = 0;
    if (CurrentStreakP1 > LongerStreakP1)
      LongerStreakP1 = CurrentStreakP1;
}
// Win Count Player2
void win_count_p2() {
    if (player2 == 100)
      CurrentStreakP2++;
    else
      CurrentStreakP2 = 0;
    if (CurrentStreakP2 > LongerStreakP2)
      LongerStreakP2 = CurrentStreakP2;
}

main() {
    // Call Display Welcome Message Function
    welcome();
    // Call Display Input Player 1 Name Function
    player1n();
    // Call Display Input Player 2 Name Function
    player2n();
    
char response;
do {
    // Display Player Turn
    player_turn();
    // Display Result
    result();
    // Display Win Count
    win_count_p1();
    win_count_p2();

    // Display Win Count
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\n\t\tWIN Count";
    SetConsoleTextAttribute(hConsole, 7);

    // Display Player Name 1
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\n" << setw(10) << player1name;
    SetConsoleTextAttribute(hConsole, 7);
    // Display Player's Number of Wins
    cout << setw(20) << LongerStreakP1 << endl;
    
    // Display Player Name 2
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\n" << setw(10) << player2name;
    SetConsoleTextAttribute(hConsole, 7);
    // Display Player's Number of Wins
    cout << setw(20) << LongerStreakP2 << endl;

    while (response != 'Y' || response != 'y' || response != 'N' || response != 'n') {
        // Check Player wants to Play Again or Not
        if (player1 >= 100 || player2 >= 100) {
            cout << endl;
            cout <<"\n\t\tDo you want to play again! Respond with Y/N ?: ";
            response = getch();
            // If User want to PlayAgain
            if (response=='Y' || response=='y') {
                player1 = 0, player2 = 0, lastpositionP1 = 0, lastpositionP2 = 0;
                break;
            }
            // If User don't want to PlayAgain
            else if (response=='N' || response=='n') {
                cout << endl;
                cout <<"\n\t\tGood Bye!"<< endl;
                cout << endl;
                this_thread::sleep_for(2s);
                break;
            }
            // If User Give Wrong Input
            else {
                cout << endl;
                cout <<"\n\t\tIncorrect Choice"<< endl;
            }
        }
    }
}
while(response == 'Y' || response == 'y');
    return 0;
}