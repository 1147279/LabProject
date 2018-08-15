#include <string>
#include <iostream>
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

int main(int argc, char *argv[]){

    std::string t1 = "Hello world!";
    std::string t2 = "foo bar baz";

    bloom::OrdinaryBloomFilter<std::string> bf(4, 900000);


    bf.setFilter();

    bf.printFilter();


    return 0;
}
