# RC4 Decryption - decypt_nguyenhuutiep20224162
Nhap do dai cua so nguyen to p (L-bit, vi du: 512, 640, 1024): 1024

Simulation of Digital Signature Algorithm

Global public key components are:

P (1024 bits): 0xE0A67598CD1B763BC98C8ABB333E5DDA0CD3AA0E5E1FB5BA8A7B4EABC10BA338FAE06DD4B90FDA70D7CF0CB0C638BE3341BEC0AF8A7330A3307DED2299A0EE606DF035177A239C34A912C202AA5F83B9C4A7CF0235B5316BFC6EFB9A248411258B30B839AF172440F32563056CB67A861158DDD90E6A894C72A5BBEF9E286C6B

Q (160 bits): 0xE950511EAB424B9A19A2AEB4E159B7844C589C4F

G is: 0xD29D5121B0423C2769AB21843E5A3240FF19CACC792264E3BB6BE4F78EDD1B15C4DFF7F1D905431F0AB16790E1F773B5CE01C804E509066A9919F5195F4ABC58189FD9FF987389CB5BEDF21B4DAB4F8B76A055FFE2770988FE2EC2DE11AD92219F0B351869AC24DA3D7BA87011A701CE8EE7BFE49486ED4527B7186CA4610A75

Secret information:
X (private) is: 0xD0EC4E50BB290A42E9E355C73D8809345DE2E139
Y (public) is: 0x25282217F5730501DD8DBA3EDFCF349AAFFEC20921128D70FAC44110332201BBA3F10986140CBB97C726938060473C8EC97B4731DB004293B5E730363609DF9780F8D883D8C4D41DED6A2F1E1BBBDC979E1B9D6D3C940301F4E978D65B19041FCF1E8B518F5C0576C770FE5A7A485D8329EE2914A2DE1B5DA4A6128CEAB70F79
H (mdhash) is: 0xA9993E364706816ABA3E25717850C26C9CD0D89D

Generating digital signature:
DSA Signature Generated:
R is: 0x636155AC9A4633B4665D179F9E4117DF68601F34
S is: 0x6C540B02D9D4852F89DF8CFC99963204F4347704

Verifying digital signature:
DSA Signature Verification Result: Valid

Success: Digital signature is verified!
R = 0x636155AC9A4633B4665D179F9E4117DF68601F34

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
| Ký hiệu | Ý nghĩa | Vai trò thực tế |
| :--- | :--- | :--- |
| **L** | Key Length | Độ dài bit của số nguyên tố lớn $P$ (ví dụ: 1024, 2048, 3072). |
| **N** | Sub-group Order | Độ dài bit của số nguyên tố nhỏ $Q$. |
| **P** | Modulus | Số nguyên tố lớn dùng làm nền cho các phép toán modulo. |
| **Q** | Divisor | Số nguyên tố nhỏ, là một ước số của $(P-1)$. |
| **G** | Generator | Phần tử sinh của nhóm con bậc $Q$ modulo $P$. |
| **Seed** | Random Seed | Giá trị ngẫu nhiên dùng để khởi tạo quá trình tìm $P, Q$ một cách minh bạch. |
| **Counter** | Iteration Count | Số lần thuật toán phải lặp lại để tìm được số nguyên tố $P$ phù hợp. |

| Ciphertext (hex)                                                                                             | Key    | Plaintext                                   |
|--------------------------------------------------------------------------------------------------------------|--------|---------------------------------------------|
| 8f 63 b8 d5 61 e9 53 ae bc 72 ea 20 fa 28 3f 3c 32 71 aa 31 5e 55 f7 13 dd 99 a9 9d 2 6e db fd 9e 6d a5 9c ba 19 2e a bc 52 | DHBK   | Hanoi University of Science and Technology  |
| 5d 6c db f7 9a 59 1e c2 5c ee 3e 7f 0b                                                                       | SecretKey | nguyenhuutiep                              |

> **Lưu ý:** Ciphertext nhập vào là các byte hex, cách nhau bằng dấu cách.

--------------------------------------------------------------
📊 DSA Test Vectors DataDữ liệu dưới đây trích xuất từ quá trình mô phỏng thuật toán DSA với các cấu hình bảo mật khác nhau theo tiêu chuẩn NIST.🔑 Chú thích các thông số (Legend)Ký hiệuÝ nghĩa thực tếL / NĐộ dài bit của số nguyên tố $P$ và $Q$.P / QCác số nguyên tố làm tham số miền (Domain Parameters).GGenerator (Phần tử sinh).X / YKhóa bí mật (Private Key) và Khóa công khai (Public Key).KSố ngẫu nhiên dùng riêng cho mỗi bản tin.R, SCặp giá trị tạo nên chữ ký số.VGiá trị tính toán để đối sánh với $R$ khi xác thực.🔹 1. Cấu hình: L = 1024, N = 160🛠 Domain Parameter GenerationSeed: ED8BEE8D 1CB89229 D2903CBF 0E51EE73 77F48698Q: E950511E AB424B9A 19A2AEB4 E159B784 4C589C4FP (Found at counter 5):PlaintextE0A67598 CD1B763B C98C8ABB 333E5DDA 0CD3AA0E 5E1FB5BA 8A7B4EAB C10BA338
FAE06DD4 B90FDA70 D7CF0CB0 C638BE33 41BEC0AF 8A7330A3 307DED22 99A0EE60
6DF03517 7A239C34 A912C202 AA5F83B9 C4A7CF02 35B5316B FC6EFB9A 24841125
8B30B839 AF172440 F3256305 6CB67A86 1158DDD9 0E6A894C 72A5BBEF 9E286C6B
G (Generator):PlaintextD29D5121 B0423C27 69AB2184 3E5A3240 FF19CACC 792264E3 BB6BE4F7 8EDD1B15
C4DFF7F1 D905431F 0AB16790 E1F773B5 CE01C804 E509066A 9919F519 5F4ABC58
189FD9FF 987389CB 5BEDF21B 4DAB4F8B 76A055FF E2770988 FE2EC2DE 11AD9221
9F0B3518 69AC24DA 3D7BA870 11A701CE 8EE7BFE4 9486ED45 27B7186C A4610A75
🔑 Key Pair GenerationPrivate Key (X): D0EC4E50 BB290A42 E9E355C7 3D880934 5DE2E139Public Key (Y):Plaintext25282217 F5730501 DD8DBA3E DFCF349A AFFEC209 21128D70 FAC44110 332201BB
A3F10986 140CBB97 C7269380 60473C8E C97B4731 DB004293 B5E73036 3609DF97
80F8D883 D8C4D41D ED6A2F1E 1BBBDC97 9E1B9D6D 3C940301 F4E978D6 5B19041F
CF1E8B51 8F5C0576 C770FE5A 7A485D83 29EE2914 A2DE1B5D A4A6128C EAB70F79
🖋 Signature (Message: "abc")R: 636155AC 9A4633B4 665D179F 9E4117DF 68601F34S: 6C540B02 D9D4852F 89DF8CFC 99963204 F4347704Status: ✅ Signature is verified🔹 2. Cấu hình: L = 2048, N = 224🛠 Domain Parameter GenerationSeed: 5AFCC1EF FC079A9C CA6ECA86 D6E3CC3B...Q: 90EAF4D1 AF0708B1 B612FF35 E0A2997E B9E9D263 C9CE6595 28945C0DP (Found at counter 21):PlaintextC196BA05 AC29E1F9 C3C72D56 DFFC6154 A033F147 7AC88EC3 7F09BE6C 5BB95F51
C296DD20 D1A28A06 7CCC4D43 16A4BD1D CA55ED10 66D438C3 5AEBAABF 57E7DAE4
28782A95 ECA1C143 DB701FD4 8533A3C1 8F0FE235 57EA7AE6 19ECACC7 E0B51652
A8776D02 A425567D ED36EABD 90CA33A1 E8D988F0 BBB92D02 D1D20290 113BB562
CE1FC856 EEB7CDD9 2D33EEA6 F410859B 179E7E78 9A8F75F6 45FAE2E1 36D252BF
FAFF8952 8945C1AB E705A38D BC2D364A ADE99BE0 D0AAD82E 53201214 96DC65B3
930E3804 7294FF87 7831A16D 5228418D E8AB275D 7D75651C EFED65F7 8AFC3EA7
FE4D79B3 5F62A040 2A111759 9ADAC7B2 69A59F35 3CF450E6 982D3B17 02D9CA83
🖋 Signature (Message: "abc")R: 4400138D 05F9639C AF54A583 CAAF25D2 B76D0C3E AD752CE1 7DBC85FES: 874D4F12 CB13B617 32D39844 5698CFA9 D92381D9 38AA57EE 2C9327B3Status: ✅ Signature is verified🔹 3. Cấu hình: L = 2048, N = 256🛠 Domain Parameter GenerationSeed: 47830819 72865EA9 5D43318A B2EAF9C6...Q: C24ED361 870B61E0 D367F008 F99F8A1F 75525889 C89DB1B6 73C45AF5 867CB467P (Found at counter 12): (Dữ liệu số lớn tương tự cấu hình trên)🖋 Signature (Message: "abc")R: 315C875D CD4850E9 48B8AC42 824E9483 A32D5BA5 ABE0681B 9B9448D4 44F2BE3C1234567891011S: 89718D12 E54A8D9E D066E4A5 5F7ED5A2 229CD23B 9A3CEE78 F83ED6AA 61F6BCB9Status: ✅ Signature is verified1213141516171819202122🔹 4. Cấu hình: L = 3072, N = 2562324252627282930313233🛠 Domain Pa34rameter Generation35363738394041424344Q: CFA0478A 54717B08 CE64805B 76E5B142 49A77A48 38469DF7 F7DC987E FCCFB11DP (Found at counter 20)45:46474849505152Plaintext90066455 B5CFC38F 9CAA4A48 B4281F29 2C260FEE F01FD610 37E56258 A7795A1C
7AD46076 982CE6BB 956936C6 AB4DCFE0 5E678458 6940CA54 4B9B2140 E1EB523F
009D20A7 E7880E4E 5BFA690F 1B9004A2 7811CD99 04AF7042 0EEFD6EA 11EF7DA1
29F58835 FF56B89F AA637BC9 AC2EFAAB 90340222 9F491D8D 3485261C D068699B
6BA58A1D DBBEF6DB 51E8FE34 E8A78E54 2D7BA351 C21EA8D8 F1D29F5D 5D159394
87E27F44 16B0CA63 2C59EFD1 B1EB6651 1A5A0FBF 615B766C 5862D0BD 8A3FE7A0
E0DA0FB2 FE1FCB19 E8F9996A 8EA0FCCD E5381752 38FC8B0E E6F29AF7 F642773E
BE8CD540 2415A014 51A84047 6B2FCEB0 E388D30D 4B376C37 FE401C2A 2C2F941D
AD179C54 0C1C8CE0 30D460C4 D983BE9A B0B20F69 144C1AE1 3F9383EA 1C08504F
B0BF3215 03EFE434 88310DD8 DC77EC5B 8349B8BF E97C2C56 0EA878DE 87C11E3D
597F1FEA 742D73EE C7F37BE4 3949EF1A 0D15C3F3 E3FC0A83 35617055 AC91328E
C22B50FC 15B941D3 D1624CD8 8BC25F3E 941FDDC6 20068958 1BFEC416 B4B2CB73
🖋 Signature (Message: "abc")R: 5F184E64 5A38BE8F B4A6871B 6503A9D1 2924C7AB E04B7141 0066C2EC A6E3BE3ES: 91EB0C7B A3D4B9B6 0B825C3D 9F2CADA8 A2C9D772 3267B033 CBCDCF88 03DB9C18Status: ✅ Signature is verified

## Liên hệ

- Tác giả: tiep5027-design
- Link repo: [https://github.com/tiep5027-design/decypt_nguyenhuutiep20224162](https://github.com/tiep5027-design/decypt_nguyenhuutiep20224162)
