#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
    std::clock_t start;
    double duration;

    start = std::clock();
    cout<<"Start";
    cout<<start;
    sleep(4);

    /* Your algorithm here */
    for(long i=0;i<1000000;i++);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';
    cout<<"Clock now"<<clock();
}
