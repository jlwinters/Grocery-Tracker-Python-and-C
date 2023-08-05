/*
	CS 210, Source.cpp
	Purpose: Grocery item tracking for Corner Grocer store.

	@author Jacob Winters
	@date 06/16/2021
*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


int main() {
	int a, c = 1;
	// String variable for the item names in the frequency.dat file
	string itemName;
	// Integer for the item quantity in the frequency.dat file
	int itemQuantity;
	while (c > 0) {
		// The below loop command allows the program to display the menu and return to the menu if invalid input is received
			// Prompt for and obtain user input for the program menu
		printf("*************************************\n");
		printf("********Corner Grocer Tracker********\n");
		cout << "1: View Item Purchase List\n";
		cout << "2: View Specific Item Purchase Information\n";
		cout << "3: View Daily Item Purchase Information\n";
		cout << "4: Exit\n";
		// Using printf command since we do not need to collect input here
		printf("Enter your selection as a number 1, 2, 3, or 4.\n");

		cin >> a;
		// if loop to provide functions for user input of 1, 2, 3, or 4.
		// If user input is 1, send input to python script
		if (a == 1) {
			// Access the item list that is setup in the PythonCode.py file
			CallProcedure("ItemList");
			system("pause");
		}
		// Option 2 for our specific item purchase information
		else if (a == 2) {
			// Pass a string to Python that will be searched for within the item list
			string v;
			cout << "Please enter the name of an item to begin search: ";
			cin >> v;
			// Execute the ItemFreq function defined in PythonCode.py
			cout << callIntFunc("ItemFreq", v) << endl;
			system("pause");
		}
		// Option 3 for our daily item purchase information
		else if (a == 3) {
			// Use Python to create the frequency.dat file and then read from it
			CallProcedure("Frequency");
			ifstream inFile("frequency.dat");
			while (inFile >> itemName >> itemQuantity) {
				cout << itemName << " ";
				// Replace the item quantity with an asterisk character
				for (int i = 0; i < itemQuantity; i++) {
					cout << "*";
				}
				cout << endl;
			}
			system("pause");
		}
		// Exit the program if option 4 is selected
		else if (a == 4) {
			exit(0);
		}
	}
}
