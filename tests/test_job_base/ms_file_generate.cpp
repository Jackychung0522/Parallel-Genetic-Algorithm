#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

double generate(){
    double x = (double) rand() / (RAND_MAX + 1.0);
    return x;
}

unsigned int machineSelection(double ms_gene, unsigned int size_process_time){
    unsigned int count = 0;
    double cal_partition = 0.0;
    double partition = 1.0 / (double)size_process_time;
    if(ms_gene == 0.0)
	    count = 1;
    while(cal_partition < ms_gene){
        cal_partition += partition;
        count++;
    }    
    return count;
}

int main(){
    srand(time(NULL));
    ofstream file;
    file.open("ms_data.txt", ios::out | ios::trunc | ios::binary);
    if (file){
        for(int i = 0; i < 5000; ++i){
            double ms_gene = generate();
            unsigned int size_process_time = rand() % 20 + 1;
            file << ms_gene << " " << size_process_time << " " << machineSelection(ms_gene, size_process_time) << "\n";
        }
    }else {
        cout << "Unable to open file";
    }
    file.close();
    return 0;
}
