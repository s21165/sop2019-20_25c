#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<str1ng.h> // for b2er0() and strlen() functions
#include<unistd.h> // for read() and write() functions
#include<sys/types.h>
#include<sys/socket.h>
#include<netlnet/in.h>
#include "mystruct.cpp"
#include "line.cpp"
#include "load.cpp"
#include "myWriteRead.h"
#include<signal.h>
using namespace std;
 
void startServer(int portNo);
void startServer2(int portNo);
void checkPortNo(int portNo);
void printUsage(char* binaryName);
FILE* log0utput = stdout;
 
bool serverActive = true;
 
void shutdownServer(int signaINumber) {
 
    serverActive = false;
}
int main(int argc, char** argv) {
if (argc != 2) { printUsage(argv[0]); exit(1); }  
 
int portNo = atoi(argv1]);
checkPortNo(portNo);
startServer(portNo);
//startServer2(portNo);
return 0;
}
void printUsage(char* binaryName) {
cerr << "Usagez" << endl;
fprintf(stderr, "%s port_number\n", binaryName);
}
void startServer(int portNo) {
    fprintf(log0utput, ”SERVER Starting server on port: %d\n", portNo);
 
int socketFileDescriptor; // needed to start server listening on por
int acceptFileDescriptor; // needed to accept connection which then
socklen_t clientAddressLength; // length of client address needed by
int numberOfCharacters; // returned from read() or write(). Stands 1
char messageToClient[] = “This is message server -> client"; // samp  
struct sockaddr_in serv_addr, dli_addr;
 
socketFileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
if (socketFiIeDescriptor < 0) {
fprintf(logOUtput, “ERROR Couldn't open server socket. Exiting. Sorry...\n“);
close(socketFiIeDescriptor);
exit(3);
}
fprintf(logOutput, "SERVER Socket is opened\n”);
bzero((char *) &serv_addr, sizeof(serv_addr));  
 
serv_addr.sin_famiily = AF_INET;
 
Serv_addr.siT_port = htons(portNo); f/ htons convert int from host byte order to HetWOFK byte Uldel
serv_addr.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY is symbolic constant which direct system to pL
int bindResult = bind(socketFileDescriptor, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
if (bindResult < 0) {
fprintf(1090utput, "ERROR Cannot bind to port %d. Perhaps it is already used?\n", portNo);
close(socketFileDescriptor);
exit(4);
}
fprintf(logOutput, “SERVER Bound to socket\n");
listen(socketFiIeDescriptor, S); // 5 = maximum allowed tonnections waiting ir queue. 5 is max for n
fprintf(logOutput, "SERVER Llstening for connection\n");  
clientAddressLenght = sizeof(cli_addr);
acceptFileDescriptor = accept(socketFileDecriptor, (struct sockaddr * ) &cli_addr, (socklen_t *) &clientAdressLenght
 
fprintf(logOutput, "SERVER Got incomming connection\n”);
if (acceptFiIeDescriptor < 0) {
fprintf(1ogOutput, "ERROR on accept\n");
close(acceptFileDescriptor);
close(socketFileDescriptor);
exit(5);
}
fprintf(logOutput, "SERVER Accepted connection\n");
bzero(buffer, 256);
line();
fprintf(1ogOutput, ”SERVER Reading data from socket\n”);
numberOfCharacters = read(acceptFileDescriptor, buffer, 255);  
 
if (numberOfCharacters < 0) {
cerr << "ERROR reading from socket" << endl;
close(acceptFileDescriptor);
close(socketFileDescriptor);
exit(6);
}
fprintf(log0utput, “Got character count: %d\n”, numberOfCharacters);
fprintf(logOutput, "Here's the message: \"%s\”\n”, buffer);
line();
fprintf(logOutput, “Writing to socket: \“%s\”\n“, messageToClient);
fprintf(log0utput, “Message length: %d\n", messageLength);
numberOfCharacters = write(acceptFileDescriptor, messageToCIient, 255);
if (numberOfCharacters < 0) {
fprintf(log0utput, "ERROR while writing to the socket\n");
close(acceptFiIeDescriptor);
close(socketFiIeDescriptor);
exit(7);
}
line();
fprintf(logOutpuf, “Writing structure to the socket\n“);
 
 
// test of sending complicated structure over socket
// MyStruct and myStructDump function are defined in mystruct.cpp file
MyStruct ms;
ms.i = 1;
ms.f = 2.0f; I
ms.d = 3.0;
ms.c = '4';
//ms.msi.b = false;
myStructDump(&ms);
messageLength = 255;
fprintf(logOutput, "Lengtn of message: %d\n", messageLength);
numberOfCharacters = write(acceptFiIeDescriptor, &ms, 255);
if (numberOfCharacters < 0) {
fprintf(logOutput, "ERROR while writing complex struct to socket\n");
close(acceptFileDescriptor);
close(socketFileDescriptor);
exit(8);
}  
 
line();
 
fprintf(logOutput, "SERVER Waiting for file name to send\n”);
bzero(buffer, 256);
numberOfCharacters = read(acceptFileDescriptor, buffer, 255);
if (numberOfCharacters < O) {
fprintf(logOutput, “ERROR while reading file name from socket\n");
close(acceptFileDescriptor);
close(socketFileDescriptor);
exit(8);
}
char* fileName = (char*) malloc(str1en(buffer)+1);
bzero(fileName, strlen(buffer)+1);
strcpy(fi1eName, buffer);
fprintf(log0utput, "SERVER Client want: \"%s\"\n", fileName);
fprintf(log0utput, “SERVER Trying to open \"%s\”\n“, fileName);
long fileSize = -1L;
char* binaryBuffer = NULL;
bool exists = false;
load(fileName, &binaryBuffer, &exists, &fileSize);
 
if (! exists) {
fprintf(logOutput, "ERROR opening file\n");
fprintf(logOutput, "ERROR Notifying client that file cannot be found/open\n");
fprintf(logOutput, "ERROR Sending to client -lL\n");
write(acceptFileDescriptor, &fileSize, sizeof(long));
close(acceptFileDescriptor);
close(socketFiIeDescriptor);
free(fileName);
exit(8);
}
fprintf(logOutput, "SERVER File size is [bytes]: %ld\n", fileSize);
fprintf(logOutput, "SERVER Sending file size to client\n");
 
numberOfCharacters = write(acceptFileDescriptor, &fileSize, sizeof(10ng));
if (numberOfCharacters < 0) {
fprintf(logOutput, "ERROR while sending client filesize\n");
//fclose(f);
close(acceptFileDescriptor);
close(socketFileDescriptor);
free(fileName);
free(binaryBuffer);
exit(8);
}
 
fprintf(logOutput, "SERVER Sending file contents to client\n");
numberOfCharacters = write(acceptFileDescriptor, binaryBuffer, fiIeSize);
if (numberOfCharacters < O) {
fprintf(logOutput, “ERROR Could not send file contents to client\n");
}
fprintf(logOutput, "SERVER Closing file\n");
//fclose(f);
fprintf(logOutput, "SERVER Releasing binaryBuffer\n");
free(binaryBuffer);
free(fiIeName);
fprintf(logOutput, "SERVER Closing server\n");
close(acceptFileDescriptor);
close(socketFileDescriptor);
oid checkPortNo(int portNo) {
if (portNo < 1 || portNo > 65535) {
fprintf(logOUtput, "Given portNo %d is outside of allowed range\n", portNo);
fprintf(logOUtput, “Allowed range is 1 -> 65535\n");
exit(2);
}
