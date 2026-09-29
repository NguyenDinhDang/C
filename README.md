# Hành trình Khám phá và Chinh phục Ngôn ngữ C 🚀

Chào mừng bạn đến với không gian lưu trữ mã nguồn C của tôi! Đây không chỉ là một repository, mà là một cuốn nhật ký ghi lại toàn bộ hành trình tôi học tập, rèn luyện và áp dụng ngôn ngữ C - từ những dòng code chập chững đầu tiên cho đến khi xây dựng các ứng dụng mô phỏng tính toán phức tạp.

## 🗺️ Bản đồ Hành trình (Cấu trúc Repository)

Toàn bộ codebase này được chia thành 3 chặng đường chính, phản ánh quá trình phát triển kỹ năng của tôi:

### 🎒 Chặng 1: Nền tảng Kỹ thuật Lập trình (Thư mục `TITV`)
Đây là nơi bắt đầu mọi thứ. Thư mục này lưu giữ những bài học đầu tiên về cú pháp, biến, vòng lặp và tư duy cấu trúc.
- **`80_TITV_struct.c`**: Nơi tôi làm quen với kiểu dữ liệu tự định nghĩa (`struct`) – nền tảng để quản lý dữ liệu đối tượng phức tạp sau này.
- **`testKTLT.c`**: Các bài kiểm tra và bài tập thực hành môn Kỹ thuật Lập trình (KTLT), giúp củng cố logic lập trình cơ bản.

### 🧠 Chặng 2: Cấu trúc Dữ liệu & Thuật toán - Cốt lõi của Lập trình (Thư mục `DSA-Data Structures and Algorithms`)
Sau khi nắm vững cơ bản, tôi dấn thân vào thế giới của DSA. Việc tự tay cài đặt các cấu trúc dữ liệu từ con số không (from scratch) bằng C đã giúp tôi hiểu sâu sắc về cách bộ nhớ hoạt động (pointers, dynamic memory allocation).
- **Cấu trúc dữ liệu tự xây dựng:** `Link List` (Singly, Doubly, Circular), `Stack`, `Queue`, `Tree`, `HashTable`... Tất cả đều được thao tác thủ công qua từng dòng `malloc` và `free`.
- **Thuật toán cốt lõi:** Các bài toán về sắp xếp (`Sort`), đệ quy (`DeQuy.c`), và đặc biệt là Quy hoạch động/Tham lam (`Dynamic Programing` - điển hình là bài toán cái túi Knapsack/Balo).
- **Luyện tập Olympic:** Thư mục con `Olympic` là sàn đấu nơi tôi rèn luyện tư duy giải quyết vấn đề (problem-solving) và tối ưu độ phức tạp thuật toán thông qua các bài tập thi đấu (fibonaci, kiểm tra số nguyên tố, xử lý chuỗi...).

### 🔬 Chặng 3: Áp dụng Thực tế - Hệ thống Mô phỏng (Thư mục gốc)
Trái ngọt của quá trình rèn luyện thuật toán là khả năng áp dụng C vào giải quyết bài toán thực tiễn. Tôi đã vận dụng sức mạnh xử lý tốc độ cao của C để xây dựng các chương trình mô phỏng lý thuyết hàng đợi (Queueing Theory) thông qua phương pháp Monte Carlo.
- **`backendSim.c`**: Mô phỏng cơ sở các mô hình toán học M/M/1, M/G/1, M/M/2, M/G/2 để phân tích thời gian chờ, độ dài hàng đợi và hiệu suất hệ thống.
- **`Bank_Market_Simulator.c`**: Ứng dụng mô phỏng nâng cao với tương tác dòng lệnh (CLI). Chương trình giả lập hàng chục ngàn khách hàng để so sánh trực tiếp hiệu năng giữa kiến trúc một hàng đợi (Ngân hàng) và nhiều hàng đợi (Siêu thị), đồng thời đo lường cả tỷ lệ khách bỏ cuộc (renege) do đợi quá lâu.

## 💡 Bài học và Trải nghiệm của tôi

- **Nghệ thuật Quản lý bộ nhớ:** Code C đồng nghĩa với việc bạn là "người làm chủ" bộ nhớ. Những lỗi `Segmentation Fault` từng là nỗi ám ảnh, nhưng nhờ việc "cày ải" các bài tập `Link List` và `Tree`, tôi đã thực sự làm bạn được với con trỏ (pointers).
- **Tư duy Tối ưu hóa:** Giải các bài tập trong phần `Olympic` rèn cho tôi thói quen luôn đánh giá: *Thuật toán này tốn bao nhiêu thời gian (O)? Khai báo biến này có tốn thêm dung lượng không?*
- **Sức mạnh nguyên thủy của C:** Khi chạy mô phỏng hàng đợi với vòng lặp hàng trăm ngàn lượt Monte Carlo, tốc độ thực thi (runtime execution) của C thực sự tỏa sáng, cho thấy lý do vì sao C vẫn là vua của các hệ thống cần hiệu năng cao.

## 🛠️ Hướng dẫn trải nghiệm cùng tôi

Nếu bạn muốn chạy thử và "nghía" qua các dòng code trong hành trình này, chỉ cần một trình biên dịch C (như GCC / MinGW trên Windows) và làm theo các bước sau:

```powershell
# 1. Clone hành trình này về máy của bạn
git clone https://github.com/NguyenDinhDang/C.git
cd C

# 2. Khám phá một thuật toán (ví dụ Danh sách liên kết đôi)
gcc "DSA-Data Structures and Algorithms/Link List/doubly_full.c" -o doubly
.\doubly.exe

# 3. Trải nghiệm chương trình mô phỏng Siêu thị/Ngân hàng
gcc Bank_Market_Simulator.c -o Bank_Market_Simulator
.\Bank_Market_Simulator.exe
```

Hy vọng bạn sẽ tìm thấy một chút cảm hứng, một thuật toán hữu ích hay đơn giản là sự đồng điệu trong quá trình học tập. Cứ tự do khám phá, chỉnh sửa và phá vỡ (break) code để học hỏi thêm nhé!
