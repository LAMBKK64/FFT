## Giới thiệu:
Đây là thuật toán lập trình C cho công cụ FFT. FFT là công cụ được sử dụng rộng rãi trong xử lý số tín hiệu để chuyển cách biểu diễn tín hiệu và hệ thống rời rạc sang miền tần số rời rạc.
## Các bước tiến hành:
## Sơ đồ khối

## Thuật toán
**Input**
- Tín hiệu đầu vào x[n].
- Chu kỳ N.
  
**Thực hiện**
-	So sánh giá trị N với 4.
-	Chia nhỏ dãy đầu vào ban đầu thành 4 dãy con.
-	Dùng công cụ truyền thống tính DFT cho từng dãy con.

**Output**
- Tín hiệu đầu ra X[k].

## Đánh giá:
-	Khi sử dụng code C ta thu được kết quả tương tự khi sử dụng hàm có sẵn trên Matlab.



