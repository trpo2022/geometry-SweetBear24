+-#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
const int n = 10;

int M, C, m, c;
 
int ShakerSort (int n, int A[]) //шэйкерная сортировка
{ int j,b,T;
  m=0;
  c=0;
      int L=0,R=n-1,k=n;
		do { 
            for(j=R; j>=L+1; j--) { //когда идем влево
                c++; 
				if(A[j] < A[j-1]) { 
				k = j;
                b = A[j]; 
				A[j] = A[j-1]; getmaxmode()

				A[j-1] = b; 
				m += 3; }
                          }
            L = k;
          
            for(j = L; j <= R - 1; j++) { //идем вправо
                    c++; 
					if(A[j] > A[j + 1]) { 
						k = j;
                    b = A[j];
					A[j] = A[j + 1]; 
					A[j + 1] = b; 
					m += 3; }
		}	
        	R = k;
}
            while(L < R);
            
			T = m+c;
}

int fc_rand (int n, int A[])
{
    int i;
    for (i = 0;i < n; i++)
	A[i] = rand()%11;
}



int BubbleSort (int n, int A[]) //пузырьковая сортировка
{ int i,j,b,T;
  M=0; //пересылки
  C=0;  //сравнения
      for(i = 0;i < n;i++) //сколько раз всплывает элемент (кол-во проходов)
      { 
        for(j = n - 1;j > i;j--) { //1 проход, меняем элементы до i
			C++; 
			if (A[j] < A[j - 1]) { 
				b = A[j]; 
			  	A[j] = A[j - 1]; 
				A[j - 1] = b;
				M += 3; //перставляем местами и считаем кол-во пересылок
                }
		}
      }
      T = M + C;
}

int grafic()
{
int n;
int i;
int A[500];

 initwindow (1000, 640); 
    
    //оси координат
    line(50,600,950,600);
    line(50,600,50,50);
    line(65,65,50,50);
    line(35,65,50,50);
    line(950,600,935,615);
    line(950,600,935,585);
    setcolor (COLOR(255,0,0) ); 
    outtextxy ( 700, 200, "ShakerSort" );
    setcolor (COLOR(0,255,0) ); 
    outtextxy ( 700, 180, "BubbleSort" );
    setcolor (COLOR(255,255,0) ); 
    outtextxy ( 950, 600, "(n)" );
	setcolor (COLOR(255,255,0) );
	outtextxy ( 5, 70, "(Mf+Cf)" );
    
    //BubbleSort - зеленый
    setcolor(COLOR(0,255,0));
    moveto(50,600);
    for(n = 100;n <= 500;n += 100)
    {
      fc_rand (n, A);  
      lineto(50 + n, 600 - ( BubbleSort (n, A) / 500 ));
    }

    //ShakerSort - Красный
    n = 100;
    fc_rand	(n, A);
    setcolor(COLOR(255,0,0));
    moveto(50,600);
    for(n = 100;n <= 500;n += 100)
    {
      fc_rand (n, A);  
      lineto(50 + n, 600 - (ShakerSort (n, A) / 500));
    }
    
  getch();
  closegraph();
}

void fc_up(int n, int *s) 
{
    int i;
    for (i = 0; i < n; i++) 
	s[i] = i + 1;
}

void fc_down(int n, int *A) 
{
    int i, x;
    x = n;
    for (i = 0; i < n; i++) 
	A[i] = x--;
}



int main()
{
    int i, S[n], B[n], k, Mt, Ct, N;
    double t, total = 0;
    Ct=(n*n-n)/2;
    Mt=3*(n*n-n)/4;

    printf("неотсортированный массив: ");
    fc_rand(n, S);
    fc_rand(n, B);
    for (i = 0; i < n; i++)
	printf("%d ", B[i]);
    printf("\n");
    printf("неотсортированный массив: ");
    for (i = 0; i < n; i++)
	printf("%d ", S[i]);
    printf("\n________________________________________________________");
    
	ShakerSort(n, S);
	BubbleSort (n, B);
    printf("\nотсортированный массив BubbleSort: ");
    for (i = 0; i < n; i++)
	printf("%d ", B[i]);
	printf("\nотсортированный массив ShakerSort: ");
    for (i = 0; i < n; i++)
	printf("%d ", S[i]);
	printf("\n________________________________________________________");
	printf("\nТеоретическое количество сравнений %d\nТеоретическое количество пересылок %d\n",Ct,Mt);
	printf("________________________________________________________");
    printf("\nПрактическое количество сравнений %d\nПрактическое количество пересылок %d",C,M);
    printf("\n________________________________________________________");
    printf("\n \n \n n  |          M+C bubble      |          M+C shaker\n");
                               
 printf("    |   inc  |  rand  |  dec   |   inc  |  rand   |  dec  \n");
 printf("____|________|________|________|________|_________|______\n");
 for (i=1;i<6;i++)
 {
  N=i*100;
  int array[N];
  printf("%3d |",i);
  fc_up(N,array);
  BubbleSort(N, array);
  printf("%7d |",M + C);
  fc_rand(N, array);
  BubbleSort(N, array);
  printf("%7d |",M + C);
  fc_down(N,array);
  BubbleSort(N, array);
  printf("%7d |",M + C);
  fc_up(N, array);
  ShakerSort(N, array);
  printf("%7d |", m + c);
  fc_rand(N, array);
  ShakerSort(N, array);
  printf("%7d |", m + c);
  fc_down(N, array);
  ShakerSort(N, array);
  printf("%7d |\n",m + c);
 }
    grafic();
	getch();
    return 0;
}
