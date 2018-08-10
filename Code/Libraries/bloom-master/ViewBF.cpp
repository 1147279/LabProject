
#include <iostream>
#include <string>
#include <fstream>
#include "bloom_filter.hpp"
#include <ctime>


using namespace std;

void createParameters(bloom_parameters &parameters, int elementCount, double falsePositiveProbability, int randSeed)
{


  // Expected Number of Entries
  parameters.projected_element_count = elementCount;

  // Max false positive probability allowed
  parameters.false_positive_probability = falsePositiveProbability; // 1 in 10

  // seed
  parameters.random_seed = randSeed;


  if (!parameters)
  {
    cout << "Error - Invalid parameters!" << endl;
    return;
  }


  parameters.compute_optimal_parameters();
  return;


}



int main()
{

  int elementCount = 0 ;
  double falsePositiveProbability = 0;
  int randSeed = 0xA5A5A5A5;


  // Get info From User

  cout << "Enter Number Of Elements" << endl;
  cin >> elementCount;

  cout << "Enter Alloweable Probability of False Positive" << endl;
  cin >> falsePositiveProbability;


  // ----------------------------------------------------------------------------------------------------------



  // Create Filter


  bloom_parameters parameters;

  createParameters(parameters, elementCount,falsePositiveProbability, randSeed);


  bloom_filter filter(parameters);










  // ----------------------------------------------------------------------------------------------------------



  // READ FROM Filter

  ifstream inputFile;
  ofstream outputFile;

  inputFile.open("small.txt", ifstream::in);
  outputFile.open("rez.txt",ofstream::out);



  string tempElement;
  int count = 0;

  while (inputFile >> tempElement)
  {
    filter.insert(tempElement);
    //cout << "read in " << '(' << tempElement << ')' << endl;
    count++;
  }

  if (filter.containsbitstring("a"))
  {
    cout << "filter contains: " << "A" << endl;
  }

  if (filter.containsbitstring("b"))
  {
    cout << "filter contains: " << "B" << endl;
  }

  if (filter.containsbitstring("c"))
  {
    cout << "filter contains: " << "C" << endl;
  }

  if (filter.containsbitstring("d"))
  {
    cout << "filter contains: " << "D" << endl;
  }

  if (filter.containsbitstring("e"))
  {
    cout << "filter contains: " << "E" << endl;
  }

  if (filter.containsbitstring("f"))
  {
    cout << "filter contains: " << "F" << endl;
  }

  if (filter.containsbitstring("k"))
  {
    cout << "filter contains: " << "K" << endl;
  }

  if (filter.containsbitstring("l"))
  {
    cout << "filter contains: " << "L" << endl;
  }

  if (filter.containsbitstring("n"))
  {
    cout << "filter contains: " << "N" << endl;
  }

  if (filter.containsbitstring("o"))
  {
    cout << "filter contains: " << "O" << endl;
  }

  if (filter.containsbitstring("q"))
  {
    cout << "filter contains: " << "Q" << endl;
  }

  if (filter.containsbitstring("r"))
  {
    cout << "filter contains: " << "R" << endl;
  }

  if (filter.containsbitstring("s"))
  {
    cout << "filter contains: " << "S" << endl;
  }

  if (filter.containsbitstring("t"))
  {
    cout << "filter contains: " << "T" << endl;
  }

  if (filter.containsbitstring("x"))
  {
    cout << "filter contains: " << "X" << endl;
  }

  if (filter.containsbitstring("z"))
  {
    cout << "filter contains: " << "Z" << endl;
  }




  if (filter.containsbitstring("g"))
  {
    cout << "filter falsely contains: " << "G" << endl;
  }

  if (filter.containsbitstring("h"))
  {
    cout << "filter falsely contains: " << "H" << endl;
  }

  if (filter.containsbitstring("i"))
  {
    cout << "filter falsely contains: " << "I" << endl;
  }

  if (filter.containsbitstring("j"))
  {
    cout << "filter falsely contains: " << "J" << endl;
  }

  if (filter.containsbitstring("m"))
  {
    cout << "filter falsely contains: " << "M" << endl;
  }

  if (filter.containsbitstring("p"))
  {
    cout << "filter falsely contains: " << "P" << endl;
  }

  if (filter.containsbitstring("u"))
  {
    cout << "filter falsely contains: " << "U" << endl;
  }

  if (filter.containsbitstring("v"))
  {
    cout << "filter falsely contains: " << "V" << endl;
  }

  if (filter.containsbitstring("w"))
  {
    cout << "filter falsely contains: " << "W" << endl;
  }

  if (filter.containsbitstring("y"))
  {
    cout << "filter falsely contains: " << "Y" << endl;
  }

  inputFile.close();






  outputFile.close();

  filter.displayFilter();




/*
  // Put Stuff In Filter


  string str_list[] = { "AbC", "iJk", "XYZ" };


  {
    // STRINGS
    for (int i = 0; i < (int)((sizeof(str_list) / sizeof(string))); ++i)
    {
       filter.insert(str_list[i]);
    }

    // NUMBERS
    for (int i = 0; i < elementCount; ++i)
    {
      if (i%2 != 0)
      {
        filter.insert(i);
      }
    }
  }




  // ----------------------------------------------------------------------------------------------------------



  // Genuine Queries


  {
    // STRINGS
    for (int i = 0; i < (int)((sizeof(str_list) / sizeof(string))); ++i)
    {
       if (filter.contains(str_list[i]))
       {
          cout << "BF contains: " << str_list[i] << endl;
       }
    }

    // NUMBERS
    for (int i = 0; i < elementCount; ++i)
    {
       if (filter.contains(i))
       {
          cout << "BF contains: " << i << endl;
       }
    }




    // ----------------------------------------------------------------------------------------------------------



    // Not Genuine Queries


    string invalid_str_list[] = { "AbCX", "iJkX", "XYZX" };

    // invalid strings
    for (int i = 0; i < (int)((sizeof(invalid_str_list) / sizeof(string))); ++i)
    {
       if (filter.contains(invalid_str_list[i]))
       {
          cout << "BF falsely contains: " << invalid_str_list[i] << endl;
       }
    }

    // invalid numbers
    for (int i = -1; i > -elementCount; --i)
    {
       if (filter.contains(i))
       {
          cout << "BF falsely contains: " << i << endl;
       }
    }
  }

  */

  return 0;
}
