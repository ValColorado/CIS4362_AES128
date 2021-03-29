#include "../include/aes_128_encrypt.h"
#include <iostream>

using namespace std;

// Encryption function
byte *encrypt_aes_128(byte *plaintext, byte *key) {
    byte *ciphertext = NULL;
    // Fill this function
    shift_rows(plaintext);
    return ciphertext;

}

// Shift rows
void shift_rows(byte *byte_array) {

    // Fill this function
    /*
    Plaintext block:
    0x41[0], 0x31[4], 0x69[8], 0x72[12],
    0x45[1],;0x32[5], 0x73[9], 0x65[13]
    0x53[2], 0x38[6], 0x20[10], 0x611[14]
    0x2d[3], 0x20[7], 0x67[11], 0x74[15
*/
    //Row 0 stays the same
    //Row 1 shift to the left one
        byte temp = byte_array[1];
        byte_array[1] = byte_array[5];
        byte_array[5] = byte_array[9];
        byte_array[9] = byte_array[13];
        byte_array[13] = temp;

    //row 2 shift to the left by two
    //create two temp values for the sift
        temp = byte_array[2];
        byte temp1 = byte_array[6];

        byte_array[2] = byte_array[10];
        byte_array[6] = byte_array[14];
        byte_array[10] = temp;
        byte_array[14] = temp1;

    //row 3 shift to the left by three
        temp = byte_array[3];
        temp1 = byte_array[7];
        byte temp2 = byte_array [11];
        byte_array[3] = byte_array[15];
        byte_array[7] = temp;
        byte_array[11] = temp1;
        byte_array[15] = temp2;

        cout<<"SHIFT ROWS"<<endl;
         for (size_t i = 0; i < 4; i++) {
        cout << "0x" << hex << byte_array[i] << " " << "0x" << hex << byte_array[i + 4] << " " << "0x" << hex
             << byte_array[i + 8] << " " << "0x" << hex << byte_array[i + 12] << endl;

    }
        //sends new byte array to mix columns function
        mix_columns(byte_array);

}

// Mix Columns
void mix_columns(byte *byte_array) {
    // Fill this function
    /*
    Mix columns takes the dot product and xor of the matrix

    2 [0], 3[4], 1[8], 1[12],
    1 [1], 2[5], 3[9], 1[13],
    1[2], 1[6], 2[10], 3[14],
    3[3], 1[7], 1[11], 2[15]

    AFTER SHIFT ROWS
    0x41[0], 0x31[4] 0x69[8] 0x72[12]
    0x32[1] 0x73[5] 0x65[9] 0x45[13]
    0x20[2] 0x61[6] 0x53[10] 0x38[14]
    0x74[3] 0x2d[7] 0x20[11] 0x67[15]

    Column 1: 2.0x41[0] xor 3.0x31[1] xor 1.0x69[2] xor 1.0x72[3]
    */

    //initialize set array
    byte mix_array [16]={2,1,1,3,3,2,1,1,1,3,2,1,1,1,3,2};

    //initialize array where product is going to be stored
    byte new_array [16];

    //Value 1
    new_array[0] = ( (mix_array[0] * byte_array[0]) ^ (mix_array[4] * byte_array[1]) ^ (mix_array[8] * byte_array[2]) ^ (mix_array[12] * byte_array[3]) );

    new_array[1] = ( (mix_array[1] * byte_array[0]) ^ (mix_array[5] * byte_array[1]) ^ (mix_array[9] * byte_array[2]) ^ (mix_array[13] * byte_array[3]) );

    new_array[2] = ( (mix_array[2] * byte_array[0]) ^ (mix_array[6] * byte_array[1]) ^ (mix_array[10] * byte_array[2]) ^ (mix_array[14] * byte_array[3]) );

    new_array[3] = ( (mix_array[3] * byte_array[0]) ^ (mix_array[7] * byte_array[1]) ^ (mix_array[11] * byte_array[2]) ^ (mix_array[15] * byte_array[3]) );


    new_array[4] = ( (mix_array[0] * byte_array[4]) ^ (mix_array[4] * byte_array[5]) ^ (mix_array[8] * byte_array[6]) ^ (mix_array[12] * byte_array[7]) );

    new_array[5] = ( (mix_array[1] * byte_array[4]) ^ (mix_array[5] * byte_array[5]) ^ (mix_array[9] * byte_array[6]) ^ (mix_array[13] * byte_array[7]) );

    new_array[6] = ( (mix_array[2] * byte_array[4]) ^ (mix_array[6] * byte_array[5]) ^ (mix_array[10] * byte_array[6]) ^ (mix_array[14] * byte_array[7]) );

    new_array[7] = ( (mix_array[3] * byte_array[4]) ^ (mix_array[7] * byte_array[5]) ^ (mix_array[11] * byte_array[6]) ^ (mix_array[15] * byte_array[7]) );


    new_array[8] = ( (mix_array[0] * byte_array[8]) ^ (mix_array[4] * byte_array[9]) ^ (mix_array[8] * byte_array[10]) ^ (mix_array[12] * byte_array[11]) );

    new_array[9] = ( (mix_array[1] * byte_array[8]) ^ (mix_array[5] * byte_array[9]) ^ (mix_array[9] * byte_array[10]) ^ (mix_array[13] * byte_array[11]) );

    new_array[10] = ( (mix_array[2] * byte_array[8]) ^ (mix_array[6] * byte_array[9]) ^ (mix_array[10] * byte_array[10]) ^ (mix_array[14] * byte_array[11]) );

    new_array[11] = ( (mix_array[3] * byte_array[8]) ^ (mix_array[7] * byte_array[9]) ^ (mix_array[11] * byte_array[10]) ^ (mix_array[15] * byte_array[11]) );


    new_array[12] = ( (mix_array[0] * byte_array[12]) ^ (mix_array[4] * byte_array[13]) ^ (mix_array[8] * byte_array[14]) ^ (mix_array[12] * byte_array[15]) );

    new_array[13] = ( (mix_array[1] * byte_array[12]) ^ (mix_array[5] * byte_array[13]) ^ (mix_array[9] * byte_array[14]) ^ (mix_array[13] * byte_array[15]) );

    new_array[14] = ( (mix_array[2] * byte_array[12]) ^ (mix_array[6] * byte_array[13]) ^ (mix_array[10] * byte_array[14]) ^ (mix_array[14] * byte_array[15]) );

    new_array[15] = ( (mix_array[3] * byte_array[12]) ^ (mix_array[7] * byte_array[13]) ^ (mix_array[11] * byte_array[14]) ^ (mix_array[15] * byte_array[15]) );


    for (int i=0; i<16;i++){
        byte_array[i] = new_array[i];
    }
      cout<<"MIX ROWS"<<endl;
         for (size_t i = 0; i < 4; i++) {
        cout << "0x" << hex << byte_array[i] << " " << "0x" << hex << byte_array[i + 4] << " " << "0x" << hex
             << byte_array[i + 8] << " " << "0x" << hex << byte_array[i + 12] << endl;



         }

}

