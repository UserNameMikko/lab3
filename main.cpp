/*Вариант 10

*Задание 1. Унарная операция
Создать объект "Дэк".Размер и значения дэка вводятся с клавиатуры пользователем. Необходимо перегрузить
следующие операторы:
-оператор ! как метод для получения дэка с отрицательными значениями;
-оператор префиксного декрементирования как метод для уменьшения значения всех элементов дэка на единицу;
-оператор префиксного инкрементирования как метод для увеличения всех элементов на 0,5;
-оператор постфиксного декрементирования как дружественную функцию для извлечения из дэка;
-оператор постфиксного инкрементирования как дружественная функция для добавления элемента(пользовательское число) в дэк.

*Задание 2. Бинарная операция
Создать класс "Целое число".Необходимо перегрузить следующие операторы:
-оператор сложения,
-оператор вычитания,
-оператор умножения,
-оператор деления
как для работы с другими экземплярами класса, так и с пользовательскими числами;
-оператор преобразования в int.
Необходимо учитывать то, что пользовательское число и объект класса могут находится и слева и справа от оператора.
На усмотрение студента остается решение какой оператор какой перегрузки требует(метод или дружественная функция)*/
#include "Deque.h"
#include "Int.h"

template<class T> struct Data{
    T value;
    T* ptr = &value;
};

void menu(){
    std::cout<<"1 - add new element push_back()\n2 - add new element push_front()\n3 - erase an element pop_back()\n"\
    "4 - erase an element pop_front()\n5 - define size of the deque\n6 - define peek\n7 - is the deque empty?\n"\
    "8 - print()\n9 - operator !\n10- prefix decrement\n11 - prefix increment\n"\
    "12 - postfix decrement\n13 - postfix increment\n0 - exit"<<std::endl;
}

int main() {

    //initializing of variables

    Deque<double> deque;
    int sizeOfDeque = 0;
    int choose = 0;

    std::cout<<"-------DEQUE-------\n\ninput size of deque->";
    std::cin>>sizeOfDeque;

    // fill the deque

    for(int i = 0; i < sizeOfDeque;i++) {
        Data<double> *data = new Data<double>;
        std::cout << "input a value->";
        std::cin >> data->value;
        std::cout << "choose how do you want to fill the deque:\n1-push_front\n2-push_back\n-->";
        std::cin >> choose;
        switch (choose) {
            case 1:
                deque.push_front(data->ptr);
                break;
            case 2:
                deque.push_back(data->ptr);
                break;
            default://exception
                std::cout<<("Incorrect input!")<<std::endl;
                i--;
                break;
        }
    }
    //the first part of the program

    std::cout<<"Your deque:\n"<<deque<<"\n";
    std::cout<<"what do you want to do in the next step?\n";

    int ch;
    do{
        Data<double>*data = new Data<double>;
        menu();
        std::cin>>ch;
        switch (ch) {
            case 1:
                std::cout << "input a value->"<<std::endl;
                std::cin >> data->value;
                deque.push_back(data->ptr);
                std::cout<<"success!"<<std::endl;
                break;
            case 2:
                std::cout << "input a value->"<<std::endl;
                std::cin >> data->value;
                deque.push_front(data->ptr);
                std::cout<<"success!"<<std::endl;
                break;
            case 3:
                deque.pop_back();
                std::cout<<"success!"<<std::endl;
                break;
            case 4:
                deque.pop_front();
                std::cout<<"success!"<<std::endl;
                break;
            case 5:
                std::cout<<"size of the deque: "<<deque.size_deque()<<std::endl;
                break;
            case 6:
                std::cout<<"peek of the deque: "<<deque.peek()<<std::endl;
                break;
            case 7:
                std::cout<<deque.isEmpty()<<std::endl;
                break;
            case 8:
                std::cout<<"Your deque:\n"<<deque<<std::endl;
                break;
            case 9:
                !deque;
                break;
            case 10:
                --deque;
                break;
            case 11:
                ++deque;
                break;
            case 12://postfix decrement
                deque--;
                break;
            case 13: //postfix increment
                deque++;
                break;
            default:
                if(ch != 0)
                    std::cout<<"incorrect input!"<<std::endl;
        }

    } while (ch != 0);
    // the second part of the program
    //class int



    return 0;
}


