# Array


## Multi_dimensional Array

C programming language allows multidimensional arrays. Here is the general form of a multidimensional array declaration −

````
type name[size1][size2]...[sizeN];
````

For example, the following declaration creates a three dimensional integer array −

````
int threedim[5][10][4];
````

### Two-dimensional Arrays
The simplest form of multidimensional array is the two-dimensional array. A two-dimensional array is, in essence, a list of one-dimensional arrays. To declare a two-dimensional integer array of size [x][y], you would write something as follows −

````
type arrayName [ x ][ y ];
````

Where type can be any valid C data type and arrayName will be a valid C identifier. A two-dimensional array can be considered as a table which will have x number of rows and y number of columns. A two-dimensional array a, which contains three rows and four columns can be shown as follows −

![two_dimensional_arrays](https://github.com/Amirsorouri00/Iran-University-ST-OS191/blob/master/00-%20Intro%20to%20C%20Programming/10-%20c_array/two_dimensional_arrays.jpg)


#### Initializing Two-Dimensional Arrays
````
int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};
````

#### Accessing Two-Dimensional Array Elements
````
int val = a[2][3];
````

## Passing Arrays as Function Arguments in C
If you want to pass a single-dimension array as an argument in a function, you would have to declare a formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received. Similarly, you can pass multi-dimensional arrays as formal parameters.

### Way-1
Formal parameters as a pointer −
````
void myFunction(int *param) {
   .
   .
   .
}
````

### Way-2
Formal parameters as a sized array −
````
void myFunction(int param[10]) {
   .
   .
   .
}
````

### Way-3
Formal parameters as an unsized array −

````
void myFunction(int param[]) {
   .
   .
   .
}
````


## Return array from function in C
C programming does not allow to return an entire array as an argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.

If you want to return a single-dimension array from a function, you would have to declare a function returning a pointer as in the following example −
````
int * myFunction() {
   .
   .
   .
}
````

**Second point to remember** is that C does not advocate to return the address of a local variable to outside of the function, so you would have to define the local variable as static variable.


## Pointer to an Array in C

It is most likely that you would not understand this section until you are through with the chapter 'Pointers'.

Assuming you have some understanding of pointers in C, let us start: An array name is a constant pointer to the first element of the array. Therefore, in the declaration −

````
double balance[50];
````

**balance is a pointer to &balance[0]**, which is the address of the first element of the array balance. Thus, the following program fragment assigns p as the address of the first element of balance −

````
double *p;
double balance[10];

p = balance;
````

It is legal to use array names as constant pointers, and vice versa. Therefore, *(balance + 4) is a legitimate way of accessing the data at balance[4].

Once you store the address of the first element in 'p', you can access the array elements using *p, *(p+1), *(p+2) and so on.