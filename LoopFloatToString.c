#include <stdio.h>
#include <unistd.h> // for usleep function
#include <stdlib.h> // for malloc and free functions
#include <string.h> // for sprintf function

int main() {
    float microseconds = 1.0; // Starting at 1us
    int numSteps = 1000; // Number of steps (100us / 0.1us step size)

    // Allocate memory for the string array
    char** microStrings = (char**)malloc(numSteps * sizeof(char*));
    if (microStrings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < numSteps; i++) {
        microStrings[i] = (char*)malloc(20 * sizeof(char)); // Assuming a maximum of 20 characters for each string
        if (microStrings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    for (int i = 0; i < numSteps; i++) {
        sprintf(microStrings[i], "%.1f us", microseconds);
        microseconds += 0.1; // Increment by 0.1us
        usleep(100); // Sleep for 100 microseconds (0.1ms) to simulate the desired step size
    }

    // Print or use the strings as needed
    for (int i = 0; i < numSteps; i++) {
        printf("%s\n", microStrings[i]);
        free(microStrings[i]);
    }

    free(microStrings);

    return 0;
}
