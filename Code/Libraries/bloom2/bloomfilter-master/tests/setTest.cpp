#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include "OrdinaryBloomFilter.hpp"
#include "FnvHash.hpp"

namespace std {
    template<> struct hash<bloom::HashParams<std::string>> {
        size_t operator()(bloom::HashParams<std::string> const& s) const {
            bloom::FnvHash32 h;
            h.Update(&s.b, sizeof(uint8_t));
            h.Update((const uint8_t *) s.a.data(), s.a.length());
            return h.Digest();
        }
    };
}


using namespace std;



int main(int argc, char** argv) {



  bloom::OrdinaryBloomFilter<std::string> bf(4, 900000);

  bf.setFilter();

  string Query = "FakePlace2018815102646";

  if (bf.Query(Query))
  {
    cout << "yassss" << endl;
  }



return 0;
}
