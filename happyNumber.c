#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int squaresumdigits (int number)
{
  int sum = 0;
  int input = number;



  while (input)
    {

      int digit = input % 10;

      sum += digit * digit;

      input /= 10;

    }
  //printf("%d\n",sum);

  return sum;

}



bool isHappy (int n)
{

  int fast = n;
  int slow = n;


  do
    {

      fast = squaresumdigits (squaresumdigits (fast));

      slow = squaresumdigits (slow);

      if (slow == 1 || fast == 1)
	return true;

    }while(fast != slow); 

  return false;

}

int main() 
{
	int i = 0;
	
	printf("The number 19 is a happy number, %d\n", isHappy(19));
	
	
	for(i; i < 10; i++)
	{
		int n = rand() % 10000;
	        printf("The number %d is a happy number, %d\n", n, isHappy(n));	
	}
	

}
