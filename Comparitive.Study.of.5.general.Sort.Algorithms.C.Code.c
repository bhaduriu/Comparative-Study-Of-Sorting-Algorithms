    #include<stdio.h>
    #include<math.h>
    #include<stdlib.h>
    #include<time.h>
    clock_t begin,end;
    double bubblesort(int a[], int n)
    {
        int i,j,tmp;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    tmp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                }
            }
        }
    }
    double selSort(int d[],int size)
    {
        int i,j,min,t;
        for(i=0;i<size-1;i++)
        {
             min=i;
             for(j=i+1;j<size;j++)
             {
                  if(d[j]<d[min])
                     min=j;
             }
             t=d[i];
             d[i]=d[min];
             d[min]=t;
        }
    }
    double InsertionSort(int a[],int n)
    {
        int i,j,t;
        for(i=1;i<n;i++)
        {
            t=a[i];
            for(j=i;j>0 && t<a[j-1];j--)
               {
                   a[j]=a[j-1];
               }
            a[j]=t;
        }
    }
    double part(int arr[],int min,int max)
    {
     int mid;
     if(min<max)
     {
       mid=min+(max-min)/2;
       part(arr,min,mid);
       part(arr,mid+1,max);
       merge(arr,min,mid,max);
     }
    }
    void merge(int arr[],int min,int mid,int max)
    {
      int tmp[20000];
      int i,j,k,m;
      j=min;
      m=mid+1;
      for(i=min; j<=mid && m<=max ; i++)
      {
         if(arr[j]<=arr[m])
         {
             tmp[i]=arr[j];
             j++;
         }
         else
         {
             tmp[i]=arr[m];
             m++;
         }
      }
      if(j>mid)
      {
         for(k=m; k<=max; k++)
         {
             tmp[i]=arr[k];
             i++;
         }
      }
      else
      {
         for(k=j; k<=mid; k++)
         {
            tmp[i]=arr[k];
            i++;
         }
      }
      for(k=min; k<=max; k++)
         arr[k]=tmp[k];
    }
    void swap (int a[], int left, int right)
    {
     int temp;
     temp=a[left];
     a[left]=a[right];
     a[right]=temp;
    }
    double quicksort( int a[], int low, int high )
    {
     int pivot;
     if ( high > low )
     {
      pivot = partition( a, low, high );
      quicksort( a, low, pivot-1 );
      quicksort( a, pivot+1, high );
     }
    }
    int partition( int a[], int low, int high )
    {
     int left, right;
     int pivot_item;
     int pivot = left = low;
     pivot_item = a[low];
     right = high;
     while ( left < right )
     {
      while( a[left] <= pivot_item )
       left++;
      while( a[right] > pivot_item )
       right--;
      if ( left < right )
       swap(a,left,right);
     }
     a[low] = a[right];
     a[right] = pivot_item;
     return right;
    }
    printArray(int a[],int size)
    {
        int i;
        printf("%d\n");
        for(i=0;i<size;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    main()
    {
        time_t t;srand((unsigned) time(&t));
        int i,n=10000;int a[10000];int x,y;
        double tt;
        FILE *fp;
        fp=fopen("data.dat","w");

        for(i=0;i<10000;i++)
            a[i]=rand()%20000;
        begin = clock();
        bubblesort(a,n);
        end = clock();
        tt = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Bubble Sort:\t%lf\n",tt);
        fprintf(fp,"1 %lf\n",tt);

        for(i=0;i<10000;i++)
            a[i]=rand()%20000;
        begin = clock();
        selSort(a,n);
        end = clock();
        tt = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Selection Sort:\t%lf\n",tt);
        fprintf(fp,"2 %lf\n",tt);

        for(i=0;i<10000;i++)
            a[i]=rand()%20000;
        begin = clock();
        InsertionSort(a,n);
        end = clock();
        tt = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Insertion Sort:\t%lf\n",tt);
        fprintf(fp,"3 %lf\n",tt);

        for(i=10000-1;i>=0;i--)
            a[i]=rand()%1000;
        begin = clock();
        part(a,0,n-1);
        end = clock();
        tt = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Merge Sort:\t%lf\n",tt);
        fprintf(fp,"4 %lf\n",tt);

        for(i=10000-1;i>=0;i--)
            a[i]=rand()%1000;
        begin = clock();
        tt=quicksort(a,0,n-1);
        end = clock();
        tt = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Quick Sort:\t%lf\n",tt);
        fprintf(fp,"5 %lf\n",tt);

        fclose(fp);
    }
