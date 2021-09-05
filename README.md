# The Guessi Game 

- Written in C
- Minimum code needed for an Open Enclave app
- Help understand the basic components an OE(Open Enclave) application
- Demonstrate how to build, sign, and run an OE image
- Demonstrate how to optionally apply LVI mitigation to enclave code
- Also runs in OE simulation mode

## Prerequisites

- Use an OE SDK-supported machine or development environment (like Intel SGX).
- Install the OE SDK package and dependencies for your environment. The documentation for necessary prerequisites is provided in the [getting started page of the Open Enclave SDK](https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/README.md).
- Read the common [sample information page](../README.md#building-the-samples) to learn how to prepare the sample.

## About the Guessi Game 

This sample is about as simple as you can get regarding creating and calling into an enclave. In this sample you will see:

- The host creates an enclave
- The host calls a simple function in the enclave
- The enclave function prints a message and then calls a simple function back in the host
- The host function prints a message before returning to the enclave
- The enclave function returns back to the host
- The enclave is terminated

This sample uses the Open Enclave SDK `oeedger8r` tool to generate marshaling code necessary to call functions between the enclave
and the host. For more information on using the Open Enclave oeedger8r tool refer to
[Getting started with the Open Enclave edger8r](https://github.com/openenclave/openenclave/tree/master/docs/GettingStartedDocs/Edger8rGettingStarted.md).

First we need to define the functions we want to call between the enclave and host. To do this we create a `helloworld.edl` file:

```edl
enclave {
    trusted {
        public void enclave_helloworld();

    };

    untrusted {
        void host_helloworld();
    };
};
```
