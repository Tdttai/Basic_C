# Buổi 1
## Biến

Biến trong ngôn ngữ C là một phần của bộ nhớ  được sử đụng để lưu trữ dữ liệu, một biến bao gồm 3 thành phần sau:
- Kiểu dữ liệu: Xác định kiểu dữ liệu của biến và  xác định bộ nhớ mà biến đó sử dụng
- Tên biến: là tên của biến do người lập trình đặt, thường là những tên có nghĩa, biểu hiện một giá trị nhất định.
- Giá trị: Có thể là số hoặc ký tự.

Cú pháp để khai báo biến:

> <Kiểu dữ liệu> <Tên biến> = < Giá trị của biến>;
> <Kiểu dữ liệu> <Tên biến>;

Ví dụ khai báo một biến: 
```c 
int tuoi = 1;
char ten = Nam;
```

### Kiểu dữ liệu trong C:
#### 1.Char :

Một giá trị kiểu ` char `  chiếm 1byte dữ liệu = 8bit và được biển diễn thông qua bảng mã `ASCII`

Char được phân biệt ra 2 loại : `char` và `Unsigned char`
| Kiểu  |  Số ký tự |Kích thước|Phạm vi biểu diễn|Định dạng|
|:---:|:---:|:---:|:---:|:---:|
| Char (Signed char)  | 256  |1 byte |  -128 đến 127 |  %c |
|  Unsigned char | 256  |1 byte | 0 đến 255  |  %c |

***Cách tính phạm vi biểu diễn:***

- Char  = 1 byte = 8 bit $=>$ $2^4$ ... $2^4$-1 $=>$  -128 ... 127
- Unsigned char = 1 byte = 8 bit = $2^8$ = 256  $=>$  0 ... 255

Example:
```C
#include <stdio.h>
unsigned char var = 65;
int main(){

    printf("size : %dbyte\n ", sizeof(var));

    printf("ky tu :%c\n",var);
    var+=1;
    printf("ky tu :%c\n",var);
    
    return 0;
}
```
- `#include <stdio.h>` dùng để sử dụng các chức năng nhập, xuất trong ngôn ngữ C.
- `unsigned char var = 65;` khai báo biến var là kiểu ký tự có giá trị là 65 (giá trị nằm trong phạm vi biểu diễn 0->255).
- `int main()` hàm chính thực hiện các lệnh trong chương trình.
- `printf("size : %d\n byte", sizeof(var));` dùng để đọc kích thước của biến var.
- `printf("ky tu :%c\n",var);` xuất ký tự trong bảng mã ASCII.( kq : A ).
- `var+=100;` giá trị var thay đổi thành 66
- `printf("ky tu :%c\n",var);`  Xuất ký tự trong bảng mã ASCII ( kq : B).

#### 2.Interger(Kiểu số nguyên):

Trong ngôn ngữ C cho phép sử dụng số nguyên kiểu int, số nguyên dài kiểu long và số nguyên không dấu kiểu unsigned có kích thước khác nhau.


|  Kiểu | Kích thước  | Phạm vi biểu diễn  | Định dạng  |
|:---:|:---:|:---:|:---:|
| int  |  2->4 byte | -2^15 đến 2^15-1 -> -2^31 đến 2^31-1  | %d, %i  |
|  short int |  2 byte | 2^15 đến 2^15-1  |  %hd |
| long int  |  4->8 byte |  -2^31 đến 2^31-1 -> -2^63 đến 2^63-1 | 	%ld, %li  |
| long long int  |  8 byte |  	-2^63 đến 2^63-1 | %lld, %lli  |
|  Unsigned int |  2->4 byte |  	0 đến 2^16-1 -> 0 đến 2^32-1 | %u  |
| Unsigned long int  |  4 byte   |  	0 đến 2^32-1 | %lu  |
| Unsigned long long int  | 8 byte  | 	0 đến 2^64-1  | 	%llu  |

#### 3.float & double: 
Đây là kiểu số thực, dùng để chứa những số có dấu phẩy động

```C
    float salary;
    double price;
```

Trong C, số dấu phẩy động cũng có thể được biểu diễn theo cấp số nhân

```C
float normalizationFactor = 22.442e2;
```

***Sự khác biệt giữa float và double***


- float có kích thước 4 bytes
- double có kích thước 8 bytes

#### 4.Các kiểu dữ liệu trong thư viện stdint.h

- Các kiểu số nguyên (char, int…) tùy mỗi trình biên dịch mà nó có thể là số có dấu (signed char, signed int) hoặc không dấu (unsigned char, unsigned int), điều này ảnh hưởng đến phạm vi giá trị có thể được lưu trữ. 
- Kích thước của biến, trong một số hệ thống máy tính cũ, hoặc trên Arduino Uno…, thì kích thước kiểu int chỉ có 2 byte thay vì 4 byte. 

- Vậy, khi chuyển đổi code C/C++ từ nền tảng này sang nền tảng khác, hoặc từ môi trường phát triển IDE này sang IDE khác thì người phát triển không chỉ phải chú ý đến kích cỡ dữ liệu mà còn phải hiểu IDE đó cấu hình kiểu dữ liệu như thế nào. 

Để giải quyết vấn đề trên, một giải pháp đơn giảng là có thể sử dụng thư viện **stdint.h**

| Kiểu dữ liệu C  | Kiểu dữ liệu stdint.h  | Kích thước  |  Signed  |  Phạm vi biểu diễn |
|:---:|:---:|:---:|:---:|:---:|
| char  |  uint8_t |  8 | Unsigned  | 0 .. 255  |
|  signed char | int8_t  | 8  | Signed  | -128 .. 127  |
|  unsigned short |  uint16_t | 16  | Unsigned  | 0 .. 65,535  |
|  short | int16_t  |  16 | Signed  | -32,768 .. 32,767  |
|  unsigned int | uint32_t  |  32 | UNsigned  |0 .. 4,294,967,295   |
| int  | int32_t  | 32	  | Signed  |  -2,147,483,648 .. 2,147,483,647 |
|  unsigned long long | uint64_t  | 64  | Unsigned  | 0 .. 18,446,744,073,709,551,615  |
| long long  | int64_t  | 64  | Signed  | -9,223,372,036,854,775,808 .. 9,223,372,036,854,775,807  |

## Hàm

### 1. Hàm là gì:

\- Một hàm là một nhóm các câu lệnh cùng nhau thực hiện một nhiệm vụ. Mỗi chương trình C có ít nhất một hàm, là hàm main().

\- Một khai báo hàm cho trình biên dịch biết về tên, kiểu trả về và các tham số của hàm. Định nghĩa hàm cung cấp phần thân thực của hàm.

### 2.Cấu trúc của một định nghĩa hàm:

```c
return_type function_name(parameter list) {
    // body of the function
}
```
 - ***Kiểu trả về ( Return type)**: Một hàm có thể trả về một giá trị.Các `return type` là kiểu dữ liệu của giá trị hàm trả về. Một số hàm thực hiện các hoạt động mong muốn mà không trả về một giá trị. Trong trường hợp này, `return type` là từ khóa **void**.
 - ***Tên hàm***: Đây là tên thực của hàm. Thường được đặt theo chức năng của hàm.
 - ***Tham số***: Một tham số giống như một trình giữ chỗ. Khi một hàm được gọi, bạn chuyển một giá trị cho tham số. Giá trị này được gọi là tham số hoặc đối số thực tế. Danh sách tham số tham chiếu đến loại, thứ tự và số tham số của hàm. Các tham số là tùy chọn; có nghĩa là, một hàm có thể không chứa tham số.
 - ***Thân hàm***: Phần thân hàm chứa một tập hợp các câu lệnh xác định chức năng của hàm.

**Example**

`Hàm PrintUserName có chức năng là in tên từ một mảng`
```C
 void PrintUserName(char* name)
 {
    printf("Hello My name is %s", name;)
 }
 int main() {
    char* name = "Alice";
    PrintUserName(name);
    return 0;
}
```
`Hàm Sumof trả về giá trị tổng của hai biến`
```C
uint8_t Sumof(uint8_t a,uint8_t b)
{
    return a + b;
}
 int main() {
uint8_t a =2, b=5;
 printf("tổng của a và b là %d ", Sumof(a,b));

 }
```