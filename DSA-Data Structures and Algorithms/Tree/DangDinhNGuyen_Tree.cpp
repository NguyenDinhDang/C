#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h> 

typedef struct tagTNode	
{	
	int Key; 
	struct tagTNode* pParent;	
	struct tagTNode* pLeft;	
	struct tagTNode* pRight;	
} TNODE;
typedef TNODE *TREE;

//Tạo cây
void CreateTree(TREE &root);
//Thêm node vào cây
void InsertTree(TREE &root , int x);
//Duyệt theo 3 cách
void NLR(TREE root);
void LNR(TREE root);
void LRN(TREE root);
//Tìm node
TNODE * searchNode(TREE root, int x);
//Xóa node x
int delNode(TREE &root, int X);
//Đổi vị trí node nếu không phải node lá 
void searchStandFor(TREE &p, TREE &q);
// Xóa toàn bộ cây
void removeTree(TREE &root);

int main(){
	TREE myTree = NULL;
	int luaChon, x;
	TNODE* timKiem;

	do {
		printf("\n\n===== MENU QUAN LY CAY =====");
		printf("\n1. Tao cay bang cach nhap tung node tuong tac (CreateTree)");
		printf("\n2. Them nhanh cac node vao cay Tim Kiem Nhi Phan (InsertTree)");
		printf("\n3. Duyet cay NLR");
		printf("\n4. Duyet cay LNR");
		printf("\n5. Duyet cay LRN");
		printf("\n6. Tim kiem mot node");
		printf("\n7. Xoa mot node X");
		printf("\n8. Xoa toan bo cay");
		printf("\n0. Thoat");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d", &luaChon);

		switch(luaChon) {
			case 1:
				printf("\n--- Tao cay tuong tac (Nhan phim SPACE hoac ENTER de ket thuc nhanh) ---");
				CreateTree(myTree);
				break;
			case 2:
				printf("\nNhap cac so nguyen (Nhap 0 de dung): \n");
				while(1){
					printf("Nhap gia tri: ");
					scanf("%d", &x);
					if(x == 0) break;
					InsertTree(myTree, x);
				}
				break;
			case 3:
				printf("\nDuyet NLR: ");
				NLR(myTree);
				break;
			case 4:
				printf("\nDuyet LNR: ");
				LNR(myTree);
				break;
			case 5:
				printf("\nDuyet LRN: ");
				LRN(myTree);
				break;
			case 6:
				printf("\nNhap gia tri can tim: ");
				scanf("%d", &x);
				timKiem = searchNode(myTree, x);
				if(timKiem != NULL) printf("Tim thay node: %d", timKiem->Key);
				else printf("Khong tim thay!");
				break;
			case 7:
				printf("\nNhap gia tri can xoa: ");
				scanf("%d", &x);
				if(delNode(myTree, x)) printf("Da xoa node %d thanh cong.", x);
				else printf("Khong tim thay node de xoa.");
				break;
			case 8:
				removeTree(myTree);
				printf("\nDa xoa toan bo cay.");
				break;
			case 0:
				printf("\nThoat chuong trinh.");
				break;
			default:
				printf("\nLua chon khong hop le!");
		}
	} while(luaChon != 0);

	return 0;
}
// Tạo cây
void CreateTree(TREE &root){	
	int x;
	printf("\nGia tri node (Nhap -1 de bo qua/dung nhanh): ");
	scanf("%d", &x); 
	if(x != -1){ 
		root=(TNODE*)malloc(sizeof(TNODE));
		root->Key=x;
		printf("-> Dang o node [%d]", x);
		CreateTree(root->pLeft);
		CreateTree(root->pRight);
	}else root=NULL;
}

// Node Left Right
void NLR(TREE root){
	if (root != NULL){	
		printf("%d ", root->Key);
		NLR(root->pLeft);
		NLR(root->pRight);	
	}
}

// Left Node Right
void LNR(TREE root){
	if (root != NULL){
		LNR(root->pLeft);
		printf("%d ", root->Key); 
		LNR(root->pRight);
	}
}

// Left Right Node 
void LRN(TREE root){
	if (root != NULL){
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d ", root->Key); 
	}
}

// Thêm một node vào cây
void InsertTree(TREE &root , int x){	
	if(root != NULL){	
		if(root->Key==x) return; 
		if(root->Key >x) InsertTree(root->pLeft,x); 	
		else InsertTree(root->pRight,x);
	}	
	else{
		root= new TNODE;
		root->Key=x; 
		root->pLeft=root->pRight=NULL;
	}
}

// Tìm node
TNODE * searchNode(TREE root, int x){
	TNODE *p = root;
	while (p != NULL){
		if(x == p->Key) return p; 
		else
			if(x < p->Key) p = p->pLeft; 
			else p = p->pRight;
	}
	return NULL;
}

//Xóa node x
int delNode(TREE &root, int X){
	if(root== NULL) return 0;
	if(root->Key > X) return delNode(root->pLeft, X); 
	if(root->Key < X) return delNode(root->pRight, X); 
	
	if(root->Key==X){ 
		TNODE* p = root;
		if(root->pLeft == NULL)
			root = root->pRight;
		else
			if(root->pRight == NULL) root = root->pLeft;
			else searchStandFor(p, root->pLeft); 
		delete p; 
		return 1;
	}
	return 0;
}

// Đổi vị trí node nếu không phải node lá 
void searchStandFor(TREE &p, TREE &q){
	if(q->pRight!=NULL) searchStandFor(p, q->pRight);
	else{
		p->Key = q->Key; 
		p = q;
		if(q->pLeft!=NULL) q = q->pLeft;
		else q = q->pRight;
	}
}

// Xóa toàn bộ cây
void removeTree(TREE &root){
	if(root!=NULL){
		removeTree(root->pLeft);  
		removeTree(root->pRight); 
		delNode(root, root->Key); 
	}
}