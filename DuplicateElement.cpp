#include <vector>
#include <iostream>
using namespace std;



int findDuplicate(vector<int> &arr){
        int slow = arr[0];
        int fast = arr[0];
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while(slow != fast);
        
        fast = arr[0];
        
        while(slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
    
vector<int> arr;

int main()
{
	cout << "Enter the size of Array" << endl;
    int n;
    cin>>n;
    cout << "Enter the elements of Array" << endl;
	int inp = 0;

	for (int i = 0; i < n; i++) 
	{
		cin >> inp;
		arr.push_back(inp);
		
	}
    
    cout << "The duplicate element is" << endl;
    cout << findDuplicate(arr);
		return 0;
}