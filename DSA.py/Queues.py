class Queue:
    def __init__(self):
        self.queue = []

    def enqueue (self,item):
        self.queue.append(item)

    def dequeue(self):
        return self.queue.pop(0)
    
    def display(self):
        print(self.queue)

def main():
    queue_obj = Queue()
    ch = 0
    print("\n____ MENU ____")
    print("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n")
    while (ch != 4):
        ch = int(input(f"Enter Choice : "))
        if ch == 1:
            element = int(input(f"Enter Element To Enqueue : "))
            queue_obj.enqueue(element)
            print(f"{element} pushed enqueued.")
        elif ch == 2:
            queue_obj.dequeue()
            print(f"{element} pushed dequeued.")
        elif ch == 3:
            queue_obj.display()
        elif ch == 4:
            print(" ~ Exiting ~")
            break
        else :
            print ("Try Again.")
            
if __name__ == "__main__":
    main()