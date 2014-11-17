#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {

   ifstream file_i;
   ofstream file_o;

   char key[256], msg[256], ct[256];
   int  len = 0;

   if(argc < 3){
      cout << "program <input file> <output file>" << endl;
      return -1;
   }

   file_i.open(argv[1]);
   file_o.open(argv[2]);

   file_i.getline(key, 256);
   for(char *p = key; *p != '\0'; p++) {
      len++;
   }

   cout << "Start encryption..." << endl;
	file_o << key << endl;

	file_i.getline(msg, 256);
   for(int i = 0; i < len; i++) {
      cout << key[i] << ' ' << msg[i] << ' ' << (key[i] ^ msg[i]) << endl;
      ct[i] = key[i] ^ msg[i];
   }
   file_o << ct;
   cout << "Done..." << endl;

   file_i.close();
   file_o.close();
   return 0;
}

