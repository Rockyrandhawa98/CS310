#include <iostream>

using namespace std;

int main() {
    enum Colors {WHITE = -1, BLACK = 1};

    // Creating a chessboard of size ROWS x COLS, where '-1' represents white squares and '1' represents black squares
    // the "color" variable is multiplied by -1 repeatedly to alternate colors during and after the inner for-loop
    const int ROWS = 8;
    const int COLS = 8;

    int chessboard[ROWS][COLS];
    int color = -1;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            chessboard[r][c] = color;
            color *= -1;
        }
        color *= -1;
    }


    cout << "-------------------------------------------------------------------" << endl;
    cout << " This program will tell you the color of a square on a chessboard. " << endl;
    cout << "-------------------------------------------------------------------" << endl;


    // Asking to specify a Column and Row
    int input_row;
    char input_col;
    
    cout << "Pick a column on a chessboard, from lower case 'a' to 'h': " << endl;
    cin >> input_col;
    int reformatted_column = int(input_col) - int('a'); // subtracting the ASCII value of 'a' to zero-out the input

    cout << "\nPick a row on a chessboard - make sure this number is between 1 and 8, both inclusive: " << endl;
    cin >> input_row;


    // Error handling
    if ((input_row < 1) && (reformatted_column < 0) && (input_row > 8) && (reformatted_column > 7)) {
        cout << "The square you selected is not valid, try running the program again." << endl;
        return 0;
    }


    // Output
    if (static_cast<Colors>(chessboard[ROWS - input_row][reformatted_column]) == WHITE) {
        cout << "The color of the square '" << input_col << input_row << "' is white." << endl;
    }
    else {
        cout << "The color of the square '" << input_col << input_row << "' is black." << endl;
    }

    return 0;
}
