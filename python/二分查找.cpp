def binarySearch (arr, l, r, x): 
    if r >= l: 
        mid = int(l + (r - l)/2)
        if arr[mid] == x: 
            return mid 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
        else: 
            return binarySearch(arr, mid+1, r, x) 
    else: 
        return -1
def lower_bound(arr, left, right, tar): #在left到right范围内寻找第一个大于等于tar的值
    if left <= right:
        mid = int(left + (right-left)/2)
        if arr[mid] < tar:
            return lower_bound(arr, mid+1, right, tar)
        else:
            return lower_bound(arr, left, mid-1, tar)
    else:
        return left
def upper_bound(arr, left, right, tar): 
    if left <= right:
        mid = int(left + (right-left)/2)
        if arr[mid] <= tar:
            return upper_bound(arr, mid+1, right, tar)
        else:
            return upper_bound(arr, left, mid-1, tar)
    else:
        return left