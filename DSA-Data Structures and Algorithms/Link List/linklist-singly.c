#include <stdio.h>
// Link list là một cấu trúc dữ liệu tuyến tính, trong đó các phần tử được lưu trữ trong các nút (node) và mỗi nút chứa một con trỏ (pointer) đến nút tiếp theo trong danh sách. Điều này cho phép chèn và xóa các phần tử một cách linh hoạt mà không cần phải di chuyển các phần tử khác như trong mảng.
// Link list có thể được triển khai dưới dạng danh sách liên kết đơn (singly linked list), danh sách liên kết đôi (doubly linked list) hoặc danh sách liên kết vòng (circular linked list). Trong danh sách liên kết đơn, mỗi nút chỉ chứa một con trỏ đến nút tiếp theo, trong khi trong danh sách liên kết đôi, mỗi nút chứa hai con trỏ: một đến nút tiếp theo và một đến nút trước đó. Danh sách liên kết vòng là một biến thể của danh sách liên kết đơn hoặc đôi, trong đó nút cuối cùng trỏ lại đến nút đầu tiên, tạo thành một vòng tròn.
//single linked list: [data | next] -> [data | next] -> [data | next] -> NULL
//double linked list: [prev | data | next] <-> [prev | data | next] <-> [prev | data | next] <-> NULL
//circular linked list:
/* [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> [prev | data | next] -> NULL */
struct Node {
    int data; // Dữ liệu của nút
    struct Node* next; // Con trỏ đến nút tiếp theo
};

// tạo node mới
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho nút mới
    newNode->data = data; // Gán dữ liệu cho nút mới
    newNode->next = NULL; // Khởi tạo con trỏ next của nút mới là NULL
    return newNode; 
}

int main(){

}