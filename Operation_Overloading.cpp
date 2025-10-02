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
            this->next = NULL;
        }
        // Ở đây thay vì sử dụng hàm tạo ta hoàn toàn có thể nạp chồng toán tử cin >> 
        // để vừa in prompt ra màn hình cho người nhập sử dụng, vừa gán giá trị chỉ bằng một cú pháp đơn giản 
        friend void Create_List(int);
        friend void Display_List(Node*);
};

Node *START = NULL; 
// Khởi tạo một con trỏ trỏ vào đổi tượng Node thì hàm tạo không hề được gọi nên gán giá trị thoải mái 
// Chỉ khi nào khởi tạo một đối tượng mới thì hàm tạo mới được gọi 
// Ví dụ *START = new Node(12); -> Khi này một đối tượng Node được tạo ra với thuộc tính giá trị bằng 12 và con trỏ kế tiếp = NULL
// và nó được quản lí bởi con trỏ START 
void Create_List(int n)
{
    int val;
    cout << endl << "Nhap thong tin cho danh sach: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << "Nhap gia tri thu " << i+1 << " : " ;
        cin >> val;
        Node *new_node = new Node(val);
        if(START == NULL)
        {
            START = new_node;
        }
        else{
            Node *ptr = START;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node; 
        }
    }
}

void Display_List(Node *START)
{
    Node *ptr = START;
    while(ptr != NULL)
    {
        cout << ptr->val << " "; 
        ptr = ptr->next;
    }
}
int main()
{
    int n;
    cout << "Nhap: "; cin >> n;
    Create_List(n);
    Display_List(START);
}
