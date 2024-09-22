/*
Craig Truitt (49115566)
Code made with assistance from https://chatgpt.com/g/g-2DQzU5UZl-code-copilot
No Collaborators
*/
#include <iostream>
using namespace std;

void insert(int* arr, int val, int len); // Function to insert a value into an array
void remove(int* arr, int val, int len); // Function to remove a value from an array
int find(int* arr, int val, int len); // Function to find a value in an array
void display(int* arr, int len); // Function to display the contents of an array

int main() {
	int sArray[10]; // Declare a static array of size 10
	for (int i = 0; i < 10; i++) sArray[i] = INT_MIN; // Initialize static array elements to INT_MIN (used as empty)

	cout << "How long should the dynamic array be? "; // Prompt user for the size of the dynamic array
	int len; // Declare a variable to hold the length of the dynamic array
	cin >> len; // Read the length input from the user
	int* dArray = new int[len]; // Dynamically allocate an array of size `len`
	for (int i = 0; i < len; i++) dArray[i] = INT_MIN; // Initialize dynamic array elements to INT_MIN

	cout << "Static Array:\n"; // Output label for static array operations
	insert(sArray, 0, 10); // Insert 0 into the static array
	display(sArray, 10); // Display the static array contents
	insert(sArray, 1, 10); // Insert 1 into the static array
	display(sArray, 10); // Display the static array contents
	insert(sArray, 2, 10); // Insert 2 into the static array
	display(sArray, 10); // Display the static array contents
	insert(sArray, 3, 10); // Insert 3 into the static array
	display(sArray, 10); // Display the static array contents
	remove(sArray, 2, 10); // Remove 2 from the static array
	display(sArray, 10); // Display the static array contents
	int index = find(sArray, 3, 10); // Find the index of 3 in the static array
	if (index != INT_MIN) cout << sArray[index] << " @ " << index << endl; // If found, print value and index
	else cout << "3 not found\n"; // If not found, print "not found" message
	remove(sArray, 3, 10); // Remove 3 from the static array
	display(sArray, 10); // Display the static array contents
	index = find(sArray, 3, 10); // Find the index of 3 in the static array again
	if (index != INT_MIN) cout << sArray[index] << " @ " << index << endl; // If found, print value and index
	else cout << "3 not found\n"; // If not found, print "not found" message

	cout << "Dynamic Array:\n"; // Output label for dynamic array operations
	insert(dArray, 0, len); // Insert 0 into the dynamic array
	display(dArray, len); // Display the dynamic array contents
	insert(dArray, 1, len); // Insert 1 into the dynamic array
	display(dArray, len); // Display the dynamic array contents
	insert(dArray, 2, len); // Insert 2 into the dynamic array
	display(dArray, len); // Display the dynamic array contents
	insert(dArray, 3, len); // Insert 3 into the dynamic array
	display(dArray, len); // Display the dynamic array contents
	remove(dArray, 2, len); // Remove 2 from the dynamic array
	display(dArray, len); // Display the dynamic array contents
	index = find(dArray, 3, len); // Find the index of 3 in the dynamic array
	if (index != INT_MIN) cout << dArray[index] << " @ " << index << endl; // If found, print value and index
	else cout << "3 not found\n"; // If not found, print "not found" message
	remove(dArray, 3, len); // Remove 3 from the dynamic array
	display(dArray, len); // Display the dynamic array contents
	index = find(dArray, 3, len); // Find the index of 3 in the dynamic array again
	if (index != INT_MIN) cout << dArray[index] << " @ " << index << endl; // If found, print value and index
	else cout << "3 not found\n"; // If not found, print "not found" message

	delete[] dArray; // Deallocate the dynamic array memory

	return 0; // End of program
}

void insert(int* arr, int val, int len) {
	int i; // Declare index variable
	for (i = 0; i < len && arr[i] != INT_MIN; i++); // Find the first empty slot (INT_MIN) in the array
	if (i < len) arr[i] = val; // If a slot is found, insert the value
	else cout << "Array full\n"; // If no slot is found, print "Array full"
}

void remove(int* arr, int val, int len) {
	int i; // Declare index variable
	for (i = 0; i < len && arr[i] != val; i++); // Find the element to remove
	for (; i < len - 1; i++) arr[i] = arr[i + 1]; // Shift remaining elements to the left
	arr[len - 1] = INT_MIN; // Mark the last element as empty (INT_MIN)
}

int find(int* arr, int val, int len) {
	for (int i = 0; i < len; i++) { // Iterate through the array
		if (arr[i] == val) return i; // If the value is found, return its index
	}
	return INT_MIN; // If the value is not found, return INT_MIN
}

void display(int* arr, int len) {
	int max; // Declare a variable to track the number of valid elements
	for (max = 0; max < len && arr[max] != INT_MIN; max++); // Count valid elements (non-INT_MIN)
	for (int i = 0; i < max; i++) { // Loop through the valid elements
		cout << arr[i]; // Print the element
		if (i != max - 1) cout << ", "; // Print a comma if it's not the last element
	}
	cout << endl; // Print a newline at the end
}
