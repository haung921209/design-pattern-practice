#include <iostream>
#include <type_traits>
#include <memory>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


enum oper {add, sub, mul, divi};

template <typename T1,
          typename T2,
          typename RES = common_type_t<T1, T2>>
class BinaryOperationCalculator{
private:
    RES addition(const T1& a, const T2& b) const {
        return a+b;
    }
    RES substract(const T1& a, const T2& b) const {
        return a-b;
    }
    RES multiply(const T1& a, const T2& b) const {
        return a*b;
    }
    RES divide(const T1& a, const T2& b) const {
        if(!b) throw out_of_range("b가 연산에 적합한 범위를 벗어났습니다");
        return a/b;
    }
protected:
    oper givenOp;
public:
    BinaryOperationCalculator(oper givenOp):givenOp(givenOp){
    }
    
    RES eval(const T1& lhs, const T2& rhs) const {
        switch (givenOp) {
            case oper::add:
                return addition(lhs, rhs);
            case oper::sub:
                return substract(lhs, rhs);
            case oper::mul:
                return multiply(lhs, rhs);
            case oper::divi:
                return divide(lhs, rhs);
            default:
                throw out_of_range("적합한 연산자의 범위를 넘어갔습니다");
        }
        return 0;
    };
};


int main() {
    BinaryOperationCalculator<long, float> binaryOperationCalculator(add);
    cout<<binaryOperationCalculator.eval(1,2)<<endl;
 
  return 0;
}
