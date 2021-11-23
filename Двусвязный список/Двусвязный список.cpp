// Двусвязный список.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>

struct Node {
    int value;
    Node* next;
    Node* previous;
    Node(int value, Node* next, Node* previous) {
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
    Node(int value) {
        this->value = value;
        next = nullptr;
        previous = nullptr;
    }
};

class LinkedList {
private:
    Node* root;
    Node* tail;
public:
    LinkedList() {
        root = nullptr;
        tail = nullptr;
    }

    void push_back(int value) {
        Node* new_node = new Node(value, nullptr, tail);
        if (size() == 0) {
            tail = new_node;
            root = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node ;
    }
    void push_front(int value) {
        Node* new_node = new Node(value, root, nullptr);
        if (size() == 0) {
            tail = new_node;
            root = new_node;
            return;
        }
        root->previous = new_node;
        root = new_node ;
        
    }

    void insert(int position, int value) { 
        if (position < 0 || position >= size())
            return;
        Node* new_node = new Node(value);

        Node* next = root;
        Node* prev = nullptr;
        for (int i = 0; i < position; i++) {
            prev = next;
            next = next->next;
        }
        if (prev == nullptr) {
            root->previous = new_node;
            new_node = root;
            return;
        }

        prev->next = new_node;
        new_node->previous = prev;
        new_node->next = next;
        next->previous = new_node;
    }
    void erase(int position) {
        if (position < 0 || position >= size())
            return;

        Node* prev = nullptr;
        Node* cur = root;

        for (int i = 0; i < position; i++) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == nullptr) {
            if (size() == 1) {
                prev = nullptr;
                cur = nullptr;
            }
            Node* next = root->next;
            delete root;
            root = next;
            return;
        }
     
       prev->next = cur->next;
       Node* next_node = cur->next;
       delete cur;
       next_node->previous = prev;
    }

    int size() {
        Node* cur_node = root;
        int size = 0;
        while (cur_node != nullptr) {
            size++;
            cur_node = cur_node->next;
        }
        return size;

    }
    int get_element(int position) {
        Node* cur_node = root;
        int s = 0;
        if (position < 0 || position >= size()) {
            return -1 ;
        }
        
        while (s != position)
        {
            cur_node = cur_node->next;
            s++;
        }
        return cur_node->value;
    }

    void print_list() {
        Node* cur_node = root;

        while (cur_node != nullptr) {
            std::cout << cur_node->value <<" ";
            cur_node = cur_node->next;
        }
        std::cout << std::endl;
    }

};

int main()
{
    LinkedList list;
    list.push_back(3);
    list.print_list();
    list.erase(0);
    list.print_list();
    list.push_front(7);
    list.print_list();
    list.push_front(5);
    list.print_list();
    list.push_back(7);
    list.print_list();
    list.insert(1,4);
    list.print_list();
   std::cout<< list.get_element(3)<< " " << list.size() << std::endl;
   list.erase(2);
   list.print_list();

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
