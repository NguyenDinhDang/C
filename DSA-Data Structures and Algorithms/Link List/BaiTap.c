#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Cau truc luu thong tin 1 dai ly cap 2
struct DaiLy
{
    int maSo;              // Ma so dai ly
    char tenDaiLy[50];     // Ten dai ly
    char tenTinh[30];      // Ten tinh (thanh pho)
    char soDienThoai[15];  // So dien thoai
    long soTien;           // So tien (dung long vi so tien co the lon)
};

// Cau truc 1 nut (Node) cua danh sach lien ket don
struct Node
{
    struct DaiLy info;     // Du lieu cua nut (thong tin 1 dai ly)
    struct Node *next;     // Con tro chi den nut ke tiep
};

// Con tro dau danh sach (head) - thuong duoc khai bao la struct Node*
typedef struct Node* NodeList;


/* ======================================================
   HAM HO TRO: TAO 1 NUT MOI (khong bat buoc de bai,
   nhung can thiet de xay dung/test danh sach)
   ====================================================== */
struct Node* taoNut(int maSo, char tenDaiLy[], char tenTinh[],
                     char soDienThoai[], long soTien)
{
    // Cap phat vung nho cho 1 nut moi
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    // Gan du lieu cho nut vua tao
    p->info.maSo = maSo;
    strcpy(p->info.tenDaiLy, tenDaiLy);
    strcpy(p->info.tenTinh, tenTinh);
    strcpy(p->info.soDienThoai, soDienThoai);
    p->info.soTien = soTien;

    // Nut moi chua co nut ke tiep
    p->next = NULL;

    return p;
}

/* ======================================================
   HAM HO TRO: THEM 1 NUT VAO CUOI DANH SACH (noi duoi)
   Dung de tao du lieu mau trong ham main
   ====================================================== */
void themCuoi(struct Node **head, int maSo, char tenDaiLy[], char tenTinh[],
              char soDienThoai[], long soTien)
{
    // Tao nut moi
    struct Node *p = taoNut(maSo, tenDaiLy, tenTinh, soDienThoai, soTien);

    // Neu danh sach rong thi nut moi tro thanh head
    if (*head == NULL)
    {
        *head = p;
        return;
    }

    // Nguoc lai, di chuyen con tro q toi nut cuoi cung
    struct Node *q = *head;
    while (q->next != NULL)
    {
        q = q->next;
    }

    // Gan nut moi vao sau nut cuoi cung
    q->next = p;
}


/* ======================================================
   b. HAM IN DANH SACH MA SO DAI LY O THANH PHO CAN THO
   ====================================================== */
void inMaSoCanTho(struct Node *head)
{
    printf("\n--- Danh sach ma so dai ly o Can Tho ---\n");

    // Bien danh dau xem co tim thay dai ly nao khong
    int demSoLuong = 0;

    // Con tro p dung de duyet qua tung nut trong danh sach
    struct Node *p = head;

    // Duyet tu dau danh sach den khi het (p == NULL)
    while (p != NULL)
    {
        // So sanh chuoi tenTinh cua nut hien tai voi "Can Tho"
        // strcmp tra ve 0 neu 2 chuoi giong nhau
        if (strcmp(p->info.tenTinh, "Can Tho") == 0)
        {
            printf("Ma so: %d\n", p->info.maSo);
            demSoLuong++;
        }

        // Di chuyen con tro p sang nut ke tiep
        p = p->next;
    }

    // Neu khong co dai ly nao thoa dieu kien thi thong bao
    if (demSoLuong == 0)
    {
        printf("Khong co dai ly nao o Can Tho.\n");
    }
}


/* ======================================================
   c. HAM DEM SO LUONG DAI LY CO SO TIEN TU 1.000.000
      DEN 90.000.000
   ====================================================== */
int demDaiLyTheoSoTien(struct Node *head)
{
    // Bien dem, khoi tao bang 0
    int dem = 0;

    // Con tro p dung de duyet danh sach, bat dau tu head
    struct Node *p = head;

    // Duyet qua tung nut cho den khi p tro toi NULL (het danh sach)
    while (p != NULL)
    {
        // Kiem tra dieu kien: so tien nam trong khoang [1.000.000, 90.000.000]
        if (p->info.soTien >= 1000000 && p->info.soTien <= 90000000)
        {
            dem++; // Neu thoa dieu kien thi tang bien dem len 1
        }

        // Di chuyen sang nut ke tiep
        p = p->next;
    }

    // Tra ve tong so luong dai ly thoa dieu kien
    return dem;
}


/* ======================================================
   HAM HO TRO: IN TOAN BO DANH SACH (de kiem tra ket qua)
   ====================================================== */
void inDanhSach(struct Node *head)
{
    printf("\n--- Danh sach tat ca dai ly ---\n");
    struct Node *p = head;

    while (p != NULL)
    {
        printf("Ma so: %-5d | Ten: %-15s | Tinh: %-10s | SDT: %-12s | So tien: %ld\n",
               p->info.maSo, p->info.tenDaiLy, p->info.tenTinh,
               p->info.soDienThoai, p->info.soTien);
        p = p->next;
    }
}


/* ======================================================
   HAM HO TRO: GIAI PHONG TOAN BO DANH SACH (tranh ro ri bo nho)
   ====================================================== */
void giaiPhongDanhSach(struct Node **head)
{
    struct Node *p = *head;
    struct Node *temp;

    while (p != NULL)
    {
        temp = p;        // Luu lai nut hien tai
        p = p->next;      // Di chuyen p sang nut ke tiep
        free(temp);       // Giai phong nut da luu
    }

    *head = NULL; // Sau khi giai phong het, head tro ve NULL
}


/* ======================================================
   HAM MAIN: TAO DU LIEU MAU VA GOI CAC HAM TREN DE TEST
   ====================================================== */
int main()
{
    // head la con tro dau danh sach, ban dau danh sach rong
    struct Node *head = NULL;

    // Tao du lieu mau bang cach them cac nut vao cuoi danh sach
    themCuoi(&head, 1, "Dai ly A", "Can Tho", "0901111111", 5000000);
    themCuoi(&head, 2, "Dai ly B", "Vinh Long", "0902222222", 20000000);
    themCuoi(&head, 3, "Dai ly C", "Can Tho", "0903333333", 95000000);
    themCuoi(&head, 4, "Dai ly D", "Can Tho", "0904444444", 800000);
    themCuoi(&head, 5, "Dai ly E", "Ben Tre", "0905555555", 15000000);

    // In toan bo danh sach de kiem tra
    inDanhSach(head);

    // Cau b: In danh sach ma so dai ly o Can Tho
    inMaSoCanTho(head);

    // Cau c: Dem so luong dai ly co so tien tu 1.000.000 den 90.000.000
    int soLuong = demDaiLyTheoSoTien(head);
    printf("\nSo luong dai ly co so tien tu 1.000.000 den 90.000.000 la: %d\n", soLuong);

    // Giai phong bo nho da cap phat truoc khi ket thuc chuong trinh
    giaiPhongDanhSach(&head);

    return 0;
}