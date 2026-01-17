# RC4 Decryption - decypt_nguyenhuutiep20224162

## Giới thiệu
Đây là project giải mã chuỗi sử dụng thuật toán RC4 viết bằng C++. Chương trình cho phép người dùng nhập ciphertext dạng hex và key từ bàn phím, sau đó xuất ra plaintext gốc.

---

## Hướng dẫn chạy chương trình

### Biên dịch chương trình giải mã
```sh
g++ -o rc4_decrypt main.cpp rc4_decrypt.h rc4_ksa.h rc4_prga.h
```

### Chạy chương trình giải mã
```sh
./rc4_decrypt
```
Hoặc trên Windows:
```sh
rc4_decrypt.exe
```

- Nhập **ciphertext** dạng hex khi được yêu cầu (ví dụ: `8f 63 b8 d5 61 e9 53 ae ...`)
- Nhập **key** khi được yêu cầu (ví dụ: `DHBK`)
- Kết quả sẽ là plaintext gốc.

---

## Bộ test vector
Ký hiệuÝ nghĩaVai tròLKey LengthĐộ dài bit của số nguyên tố lớn $P$ (ví dụ: 1024, 2048, 3072).NSub-group OrderĐộ dài bit của số nguyên tố nhỏ $Q$.PModulusSố nguyên tố lớn dùng làm nền cho các phép toán modulo.QDivisorSố nguyên tố nhỏ, là một ước số của $(P-1)$.GGeneratorPhần tử sinh của nhóm con bậc $Q$ modulo $P$.SeedRandom SeedGiá trị ngẫu nhiên dùng để khởi tạo quá trình tìm $P, Q$.CounterIteration CountSố lần thử nghiệm để tìm được số nguyên tố $P$ đạt chuẩn.

| Ciphertext (hex)                                                                                             | Key    | Plaintext                                   |
|--------------------------------------------------------------------------------------------------------------|--------|---------------------------------------------|
| 8f 63 b8 d5 61 e9 53 ae bc 72 ea 20 fa 28 3f 3c 32 71 aa 31 5e 55 f7 13 dd 99 a9 9d 2 6e db fd 9e 6d a5 9c ba 19 2e a bc 52 | DHBK   | Hanoi University of Science and Technology  |
| 5d 6c db f7 9a 59 1e c2 5c ee 3e 7f 0b                                                                       | SecretKey | nguyenhuutiep                              |

> **Lưu ý:** Ciphertext nhập vào là các byte hex, cách nhau bằng dấu cách.

---

## Liên hệ

- Tác giả: tiep5027-design
- Link repo: [https://github.com/tiep5027-design/decypt_nguyenhuutiep20224162](https://github.com/tiep5027-design/decypt_nguyenhuutiep20224162)
