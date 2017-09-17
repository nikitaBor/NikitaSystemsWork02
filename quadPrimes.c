#include <stdio.h>
#include <stdlib.h>

//Nikita Borisov
//Systems with DW
//Work02: Problem 27: Quadratic Primes

//Find a and b such that quadritic n^2+an+b has the longest streak of prime outputs starting with
//n=0.

//plugs numbers into quadrtic for the purpose of this problem
int quadratic(int n, int a, int b){
  return n*n+a*n+b;
}

//returns 1 if number is prime and 0 if number is composite
//negative numbers are considered prime if their postivie counterpart is prime
int prime(int x){
  int i;
  for(i=2; i<=abs(x)/2; i++){
    if((x/i)*i == x){return 0;} 
  }
  return 1;
}

//returns length of streak of primes starting with n=0
int streakLength(int a, int b){
  int n = 0;
  while(prime(quadratic(n,a,b)) == 1){n++;}
  return n;
} 

//returns a*b for longest streak achieved by |a|<1000,|b|<=1000(answer to problem)
//prints a and b(just for fun)
int longestStreak(){
  int a,b;
  int champLen = 0;//champion for longest streak thus far
  int champA,champB;//champion a and b values
  for(a=-999;a<1000;a++){
    for(b=-1000;b<1001;b++){
      if(streakLength(a,b)>champLen){
        printf("champion so far: n^2+(%dn)+(%d) with streak of %d\n",a,b,streakLength(a,b));
        champA = a; champB = b; champLen = streakLength(a,b);
      }//end of if
    }//end of inner for
  }//end of outer for
  return champA*champB;
}

int main(){
  printf("length of n^2+n+41 streak: %d(should be 40)\n", streakLength(1,41));
  printf("length of n^2-79n+1601 streak: %d(should be 80)\n", streakLength(-79,1601));
  printf("longest streak product goes to... %d\n", longestStreak());
  return 0;
}
