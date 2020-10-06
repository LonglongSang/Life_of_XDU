class node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None


def build_tree(root,val):
    if root is None:
        return node(val)
    elif val > root.val:
        root.right = build_tree(root.right,val)
    elif val < root.val:
        root.left = build_tree(root.left,val)
    return root
def mid_traverse(root,arr):
    if root is None:
        return
    else:
        mid_traverse(root.left,arr)
        arr.append(root.val)
        mid_traverse(root.right,arr)

arr = [random.randint(0,1000000) for i in range(100)]
root = None
for i in arr:
    root = build_tree(root,i)
arr.clear()
mid_traverse(root,arr)
for i in range(0,min(100,len(arr))):
    print(arr[i])


