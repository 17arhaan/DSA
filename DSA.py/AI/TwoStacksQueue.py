class TwoStacksQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    def enqueue(self,item):
        self.stack1.append(item)
    
    def dequeue(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop() if self.stack1 else "Queue is Empty..."

    def display(self):
        print("Stack 1 ---->")
        print(self.stack1)
        print("Stack 2 ---->")
        print(self.stack2)

if __name__ == "__main__":
    queue_obj = TwoStacksQueue()
    ch = 0  
    while (ch != 4):                         
        print("\n____ MENU ____")
        print("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n")
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