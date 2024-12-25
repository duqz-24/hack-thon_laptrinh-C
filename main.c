#include <stdio.h>
#include <stdbool.h>

int isPerfectNumber(int num) {
    int sum = 1; 
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

void nhapMang(int a[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang sau khi chen:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void chenPhanTu(int a[], int *n, int x, int viTri) {
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri chen khong hop le!\n");
        return;
    }

    for (int i = *n - 1; i >= viTri; i--) {
        a[i + 1] = a[i];
    }

    
    a[viTri] = x;
    (*n)++; 
}

int main(){
    // NHẬP VÀ IN RA SỐ PHẦN TỬ VÀ GIÁ TRỊ CỦA MẢNG
    int n, a[1000];
    printf("Nhap n : ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("Mang vua nhap : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    
    
    //KIỂM TRA SỐ HOÀN hảo
    printf("Các số hoàn hảo trong mảng:\n");
    for (int i = 0; i < n; i++) {
        if (isPerfectNumber(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
    //TÌM PHẦN TỬ CÓ GIÁ TRỊ LỚN THỨ 2
    int loop, largest, second;

   if(a[0] > a[1]) {
      largest = a[0];
      second  = a[1];
   }else {
      largest = a[1];
      second  = a[0];
   }

   printf("Chuong trinh tim phan tu lon nhat va lon thu hai cua mang:\n\n"); 
   for(loop = 2; loop < 10; loop++) {
      if( largest < a[loop] ) {
         second = largest;
         largest = a[loop];
      }else if( second < a[loop] ) {
         second =  a[loop];
      }
   }

   printf("Phan tu lon nhat: %d \nPhan tu lon thu hai: %d \n", largest, second);   
   // chèn
    int x, viTri;
    printf("Nhap phan tu can chen: ");
    scanf("%d", &x);
    printf("Nhap vi tri can chen (bat dau tu 0): ");
    scanf("%d", &viTri);

    chenPhanTu(a, &n, x, viTri);

    xuatMang(a, n);
    return 0;
}