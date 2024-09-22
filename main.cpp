/*
Craig Truitt (49115566)
Code made with assistance from https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
Main Contributor: Ava Everett
Other Contributors: Craig Truitt, Jordan Cox, Alex Gao, & Jeremy Baron
*/
#include <iostream> // Include input/output stream
using namespace std; // Use the standard namespace

int* find(int v, int** s, int nR, int nC); // Function declaration to find a value in a 2D array

int main() { // Main function
    int numRows = 0; // Number of rows in the spreadsheet
    int numColumns = 0; // Number of columns in the spreadsheet
    int val = 0; // Variable to store values

    cout << "How many rows would you like your spreadsheet to be?" << endl; // Ask the user for the number of rows
    cin >> numRows; // Input the number of rows

    cout << "How many columns would you like your spreadsheet to be?" << endl; // Ask the user for the number of columns
    cin >> numColumns; // Input the number of columns

    int** spreadsheet = new int* [numRows]; // Allocate memory for a 2D array of rows
    for (int i = 0; i < numRows; i++) { // Loop to allocate memory for each row
        spreadsheet[i] = new int[numColumns]; // Allocate memory for the columns in each row
    }

    for (int i = 0; i < numRows; i++) { // Loop through each row to fill the spreadsheet
        for (int j = 0; j < numColumns; j++) { // Loop through each column to fill the spreadsheet
            cout << "Enter the val for " << i + 1 << ',' << j + 1 << ' '; // Prompt user for values at (i+1, j+1)
            cin >> val; // Input value for the cell
            spreadsheet[i][j] = val; // Store the value in the cell
        }
    }

    cout << "Spreadsheet made with " << numRows << " rows and " << numColumns << " columns." << endl; // Output message showing the spreadsheet size

    // Print the spreadsheet
    for (int i = 0; i < numRows; i++) { // Loop through each row
        for (int j = 0; j < numColumns; j++) { // Loop through each column
            cout << spreadsheet[i][j] << '\t'; // Output each value with tab spacing
        }
        cout << endl; // Move to the next line after printing all columns in the row
    }

    for (int i = 0; i < numRows; i++) { // Loop to calculate row sums and averages
        val = 0; // Reset val to 0 for each row
        for (int j = 0; j < numColumns; j++) val += spreadsheet[i][j]; // Add all values in the row
        cout << "Value of Row " << i + 1 << " = " << val << endl; // Output the sum of the row
        cout << "Avg of Row " << i + 1 << " = " << double(val) / numRows << endl; // Output the average of the row
    }

    for (int i = 0; i < numColumns; i++) { // Loop to calculate column sums and averages
        val = 0; // Reset val to 0 for each column
        for (int j = 0; j < numRows; j++) val += spreadsheet[j][i]; // Add all values in the column
        cout << "Value of Column " << i + 1 << " = " << val << endl; // Output the sum of the column
        cout << "Avg of Column " << i + 1 << " = " << double(val) / numRows << endl; // Output the average of the column
    }

    val = INT_MIN; // Set val to the minimum possible integer
    for (int i = 0; i < numRows; i++) // Loop through each row
        for (int j = 0; j < numColumns; j++) // Loop through each column
            if (spreadsheet[i][j] > val) // Check if current cell value is greater than val
                val = spreadsheet[i][j]; // Update val with the maximum value
    cout << "Max val: " << val << endl; // Output the maximum value in the spreadsheet

    val = INT_MAX; // Set val to the maximum possible integer
    for (int i = 0; i < numRows; i++) // Loop through each row
        for (int j = 0; j < numColumns; j++) // Loop through each column
            if (spreadsheet[i][j] < val) // Check if current cell value is less than val
                val = spreadsheet[i][j]; // Update val with the minimum value
    cout << "Min val: " << val << endl; // Output the minimum value in the spreadsheet

    cout << "What value needs finding: " << endl; // Ask the user for a value to find
    cin >> val; // Input the value to find
    int* res = find(val, spreadsheet, numRows, numColumns); // Call the find function to search for the value
    if (res[0] != INT_MIN) cout << "First finding @ " << res[0] << ',' << res[1] << endl; // If found, output the location of the first occurrence
    else cout << "Value not found" << endl; // If not found, output message
    delete[] res; // Deallocate memory for the result array

    // Deallocate memory for the spreadsheet
    for (int i = 0; i < numRows; i++) { // Loop through each row
        delete[] spreadsheet[i]; // Deallocate memory for each row
    }
    delete[] spreadsheet; // Deallocate memory for the array of pointers

    return 0; // Return success code
}

int* find(int v, int** s, int nR, int nC) { // Function to find the value in the spreadsheet
    int* p = new int[2]; // Allocate memory for result coordinates
    for (p[0] = 0; p[0] < nR; p[0]++) // Loop through each row
        for (p[1] = 0; p[1] < nC; p[1]++) // Loop through each column
            if (v == s[p[0]][p[1]]) // If the value is found
                return p; // Return the coordinates
    p[0] = INT_MIN; // If not found, set result to INT_MIN
    p[1] = INT_MIN; // Set both coordinates to INT_MIN
    return p; // Return result
}
