#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

const int PORT = 8080;
const char* SERVER_IP = "127.0.0.1";

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    // Set SO_REUSEADDR option
    int opt = 1;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        std::cerr << "Error setting socket options\n";
        close(serverSocket);
        return -1;
    }

    // Bind socket
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket\n";
        close(serverSocket);
        return -1;
    }
    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening for connections\n";
        close(serverSocket);
        return -1;
    }

    std::cout << "Server listening on port " << PORT << "\n";

    while (true) {
        // Accept a connection
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection\n";
            continue;
        }

        // Read abbreviation from client
        char abbreviation[3];
        recv(clientSocket, abbreviation, sizeof(abbreviation), 0);

        abbreviation[2] = '\0';

        // Process the abbreviation (replace with your logic)
        std::string stateName;
        
        if (strcmp(abbreviation, "IN") == 0) {
            stateName = "Indiana";
        } else if (strcmp(abbreviation, "NY") == 0) {
            stateName = "New York";
        } else if (strcmp(abbreviation, "CA") == 0 {
            stateName = "California";
        }
        }

        // Send the state name back to the client
        send(clientSocket, stateName.c_str(), stateName.size() + 1, 0);

        // Close the connection
        close(clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return 0;
}
