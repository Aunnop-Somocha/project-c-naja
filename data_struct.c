#include <stdio.h>
#include <stdlib.h>
//#include <limits.h> // ใช้ INT_MIN;
#define MAX_SIZE 10
// โครงสร้าง queue
struct Queue
{
    int items[MAX_SIZE];
    int rear; // ชี้ตำแหน่งที่จะเพิ่มdata
};
//functino สร้าง queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); /* malloc(sizeof(struct Queue)) จองหน่วยความจำมีขนาดเท่า struct Queue 
    ในวงเล็บของ sizeof และคืนค่าที่อยู่หน่วยความจำนั้นใน pointer q    (struct Queue *q)*/
    q->rear = -1; // หมายถึง คิวยังว่าง
    return q;
}
// function ตรวจสอบว่าคิวเต็มหรือไม่
int isFull(struct Queue* q){ // struct Queue *q  คือ pointer ที่ชี้ไปยัง struct Queue เพิ่อใช้อ้างอิงถึงตัวแปรด้านใน  ในที่นี่ คือ item กับ rear 
    return q->rear == MAX_SIZE - 1; // ถ้าเป็น True (1) คือเต็ม แต่ถ้าเป็น False (0) คือยังว่าง
}
// function ตรวจสอบว่าคิวว่างหรือไม่
int isEmpty(struct Queue*q){
    return q->rear == -1;
}
// function เพิ่มข้อมูล
void enqueue(struct Queue * q,int value){
    if (isFull(q))
    {
        printf("Queue is full.Cannot add element %d\n",value);
        return ;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Add sucsess  %d\n",value);
}
//function นำข้อมูล ออกจากคิว 
int dequeue(struct Queue*q){
    if (isEmpty(q))
    {
        printf("Queue is empty.cannot delete\n");
        return ;//INT_MIN; // return ค่าที่บอกว่าผิดพลาด
    }
    //1. นำข้อมูลตัวหน้าสุดออก (ตำแหน่ง 0)
    int item = q->items[0];
    printf("Delete %d\n",item);
    // 2. เลื่อนข้อมูลทั้งหมดมาข้างหน้า 1 ตำแหน่ง
    for (int i = 0;i< q->rear; i++)
    {
        q->items[i] = q->items[i+1] ; // ตำแหน่งที่ 1 =  2  ย้าย ตัวด้านซ้ายมาขวา 1 ตำแหน่ง
    }
    q->rear--; //ลดขนาด rearลงมา
    return item;
}
//function แสดงข้อมูล ใน Queue
void display(struct Queue* q){
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Items in queue:  ");
    for(int i = 0; i<=q->rear;i++){
        printf("%d\t",q->items[i]);
    }
    printf("\n");
    
}
int main(){
   struct Queue *q = createQueue();
   enqueue(q,10);
   enqueue(q,20);
   enqueue(q,30);
   display(q);
   printf("\n---Delet one item---\n");
   dequeue(q);
   dequeue(q);
   display(q);
}
