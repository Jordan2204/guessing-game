// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <openenclave/host.h>
#include <stdio.h>
#include <stdlib.h>


// Include the untrusted guessing header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the guessing.edl file.
#include "guessing_u.h"

bool check_simulate_opt(int* argc, const char* argv[])
{
    for (int i = 0; i < *argc; i++)
    {
        if (strcmp(argv[i], "--simulate") == 0)
        {
            fprintf(stdout, "Running in simulation mode\n");
            memmove(&argv[i], &argv[i + 1], (*argc - i) * sizeof(char*));
            (*argc)--;
            return true;
        }
    }
    return false;
}

// This is the function that the enclave will call back into to
// print a message.


int host_guessing_init(int max) {
   
    fprintf(stdout, "Max value : %d \n", max);

}

int main(int argc, const char* argv[])
{
    oe_result_t result;
    int ret = 1;
    oe_enclave_t* enclave = NULL;

    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;
    if (check_simulate_opt(&argc, argv))
    {
        flags |= OE_ENCLAVE_FLAG_SIMULATE;
    }

    if (argc != 2)
    {
        fprintf(
            stderr, "Usage: %s enclave_image_path [ --simulate  ]\n", argv[0]);
        goto exit;
    }

    // Create helloworld the enclave
    result = oe_create_helloworld_enclave(
        argv[1], OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "oe_create_helloworld_enclave(): result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

     // Create the guessing_init  enclave
    result = oe_create_guessing_init_enclave(
        argv[1], OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "oe_create_guessing_init_enclave(): result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

    result = enclave_guessing_init_t(enclave, scanf("%d"););
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "calling into enclave_guessing failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }


    //Loop
     do{

        printf("\nEnter a guess value :  ");
        scanf("%d",&n);


        if(n < nbreAd){
            printf("%d est inferieur",n);
        }else if(n> nbreAd){
            printf("%d est superieur",n);
        }else{
        printf("\nBravo vous avez trouver le nombre mystere en %d coup",compteur);
        }

        compteur++;
        }while(n != nbreAd);




    ret = 0;
    exit:
    // Clean up the enclave if we created one
    if (enclave)
        oe_terminate_enclave(enclave);

    return ret;
}
