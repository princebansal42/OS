#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout << "Thread ID, " << tid <<" says Hello to the World"<< endl;
   pthread_exit(NULL);
}

int main () {
	int n;
	cout<<"Enter the total number of threads to be created: ";
	cin>>n;
   	pthread_t threads[n];
   	int rc;
   	int i;
    for( i = 0; i < n; i++ ) {
      cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
      
      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
