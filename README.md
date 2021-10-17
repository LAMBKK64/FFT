## Giới thiệu:
Đây là thuật toán lập trình C cho công cụ FFT. FFT là công cụ được sử dụng rộng rãi trong xử lý số tín hiệu để chuyển cách biểu diễn tín hiệu và hệ thống rời rạc sang miền tần số rời rạc.
## Các bước tiến hành:
## Sơ đồ khối
![bc3](https://user-images.githubusercontent.com/92636271/137636463-c0e9d5f9-decd-4fdd-ac9f-cb4b98565d9a.png)

## Thuật toán
**Input**
- Tín hiệu đầu vào x[n].
- Chu kỳ N.
  
**Thực hiện**
-	So sánh giá trị N với 4.
-	Chia nhỏ dãy đầu vào ban đầu thành 4 dãy con.
-	Dùng công cụ truyền thống tính DFT cho từng dãy con.

![bc4](https://user-images.githubusercontent.com/92636271/137636774-95252f02-c440-4a2d-ae9b-eb2202498943.PNG)

**Output**
- Tín hiệu đầu ra X[k].

## Đánh giá:
-	Khi sử dụng code C ta thu được kết quả tương tự khi sử dụng hàm có sẵn trên Matlab.

*Kết quả khi sử dụng lập trình trên C:*
![bc1](https://user-images.githubusercontent.com/92636271/137636886-66e60bab-5baf-4ae9-82f0-d863a1e6f944.PNG)

*Kết quả khi sử dụng Matlab:*

![bc2](https://user-images.githubusercontent.com/92636271/137636948-b18ab686-00f4-4c81-ae12-89085cc3a71b.PNG)
- Số lượng phép toán cần thực hiện ít hơn 4 lần so với DFT nhưng còn lớn hơn nhiều so với hàm có sẵn trên Matlab:
- 
![bc5](https://user-images.githubusercontent.com/92636271/137638094-7c3caf93-f949-4fa9-9bdf-a20f5eec89e0.PNG)


