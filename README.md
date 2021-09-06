# The Guessing Game 

- Written in C (the c++ version is in progress)
- Minimum code needed for an Open Enclave app
- Also runs in OE simulation mode

## Prerequisites

- Use an OE SDK-supported machine or development environment (like Intel SGX).
- Install the OE SDK package and dependencies for your environment. The documentation for necessary prerequisites is provided in the [getting started page of the Open Enclave SDK](https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/README.md).
- Read the common [sample information page](../README.md#building-the-samples) to learn how to prepare the sample.

## About the Guessi Game 

This is a game where the user must try to guess a number generated by the program. 
The particularity of this game is the use of a secured environment for the generation of the number to guess.

This sample uses the Open Enclave SDK `oeedger8r` tool to generate marshaling code necessary to call functions between the enclave
and the host. For more information on using the Open Enclave oeedger8r tool refer to
[Getting started with the Open Enclave edger8r](https://github.com/openenclave/openenclave/tree/master/docs/GettingStartedDocs/Edger8rGettingStarted.md).

## How To Run (we assume that you are in the guessing-game folder)

### 1- Using make

Execute the following commands in " "

- Add ". /opt/openenclave/share/openenclave/openenclaverc" to your .bashrc file before compiling.
- "make build"
- "make simulate"

### 1- Using cmake

- Add ". /opt/openenclave/share/openenclave/openenclaverc" to your .bashrc file before compiling.

Execute the following commands
- "mkdir build" & "cd build"
- "make"
- "make simulate"