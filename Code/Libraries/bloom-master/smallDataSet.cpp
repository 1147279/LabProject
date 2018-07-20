
#include <iostream>
#include <string>

#include "bloom_filter.hpp"

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

  int elementCount = 0;
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
    for (int i = -1; i > -100; --i)
    {
       if (filter.contains(i))
       {
          cout << "BF falsely contains: " << i << endl;
       }
    }
  }

  return 0;
}
