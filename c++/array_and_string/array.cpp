#include <iostream>

using namespace std;

int main(){
    // static array
    int arr[15];
    int n = 0;
    int value = 0;
    cout << "Enter values. Type \"-1\" to stop: " << endl;
    while (n < 15 && value != -1){
		cout << "Please enter the value of arr[" << n <<"]:";
        cin >> value;
        if (value != -1){
            arr[n] = value;
            n++;
        }
    }
    if (n == 0){
        cout << "You have entered no value,bye!";
    }else{
        int min = arr[0];
        for (int i=1; i<n; i++){
            if (arr[i] < min){
                min = arr[i];
            }
        }
        cout << "The minimal value of the array is " << min << endl;
}
    return 0;
}

