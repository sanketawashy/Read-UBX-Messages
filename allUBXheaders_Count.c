/*
*
* SANKET AWASTHY
* 07 SEP 2023 | 09:41
*
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    FILE *file;
    uint8_t buffer[4];  // A buffer to read 4 bytes at a time
    int headerCount0d03 = 0;
    int headerCount0215 = 0;
    int headerCount0213 = 0;
    int bytesRead;

    // Open the .ubx file for reading
    file = fopen("/home/sanket/Desktop/Fly_022.ubx", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file in 4-byte chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) == sizeof(buffer)) {
        // Check for b5620d03
        if (buffer[0] == 0xb5 && buffer[1] == 0x62 && buffer[2] == 0x0d && buffer[3] == 0x03) {
            headerCount0d03++;
        }
        // Check for b5620215
        if (buffer[0] == 0xb5 && buffer[1] == 0x62 && buffer[2] == 0x02 && buffer[3] == 0x15) {
            headerCount0215++;
        }
        // Check for b5620213
        if (buffer[0] == 0xb5 && buffer[1] == 0x62 && buffer[2] == 0x02 && buffer[3] == 0x13) {
            headerCount0213++;
        }
    }

    // Close the file
    fclose(file);

    // Print the counts
    printf("Header b5620d03 appears %d times.\n", headerCount0d03);
    printf("Header b5620215 appears %d times.\n", headerCount0215);
    printf("Header b5620213 appears %d times.\n", headerCount0213);
    

    return 0;
}
