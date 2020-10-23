#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <mpi.h>
#include "DES.c"
#include "keyManipulation.c"
#include "DES.h"
#include "definitions.h"
#include "keyManipulation.h"

int main(int argc, char *argv[]) {
	int keySize = 33;

	if (keySize == 16){
		const ubyte messageEncoded[] = { 0xF9, 0x19, 0xBF, 0x01, 0xFD, 0x14, 0xA3, 0xE2 };
	}
	else if (keySize == 32) {
		const ubyte messageEncoded[] = { 0xAC, 0xCC, 0xCA, 0xAB, 0x8E, 0x11, 0xF2, 0xB7 };
	}
	else if (keySize == 33) {
		const ubyte messageEncoded[] = { 0xC4, 0x01, 0x7C, 0x1F, 0x8D, 0x50, 0xF4, 0x41 };
	}
	else if (keySize == 34) {
		const ubyte messageEncoded[] = { 0xA4, 0xB0, 0x62, 0x8F, 0x50, 0x91, 0x9C, 0x0E };
	}
	else if (keySize == 35) {
		const ubyte messageEncoded[] = { 0xB6, 0x69, 0x7D, 0x83, 0x80, 0xCA, 0x5A, 0x4F };
	}
	else if (keySize == 36) {
		const ubyte messageEncoded[] = { 0x74, 0xBE, 0x8A, 0x82, 0x9F, 0x10, 0x66, 0xBC };
	}
	else if (keySize == 37) {
		const ubyte messageEncoded[] = { 0xBD, 0xFF, 0x19, 0xFA, 0x87, 0x93, 0xCF, 0xBD };
	}
	else if (keySize == 38) {
		const ubyte messageEncoded[] = { 0xA4, 0xAF, 0xCF, 0x95, 0xC0, 0x12, 0x4F, 0x9E };
	}
	else if (keySize == 39) {
		const ubyte messageEncoded[] = { 0xA1, 0x6D, 0xE1, 0x8D, 0xEC, 0x3C, 0xA9, 0xD8 };
	}
	else if (keySize == 40) {
		const ubyte messageEncoded[] = { 0xDA, 0x9C, 0x29, 0x53, 0xFD, 0xD0, 0x6E, 0xDF };
	}
	else if (keySize == 41) {
		const ubyte messageEncoded[] = { 0x42, 0xC5, 0x2C, 0x43, 0x1A, 0x66, 0x3E, 0x50 };
	}
	else if (keySize == 42) {
		const ubyte messageEncoded[] = { 0x42, 0x4D, 0x8A, 0xA3, 0x39, 0x8A, 0x9E, 0xEC };
	}
	else if (keySize == 43) {
		const ubyte messageEncoded[] = { 0x67, 0x53, 0xA3, 0x15, 0x67, 0x1E, 0x74, 0x96 };
	}
	else if (keySize == 44) {
		const ubyte messageEncoded[] = { 0xCC, 0x58, 0xB8, 0x9D, 0xA8, 0x9D, 0xCD, 0x9E };
	}
	else if (keySize == 45) {
		const ubyte messageEncoded[] = { 0x0C, 0x25, 0x35, 0x02, 0x16, 0x60, 0x41, 0x20 };
	}
	else if (keySize == 46) {
		const ubyte messageEncoded[] = { 0xBE, 0x38, 0x10, 0x87, 0xED, 0xFD, 0x90, 0x3C };
	}
	else if (keySize == 47) {
		const ubyte messageEncoded[] = { 0x30, 0xB2, 0x47, 0x0A, 0x01, 0xE4, 0xCF, 0x23 };
	}
	else if (keySize == 48) {
		const ubyte messageEncoded[] = { 0xE2, 0x7F, 0x88, 0xF5, 0xAE, 0xEA, 0xF6, 0x96 };
	}
	else if (keySize == 49) {
		const ubyte messageEncoded[] = { 0x8B, 0xD3, 0x8E, 0x39, 0xD3, 0xCE, 0x61, 0x03 };
	}
	else if (keySize == 50) {
		const ubyte messageEncoded[] = { 0xE7, 0x47, 0x05, 0x9B, 0xB6, 0x61, 0x13, 0x72 };
	}
	else if (keySize == 51) {
		const ubyte messageEncoded[] = { 0xB1, 0xD9, 0xC6, 0xBD, 0xF9, 0x51, 0xDD, 0x15 };
	}
	else if (keySize == 52) {
		const ubyte messageEncoded[] = { 0x54, 0xAE, 0x21, 0xEE, 0xB3, 0x2B, 0x46, 0x3F };
	}
	else if (keySize == 53) {
		const ubyte messageEncoded[] = { 0xA9, 0xF8, 0x2B, 0x93, 0x2B, 0x9E, 0x73, 0x17 };
	}
	else if (keySize == 54) {
		const ubyte messageEncoded[] = { 0xCC, 0x7B, 0x53, 0x73, 0x40, 0xC8, 0x75, 0x8C };
	}
	else if (keySize == 55) {
		const ubyte messageEncoded[] = { 0x85, 0xED, 0x8D, 0x30, 0x42, 0x56, 0x20, 0xA2 };
	}
	else if (keySize == 56) {
		const ubyte messageEncoded[] = { 0xA7, 0xAF, 0xD1, 0x7C, 0x3D, 0x6E, 0x6B, 0xC2 };
	}

	// Start time variables
	struct timeval startTime;
	gettimeofday(&startTime, NULL);

	// Message variable
	const ubyte messagePlain[] = { 0x46, 0x45, 0x52, 0x52, 0x4F, 0x56, 0x49, 0x41 };
	// const ubyte messageEncoded[] = { 0xAC, 0xCC, 0xCA, 0xAB, 0x8E, 0x11, 0xF2, 0xB7 };
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
	
	int npes, myrank, i = 0, endAllThreads = 0;

	MPI_Status status;
	MPI_Request request;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &npes);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Irecv(&endAllThreads, 1, MPI_INT, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &request);
	int end_flag = 0;

	getFirstKey(keySize, &maxValue, &validKey, key64Bits);

	for (i = 0; i < myrank; i++) generateNextKey(&validKey, key64Bits);

	while (validKey <= maxValue) {
		for (i = 0; i < npes; i++) generateNextKey(&validKey, key64Bits);

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

		generateNextKey(&validKey, key64Bits);

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
		printf("SOLUTION FOUND BY NODE %d", myrank);
		printf("Found key of 64 bits: ");
		printKey(key64Bits);
		printf("Valid 56 bit key: %014llx\n", validKey);
		printf("Execution time: %ld.%ld seconds \n \n", seconds, miliseconds);
	}

	return 0;
}
