#include <iostream>

class Node {
    public:
        int value;
        struct Node *next;
    Node (int v1);
    Node();
};  

Node::Node(){
    value = 0;
    next = NULL;
}

Node::Node(int v1){
    value = v1;
    next = new Node();
}


class Circle {
    private:
        int radius;
    public:
    Circle(int r1);
    Circle();
    Circle operator+(const Circle& A) const;
    Circle operator-(const Circle& A) const;
    Circle operator+(float A) const;
    Circle operator-(float A) const;
};

Circle::Circle(){
    radius = 0;
}

Circle::Circle(float r1){
    radius = r1;
}

Circle Circle::operator+(const Circle& A) const{
    Circle result;
    result.radius = radius + A.radius;
    return result;
}

Circle Circle::operator-(const Circle& A) const{
    Circle result;
    result.radius = radius - A.radius;
    return result;
}

Circle Circle::operator+(float A) const{
    Circle result;
    result.radius = radius + A;
    return result;
}

Circle Circle::operator-(float A) const{
    Circle result;
    result.radius = radius - A;
    return result;
}

int main(){
    Circle circ1(4);
    Circle circ2 = circ1 + circ1;
    Circle circ3 = 1 + circ1;
    Circle circ4 = circ1 + 1;
    circ1 = circ2 - circ3;
    circ4 - circ4 - 2.3;
}