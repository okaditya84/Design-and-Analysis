def mergesort(arr):
    if(len(arr)>1):
        mid=len(arr)//2
        left=arr[:mid]
        right=arr[mid:]
        mergesort(left)
        mergesort(right)
        i=j=k=0
        while(i<len(left) and j<len(right)):
            if(left[i]<right[j]):
                arr[k]=left[i]
                i+=1
            else:
                arr[k]=right[j]
                j+=1
            k+=1
        while(i<len(left)):
            arr[k]=left[i]
            i+=1
            k+=1
        while(j<len(right)):
            arr[k]=right[j]
            j+=1
            k+=1
arr=[1,2,3,4,5,6,7,8,9,10]
mergesort(arr)
print(arr)
