#include <iostream>
#include <fstream>
//#include "mpi.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char **argv) {
    FILE *fp = popen("mkdir FFFF", "w");
    int i = 0;


    fprintf(fp, "cd FFFF");


    pclose(fp);

    return 0;
}
