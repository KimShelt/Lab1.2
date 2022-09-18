#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class modBetaCipher
{
private:
    int p;
public:
    modBetaCipher()=delete;
    modBetaCipher(int w);
    wstring CoderBetaCipher(modBetaCipher w, wstring& s);
    wstring DecoderBetaCipher(modBetaCipher w, wstring& s);
};
