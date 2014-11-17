#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {

   ifstream file_i;
   ofstream file_o;

   char key[256], msg[256], ct[256];
   int  len;

   if(argc < 3){
      cout << "program <cipher text> <msg text>" << endl;
      return -1;
   }

   file_i.open(argv[1]);
   file_o.open(argv[2]);

   file_i.getline(key, 256);
	for(char *p = key; *p != '\0'; p++) {
      len++;
   }
   cout << "Start decryption..." << endl;
   cout << key;
	
	file_i.getline(ct, 256);
   cout << ct << endl;
   for(int i = 0; i < len - 1; i++) {
		cout << key[i] << ' ' << ct[i] << ' ' << (key[i] ^ ct[i]) << endl;
      msg[i] = key[i] ^ ct[i];
   }
   file_o << ct << endl;
   cout << "Done..." << endl;

   file_i.close();
   file_o.close();
   return 0;
}

