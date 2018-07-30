#include <iostream>
#include <fstream>
#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include "bloom_filter.hpp"
#include <ctime>
using namespace std;

const char delimiter = '|';																					//Can be changed dependent on style of delimiter in database





int main(int argc, char *argv[]){

  //------------------------ MPI Variable Declaration ------------------------//
  int Npes, myrank, source, dest;
  int tag=0;
	int count = 0;
	double sum = 0;
  int bufferSize=100;
  char sentMsg [100];
  char recvMsg [100];
  MPI_Status status;

	clock_t start;

  start = clock();


  MPI_Init (&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &Npes);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	string tmp;
	vector<string> hashTable_A;
//____________________________________________________________________________//

//---------------------- Transfer Table A amongst Nodes ----------------------//

// Timing
	double startTime = MPI_Wtime();
	double stopTime ;
	double diffTime;


  if (myrank == 1)
	{                                          //Master process, reading in data from Table A and distributing to processes according to hash.
    ifstream areaA;
    areaA.open("Table1.txt", ifstream::in);

    double countA = 0 ;
    string tempA;
    double sumA = 0;

    while (areaA >> tempA)
		{

      sumA += stoi(tempA);
      countA = countA+1;
			//cout << myrank << " sent " << sentMsg << " to " << dest <<  endl;
    }

    dest = 0;
    double avgA = sumA/countA;
    tempA = to_string(avgA);
    strcpy(sentMsg, tempA.c_str());

		MPI_Send(sentMsg, bufferSize, MPI_CHAR, dest, tag, MPI_COMM_WORLD );

		areaA.close();

  } else if (myrank == 2)
	{                                          //Master process, reading in data from Table A and distributing to processes according to hash.
    ifstream areaB;
    areaB.open("Table2.txt", ifstream::in);


    double countB = 0 ;
    string tempB;
    double sumB = 0;

    while (areaB >> tempB)
		{

      sumB += stoi(tempB);
      countB = countB + 1;
			//cout << myrank << " sent " << sentMsg << " to " << dest <<  endl;
    }

    dest = 0;
    double avgB = sumB/countB;
    tempB = to_string(avgB);
    strcpy(sentMsg, tempB.c_str());

		MPI_Send(sentMsg, bufferSize, MPI_CHAR, dest, tag, MPI_COMM_WORLD );

		areaB.close();

  } else if (myrank == 3)
	{                                          //Master process, reading in data from Table A and distributing to processes according to hash.
    ifstream areaC;
    areaC.open("Table3.txt", ifstream::in);


    double countC = 0 ;
    string tempC;
    double sumC = 0;

    while (areaC >> tempC)
		{

      sumC += stoi(tempC);
      countC = countC +1;
			//cout << myrank << " sent " << sentMsg << " to " << dest <<  endl;
    }

    dest = 0;
    double avgC = sumC/countC;
    tempC = to_string(avgC);
    strcpy(sentMsg, tempC.c_str());

		MPI_Send(sentMsg, bufferSize, MPI_CHAR, dest, tag, MPI_COMM_WORLD );

		areaC.close();

  }

	if (myrank == 0)
	{                                          //Master process, reading in data from Table A and distributing to processes according to hash.
																									//Slave process, receiving process.
		for (int i = 1 ; i < Npes ; i ++)
		{
			MPI_Recv(recvMsg, bufferSize, MPI_CHAR, i, tag, MPI_COMM_WORLD,&status);


			tmp =  string(recvMsg);
			//cout << myrank << " received " << recvMsg << " from " << i <<  endl;

			sum += stoi(tmp);



		}


		double avg = sum/((double)(Npes-1));
		cout << avg << endl;
		cout << "Time with no filter: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	}

//____________________________________________________________________________//


	stopTime = MPI_Wtime();
	diffTime = stopTime - startTime;

	MPI_Finalize();


  return 0;
}
