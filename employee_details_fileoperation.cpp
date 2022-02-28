#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

struct TIME
{
  int seconds;
  int minutes;
  int hours;
};

struct Employee{
    float leave_balance;
} e[10];


void display_duration(struct TIME, struct TIME, struct TIME *);

void display_duration(struct TIME t1, struct TIME t2, struct TIME *difference){
    
    if(t2.seconds > t1.seconds) {
        difference->seconds = t2.seconds - t1.seconds;
    }
    else {
        difference->seconds = t1.seconds - t2.seconds;
    }
    
    
    if(t2.minutes > t1.minutes) {
        difference->minutes = t2.minutes - t1.minutes;
    }
    else {
        difference->minutes = t1.minutes - t2.minutes;
    }
    
    
    if(t2.hours > t1.hours) {
        difference->hours = t2.hours-t1.hours;
    }
    else{
        difference->hours = t1.hours-t2.hours;
    }
    
}

int main() {
    int option;
    struct TIME t1, t2, difference;
    fstream file;
    file.open("employee_file.txt", ios:: out);
    	
	for(int i=0;i<10;i++){
    	file << 15 << " ";
	}

   file.close();
   
   file.open("employee_file.txt", ios:: in);
  	for(int j=0;j<10;j++){
  		file >> e[j].leave_balance;
	  }
	
	file.close();

    while (1) {
    
    int employee_id;
    cout<<"Enter the option: ";
    cin>> option;
    
    cout<<"Enter Employee id: ";
    cin>> employee_id;
    
    
    if(option == 1){
        cout << "Available Leave Balance: " << e[employee_id-1].leave_balance << endl;
    }
    
    else if(option == 2){
        
        cout << "Enter entry time" << endl;
        cin >> t1.hours >> t1.minutes >> t1.seconds;

        cout << "Enter exit time" << endl;
        cin >> t2.hours >> t2.minutes >> t2.seconds;
        
        display_duration(t1,t2,&difference);
    
        cout << "Time duration: " << difference.hours << ":" << difference.minutes << ":" << difference.seconds << endl;
        
        if(difference.hours>=8 && difference.minutes>=0 && difference.seconds>=0 ){
            cout << "Employee is present" << endl;
        }
        
        else if((difference.hours>6) && (difference.hours<8)){
            cout << "Employee is present" << endl;
        }
        
        else if(difference.hours==6 && difference.minutes==0 && difference.seconds==0){
            cout << "Employee has taken a half day leave" << endl;
            e[employee_id-1].leave_balance = e[employee_id-1].leave_balance - 0.50;
        }
        
        else if(difference.hours<6){
            cout << "Employee has taken a full day leave" << endl;
            e[employee_id-1].leave_balance = e[employee_id-1].leave_balance - 1.00;
        }
        
    	file.open("employee_file.txt", ios:: out);
    	
		for(int i=0;i<10;i++){
    	file << e[i].leave_balance << " ";
		}
		file.close();
		
    }
      
    cout << endl;
    
}

}
