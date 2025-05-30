def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

size = int(input("Enter the number of elements: "))
arr = []
for i in range(size):
    print(f"Enter the element {i+1} :" ,end=" ")
    element = int(input())
    arr.append(element)

print("Original Array --->", end=" ")
for i in range(size):
    print(arr[i], end=" ")

bubbleSort(arr)

print("\nSorted Array ----->", end=" ")
for i in range(size):
    print(arr[i], end=" ")
