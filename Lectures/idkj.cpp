class Circle{
    private:
        float radius;
    public:
        Circle operator+(Circle A);
        Circle operator-(Circle A);
        Circle operator-(float a);
        Circle operator+(float a);
        friend Circle operator+(float a, Circle B);
        friend Circle operator-(float a, Circle B);
        Circle(float r1);
        Circle();
};

Circle::Circle(float r1){
    radius = r1;
}

Circle::Circle(){
    radius = 0;
}

Circle Circle::operator+(Circle A){
    Circle newC;
    newC.radius = radius + A.radius;
    return newC;
}

Circle operator+(float a, Circle B){
    Circle newC;
    newC.radius = a + B.radius;
    return newC;
}

Circle Circle::operator+(float a){
    Circle newC;
    newC.radius = radius + a;
    return newC;
}

Circle Circle::operator-(Circle A){
    Circle newC;
    newC.radius = radius - A.radius;
    return newC;
}

Circle operator-(float a, Circle B){
    Circle newC;
    newC.radius = a - B.radius;
    return newC;
}

Circle Circle::operator-(float a){
    Circle newC;
    newC.radius = radius - a;
    return newC;
}

int main(){
    Circle c1(4);
    Circle c2 = c1 + c1;
    Circle c3 = 1.0 + c1;
    Circle c4 = c1 + 1.0;
    c1 = c2 - c3;
    c4 = c4 - 2.3;
    c2 = 21 - c3;
}