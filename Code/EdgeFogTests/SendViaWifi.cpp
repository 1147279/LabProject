#include <iostream>
#include <fstream>
#include <stdio.h>
//#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
#include <unistd.h>


using namespace std;




int main(int argc, char *argv[]){


  system("sudo service ssh start");




  system("./script.sh");



  system("sudo service ssh stop");

  return 0;
}
