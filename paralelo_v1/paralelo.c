#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "DES.c"
#include "keyManipulation.c"
#include "DES.h"
#include "definitions.h"
#include "keyManipulation.h"
#include <mpi.h>
int main(int argc, char *argv[]) {

	// Start time variables
	struct timeval startTime;
	gettimeofday(&startTime, NULL);

	// Message variable
	const ubyte messagePlain[] = { 0x46, 0x45, 0x52, 0x52, 0x4F, 0x56, 0x49, 0x41 };
	const ubyte messageEncoded[] = { 0xAC, 0xCC, 0xCA, 0xAB, 0x8E, 0x11, 0xF2, 0xB7 };
	// const ubyte messageEncoded[] = { 0xF9, 0x19, 0xBF, 0x01, 0xFD, 0x14, 0xA3, 0xE2 };
	char buffer[128];
	char bufferMessageEncoded[128];
	printBytes(messageEncoded, 8, bufferMessageEncoded);
	int len = sizeof(messagePlain) / sizeof(ubyte);
	int foundAnswer = 0;

	// Key variables
	key_t2 key64Bits = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint64_t validKey;
	uint64_t maxValue;
	int keySize = 32;

	int npes, myrank, i = 0, endAllThreads = 0;

	MPI_Status status;
	MPI_Request request;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Irecv(&endAllThreads, 1, MPI_INT, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &request);
	int end_flag = 0;

	getFirstKey(myrank, keySize, &maxValue, &validKey, key64Bits);

	while (validKey <= maxValue) {

		String encoded = encrypt(key64Bits, messagePlain, len);
		printBytes(encoded.data, 8, buffer);

		if (!strcmp(buffer, bufferMessageEncoded)) {
			for (i = 0; i < npes; i++) if (i != myrank) MPI_Isend(&endAllThreads, 1, MPI_INT, i, 99, MPI_COMM_WORLD, &request);
			end_flag = 1;

			printf("Solution found by node %d\n", myrank);
			foundAnswer = 1;
			MPI_Finalize();
			break;
		}

		generateNextKey(npes, &validKey, key64Bits);

		MPI_Test(&request, &end_flag, &status);
		if (end_flag == 1) {
			MPI_Finalize();
			return 0;
		}
	}
	// End time variable
	struct timeval endTime;
	gettimeofday(&endTime, NULL);

	// Calculate execution time
	long seconds = (endTime.tv_sec - startTime.tv_sec);
	long miliseconds = ((seconds * 1000000) + endTime.tv_usec) - (startTime.tv_usec);

	if (foundAnswer == 0) {
		printf("Node %d did not find the key.\n", myrank);
	}
	else {
		printf("SOLUTION FOUND BY NODE %d\n", myrank);
		printf("Found key of 64 bits: ");
		printKey(key64Bits);
		printf("Valid 56 bit key: %014llx\n", validKey);
		printf("Execution time: %ld.%ld seconds \n \n", seconds, miliseconds);
	}

	return 0;
}
