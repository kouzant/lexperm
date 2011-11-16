/*
    Copyright (C) 2011
    Kouzoupis Antonis

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>

void printv(int *, int);
void swap(int *, int, int);
void reverse(int *, int, int);
int perm(int *, int);

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("You should give the order of the permutation or a permutation\n");
        return 1;
    }

    int i;

    if (argc == 2){
        int n = atoi(argv[1]);
        int p[n];
        int complete = 1;

        /*Initialize the vector*/
        for (i = 0; i < n; i++)
            p[i] = i + 1;
        printv(p, n);
    
        do{
            complete = perm(p, n);
        }while(!complete);
    }else{
        /*Build the permutation vector*/
        int p[argc - 1];
        for (i = 0; i < argc - 1; i++)
            p[i] = atoi(argv[i + 1]);
        printv(p, argc - 1);
        /*Compute next permutation*/
        perm(p, argc - 1);
    }

    return 0;
}

/*Print the vector aka permutation*/
void printv(int p[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", p[i]);
    printf("\n");
}

/*Swap two digits of the vector*/
void swap(int *p, int k, int l){
    int tmp = p[l];
    p[l] = p[k];
    p[k] = tmp;
}

/*Reverse the digits from p[k + 1] to p[n]*/
void reverse(int *p, int n, int k){
    int i, j, tmp[n-k-1];
    for (i = n - 1, j = 0 ; i >= k + 1 ; i--, j++ )
        tmp[j] = p[i];
 
   for (i = 0 ; i < n ; i++ )
      p[k + i + 1] = tmp[i];
}

/*Calculate the permutation*/
int perm(int p[], int n){
    int l, k, i, counter = 0, t = n - 2;
    /*Find largest index k such that p[k] < p[k + 1]*/
    for (i = 0; i <= t; i++){
        if (p[i] < p[i + 1])
            k = i;
        else
            counter++;
    }
  
    /*If none index found, there are no more permutations*/ 
    if(counter > n - 2)
        return 1;

    /*Find the largest index l such that p[k] < p[l] and k < l*/
    t = n - 1;
    for (i = k + 1; i < n; i++){
        if (p[k] < p[i])
            l = i;
    }

    /*Swap p[k] with p[l]*/
    swap(p, k, l);
    /*Reverse the digits from p[k + 1] to p[n]*/
    reverse(p, n, k);
    printv(p, n); 

    return 0;
}
