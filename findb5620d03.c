#include <stdio.h>
#include <stdint.h>

int main() {
    // Open the .ubx file in binary mode
    FILE *file = fopen("/home/sanket/Desktop/Fly_022.ubx", "rb");

    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    uint8_t header[] = {0xb5, 0x62, 0x0d, 0x03
};
    int headerSize = sizeof(header);
    int count = 0;
    int c;

    // Read the file byte by byte and look for the header pattern
    while ((c = fgetc(file)) != EOF) {
        if (c == header[0]) {
            // First byte matched, check for the complete header
            int i;
            for (i = 1; i < headerSize; i++) {
                c = fgetc(file);
                if (c != header[i]) {
                    break;  // Header mismatch, break the loop
                }
            }

            if (i == headerSize) {
                // Complete header matched
                count++;
            }
        }
    }

    printf("Header 'b5620d03' appears %d times in the file.\n", count);

    // Close the file
    fclose(file);

    return 0;
}
