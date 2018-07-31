class Node:
    def __init__(self, val):
        self.l = None
        self.r = None
        self.val = val

    def insert(self, val):
        if self.data < val:
            if (self.left is None):
                self.left = Node(val)
            else: 
                self.left.insert(self.l, val)
        elif self.data > val: 
            if (self.right is None):
                self.right = Node(val)
            else:
                self.right.insert(self.r, val)
        else:
            self.val = val