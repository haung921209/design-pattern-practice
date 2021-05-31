#include <iostream>
#include <type_traits>
#include <memory>
#include <vector>
#include <cassert>

using namespace std;


enum class oper {add, sub, mul, divi};

template <typename T1,
          typename T2,
          typename RES>
class BinaryOperationCalculator{
    RES add(const T1& a, const T2& b){
        return a+b;
    }
    RES substract(const T1& a, const T2& b){
        return a-b;
    }
    RES multiply(const T1& a, const T2& b){
        return a*b;
    }
    RES divide(const T1& a, const T2& b){
        if(!b) throw out_of_range("b가 연산에 적합한 범위를 벗어났습니다");
        return a/b;
    }
protected:
    oper givenOp;
public:
    BinaryOperationCalculator(oper givenOp):givenOp(givenOp){
    }
    
    RES switchOperator(const T1& a, const T2& b) const {
        switch (givenOp) {
            case oper::add:
              return add(a, b);
            case oper::sub:
              return substract(a, b);
            case oper:: mul:
              return multiply(a, b);
            case oper::divi:
              return divide(a, b);
            default:
                throw out_of_range("적합한 연산자의 범위를 넘어갔습니다");
        }
        return 0;
    };
};
int main() {
  
  return 0;
}
