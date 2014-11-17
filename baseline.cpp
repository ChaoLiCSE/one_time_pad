#include <iostream>
#include <bitset>
using namespace std;


int main() {
   bitset<16> key(0xDEAD);
   bitset<16> msg(0xBEEF);
   bitset<16> tmp;

   cout << "key: " << key << endl;
   cout << "msg: " << msg << endl;
   
   for(int i = 0; i < 16; i++) {
      tmp[i] = key[i] ^ msg[i];
   }
   cout << "msg -> cip: " << tmp << endl;

   for(int i = 0; i < 16; i++) {
      tmp[i] = key[i] ^ tmp[i];
   }
   cout << "cip -> msg: " << tmp << endl;

   return 0;
}
