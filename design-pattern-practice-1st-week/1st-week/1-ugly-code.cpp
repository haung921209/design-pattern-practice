#include <iostream>
#include <type_traits>
#include <memory>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


enum class oper {add, sub, mul, divi};

template <typename T1,
          typename T2,
          typename RES = common_type_t<T1, T2>>
class BinaryOperationCalculator{
public:
    BinaryOperationCalculator(){ };
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
    
    
};
int main() {
    BinaryOperationCalculator<int, int> binaryOperationCalculator;
    cout<<binaryOperationCalculator.add(1, 2)<<endl;
    
  
    return 0;
}
