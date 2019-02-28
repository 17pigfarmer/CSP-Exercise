#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	 int action = 0;
	 int center_count = 0;
	 int sum = 0;
	 while(cin>>action){
	 	if(action == 0){
	 		cout<<sum<<endl;
	 		break;
	 	}
	 	if(action == 1){
	 		center_count = 0;
	 		sum++;
	 		
	 	}
	 	if(action == 2){
	 		center_count++;
	 		sum += 2*center_count;
			  
	 	}
	 }
	
	
	return 0;
}
