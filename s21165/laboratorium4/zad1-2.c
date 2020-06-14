#include <stdio.h>
#include <stdlib.h>

typedef int (*function)(int,int*);

int askNumber(char* message);
int readNumber();
int readANDCalc(int,function);
int sumArray(int, int*);
int multiplyArray(int count, int *numbers);
void printResult(int result);

int main(int argc, char**argv) {
	function functions[] = {sumArray, multiplyArray};
	int numberCount = 0;
	int result = 0;
	int functionNumber = 0;

	printf("0- sumowanie\n1 - mnożenie\n");
	functionNumber = askNumber("wybierz ktore działanie wykorzystać [0,1]");
	numberCount = askNumber("ile chcesz wprowadzic liczb?");

	result = readANDCalc(numberCount, functions[functionNumber]);
	printResult(result);

	return result;
}

int readANDCalc(int numberCount, function f) {
	int *numbers = calloc(numberCount, sizeof(int));
	int i;
	int result = 0;
	printf("podaj numery w osobnych wierszach \n");
	for(i = 0; i < numberCount; i++ ){
	numbers[i] = readNumber();
	}
	result = f(numberCount, numbers);
	free(numbers);
	return result;
}
int askNumber(char* message){
	int result = 0;
	printf("%s: ", message);
	result = readNumber();
	return result;
}
int readNumber(){
	int number = 0;
	scanf("%d", &number);
	return number;
}

int sumArray(int count, int *numbers) {
	int result =0;
	int i;
	printf("Uruchomiono sumowanie \r\n");
	for(i=0; i< count; i++){
	result += numbers[i];
	}
	return result;
}
int multiplyArray(int count, int *numbers) {
	int result = 1;
	int i;
	printf("Uruchomiono mnozenie: \r\n");
	for(i=0; i < count; i++){
	result *=numbers[i];
	}
	return result;
}
void printResult(int result) {
	printf("Wynik: %d\r\n", result);
}
