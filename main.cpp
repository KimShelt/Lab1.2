#include <stdio.h>
#include <iostream>
#include <cctype>
#include "modBetaCipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int key=3;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring z;
    wstring text;
    unsigned pa;
    wcout<<L"Cipher ready. Input Password: ";
    wcin>>z;
    modBetaCipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>pa;
        if (pa > 2) {
            wcout<<L"Wrong operation\n";
        } else if (pa >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (isValid(text)) {
                if (pa==1) {
                    wcout<<L"Encrypted text: "<<cipher.CoderBetaCipher(cipher, text)<<endl;
                } else {
                    wcout<<L"Decrypted text: "<<cipher.DecoderBetaCipher(cipher, text)<<endl;
                }
            } else {
                wcout<<L"Operation aborted: Invalid text\n";
            }
        }
    } while (pa!=0);
    return 0;
}
