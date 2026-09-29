# Mô Phỏng Hệ Thống Hàng Đợi (Queueing System Simulation)

Dự án này bao gồm các chương trình viết bằng ngôn ngữ C dùng để mô phỏng và phân tích hiệu suất của các hệ thống hàng đợi khác nhau bằng phương pháp Monte Carlo. Hệ thống cung cấp cái nhìn thực tế về cách các cấu trúc hàng đợi hoạt động, từ đó hỗ trợ tối ưu hóa quá trình phục vụ.

## Các thành phần chính

### 1. `backendSim.c` (Mô phỏng cơ bản)
Chương trình mô phỏng tự động cho các mô hình hàng đợi chuẩn bao gồm: **M/M/1, M/G/1, M/M/2, và M/G/2**.
* **Đầu ra (Output):** In ra màn hình console và lưu kết quả vào file `results_full.csv` (được tự động tạo).
* **Các chỉ số được tính toán:**
  * `Wq`: Thời gian chờ trung bình trong hàng đợi.
  * `W`: Tổng thời gian trung bình trong hệ thống (chờ + phục vụ).
  * `Lq`: Số lượng khách hàng chờ trung bình (độ dài hàng đợi).
  * `L`: Số lượng khách hàng trung bình trong hệ thống.
  * `Rho`: Hiệu suất sử dụng quầy phục vụ (tỷ lệ bận).

### 2. `Bank_Market_Simulator.c` (Mô phỏng tương tác nâng cao)
Phiên bản mô phỏng toàn diện với giao diện dòng lệnh (CLI), cho phép người dùng tùy chỉnh số liệu linh hoạt (số khách hàng, thời gian kiên nhẫn, tốc độ đến, phân phối phục vụ...).
* **Kiến trúc mô phỏng:**
  * **Hệ thống Ngân hàng (Bank - Single Queue):** Một hàng đợi chung cho nhiều quầy. Quầy nào trống trước sẽ gọi khách hàng tiếp theo.
  * **Hệ thống Siêu thị (Supermarket - Multiple Queues):** Mỗi quầy có một hàng đợi độc lập, khách hàng chọn ngẫu nhiên một hàng để xếp.
* **Tính năng nổi bật:** Đo lường tỷ lệ khách hàng bỏ cuộc (Renege) khi thời gian chờ vượt quá giới hạn kiên nhẫn cho phép. Hỗ trợ phân phối thời gian phục vụ theo quy luật Mũ (Exponential) và Log-Chuẩn (Log-Normal).

## Hướng dẫn cài đặt và sử dụng

### Yêu cầu
* Trình biên dịch C như GCC (ví dụ: MinGW-w64 trên Windows).

### Biên dịch và khởi chạy

**Đối với `backendSim.c`:**
```powershell
gcc backendSim.c -o backendSim
.\backendSim.exe
```

**Đối với `Bank_Market_Simulator.c`:**
```powershell
gcc Bank_Market_Simulator.c -o Bank_Market_Simulator
.\Bank_Market_Simulator.exe
```
Sau khi khởi chạy chương trình `Bank_Market_Simulator`, hệ thống sẽ yêu cầu bạn nhập các thông số đầu vào để tiến hành mô phỏng và so sánh kết quả.
