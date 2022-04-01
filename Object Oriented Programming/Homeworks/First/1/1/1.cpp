#include <iostream>
#include <fstream>
#include "Helpers.h"
#include "MyFile.h"

using namespace std;

const char* VIEW_COMMAND = "view";
const char* REMOVE_COMMAND = "remove";
const char* CHANGE_COMMAND = "change";
const char* ADD_COMMAND = "add";
const char* SAVE_COMMAND = "save";

const char* INVALID_COMMAND_MESSAGE = "Invalid command! Please enter a new one!";
const char* SUCCESSFUL_OPERATION_MESSAGE = "Operation successfully executed!";
const char* INVALID_OPERATION_MESSAGE = "Operation is not successful!";
const char* SUCCESSFUL_FILE_SAVING = "File successfully saved!";

int main()
{
	cout << "Enter a file path:" << endl;
	char input[50];
	cin.getline(input, 50);
	int bytesCount = getBytesOfFile(input);
	if (bytesCount == -1)
	{
		cout << "File could not be loaded!" << endl;
		return -1;
	}
	MyFile myFile(bytesCount, input);

	char command[20];
	while (true)
	{
		cin >> command;
		if (areEqual(command, VIEW_COMMAND))
		{
			myFile.printBytesAsHex();
			cout << "-----------------------" << endl;
			myFile.printBytesAsSymbols();
		}
		else if (areEqual(command, REMOVE_COMMAND))
		{
			myFile.removeLastByte();
			cout << SUCCESSFUL_OPERATION_MESSAGE << endl;
		}
		else if (areEqual(command, CHANGE_COMMAND))
		{
			char index[5];
			cin >> index;
			char value[10];
			cin >> value;

			int indexAsInt = getIntFromString(index);
			int valueAsInt = getIntFromString(value);

			if (myFile.replaceByte(indexAsInt, valueAsInt))
			{
				cout << SUCCESSFUL_OPERATION_MESSAGE << endl;
			}
			else
			{
				cout << INVALID_OPERATION_MESSAGE << endl;
			}
		}
		else if (areEqual(command, ADD_COMMAND))
		{
			char value[10];
			cin >> value;

			int valueAsInt = getIntFromString(value);

			if (myFile.addByteAtTheEnd(valueAsInt))
			{
				cout << SUCCESSFUL_OPERATION_MESSAGE << endl;
			}
			else
			{
				cout << INVALID_OPERATION_MESSAGE << endl;
			}
		}
		else if (areEqual(command, SAVE_COMMAND))
		{
			char symbol[1];
			cin.read(symbol, 1);
			if (symbol[0] != '\n')
			{
				char other[3];
				cin >> other;
				char filePath[20];
				cin >> filePath;
				myFile.saveAs(filePath);
			}
			else
			{
				myFile.save();
			}

			cout << SUCCESSFUL_FILE_SAVING << endl;
			break;
		}
		else
		{
			cout << INVALID_COMMAND_MESSAGE << endl;
			continue;
		}
	}

	return 0;
}
