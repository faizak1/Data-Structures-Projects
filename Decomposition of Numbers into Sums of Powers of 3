//Displaying numbers between -121 and 121 (including) in terms of the sum of powers of 3
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<cstdlib>
using namespace std;
  
int get_third_power(int num); //function which returns the third power based on the interval to powers_three 
void powers_three(int num); //function which utilizes variables remaining, sum, and num to evaluate and output
                          // the correct signs (+ or -) and continue the loop until the sum of the powers of 3 (thirdpower) 
                          //is equal to num (user input)
  
int main()
{                
          if (system("CLS")) system("clear");
          int num;
          char rerun = 'Y';
          do
          {       
                  if (system("CLS")) system("clear");
                  cout << "Welcome to Faiza's program of decomposition of powers!" << endl; 
                  cout << "This program outputs any integer between -121 and 121 in terms of sums of powers of 3." << endl;
                  cout << "For example, you can enter 39 and the output will be 39 = 27 + 9 + 3." << endl;
                  cout << "You can also enter a negative number, such as -14, and the output will be -14 = -27 + 9 + 3 + 1." <    < endl;         
                  cout << "Enter a number : "; //asks for user input
                  cin >> num;  //stores input into variable called num
                  cout << num << " = "; 
                  powers_three(num); //calls function to output what num is equal to in terms of powers of 3
                  cout << "Would you like to run this program again? (Y or N) : ";
                  cin >> rerun;
                  rerun = toupper(rerun);
          
          } while (rerun == 'Y');
}
  
void powers_three(int num)
{       
          int remaining = num; //remaining is the difference, so it is initialized to user input 
          int thirdpower=get_third_power(num); //declare and initialize thirdpower to the power that is returned from get_third_power 
          int sum = thirdpower; //value of thirdpower is copied over in sum with the assignment statement
                          //sum increases or decreases as needed until it reaches num 
          cout << thirdpower; //the first third power that is returned from get_third_power is shown 
          while (sum != num) //loop that executes while the sum of the third powers is not equal to num
          {       
                  remaining=abs(thirdpower-remaining); //remaining is the absolute value of the difference between third power and remaining
                                            //For instance, for the number 40, the abs. diff. between 27 and 40   is 13
                                              //so 13 becomes the new remaining in that particular case. This also works for any number
                  thirdpower=get_third_power(remaining); //the next third power displayed is equal to what get_third_power returns for the remaining value
                                                  //if we stick to the example for 40, 13 is the remaining so get_third_power would get 
                                                  //the next third power based on 13 (so the next third power would be 9)             
  
                  if(sum<num) //if the sum of the powers of 3 is less than num, we need to add because num is higher
                  {
                          cout << " + ";
                          sum = sum + thirdpower; //sum is equal to the previous sum combined with the next third power
                  }
  
                  else //in any other case, sum is greater than num so we need to subtract since num is lower than what sum currently is
                  {
                          cout << " - ";
                          sum = sum - thirdpower; //sum is equal to the new third power subtracted from the previous sum 
                  }
  
                  cout << thirdpower;
          }
          cout << endl;
}
  
int get_third_power(int num)
{
          const int size = 10; //size of both arrays are a constant size of 10 since there were 10 intervals for this project
          int power = 0; //power is declared as an integer variable and is initialized to 0
          //I declared and initialized two arrays below, accounting for the largest and smallest values in each other intervals
          //Essentially I paired them off (first large value and first small value is one interval, etc.)
          int large_values_array[size] = {-41,-14, -5 , -2, -1, 1, 4, 13, 40, 121}; //larger values of each interval
          int small_values_array[size] = {-121, -40, -13, -4, -1, 1 , 2, 5, 14, 41}; //smaller values of each interval
  
          for (int i=0; i<size; i++)
            {
                if (num <= large_values_array[i] && num >= small_values_array[i])
                  //checks to see if the num is larger than a certain value or smaller than a certain value
                  //to find which interval it is in
                 {
                          power = ((large_values_array[i] + small_values_array[i]) / 2); //the number in between the two numbe    rs in the interval
                                                                                  //is the power of 3 
                          break; //exits out of the loop 
                  }
          }
          return power; //power is returned to powers_three
}
