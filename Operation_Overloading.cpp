// Trong C++ ta có thể nạp chồng toán tử để có thể thực hiện các toán tử đối với toán hạng là 
// các đối tượng trong một lớp ( thay vì chỉ sử dụng được toán tử đối với các biến đơn thuần )


// Mối liên hệ giữa hàm tạo , hàm hủy - cấp phát động và giải phóng vùng nhớ 
// -> Khi cấp phát động -> hàm tạo được gọi 
// -> Khi giải phóng vùng nhớ -> hàm hủy được gọi
// -> Thông thường hàm tạo cũng thường dùng để cấp phát động giá trị ban đầu 
// -> Còn hàm hủy gần như chỉ dùng để giải phóng vùng nhớ 


#include <iostream>

using namespace std;

class Node{
    private:
        int val;
        Node *next;
    public:
        Node(int val){
            this->val = val; 
            //this->next = NULL;
        }
        // Ở đây thay vì sử dụng hàm tạo ta hoàn toàn có thể nạp chồng toán tử cin >> 
        // để vừa in prompt ra màn hình cho người nhập sử dụng, vừa gán giá trị chỉ bằng một cú pháp đơn giản 
        friend void Create_List(Node **, int);
        friend void Display_List(Node*);
        friend Node* Find_Element(Node*,int);
};

//Node *START = NULL; 
// Khởi tạo một con trỏ trỏ vào đổi tượng Node thì hàm tạo không hề được gọi nên gán giá trị thoải mái 
// Chỉ khi nào khởi tạo một đối tượng mới thì hàm tạo mới được gọi 
// Ví dụ *START = new Node(12); -> Khi này một đối tượng Node được tạo ra với thuộc tính giá trị bằng 12 và con trỏ kế tiếp = NULL
// và nó được quản lí bởi con trỏ START 
void Create_List(Node **START, int n)
{
    int val;
    cout << endl << "Nhap thong tin danh sach: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << "Nhap phan tu thu " << i+1 << " : ";
        cin >> val;
        Node *new_node = new Node(val);
        if(*START == NULL)
        {
            *START = new_node;
            new_node->next = NULL;
        }
        else{
            Node *ptr = *START;
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            ptr->next = new_node; 
            if(i != (n-1)) new_node -> next = NULL;
            else new_node->next = *START; 
        }
    }
}
Node* Find_Element(Node *START, int val)
{
    Node *ptr = START->next;
    while(ptr != START)
    {
        if(ptr -> val == val)
            return ptr; 
        ptr = ptr->next;
    }
    throw "Can't find ";
}
void Display_List(Node *START)
{
    Node *ptr = START;
    cout << ptr->val << " ";
    ptr = ptr->next; 
    while(ptr != START)
    {
        cout << ptr -> val << " ";
        ptr = ptr->next;
    } 
}
int main()
{
    int n;
    int val;
    Node *START = NULL;
    cout << "Enter the volumn of the list: ";
    cin >> n;
    cout << "Enter the value for the begining of iteration: ";
    cin >> val;
    Create_List(&START,n);
    Display_List(START);
    cout << endl;
    try{
        Node *ptr = Find_Element(START, val);
        Display_List(ptr);
    }
    catch (char const* allert)
    {
        cout << allert << val << " in the list" << endl; 
    }   
}
