//Counter.h
#include <iostream>
class Counter{
    public:
        Counter();
        Counter(int x);
        void setCount(int x);
        int getCount();
        Counter operator+(int);
        Counter operator+(Counter);
        friend Counter operator+(int, Counter);
        
        // Write these 3 functions
        Counter operator-(int);
        Counter operator-(Counter);
        friend Counter operator-(int, Counter);

    private:
        int this_count;
};
