#include <iostream>
#include "include/md5wrapper.h"
#include <stdlib.h>  
#include <ctime>
using namespace std;



string maHoaMD5(string password){
	md5wrapper md5;
	string paswwordmd5= md5.getHashFromString(password);
	return paswwordmd5;
}

string randomID(int length){
	char a[]="123456789QAZXSWEDCVFRTGBNHYUJMKILOP";
	string result;
	srand (time (NULL)); 
	for(int i=0; i<length; i++){	
		int x= rand() % (sizeof(a)-1); 
		result+=a[x];
	}	
	return result;
}







int main(int argc, char** argv) {

	return 0;
}
