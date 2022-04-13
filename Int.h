#include <iostream>
/*Задание 2. Бинарная операция
Создать класс "Целое число".Необходимо перегрузить следующие операторы:
-оператор сложения,
-оператор вычитания,
-оператор умножения,
-оператор деления
как для работы с другими экземплярами класса, так и с пользовательскими числами;
-оператор преобразования в int.
Необходимо учитывать то, что пользовательское число и объект класса могут находится и слева и справа от оператора.
На усмотрение студента остается решение какой оператор какой перегрузки требует(метод или дружественная функция)*/

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

    void setMyInt(int& value){ // setter
        field_i = value;
    }
    int getMyInt() const{ //getter
        return field_i;
    }
    Int operator- (const Int & i){ // subtraction
        return Int(this->field_i - i.field_i);
    }
    friend Int operator/ (const Int& l, const Int& i){ // division
        return Int(l.field_i/i.field_i);
    }
    friend Int operator+ (const Int& l, const Int& i){ // addition
        return Int(l.field_i+i.field_i);
    }
    friend Int operator *(const Int& f, const Int& s){ // multiple
        return Int(f.field_i*s.field_i);
    }
    operator int ()const{ // convert to int
        return field_i;
    }
    void out()const{
        std::cout<<field_i<<std::endl;
    }


};