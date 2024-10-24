def bubblesortt(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

size = int(input("Enter the size of Array: "))
arr = []
for i in range(size):
    element = int(input(f"Enter Element {i + 1}: "))
    arr.append(element)

print("Original Array --->", end=" ")
for ele in arr:
    print(ele, end=" ")

bubblesortt(arr)

print("\nSorted Array ----->", end=" ")
for ele in arr:
    print(ele, end=" ")