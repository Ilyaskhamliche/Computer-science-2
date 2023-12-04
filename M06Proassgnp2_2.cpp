#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;
const char* SERVER_IP = "127.0.0.1"; 

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    // Connect to the server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(clientSocket);
        return -1;
    }

    // Get state abbreviation from user
    std::cout << "Enter state abbreviation: ";
    std::string abbreviation;
    std::cin >> abbreviation;

    // Send abbreviation to server
send(clientSocket, abbreviation.c_str(), abbreviation.size() + 1, 0);


    // Receive state name from server
    char stateName[256];
    recv(clientSocket, stateName, sizeof(stateName), 0);

    
    std::cout << "State Name: " << stateName << "\n";

    // Close the connection
    close(clientSocket);
    return 0;
}
