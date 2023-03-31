#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Display the menu
void displayMenu(int & times){
    cout << "================== MENU " << times << " ==================" << endl;
    cout << "1. Output the median" << endl;
    cout << "2. Get the next permutation" << endl;
    cout << "3. Sort in descending order"<< endl;
    cout << "4. Simplify the numbers" << endl;
    cout << "Enter your choice (1 - 4), Q to quit: " << endl;
    
    ++times;
    
}

//Compute the median of three integers
int median(int a, int b, int c){
    int med;
    if((a <= b && b <= c) || (c <= b && b <= a)){
        med = b;
    } else if((b <= a && a <= c) || (c <= a && a <= b)){
        med = a;
    } else {
        med = c;
    }
    
    return med;
}

//Sorts three integers in descending order
void mySort(int& a, int& b, int& c){
    if(a < b){
        if(b < c){
            int temp = a;
            a = c;
            c = temp;
        }
        else if(a < c){
            int temp = a;
            a = b;
            b = c;
            c = temp;
        }
        else{
            int temp = a;
            a = b;
            b = temp;
        }
    }
    else{
        if(a < c){
            int temp = b;
            b = a;
            a = c;
            c = temp;
            
        }
        else if(b < c){
            int temp = b;
            b = c;
            c = temp;
        }
    }
    
    cout << "After sorting: " << a << " " << b << " " << c << endl;
    
}

//Permutate these integers
void myPermutation(int& a, int& b, int& c){
    int temp = c;
    c = b;
    b = a;
    a = temp;
    
    cout << "After one permutation: " << a << " " << b << " " << c << endl;
}

//Simplify three integers by dividing by their greatest common factor
void mySimplify(int& a, int& b, int& c){
    int max;
    int gcd;
    if(a > b && a > c){
        max = a; }
    else if
        (b > a && b > c)
        max = b;
    else
        max = c;
    
    //Compute greatest common factor
    for(int i = 2; i <= max; i++){
        if(a % i == 0 && b % i == 0 && c % i == 0){
            gcd = i;
            break;
        }
        else {
            
            gcd = 1;
            
    }
    }
    
    //Simplify the integers
    a = a / gcd;
    b = b / gcd;
    c = c / gcd;
}

    int main(){
    
    int times = 1;
    char Q;
    int choise, num1, num2, num3;
    cout << "Enter your three positive integers: ";
    cin >> num1 >> num2 >> num3;
    while(Q != 'Q'){
        displayMenu(times);
        cin >> choise;
        if(choise == 1){
            cout << "The median among the three is " << median(num1, num2, num3) << endl;
        }
        else if(choise == 2){
            myPermutation(num1, num2, num3);
            
        }
        else if(choise == 3){
            mySort(num1, num2, num3);
       }
        else if(choise == 4){
            mySimplify(num1, num2, num3);
            cout << "After simplify: " << num1 << ' ' << num2 << ' ' << num3 << endl;
        }
        else{
            Q = 'Q';
        }
      
    }
        
    return 0;
}
