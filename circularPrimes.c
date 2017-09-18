#include <stdio.h>

//Nikita Borisov(with help from Tiffany Chen)
//Systems with DW
//Work02: Problem 35: Circular Primes

//Find how many circular primes there are less than a million(197 is circular prime because 197,971,719 are all prime)

//returns how many digits a number has base 10(digits(0) will return 0 though)
int digits(int x){
	int i = 0;
	while(x!=0){x=x/10; i++;}
	return i;
}
//returns a raised to b power
int ipow(int a,int b){
	int retVal = 1;
	int i;
	for(i=0;i<b;i++){retVal=retVal*a;}
	return retVal;
}

//returns 1 if number is prime and 0 if number is composite
int prime(int x){
    int i;
    for(i=2; i<=x/2; i++){
      if((x/i)*i == x){return 0;} 
    }
    return 1;
}

//returns 1 if number is circular prime and 0 otherwise
int circularPrime(int x){
	int i;
	int d = digits(x);
	for(i=0;i<d;i++){
		if(!prime(x)){return 0;}
		//rotate last digit to first place
		x = (x%10)*ipow(10,d-1) + x/10;
	}
	return 1;
}

//returns how many circular primes are less than a millio(answer to problem)
//prints as it moves along
int countCirPrimes(){
	int i;
	int retVal;
	for(i=2;i<1000000;i++){
		if(circularPrime(i)){retVal+=1; printf("%d\n",i);}
	}
	return retVal;
}
int main(){
	printf("1634 has %d digits\n",digits(1634));
	printf("197 once rotated is %d\n",(197%10)*ipow(10,2) + 197/10);
	printf("circular primes test=>197:%d/41:%d\n",circularPrime(197),circularPrime(41));
	printf("there are %d circular primes<1000000\n",countCirPrimes());
	return 0;
}
