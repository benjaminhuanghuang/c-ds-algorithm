typedef struct HeapStruct *MaxHeap; //定义指针

struct HeapStruct {
    int *Elements; //存储堆元素的数组
    int Size;
    int Capacity;  //堆的最大容量
};


MaxHeap Create (int MaxSize) {
    MaxHeap H = malloc( sizeof(struct HeapStruct) );
    H->Elements = malloc( (MaxSize + 1) * sizeof(int) );//申请数组空间
    H->Size = 0;
    H->Capacity = MaxSize;
    //定义哨兵为大于堆中所有可能的值，便于插入时不必设置循环遍历i>1
    //堆元素从下标1开始存放
    H->Elements[0] = MaxData;
    return H;
}

void PercDown( MaxHeap H, int p )
{ /* 下滤：将H中以H->Elements[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    int X;

    X = H->Elements[p]; /* 取出根结点存放的值 */
    for( Parent = p; Parent * 2 <= H->Size; Parent = Child ) {
        Child = Parent * 2; //取左孩子
        if( (Child != H->Size) && ( H->Elements[Child] < H->Elements[Child+1]) ) 
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= H->Elements[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}

void BuildHeap( MaxHeap H, int Size)
{ /* 调整H->Elements[]中的元素，使满足最大堆的有序性  */

    int i;
    for (i = 1; i <= Size; i++)
        scanf("%d",&(H->Elements[i]));
    H->Size = Size;

    /* 从最后一个结点的父节点开始，到根结点1 */
    for( i = H->Size / 2; i>0; i-- )
        PercDown( H, i );
}

void Insert (MaxHeap H, int item) {
    int i;
    if (H->Size == H->Capacity) {
        printf("The Heap is full!\n");
        return;
    }
    i = ++H->Size;
    for (; H->Elements[i/2] < item; i/=2) {//如果没有设置哨兵，需要条件i>1
        H->Elements[i] = H->Elements[i/2]; //把父亲的值赋给孩子,小元素下沉
    }
    H->Elements[i] = item;
}

//从大顶堆中取出最大元素，并删除一个结点
int DeleteMax(MaxHeap H) {
    int Parent, Child;
    int MaxItem, temp;
    if(H->Size == 0) {
        printf("The Heap is Empty！\n");
        return 0;
    }
    //取出树根——最大值元素
    MaxItem = H->Elements[1];
    //用大顶堆中最后一个元素从根节点开始过滤下层结点
    temp = H->Elements[H->Size--];
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) { //是否有左儿子
        //从左右儿子中找一个大的
        Child = Parent * 2;
        if ( (Child != H->Size)&&
             (H->Elements[Child] < H->Elements[Child + 1]) ) //有右儿子的情况下 左右儿子比较
            Child ++; //Child指向左右子结点的较大者
        if ( temp >= H->Elements[Child]) break;//如果比左右儿子较大者还要大，就无需移动位置
        else //移动temp元素到下一层
            H->Elements[Parent] = H->Elements[Child]; //如果比左右儿子较大者小，那么把大元素拷到双亲位置
    }
    //此时的位置Parent是副本，放入末尾的元素到合适的位置
    H->Elements[Parent] = temp;
    return MaxItem;
}

int main(int argc, char const *argv[]) {
    MaxHeap mh;
    mh = Create(20);
    BuildHeap(mh,12);
    Insert(mh, 98);
    int i;
    for (i = 1; i < 14; i++)
        printf("%-4d", DeleteMax(mh));
    printf("\n");
    return 0;
}

