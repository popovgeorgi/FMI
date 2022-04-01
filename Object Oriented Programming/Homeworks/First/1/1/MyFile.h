#pragma once
struct MyFile
{
	int* bytes;
	int bytesCount;
	char* initialFileName;

	MyFile(int bytesCount, char* fileName);

	bool replaceByte(int position, int newValue);
	void removeLastByte();
	bool addByteAtTheEnd(int value);

	void save();
	void saveAs(char* fileName);

	void printBytesAsHex();
	void printBytesAsSymbols();

private:
	void setBytes(char* fileName, int fileSize);
};