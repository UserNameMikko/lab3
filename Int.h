#include <iostream>
class Int{
private:
    int field_i;
public:
    Int(): field_i(0){}
    explicit Int(int value){
        field_i = value;
    }
    ~Int(){}
    Int(const Int& intCopy){
        this->field_i = intCopy.field_i;
    }

    void setMyInt(int& value){
        field_i = value;
    }
    int getMyInt() const{
        return field_i;
    }

    // subtraction
    Int operator- (const Int & i){
        return Int(this->field_i - i.field_i);
    }
    Int operator-(const int s){
        return Int(this->field_i-s);
    }

    // division
    friend Int operator/ (const Int& l, const Int& i){
        return Int(l.field_i/i.field_i);
    }
    friend Int operator /(const Int& l, const int s){
        return Int(l.field_i/s);
    }

    // addition
    friend Int operator+ (const Int& l, const Int& i){
        return Int(l.field_i+i.field_i);
    }
    friend Int operator+ (const Int& l, const int s){
        return Int(l.field_i+s);
    }

    // multiplication
    friend Int operator *(const Int& f, const Int& s){
        return Int(f.field_i*s.field_i);
    }
    friend  Int operator*(const Int& f, const int s){
        return Int(f.field_i*s);
    }

    //convert Int to int
    operator int ()const{ // convert to int
        return this->field_i;
    }

    void out()const{
        std::cout<<field_i<<std::endl;
    }

};