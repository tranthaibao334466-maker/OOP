// Ôn tập nhanh về hàm tạo và hàm hủy trong lập trình hướng đối tượng 
// Hàm tạo -> Được gọi đến ngay sau khi một đối tượng trong class được khởi tạo ( nghĩa là được cấp phát bộ nhớ lưu trũ )
//         -> Overload Function: nghĩa là ta có thể tạo ra nhiều hàm tạo cùng tên với tham số vào khác nhau và 
//         phụ thuộc vào tham số đầu vào thì chương trình sẽ quyết định đâu là hàm tạo được gọi ( linh hoạt nhưng cũng rất dễ nhầm lẫn )
// Hàm hủy -> Được gọi khi đối tượng rời khỏi các hàm mà nó được khởi tạo 
//         -> Không có thuộc tính Overload Function
//         -> Khá hiệu quả trong việc giải phóng bộ nhớ được cấp phát động 

#include <iostream>

using namespace std;

#define MAX 100 

class Stack{
    private:
        int size;
        int *array;
    public:
        Stack(){size=0; array = new int[MAX];}
        ~Stack(){delete[] array;}
        void Push(int val);
        void Pop();
        int Top();
        bool Empty();
        void Display();
        int getsize() {return size;}
};
void Stack::Push(int val)
{
    if(size==MAX) throw string("Stack volumn is maximum !");
    array[size++] = val;
} 
void Stack::Pop()
{
    if(size == 0) throw string("Stack is empty !"); // "..." la mot xau kieu const char 
    size--;
}
int Stack::Top()
{
    if(size == 0) throw string("Stack is empty !");
    return array[size-1];
}
bool Stack::Empty()
{
    if(size == 0) return true;
    else return false;
}
void Stack::Display()
{
    for(int i=0;i<size;i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    Stack S;
    S.Push(5);
    S.Push(6);
    S.Push(7);
    S.Push(8);
    S.Display();
    S.Pop();
    S.Pop();
    cout << endl;
    S.Display();
    cout << endl << S.Top() << endl;
    try{
        S.Pop();
        S.Pop();
        // Begin to throw 
        S.Pop();
        S.Top();
    }
    catch(string &allert)
    {
        cout << allert;
    }
}