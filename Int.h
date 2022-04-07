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
    Int operator- (const Int & i){
        return Int(this->field_i + i.field_i);
    }
    friend Int operator/ (const Int& l, const Int& i){
        return Int(l/i);
    }
    friend Int operator+ (const Int& l, const Int& i){
        return Int(l+i);
    }


};