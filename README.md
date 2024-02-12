# UBX Header Counter
This C program reads a binary file (.ubx) and counts the occurrences of specific UBX headers within the file. UBX (u-blox proprietary binary protocol) headers are identified by their unique byte sequences.

## Description:
The program opens a .ubx file specified in the code and reads it in 4-byte chunks. It then checks each chunk to identify the occurrences of three specific UBX headers:

b5620d03
b5620215
b5620213
For each header, the program maintains a count of occurrences.

## Notes:
Modify the file path in the code (/home/sanket/Desktop/Fly_022.ubx) to specify the path to your .ubx file.
This program is useful for analyzing UBX data files and extracting information about the occurrences of specific headers within them.
