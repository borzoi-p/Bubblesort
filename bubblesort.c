#include<raylib.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

    
    void swap(int *a, int *b){
        int t;
        t=*a;
        *a=*b;
        *b=t;
    }

    void bub(int *a, int n){
        
        bool flag=true;
        while(flag){
            flag=false;
            for(int k=0;k<n-1;k++){
                if(*(a+k+1)<*(a+k)){
                    swap(a+k,a+k+1);
                    flag=true;
            }
        }
        
    }
    }


int main(){
    srand(time(NULL));

    InitWindow(1400, 1000, "BubbleSort");
    SetTargetFPS(60);
    int n=rand()%100+1;
    bool flag=true;
    int a[100]; 
    for(int i=0; i<n; i++){
        a[i]=rand()%1000+1;
    }
    
    int min=a[0];
    for(int i=0; i<n; i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    int max=a[0];
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    for(int i=0; i<n; i++){
        a[i]=10+((float)(a[i]-min)/(max-min))*980;
    }
    int primo=0; 
    while (!WindowShouldClose())
    {   
        if(primo==0){BeginDrawing();
        ClearBackground(BLACK);
        for(int k=0; k<n; k++){
        DrawRectangle(k*(1400/n), 1000-(a[k]), (1400/n)-2, a[k], WHITE);}
        primo++;
        EndDrawing();
        WaitTime(1);}
        
        while(flag){
            flag=false;
            for(int i=0;i<n-1;i++){
                if(a[i+1]<a[i]){
                    swap(&a[i],&a[i+1]);
                    flag=true;
                    BeginDrawing();
                    ClearBackground(BLACK);
                    for(int k=0; k<n; k++){
                        DrawRectangle(k*(1400/n), 1000-(a[k]), (1400/n)-2, a[k], WHITE);}    
                    EndDrawing();
                    }
        }
        
    }
    for(int k=0; k<n; k++){
        DrawRectangle(k*(1400/n), 1000-(a[k]), (1400/n)-2, a[k], GREEN);}
    
    EndDrawing();
    }
    
    
    CloseWindow();

    return 0;
}