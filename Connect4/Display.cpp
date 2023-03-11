
#include <iostream>
using namespace std;

class Display {
private:
    void printAvailable(int slots[], int n) {
        for (int i = 0; i < n; ++i) {
            if (slots[i] != -1)
                cout << i << " ";
        }
        cout << endl;
    }

public:
    void clrScr() { cout << "\033[2J\033[1;1H"; system("cls"); }

    void welcomeScreen() {
        char a;
        cout << "\n\n\t\t\t WELCOME TO \"CONNECT 4\" GAME \n\n\n\n";
        cout << "Rules: \n\n";
        cout << "1. Two player [Red(R) & Blue[B]] game. \n";
        cout << "2. Board Size is 6 X 7. \n";
        cout << "3. A player wins if they are able to connect 4 horizontally, "
            "vertically or diagonally \n";
        cout << "4. When the matrix is fully filled, the game is a draw! \n";
        cout << "\n\n\n";
        cout << "How To Play: \n\n";
        cout << "1. Game always start with player 1 i.e red(R). \n";
        cout << "2. In each step select the coloumn in which you like to drop your "
            "turn. \n";
        cout << "3. Rows will be filled from bottom to top in any coloumn. \n";

        cout << "\n\n\n";
        cout << "Enter any character to continue...\n";
        cin >> a;
    }

    void winningMessage(std::string message, char player = '*') {
        Display* endDisplay = new Display;
        endDisplay->clrScr();
        cout << "\n\n\n\n\n\nGAME OVER" << endl;
        string plyr;
        if (player == 'R') {
            plyr = "RED";
        }
        else
            plyr = "BLUE";
        if (player == '*') {
            cout << message << endl;
        }
        else
            cout << plyr << message << endl;
        delete endDisplay;
    }

    char replayScreen() {
        char x;
        cout << "press \'x\' to exit or any other character to start again!!\n";
        cin >> x;
        return x;
    }

    char endScreen() {
        char a;
        cout << "\n\n\n\n\t\t\tTHANKS FOR PLAYING!!\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t- sajan sj\n";
        cin >> a;
        return a;
    }

    void getInput(char player, int slots[], int n) {
        cout << "Available Slots : ";
        printAvailable(slots, n);
        cout << player
            << "'s TURN\nSelect the slot of your choice from the availabe slots "
            "to play :\n";
    }

    void viewTable(char** arr, const int rows, const int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0) { // TOP ROW lines
                    cout << "____";
                    if (j == cols - 1) { // RIGHT mid bottom lines
                        cout << "_";
                    }
                }
                else if (j == cols - 1) { // RIGHT mid bottom lines
                    cout << "|___|";
                }
                else // MID lines
                    cout << "|___";
            }
            cout << endl;
            for (int j = 0; j < cols; j++) {
                if (j == cols - 1) { // RIGHT ending lines with text
                    cout << "| " << arr[i][j] << " |";
                }
                else // other ending lines with text
                    cout << "| " << arr[i][j] << " ";
            }
            cout << endl;
            if (i == rows - 1) { // BOTTOM most lines
                for (int j = 0; j < cols; j++) {
                    if (j == cols - 1) { // RIGHT bottom most line
                        cout << "|___|";
                    }
                    else
                        cout << "|___";
                }
            }
        }
        cout << "\n\n" << endl;
    }
};
