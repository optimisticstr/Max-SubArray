#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
using namespace std;

// ProtoTypes
void find_maximum_subarray_brute(int array[], int low,int high, int total, int size);
void RandomArray(int array[], int size);

int main(){
	int size = 30000;
	
	clock_t start, end;
    double cpu_time_used;

	int low = 0, high = 0;
	int sum = INT_MIN;
	int * array = new int [size];
	
	RandomArray(array, size); // creating array of random numbers
	
	start = clock();
	find_maximum_subarray_brute(array, low, high, sum, size);
	end = clock();
	
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Time taken is: " << cpu_time_used << " s"<< endl;
	
	// stroing data of array in a csv file
	ofstream myfile;
 	myfile.open("dataBrute.csv", ios :: app);
  	if (myfile.is_open()){
  		for(int count = 0; count < size; count ++){
	        myfile << array[count] << " " << endl ;
	    }
    myfile.close();
    }
    else cout << "Unable to open file"; 
	
	return 0;
}
void find_maximum_subarray_brute(int array[], int low,int high, int total, int size) {


   double sum= 0;
    for (int i = 0; i < size; i++) {

        sum = array[i];
        if(total < sum)
        {
        	total = sum;
        	low = i;
        	high = i;
        }
        for (int j = i+1 ; j < size; j++) {
            sum  = sum + array[j];
            if (sum < total) {
                low = i;
                high = j;


            }
        }
    }
}

void RandomArray(int array[], int size){
	srand((unsigned)time(0));      //should give different values after every execution
     
    for(int i=0; i<size; i++){ 
        array[i] = (rand() % size) - (size / 3); 
    }  
}     
 
