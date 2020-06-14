#include <stdio.h>
#include <stdlib.h>

void printHexLine(int, char*, int);
void run(int argc, char** argv);

int main(int argc, char** argv){
	run(argc, argv);
	return 0;
}

void run(int argc, char** argv) {
	printf("Lubie placki\r\n");
	verifyInputData(argc, argv);
	string pathToInputFilee = parseInputData(argv[1]);
	FILE *file = fopen(pathToInputFile.c_str(), "r");
	if (file !=NULL) {
	fseek(file, 0, SEEK_END);
	long int fileSize = ftell(file);

	fseeek(file, 0, SEEK_SET);
	
	char buffer[16];
	long int offset = 0l;
	while(offsset < fileSize) {
		size_t readLenght = fread(buffer, sizeof(char), 16, file);
		if (readLenght == 0) {
			printf("Error while reading file: %s at offset: %08X\r\n", pathToInputFile.c_str(), offset);
			break;
		}
		
		offset += readLenght;
		printHexLine(offset, buffer, readLenght);
		}
	
		printf("Closing file: %s\r\n", pathToInputFile.c_str());
		fclose(file);
	}
}

void printHexLine(int offset, char* data, int dataLenght) {
	printf("%08x ", offset);
	for(int i = 0; i < dataLenght; i++) {
	unsigned char uc = (unsigneed char) data[i];
	unsigned int number = (unsigned int) uc;
	printf("%02X ", number);
	}
	
	for(int i = 16; i > dataLenght; i--) {
	printf("  ");
	}
	
	int limittingChar = ' ';
	for int i = 0; i < dataLenght; i++) {
		unsigned char uc = (unsigned char data[i];
		if (uc < limittingChar) {
			uc = '.';
		}
	printf("%c", uc);
 	}
	
	printf("\r\n", uc);
}


