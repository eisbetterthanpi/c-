#include <iostream>
// #include 'filename'
#include <cmath>
using namespace std;

/*
g++ -o F:\c++\same "F:\c++\cpptut.cpp"
F:\c++\same.exe
*/

// int main(){
//   cout << pow(2, 10) << endl;
//   cout << float(6)/3 << endl;
//
//   return 0;
// }



// int main() {
//   int num;
//   cout << "How many students do you have?" << endl;
//   cin >> num;
//   double *student_mark; //array will store memory adress
//   student_mark = new double [num]; //creating an array of doubles
//   for (int i = 0; i< num; i++){
//   cout << "Enter the mark of Student " << i + 1 <<": ";
//   cin >> student_mark [i];
//   }
//   cout << *student_mark << endl;
//   cout << student_mark << endl;
//   // do something about the mark
//   delete [] student_mark; //delete memory
//   return 0;
// }


// class BankAcct{
//   private:
//     int _acc_num;
//     double _balance;
//   public:
//     BankAcct(int acc = 1.0, double bal = 0.0){
//       _acc_num = acc;
//       _balance = bal;
//     }
//     int withdraw(double amt){
//       if (_balance < amt) return 0;
//       _balance -= amt;
//       return 1;}
//     int deposit(double amt){
//       _balance += amt;
//       return 1;}
//     int check(){
//       return _balance;}
// };
// int main(){
//   BankAcct billy(42,123.0);
//   cout << billy.check()<<endl;
//   billy.withdraw(35);
//   cout << billy.check()<<endl;
//   billy.deposit(28);
//   cout << billy.check()<<endl;
// }


// class Circle {
// private:
//   double radius; string color;
// public:
//    Circle(double r = 1.0, string c = "red"){
//       radius = r;
//       color = c;
//    //    r=r;c=c;
//    }
//    double getRadius(){return radius;}
//    string getColor(){return color;}
//    double getArea(){return radius*radius*3.1416;}
//    void setRadius(int r){radius = r;}
// };
// int main(){
//     Circle c1(1.2, "blue");
//    // Circle c1;
//    c1.setRadius(8);
//    cout << "Radius=" << c1.getRadius() << " Area=" << c1.getArea()<< " Color=" << c1.getColor() << endl;
//    return 0;
// }



//
// https://www.w3schools.com/cpp/cpp_inheritance.asp
// class Car {
//   private:
//     int maxSpeed;
//   public:
//     // int speed(int maxSpeed);
//       int speed(int maxSpeed){
//     // int speed(int speed=maxSpeed){
//     // int speed(maxSpeed){
//       // maxSpeed=speed;
//       return maxSpeed;
//     }
// };
//
// // int Car::speed(int maxSpeed) {
// //   return maxSpeed;
// // }
//
// int main() {
//   Car myObj; // Create an object of Car
//   cout << myObj.speed(200); // Call the method with an argument
//   return 0;
// }




// arrow operator
#include<iostream>
class Arb {
   public: int b;
   Arb() { b = 5; }
};
int main() {
   Arb a = Arb();
   Arb* x = &a;
   cout << "a.b = " << a.b << "\n";
   cout << "x->b = " << x->b << "\n";
   return 0;
}







// int main(){
//   int a,b;
//   int *ptr = &a;
//   a = 9;
//   // *ptr++; // equivalent to this *(ptr++); this also same? ptr++;
//   (*ptr)++;
//   b = *ptr+2;
//   cout << a << ',' << b << endl;
//   return 0;
// }




// pointers tut
// void f1(int a){
//   a=10;
// }
// void f2(int &a){ //same as int &a=x2; a=10;
//   a=10;
//   cout<<"f2 "<< a<<endl;
//   // cout<<"f2 "<< a<<endl;
// }
// void f3(int *a){ //recieves adress, change value at that adress
//   // *a=10;
//   // a=10;//cant bec a is mem add
//   // cout<<a<<endl;
//   cout<<"f3 "<< *a<<endl;  //a is mem adress
//   // cout<<"f3 "<< a<<endl;  //a is mem adress
// }
//
// int main(){
//   // int x1,x2,x3=1; // cant
//   int x1=1,x2=1,x3=1;
//   f1(x1);
//   // f2(x2);
//   int &a=x2; a=10;
//   // f3(&x3);
//   f3(x3);
//   cout<<x1<<endl;
//   cout<<x2<<endl;
//   cout<<x3<<endl;
// }

// int main(){
//   int x=10;
//   // int a=x; //shallow copy
//   // int &b=x; //deep copy
//   // int *c=&x;
//   int *d=x;
//   // int *d=8;
//   // b=2;
//   // *c=5;
//   // *d=7;
//   d=7;
//   // x=1;
//   cout<<x<<endl;
//   // cout<<a<<endl; //10
//   // cout<<b<<endl; //1
//   // cout<<*c<<endl; //
//   cout<<d<<endl; //1
// }



// int main(){
//   int a=100;
//   cout << &a <<endl;
//
//   // int &b=100; // cant
//   // cout << b <<endl;
//   // cout << *b <<endl;
//
//   int c=100;//error
//   *c=4;//error
//   // cout << c <<endl;
//   // cout << &c <<endl;
// }


// char c; int r;
// srand (time(NULL));    // initialize the random number generator
// for (i=0; i<num; i++){
//       r = rand() % 26;   // generate a random number
//       c = 'a' + r;            // Convert to a character from a-z
//       cout << c;}

// int myarray[] = {2,4,6,8}; // array, careful if out of bounds can override other data
// #include <vector>
// vector<int> intvector;
//
// cin>>num
// student_mark = new double [num] //dynamic allocate tuple
// int *p = new int[10]

// switch case
// nullptr // NONE 0


/*
g++ -o F:\cpptut "F:\cpptut.cpp"
F:\cpptut.exe
*/
