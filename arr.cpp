#include <iostream>
#include <vector>
#include <algorithm>
// Hàm kiểm tra một số có phải là số hoàn hảo hay không
bool isPerfectNumber(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm kiểm tra 3 số liền kề có lập thành cấp số cộng hay không
bool isArithmeticProgression(int arr[], int startIndex) {
    if (startIndex + 2 >= sizeof(arr) / sizeof(arr[0])) {
        return false; // Không có đủ 3 số để so sánh.
    }

    return (arr[startIndex + 1] - arr[startIndex] == arr[startIndex + 2] - arr[startIndex + 1]);
}

// Hàm tính trung bình cộng các số lẻ dương, không chia hết cho 3
double averageOfOddNumbersNotDivisibleBy3(int arr[], int size) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 1 && arr[i] % 3 != 0) {
            count++;
            sum += arr[i];
        }
    }

    if (count == 0) {
        return 0.0; // Tránh chia cho 0.
    }

    return static_cast<double>(sum) / count;
}

// Hàm sắp xếp các số trong khoảng [a, b] theo chiều tăng dần
std::vector<int> sortInRange(int arr[], int a, int b) {
    int size = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> sortedArray;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            sortedArray.push_back(arr[i]);
        }
    }

    std::sort(sortedArray.begin(), sortedArray.end()); // Sắp xếp mảng mới

    return sortedArray;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    int arr[100];
    int size = 0;

    while (true) {
        std::cout << "\nMENU:" << std::endl;
        std::cout << "1. Nhap mang" << std::endl;
        std::cout << "2. Tao danh sach so tu dong" << std::endl;
        std::cout << "3. Them mot phan tu vao mang" << std::endl;
        std::cout << "4. Dem so hoan hao va kiem tra tinh chan le" << std::endl;
        std::cout << "5. Kiem tra cap so cong" << std::endl;
        std::cout << "6. Tinh trung binh cong cac so le khong chia het cho 3" << std::endl;
        std::cout << "7. Sap xep cac so trong khoang [a, b]" << std::endl;
        std::cout << "8. Xuat mang" << std::endl;
        std::cout << "0. Thoat" << std::endl;

        int choice;
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Nhap so luong so: ";
            std::cin >> size;
            std::cout << "Nhap " << size << " so: ";
            for (int i = 0; i < size; i++) {
                std::cin >> arr[i];
            }

        }
        else if (choice == 2) {
            std::cout << "Nhap so luong so tu dong: ";
            std::cin >> size;
            // Tạo danh sách số ngẫu nhiên
            for (int i = 0; i < size; i++) {
                arr[i] = rand() % 100 + 1;
            }
            std::cout << "Danh sach so da duoc tao." << std::endl;

        }
        else if (choice == 3) {
            if (size < 100) {
                int element;
                int position;
                std::cout << "Nhap phan tu can them: ";
                std::cin >> element;
                std::cout << "Nhap vi tri them (0 <= vi tri < " << size + 1 << "): ";
                std::cin >> position;
                if (position >= 0 && position <= size) {
                    for (int i = size; i > position; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position] = element;
                    size++;
                    std::cout << "Phan tu da duoc them vao mang." << std::endl;
                } else {
                    std::cout << "Vi tri khong hop le." << std::endl;
                }
            } else {
                std::cout << "Danh sach da day, khong the them phan tu moi." << std::endl;
            }

        }
        else if (choice == 4) {
            int perfectCount = 0;
            int evenCount = 0;
            int oddCount = 0;

            for (int i = 0; i < size; i++) {
                if (isPerfectNumber(arr[i])) {
                    perfectCount++;
                }
                if (arr[i] % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
            }

            std::cout << "So hoan hao: " << perfectCount << std::endl;
            std::cout << "So luong cac so chan: " << evenCount << std::endl;
            std::cout << "So luong cac so le: " << oddCount << std::endl;

        }
        else if (choice == 5) {
            for (int i = 0; i < size - 2; i++) {
                if (isArithmeticProgression(arr, i)) {
                    std::cout << "Cap so cong tai vi tri " << i << ": " << arr[i] << ", " << arr[i + 1] << ", " << arr[i + 2] << std::endl;
                }
            }

        }
        else if (choice == 6) {
            double averageOddNotDivisibleBy3 = averageOfOddNumbersNotDivisibleBy3(arr, size);
            std::cout << "Trung binh cong cac so le duong khong chia het cho 3: " << averageOddNotDivisibleBy3 << std::endl;

        }
        else if (choice == 7) {
        int a, b;
        std::cout << "Nhập a: ";
        std::cin >> a;
        std::cout << "Nhập b: ";
        std::cin >> b;

        // Sắp xếp và lấy mảng mới
        std::vector<int> sortedArray = sortInRange(arr, a, b);

        std::cout << "Mang sau khi sap xep trong khoang [" << a << ", " << b << "]: ";
        for (int i = 0; i < sortedArray.size(); i++) {
            std::cout << sortedArray[i] << " ";
        }
        std::cout << std::endl;
    }
        else if(choice==8)
        {
            std::cout << "Cac phan tu cua mang la: ";
            printArray(arr, size);
        }
         else if (choice == 0) {
            break;

        } else {
            std::cout << "Lua chon khong hop le Vui long chon lai." << std::endl;
        }
    }

    return 0;
}
