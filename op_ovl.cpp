
#include <iostream>
using namespace std;

/*
g++ -o F:\c++\same "F:\c++\op_ovl.cpp"
F:\c++\same.exe
*/

class Food {
private:
    string _name;
    int _cal;
public:
    Food() { _name = ""; _cal = 0; };
    Food(string, int);
    Food operator+(Food& f2) {
        return Food(_name + f2._name, _cal +f2._cal);
    }
    Food operator<<(Food&) {
      cout<<_name<<", "<<_cal<<endl;
      // return Food(_name + f2._name, _cal +f2._cal);
      return
    }
};


int main(){
  // Food food1=Food("df",39);
  // Food food1= new Food("df",39);

  Food food1("Salad", 100);
  Food food2("Chicken", 200);
  Food food3("Curry", 40);
  Food food23 = food2 + food3;

  // food11 = food1 + food1;
  cout<<food23;
  return 0;
}
