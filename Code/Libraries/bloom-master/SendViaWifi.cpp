#include <iostream>
#include <fstream>
#include <stdio.h>
//#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>


using namespace std;




int main(int argc, char *argv[]){

  unsigned int microseconds;
  microseconds = 3000000;




  system("sudo service ssh start");




  FILE *stream;
   char command[ 256 ] = { 0 };
   int term_status;



   // be sure to include the full path in your command
   // here the pipe will be opened for reading and stream will be read-only
   stream = popen( "scp /home/darren/Desktop/Proooooj/LabProject/Code/Libraries/bloom-master/Table1.txt  darrenblanckensee@10.0.0.110:/Users/darrenblanckensee/Desktop", "w" );

   usleep(microseconds);

   //cout << "0116166224\n";
   //cout << "\n";
   fprintf(stdout, "0116166224\n" );

   usleep(microseconds);

   fprintf(stdout, "0116166224\n" );

   usleep(microseconds);

   fprintf(stdout, "0116166224\n" );

   usleep(microseconds);





   pclose( stream );




  system("sudo service ssh stop");

  return 0;
}
