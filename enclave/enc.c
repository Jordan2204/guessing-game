// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// Include the trusted guessing header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the guessing.edl file.
#include "guessing_t.h"

// This is the function that the host calls. It prints
// a message in the enclave before calling back out to
int number_to_guess;
int max_number;
int min_number = 0;

void enclave_helloworld()
{
    // Print a message from the enclave. Note that this
    // does not directly call fprintf, but calls into the
    // host and calls fprintf from there. This is because
    // the fprintf function is not part of the enclave
    // as it requires support from the kernel.
    fprintf(stdout, "Hello world my dear,\n Enter The max value for the Guessing Game (must be inferior to 500)\n");
}

void enclave_guessing_init(oe_enclave_t* enclave, int max){
    //Max number
    max_number =  max;

    //Guessing number generation
    srand(time(NULL));
    number_to_guess = 0+(rand()%(max_number-min_number + 1));

    // Call back into the host
    oe_result_t result = host_guessing_init(max);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "Call to host_guessing_init failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
    }

}

void enclave_guessing_send(oe_enclave_t* enclave, int value){
    int res;
    if(value != number_to_guess){
        res = 0;
    }else if(value == number_to_guess){
        res = 1;
    }

    // Call back into the host
    oe_result_t result = host_guessing_result(res);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "Call to host_guessing_result failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
    }

}